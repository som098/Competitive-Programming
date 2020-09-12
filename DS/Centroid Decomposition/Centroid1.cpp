/*
 
 CENTROID DECOMPOSITION
 Blog : https://www.quora.com/q/threadsiiithyderabad/Centroid-Decomposition-of-a-Tree
 Problem - No of Unordered pair of nodes at distance exactly k 1<=n<=1e5,1<=k<=1e5
 link:https://codeforces.com/gym/270570/problem/J
 
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
typedef pair <int, int> pii;
typedef pair <db, db> pdd;
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
const ll MOD =998244353;
const ll hell=1000000007;
const int INF = 1e6;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

const int N=100005;

set<int> g[N];
int dp[21][2];int sz[N];int vl[N];int a[N];int depth[N];int tin[N],tout[N];
int up[N][20];int sze=0;
int d[N];int k;int ans;int Time;
void dfs0(int u,int p)
{
    tin[u]=Time++;
    up[u][0]=p;
    for(int i=1;i<20;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(auto it=g[u].begin();it!=g[u].end();it++)
    {
        int v= *it;
        if(v!=p)
        {
            depth[v]=1+depth[u];
            dfs0(v,u);
        }
    }
    tout[u]=Time-1;
}
bool is_ancestor(int u,int v)
{
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int lca(int u,int v)
{
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    for(int i=19;i>=0;i--)
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}
int dist(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void preprocess()
{
    tout[0]=INF;
    dfs0(1,0);
}
void dfs1(int u,int p)
{
    sze++;sz[u]=1;
    for(auto it=g[u].begin();it!=g[u].end();it++)
    {
        if((*it)!=p)
        {
            dfs1(*it,u);
            sz[u]+=sz[*it];
        }
    }
}
int dfs2(int u,int p)
{
    for(auto it=g[u].begin();it!=g[u].end();it++)
    {
        if((*it)!=p)
        {
            if(sz[*it]>sze/2)
                return dfs2(*it,u);
        }
    }
    return u;
}
void dfs3(int u,int p,int centroid)
{
    int dt=dist(u,centroid);
    if(k>=dt)
        ans=ans+d[k-dt];
    for(auto it=g[u].begin();it!=g[u].end();it++)
    {
        if((*it)!=p)
        {
            dfs3(*it,u,centroid);
        }
    }
}
void dfs4(int u,int p,int centroid,int diff)
{
    int dt=dist(u,centroid);
    d[dt]+=diff;
    for(auto it=g[u].begin();it!=g[u].end();it++)
    {
        if((*it)!=p)
        {
            dfs4(*it,u,centroid,diff);
        }
    }
}

void decompose(int u,int p)
{
    sze=0;
    dfs1(u,u);
    int centroid=dfs2(u,u);
    
    d[0]=1;
    for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
    {
        if((*it)!=p)
        {
            dfs3(*it,centroid,centroid);
            dfs4(*it,centroid,centroid,1);
        }
    }
    d[0]--;
    for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
    {
        if((*it)!=p)
        {
            dfs4(*it,centroid,centroid,-1);
        }
    }
    for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
    {
        if((*it)!=p)
        {
            g[*it].erase(centroid);
            decompose(*it,centroid);
        }
    }
    g[centroid].clear();
    
    
}
void solve()
{
    int n;
    cin>>n>>k;
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    preprocess();
    decompose(1,0);
    cout<<ans<<endl;
}


int32_t main()
{
    
    IOS;
    //FILE *fin = freopen("in","r",stdin);
    //FILE *fout = freopen("out","w",stdout);
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

