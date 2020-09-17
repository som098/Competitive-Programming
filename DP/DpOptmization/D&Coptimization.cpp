/*
 Divide And Conquer optimization
 Problem- https://codeforces.com/contest/868/problem/F
 Blog from cp algo
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
int n;
int a[N+1];int dp[21][N+1];
int cl,cr;
int ans;int f[N+1];

int add(int x)
{
    ans+=f[x];
    f[x]++;
}
int remove(int x)
{
    f[x]--;
    ans-=f[x];
}
int cost(int l,int r)
{
    l--;r--;
    while(cl<l)
    {
        remove(a[cl]);
        cl++;
    }
    while(cl>l)
    {
        add(a[cl-1]);
        cl--;
    }
    while(cr<=r)
    {
        add(a[cr]);
        cr++;
    }
    while((cr)>(r+1))
    {
        remove(a[cr-1]);
        cr--;
    }
    return ans;
}
void dc(int i,int l,int r,int optl,int optr)
{
    
    if(l>r)
        return;
    int m=(l+r)/2;int opt =m;
    int mn=INF;
    for(int j=max((int)0,optl-1);j<=min(m-1,optr);j++)
    {
        
        int cst=cost(j+1,m);
        if(mn>(dp[i-1][j]+cst))
        {
            mn=dp[i-1][j]+cst;
            opt=j;
        }
    }
    dp[i][m]=mn;
    dc(i,l,m-1,optl,opt);
    dc(i,m+1,r,opt,optr);
}



void solve()
{
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<=20;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=1;i<=k;i++)
    {
        dc(i,i,n,i,n);
    }
    //cout<<dp[1][1]<<endl;
    cout<<dp[k][n]<<endl;
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
