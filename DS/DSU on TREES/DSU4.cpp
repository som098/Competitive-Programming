/*
 Problem : Given a tree with n vertices and their colors and q queries
 in each query given an vertex v find no of distinct colors in the subtree of v
 MERGING OF SETS TAKE NLOGN TIME
 TIME COMPLEXITY ******(nlogn)******
 //// This problem can also be solved with MO's algo find for each query no of distinct elements in a range
 https://www.hackerrank.com/contests/101feb14/challenges/coloring-tree/problem
 BLOG 1:https://codeforces.com/blog/entry/44351
 BLOG 2:https://codeforces.com/blog/entry/10696
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
const int INF = 1e17;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int N=100005;
vi adj[N];
int cnt[N];int tin[N],tout[N],Time;int sz[N];ll ans[N];
int current;int c[N];int a[N];
void dfs1(int u,int p)
{
    tin[u]=Time++;
    a[Time-1]=c[u];
    sz[u]=1;
    for(int v:adj[u])
    {
        if(v!=p)
        {
            
            dfs1(v,u);
            sz[u]+=sz[v];
        }
    }
    tout[u]=Time-1;
}
void dfs(int u,int p,int keep)
{
    int mx=0,big= -1;
    for(int v:adj[u])
    {
        if(v!=p)
        {
            if(sz[v]>mx)
            {
                mx=sz[v];
                big=v;
            }
        }
    }
    for(int v:adj[u])
        if(v!=p&&v!=big)
            dfs(v,u,0);
    if(big!= -1)
        dfs(big,u,1);
    
    for(int v:adj[u])
    {
        if(v!=big&&v!=p)
        {
            for(int j=tin[v];j<=tout[v];j++)
            {
                cnt[a[j]]++;
                if(cnt[a[j]]==1)
                    current++;
            }
        }
    }
    
    cnt[c[u]]++;
    if(cnt[c[u]]==1)
        current++;
    ans[u]=current;
    if(keep==0)
    {
        for(int j=tin[u];j<=tout[u];j++)
        {
            
            cnt[a[j]]--;
            if(cnt[a[j]]==0)
                current--;
        }
    }
}
void solve()
{
    int n,root,m;
    cin>>n>>m>>root;
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int k=0;map<int,int>mp;
    map<int,int>::iterator it;
    for(int i=0;i<n;i++)
    {cin>>c[i+1];
        mp[c[i+1]]=0;
    }
    it=mp.begin();
    while(it!=mp.end())
    {
        it->second=k;
        it++;
        k++;
    }
    for(int i=1;i<=n;i++)
        c[i]=mp[c[i]];
    dfs1(root,0);
    dfs(root,0,1);
    while(m--)
    {
        cin>>u;
        cout<<ans[u]<<endl;
    }
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

