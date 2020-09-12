/*
 Segment Tree Beats
 
 Blog- https://codeforces.com/blog/entry/57319
 
 Problem- https://codeforces.com/contest/438/problem/D

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
const ll MOD=998244353;
const ll hell=1000000007;
const int INF = 1e16;
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
int a[N+1],st[4*N],mx[4*N];

void constructtree(int i,int l,int r)
{
    if(l==r)
    {
        st[i]=a[l];
        mx[i]=a[l];
        return;
    }
    int m=(l+r)/2;
    constructtree(2*i+1,l,m);
    constructtree(2*i+2,m+1,r);
    st[i]=st[2*i+1]+st[2*i+2];
    mx[i]=max(mx[2*i+1],mx[2*i+2]);
}
void update1(int i,int l,int r,int in,int x)
{
    if(in>r||in<l)
        return;
    if(l==r)
    {
        st[i]=x;
        mx[i]=x;
        a[l]=x;
        return;
    }
    int m=(l+r)/2;
    update1(2*i+1,l,m,in,x);
    update1(2*i+2,m+1,r,in,x);
    st[i]=st[2*i+1]+st[2*i+2];
    mx[i]=max(mx[2*i+1],mx[2*i+2]);
}
void update2(int i,int l,int r,int qs,int qe,int x)
{
    if(qs>r||qe<l||mx[i]<x)
        return;
    if(l==r)
    {
        st[i]=st[i]%x;
        mx[i]=mx[i]%x;
        return;
    }
    int m=(l+r)/2;
    update2(2*i+1,l,m,qs,qe,x);
    update2(2*i+2,m+1,r,qs,qe,x);
    st[i]=st[2*i+1]+st[2*i+2];
    mx[i]=max(mx[2*i+1],mx[2*i+2]);
}
int query(int i,int l,int r,int qs,int qe)
{
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
        return st[i];
    int m=(l+r)/2;
    return query(2*i+1,l,m,qs,qe)+query(2*i+2,m+1,r,qs,qe);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    constructtree(0,0,n-1);
    int t,l,r,x;
    while(m--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>l>>r;
            cout<<query(0,0,n-1,l-1,r-1)<<endl;
        }
        else if(t==2)
        {
            cin>>l>>r>>x;
            update2(0,0,n-1,l-1,r-1,x);
        }
        else
        {
            cin>>l>>x;
            update1(0,0,n-1,l-1,x);
        }
        
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
