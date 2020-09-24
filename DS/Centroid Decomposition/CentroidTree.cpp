/*
 Centroid Tree
 Problem - https://codeforces.com/problemset/problem/321/C
 
 Height of the tree will be logn
 
 The path of any pair of city in the orignal tree will pass through the lca in centroid tree,so path between (u,v) can be breaked as (u,lca(u,v))+ (lca(u,v),v) , lca(u,v) - lca of (u,v) n centroid tree
 
 */
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define int long long int
typedef complex<long double> cd;
const long double pi=acos(-1);
typedef double db;
typedef long double ldb;
typedef pair <int,int> pii;
typedef pair <db,db> pdd;
typedef vector<int> vi;
typedef vector<vector<int> > matrix;

#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))

#define fi first
#define se second
#define endl "\n"
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>

inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p%m*p%m)%m;if(n%2) return (p%m*a%m)%m;else return p;}
const double EPS = 1e-9;
const ll MOD =998244353;
const ll hell=1000000007;
const int INF = 1e18;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

double startTime;
double getCurrentTime() {
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int N=100005;

vi adj[N+1],adj1[N+1];
int visited[N+1];int root;int sz[N+1];

void dfs(int u,int p)
{
    sz[u]=1;
    for(int v:adj[u])
        if(v!=p&& !visited[v])
        {
            dfs(v,u);
            sz[u]+=sz[v];
        }
}
int centroid(int u,int p,int sze)
{
    for(int v:adj[u])
    {
        if(v!=p && (!visited[v]) && sz[v]>sze)
            return centroid(v,u,sze);
    }
    return u;
}


void decompose(int u,int p)
{
    dfs(u,u);
    int c=centroid(u,u,sz[u]/2);
    if(!p)
        root=c;
    adj1[p].pb(c);
    adj1[c].pb(p);
    visited[c]=1;
    for(int v:adj[c])
    {
        if(!visited[v] && v!=p)
        {
            decompose(v,c);
        }
    }
}


void solve()
{
    
    int n;
    cin>>n;
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    decompose(1,0);
   
    
}



int32_t main()
{
    IOS;
    
    
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
