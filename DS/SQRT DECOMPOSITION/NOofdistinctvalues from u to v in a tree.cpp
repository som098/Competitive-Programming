//#include "stdc++.h"
#include<bits/stdc++.h>
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
#define int long long int
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int N=40000;
int a[4*N+1],tin[N+1],tout[N+1];int f[N+5];
vi adj[N+1];int sz;int node[N+5];int Time=0;
int up[N+1][21];
struct query
{
    int id,l,r,u,v;
};
void swap(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
}
bool compare(query &q1,query &q2)
{
    int b1,b2;
    b1=q1.l/sz;
    b2=q2.l/sz;
    if(b1<b2)
        return 1;
    else if(b2<b1)
        return 0;
    else
        return (q1.r<=q2.r);
}
void dfs(int u,int p)
{
    tin[u]=Time;int v;
    //fr[u]++;
    a[Time]=u;
    Time++;
    up[u][0]=p;
    for(int i=1;i<=20;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(v!=p)
        {
            dfs(v,u);
            //a[Time]=u;
            //fr[u]++;
            //Time++;
        }
    }
    //fr[u]++;
    a[Time]=u;
    Time++;
    tout[u]=Time-1;
}
bool is_ancestor(int u,int v)
{
    if(tin[u]<=tin[v]&&tout[u]>=tout[v])
        return 1;
    return 0;
}
int lca(int u,int v)
{
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    for(int i=20;i>=0;i--)
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}
int32_t main()
{
    IOS;
    int n,m,u,v,l,r,lc;
    scanf("%lld%lld",&n,&m);
    int w[n+1];int k=1;map<int,int>mp;
    map<int,int>::iterator it;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&w[i]);
        mp.insert(m1(w[i],0));
    }
    it=mp.begin();
    while(it!=mp.end())
    {
        it->second=k;
        k++;
        it++;
    }
    for(int i=1;i<=n;i++)
        w[i]=mp[w[i]];
    for(int i=0;i<n-1;i++)
    {
        scanf("%lld%lld",&u,&v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);
    //for(int i=0;i<Time;i++)
    //  cout<<a[i]<<" ";
    //cout<<endl;
    query queries[m];
    for(int i=0;i<m;i++)
    {
        scanf("%lld%lld",&u,&v);
        if(tin[u]>tin[v])
            swap(u,v);
        if(is_ancestor(u,v))
        {
            l=tin[u];
            r=tin[v];
        }
        else if(is_ancestor(v,u))
        {
            l=tin[v];
            r=tin[u];
        }
        else
        {
            
            l=tout[u];
            r=tin[v];
            
        }
        queries[i].id=i;
        queries[i].l=l;
        queries[i].r=r;
        queries[i].u=u;
        queries[i].v=v;
    }
    sz=(int)sqrt(Time);
    sort(queries,queries+m,compare);
    int ans[m];int cl=0,cr=0,crans=0;
    for(int i=0;i<m;i++)
    {
        l=queries[i].l;
        r=queries[i].r;
        u=queries[i].u;
        v=queries[i].v;
        lc=lca(u,v);
        
        //cout<<l<<" "<<r<<endl;
        while(cl>l)
        {
            node[a[cl-1]]++;
            if(node[a[cl-1]]==2)
            {
                f[w[a[cl-1]]]--;
                if(f[w[a[cl-1]]]==0)
                    crans--;
            }
            else if(node[a[cl-1]]==1)
            {
                f[w[a[cl-1]]]++;
                if(f[w[a[cl-1]]]==1)
                    crans++;
            }
            cl--;
        }
        while(cl<l)
        {
            node[a[cl]]--;
            
            if(node[a[cl]]==1)
            {
                f[w[a[cl]]]++;
                if(f[w[a[cl]]]==1)
                    crans++;
            }
            else if(node[a[cl]]==0)
            {
                f[w[a[cl]]]--;
                if(f[w[a[cl]]]==0)
                    crans--;
            }
            //cout<<crans<<" ";
            cl++;
        }
        while(cr<r+1)
        {
            node[a[cr]]++;
            if(node[a[cr]]==2)
            {
                f[w[a[cr]]]--;
                if(f[w[a[cr]]]==0)
                    crans--;
            }
            else if(node[a[cr]]==1)
            {
                f[w[a[cr]]]++;
                if(f[w[a[cr]]]==1)
                    crans++;
            }
            // cout<<crans<<" ";
            cr++;
        }
        while(cr>r+1)
        {
            node[a[cr-1]]--;
            
            if(node[a[cr-1]]==1)
            {
                f[w[a[cr-1]]]++;
                if(f[w[a[cr-1]]]==1)
                    crans++;
            }
            else if(node[a[cr-1]]==0)
            {
                f[w[a[cr-1]]]--;
                if(f[w[a[cr-1]]]==0)
                    crans--;
            }
            cr--;
        }
        //cout<<endl;
        ans[queries[i].id]=crans;
        if(lc!=u&&lc!=v)
        {
            if(f[w[lc]]==0)
                ans[queries[i].id]+=1;
        }
    }
    for(int i=0;i<m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}

