/*
 Finding articulations points n an undirected graph
 */
#include<bits/stdc++.h>
//#include "stdc++.h"
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
int Time=0;
int low[100001];
int tin[100001];
bool visited[100001];
vector<int> arpoints;
vi adj[100001];
int child=0;
void dfs(int u,int parent)
{
    int v;
    visited[u]=1;
    tin[u]=(++Time);
    low[u]=tin[u];
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(!visited[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=tin[u]&&parent!=0)
            {
                arpoints.pb(u);
            }
            if(parent==0)
                child++;
        }
        else if(v!=parent)
        {
            low[u]=min(low[u],tin[v]);
            if(low[v]>tin[u]&&parent!=0)
            {
                 arpoints.pb(u);
            }
        }
    }
    if(parent==0&&child>1)
        arpoints.pb(u);
}
int main()
{
    IOS;
    
    int n,m;
    cin>>n>>m;int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    bool is[n+1];
    reset(is,0);
    for(int i=0;i<arpoints.size();i++)
        is[arpoints[i]]=1;
    for(int i=1;i<=n;i++)
        if(is[i])
            cout<<i<<endl;
    return 0;
}
