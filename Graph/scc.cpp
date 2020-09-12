#include "stdc++.h"
//#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef vector<int> vi;
#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))
#define sz(x) (int)(x.size())
#define ff first
#define ss second
#define endl "\n"
//#define int long long int
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
/*
 shuffle(x,x+n,rng) // shuffling elements of x in random order
 */
int n,n1;
vi g[200001],r[200001];
int cn[200001];bool visited[200001];int in[200001];stack<int>st;vi adj[200001];
void dfs1(int u)
{
    visited[u]=1;
    for(int i=0;i<g[u].size();i++)
        if(!visited[g[u][i]])
            dfs1(g[u][i]);
    st.push(u);
}
void dfs2(int u,int k)
{
    visited[u]=1;
    cn[u]=k;
    for(int i=0;i<r[u].size();i++)
    {
        if(!visited[r[u][i]])
            dfs2(r[u][i],k);
    }
}
void scc()
{
    int u;
    for(int i=1;i<=n;i++)
        if(!visited[i])
        {
            dfs1(i);
        }
    memset(visited,0,sizeof(visited));int cp=1;
    while(!st.empty())
    {
        u=st.top();
        st.pop();
        if(!visited[u])
        {
            dfs2(u,cp);
            cp++;
        }
    }
    n1=cp-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            if(cn[i]!=cn[g[i][j]])
            {
                adj[cn[i]].pb(cn[g[i][j]]);
                in[cn[g[i][j]]]++;
            }
        }
    }
}
int32_t main()
{
    IOS;
    int k;int u,v;
    cin>>n>>k;
    int p[n];
    int Q[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
        cin>>Q[i];
    for(int i=0;i<n-1;i++)
    {
        g[p[i]].pb(p[i+1]);
        g[Q[i]].pb(Q[i+1]);
        r[p[i+1]].pb(p[i]);
        r[Q[i+1]].pb(Q[i]);
    }
    scc();queue<int>q;
    //cout<<1<<endl;
    //for(int i=1;i<=n;i++)
    //  cout<<cn[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=n1;i++)
    {
        if(in[i]==0)
            q.push(i);
    }
    int ans[n1+1];int st=-1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        ans[u]=min(25,st+1);
        st++;
        for(int j=0;j<adj[u].size();j++)
        {
            v=adj[u][j];
            if(in[v])
            {
                in[v]--;
                if(in[v]==0)
                    q.push(v);
            }
        }
    }
    if((st+1)<k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    char ch;
    for(int i=1;i<=n;i++)
    {
        ch='a'+ans[cn[i]];
        cout<<ch;
    }
    cout<<endl;
    return 0;
}

