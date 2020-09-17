/*
 Bridge Tree-https://www.quora.com/q/threadsiiithyderabad/The-Bridge-Tree-of-a-graph
 Problem - https://www.codechef.com/problems/CHEFLAND

 */

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

vi adj[N+1];int Time,tin[N+1],low[N+1];
map<pair<int,int>,int> mp;
int parent[N+1];bool visited[N+1];
int parent1[N+1];
int find(int i)
{
     if(parent[i]==i)
         return i;
    return parent[i]=find(parent[i]);
}
void Union(int u,int v)
{
    int x=find(u);
    int y=find(v);
    if(x!=y)
        parent[y]=x;
}
int find1(int i)
{
    if(parent1[i]==i)
        return i;
    return parent1[i]=find1(parent1[i]);
}
void Union1(int u,int v)
{
    int x=find1(u);
    int y=find1(v);
    if(x!=y)
        parent1[y]=x;
}
void dfs(int u,int p)
{
   
    visited[u]=1;
    tin[u]=Time++;
    low[u]=tin[u];
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        if(!visited[v])
        {
            dfs(v,u);
            low[u]=min(low[v],low[u]);
            if(low[v]<=tin[u]|| mp[m1(min(u,v),max(u,v))]>1)
                Union(u,v);
        }
        else
        {
            low[u]=min(low[u],tin[v]);
        }
    }
}



void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        parent[i]=i;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[m1(min(u,v),max(u,v))]++;
    }
    //debug(1);
    dfs(1,0);
  //  debug(1);
    for(int i=1;i<=n;i++)
    {parent[i]=find(i);
        parent1[i]=i;
    }
    memset(visited,0,sizeof(visited));
    int dg[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        for(int v:adj[i])
        {
            if(parent[i]==parent[v])
                continue;
            
            int x=find1(parent[v]),y=find1(parent[i]);
            if(x!=y)
            {
                dg[parent[v]]++;
                dg[parent[i]]++;
                Union1(parent[v],parent[i]);
            }
            
            
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++)
        mx=max(mx,dg[i]);

if(mx<=2)
{
    cout<<"YES"<<endl;
}
else
    cout<<"NO"<<endl;
}



int32_t main()
{
    IOS;
   
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
