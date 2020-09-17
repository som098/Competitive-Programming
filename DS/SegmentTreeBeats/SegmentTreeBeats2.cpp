/*
 Segment Tree Beats Problem
Problem- https://www.codechef.com/problems/ANDMIN/
 
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


int st[4*N];int cnt[4*N][31];
int a[N+1];

void constructtree(int i,int l,int r)
{
    
    if(l==r)
    {
        st[i]=a[l];
        for(int j=0;j<31;j++)
            if(a[l]&(1<<j))
                cnt[i][j]++;
        return;
    }
    int m=(l+r)/2;
    constructtree(2*i+1,l,m);
    constructtree(2*i+2,m+1,r);
    for(int j=0;j<31;j++)
        cnt[i][j]=cnt[2*i+1][j]+cnt[2*i+2][j];
    st[i]=min(st[2*i+1],st[2*i+2]);
}
void update(int i,int l,int r,int qs,int qe,int j)
{
    if(qs>r||qe<l||(!cnt[i][j]))
        return;
    if(l==r)
    {
        st[i]=st[i]^(1<<j);
        cnt[i][j]=0;
        return;
    }
    int m=(l+r)/2;
    update(2*i+1,l,m,qs,qe,j);
    update(2*i+2,m+1,r,qs,qe,j);
    st[i]=min(st[2*i+1],st[2*i+2]);
    cnt[i][j]=cnt[2*i+1][j]+cnt[2*i+2][j];
}
int query(int i,int l,int r,int qs,int qe)
{
    if(qs>r||qe<l)
        return INF;
    if(qs<=l&&qe>=r)
    {
        return st[i];
    }
    int m=(l+r)/2;
    return min(query(2*i+1,l,m,qs,qe),query(2*i+2,m+1,r,qs,qe));
    
    
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    constructtree(0,0,n-1);
    int t,l,r,x;
    while(q--)
    {
        cin>>t;
        if(!t)
        {
            cin>>l>>r;
            l--;r--;
            cout<<query(0,0,n-1,l,r)<<endl;
        }
        else
        {
            cin>>l>>r>>x;
            l--;r--;
            for(int j=0;j<31;j++)
                if(!(x&(1<<j)))
                    update(0,0,n-1,l,r,j);
        }
    }
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