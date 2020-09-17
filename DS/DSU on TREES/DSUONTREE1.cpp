/*
 Problem : Given a tree with n vertices and their colors and q queries
 in each query given an vertex v find no of distinct colors in the subtree of v
 MERGING OF SETS TAKE NLOGN TIME
 TIME COMPLEXITY nlogn^2
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
set<int> s[N];int ans[N];set<int>::iterator it;int ind[N];int c[N];
vi adj[N];int sz[N];
void dfs(int u,int p)
{
    int msz=0,big= -1;
    sz[u]=1;
    for(int v:adj[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            sz[u]+=sz[v];
            if(msz<s[ind[v]].size())
            {
                msz=s[ind[v]].size();// max set size of child or we can compare with size of subtree also ie sz[v];
                big=ind[v];
            }
        }
    }
    if(big== -1)
    {
        ind[u]=u;
        s[u].insert(c[u]);
        ans[u]=1;
        return;
    }
    for(int v:adj[u])
    {
        if(v!=p&&ind[v]!=big)
        {
            for(it=s[ind[v]].begin();it!=s[ind[v]].end();it++)
                s[big].insert(*it);  // merging smaller set into large
            s[ind[v]].clear();
        }
    }
    s[big].insert(c[u]);
    ans[u]=(int)s[big].size();
    
    ind[u]=big;
    // larger set is not copied to the vertex values are itself inserted into the set of big child;
}
void solve()
{
    int n,m,root;
    cin>>n>>m>>root;
    int u,v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=0;i<n;i++)
        cin>>c[i+1];
    dfs(root,0);
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




