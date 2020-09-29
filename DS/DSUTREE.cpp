/*
 DSU TREE
 Problem - https://codeforces.com/contest/1417/problem/F
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

inline int gcd(int a,int b){if(a==0) return b;return gcd(b%a,a);}
inline int power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p%m*p%m)%m;if(n%2) return (p%m*a%m)%m;else return p;}
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

const int N=400005;
vi adj[N+1];int tin[N+1],tout[N+1],Time;
int parent[N+1];int n;int a[N+1];
pair<int,int> st[4*N];
int find(int i)
{
    if(parent[i]==i)
        return i;
    return parent[i]=find(parent[i]);
}
void Union(int i,int j)
{
    int x=find(i),y=find(j);
    if(x==y)
        return;
    n++;
    parent[n]=n;
    parent[y]=n;             // creating a new node as parent of x and y
    parent[x]=n;
    adj[n].pb(x);        // making edges DSU Tree
    adj[n].pb(y);
}
void dfs(int u,int p)
{
    tin[u]=Time++;
    for(int v:adj[u])
        if(v!=p)
            dfs(v,u);
    tout[u]=Time-1;
}
void update(int i,int l,int r,int in,pair<int,int> x)
{
    if(in>r||in<l)
        return;
    if(l==r)
    {
        st[i]=x;
        return;
    }
    int m=(l+r)/2;
    update(2*i+1,l,m,in,x);
    update(2*i+2,m+1,r,in,x);
    st[i]=st[2*i+1];
    if(st[2*i+1].fi<st[2*i+2].fi)
        st[i]=st[2*i+2];
}
pii query(int i,int l,int r,int qs,int qe)
{
   if(qs>r||qe<l)
       return m1(-INF,0);
    if(qs<=l&&qe>=r)
        return st[i];
    int m=(l+r)/2;
    pair<int,int> p1=query(2*i+1,l,m,qs,qe);
    pair<int,int> p2=query(2*i+2,m+1,r,qs,qe);
    if(p1.fi>=p2.fi)
        return p1;
    else
        return p2;
}








void solve()
{
    int m,q;
    cin>>n>>m>>q;
    for(int i=0;i<=n;i++)
        parent[i]=i;
    vector<pii> edge(m);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
    {
        cin>>edge[i].fi>>edge[i].se;
    }
    int del[m]={0};
    vector<pii>qry;
    int t,u;
    for(int i=0;i<q;i++)
    {
        cin>>t>>u;
        qry.pb(m1(t,u));
        if(t==2)
            del[u-1]=1;
    }
    for(int i=0;i<m;i++)
        if(!del[i])
            Union(edge[i].fi,edge[i].se);
   
    for(int i=q-1;i>=0;i--)
    {
        t=qry[i].fi;u=qry[i].se;
        if(t==2)
        {
            Union(edge[u-1].fi,edge[u-1].se);
            continue;
        }
        qry[i].se=find(u);
    }
    for(int i=1;i<=n;i++)
        if(find(i)==i)
            dfs(i,0);
    for(int i=1;i<=n;i++)
        update(0,0,n,tin[i],m1(a[i],i));
    for(int i=0;i<q;i++)
    {
        if(qry[i].fi==2)
            continue;
        u=qry[i].se;
        pair<int,int> P=query(0,0,n,tin[u],tout[u]);
        cout<<P.fi<<endl;
        update(0,0,n,tin[P.se],m1(0,P.se));
    }
    
    
    
    
    
}

int32_t main(){
    
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


