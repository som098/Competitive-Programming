/*
 Persistent Trie on tree
 Problem - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-path-1-f7009db6/

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
const double EPS = 1e-9;
const ll MOD =998244353;
const ll hell=1000000007;
const int INF = 1e17;
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
vector<pair<int,int>> adj[N];int up[N][21];int tin[N],tout[N];int Time;
typedef struct node
{
    node *bit[2];
    int cnt=0;
    
} Trie;
Trie* root[N];

Trie* get(Trie* cur,int bt)
{
    if(!cur||(!cur->bit[bt]))
        return NULL;
    return cur->bit[bt];
}
int getcount(Trie* cur,int bt)
{
    if(!cur||(!cur->bit[bt]))
        return 0;
    else
        return cur->bit[bt]->cnt;
}
void insert(Trie* old,Trie* cur,int x,int i)
{
    if(i<0)
        return;
    int bt=(x>>i)&1;
    cur->bit[bt]=new Trie();
    cur->bit[bt]->cnt++;
    
    if(old&&old->bit[bt])
        cur->bit[bt]->cnt+=old->bit[bt]->cnt;
    cur->bit[!bt]=get(old,!bt);
    insert(get(old,bt),cur->bit[bt],x,i-1);
}
int maxxor(Trie* cur1,Trie* cur2,Trie* cur3,int x,int i)
{
    if(i<0)
        return 0;
    int bt=(x>>i)&1;
    int cnt1=getcount(cur2,!bt)+getcount(cur1,!bt)-2*getcount(cur3,!bt);
    if(cnt1>0)
        return (1LL<<i)+maxxor(get(cur1,!bt),get(cur2,!bt),get(cur3,!bt),x,i-1);
    else
        return maxxor(get(cur1,bt),get(cur2,bt),get(cur3,bt),x,i-1);
}
void dfs(int u,int p,int x)
{
    root[u]=new Trie();
    insert(root[p],root[u],x,21);
    tin[u]=Time++;
    up[u][0]=p;
    for(int i=1;i<=20;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i].fi,w=adj[u][i].se;
        if(v!=p)
        {
            dfs(v,u,w);
        }
    }
    tout[u]=Time++;
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
    for(int i=20;i>=0;i--)
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}

void solve()
{
    int n;
    //cin>>n;
    int q;
    cin>>n>>q;
    int u,v,w;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v>>w;
        adj[u].pb(m1(v,w));
        adj[v].pb(m1(u,w));
    }
    root[0]=new Trie();
    dfs(1,0,0);
    tout[0]=INF;
    while(q--)
    {
        cin>>u>>v>>w;
        cout<<maxxor(root[u],root[v],root[lca(u,v)],w,21)<<endl;
    }
    
}

int32_t main()
{
    IOS;
    //FILE *fin = freopen("in","r",stdin);
    //FILE *fout = freopen("out","w",stdout);
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}





