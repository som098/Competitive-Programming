/*
 Given a tree with n nodes and q queries in each query we are given two nodes u and v and we have to find
 the maximum weight edge in the path from u to v
 */
/*
 It is solved by BINARY LIFTING method to find LCA with some modifications
 it answers every query in logn time with nlogn preprocessing 1<=n<=200000
*/
/*
 ############### sabka katega ###############
 ********************************
 */
//#include "stdc++.h"
#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tuple<int, int, int> t3;
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
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0) return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p; }
#define flush fflush(stdout)
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
int up[200001][20];int tin[200001],tout[200001];int Time=0;int mx[200001][20];
///int prt[200001];
void dfs(vector<pair<int,int>> adj[],int u,int parent,int w1)
{
    tin[u]= ++Time;
    up[u][0]=parent;
    //prt[u]=parent;
    mx[u][0]=w1;
    for(int i=1;i<=19;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        mx[u][i]=max(mx[u][i-1],mx[up[u][i-1]][i-1]);
    }
    for(int i=0;i<adj[u].size();i++)
        if(adj[u][i].first!=parent)
            dfs(adj,adj[u][i].first,u,adj[u][i].second);
    tout[u]= ++Time;
}
int is_ancestor(int u,int v)
{
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int lca(int u,int v)
{
    int ans=0;
    if(is_ancestor(u,v))
        return 0;
    //int i=0;
    for(int i=19;i>=0;i--)
    {
        if(!is_ancestor(up[u][i],v))
        {
            ans=max(ans,mx[u][i]);
            u=up[u][i];
        }
    }
    
    return max(ans,mx[u][0]);
}
int main()
{
    IOS;//ifstream fin("input.txt");ofstream fout("output.txt");
    int n;
    cin>>n;
    vector<pair<int,int>> adj[n+1];int u,v,w;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back(m1(v,w);
      adj[v].push_back(m1(u,w));
    }
        dfs(adj,1,1,0);
        int q;
        cin>>q;int mx1,mx2;
    while(q--)
    {
        cin>>u>>v;
        mx1=lca(u,v);
        mx2=lca(v,u);
    cout<<max(mx1,mx2)<<endl;
    }
    
    return 0;
    
}
