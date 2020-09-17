/*
 Drichlet Convolution + mobius + Harmonic jumping
 
 You have to find sum((n/i)^2 * u[i]) 1<=i<=n , n<=5e8, u[i]=mobius function
 
 Problem https://www.codechef.com/problems/PUPPYGCD
 
 Bolgs- https://codeforces.com/blog/entry/53925
        https://codeforces.com/blog/entry/54150
 
 Time complexity n^2/3 , we have to do precomputation till n^2/3
 
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

const int N = 1e6+5;
bool p[N+1];int u[N+1];

map<int,int>mp;

void pre()
{
    for(int i=1;i<=N;i++)
        u[i]=1;
    for(int i=2;i<=N;i++)
        if(!p[i])
        {
            for(int j=i;j<=N;j+=i)
            {
                p[j]=1;
                u[j]= -u[j];
                if(!(j%(i*i)))
                    u[j]=0;
            }
        }
    for(int i=1;i<=N;i++)               // precomputed till n^2/3
        u[i]+=u[i-1];
}
int f(int n)                // finding sum(u[i]) ,1<=i<=n
{
    if(n<=N)
        return u[n];
    if(mp.find(n)!=mp.end())
        return mp[n];
    int ans=1;
    for(int l=2,R;l<=n;l=R+1)
    {
        R=n/(n/l);
        ans=(ans-(R-l+1)*f(n/l));
    }
    return mp[n]=ans;
}


void solve()
{
    int n;
    int ans=0;
    for(int l=1,r;l<=n;l=r+1)
    {
        int z=n/l;
        r=n/z;
        z=z*z;
        ans=ans+z*(f(r)-f(l-1));
    }
    ans=(ans+1)/2;
    cout<<ans<<endl;
    
    
    
}

int32_t main()
{
    IOS;
    pre();
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

