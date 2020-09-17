/*/*
 Summing the K-N series
 S(k,n)= 1^k+2^k+3^k........n^k
 O(k*k)- precomputation
O(k) per query using Bernoulii Numbers
 Problem https://www.hackerrank.com/contests/infinitum-mar14/challenges/summing-the-k-n-series
 Editorial :https://www.hackerrank.com/contests/infinitum-mar14/challenges/summing-the-k-n-series/editorial
 Bernoulii - https://en.wikipedia.org/wiki/Bernoulli_number
 */
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
const int INF = 1e12;
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


const int N=325;
int B[N+1];


int f[N+1],inf[N+1];

int C(int n,int r)
{
    if(r>n)
        return 0;
    int ans=(f[n]*inf[r])%hell;
    return (ans*inf[n-r])%hell;
}
void pre()
{
    f[0]=1;
    for(int i=1;i<=N;i++)
        f[i]=(f[i-1]*i)%hell;
    inf[N]=power(f[N],hell-2,hell);
    for(int i=N-1;i>=0;i--)
        inf[i]=(inf[i+1]*(i+1))%hell;
    
    B[0]=1;
    B[1]=(hell-power(2,hell-2,hell))%hell;
    for(int i=2;i<=N;i++)
    {
        if(i%2)
        {B[i]=0;
            continue;
        }
        int sm=0;
        for(int k=0;k<i;k++)
        {
            int z=(C(i+1,k)*B[k])%hell;
            sm=(sm+z)%hell;
        }
        sm=(sm*power(i+1,hell-2,hell))%hell;
        B[i]=(hell-sm)%hell;
    }
    
}
int Solve(int n,int k)
{
    n++;
    int ans=0;
    for(int i=0;i<=k;i++)
    {
        int y=C(k+1,i);
        y=(y*B[i])%hell;
        y=(y*power(n%hell,k+1-i,hell))%hell;
        ans=(ans+y)%hell;
    }
    if(k==0)
        ans=(n-1)%hell;
    ans=(ans*power(1+k,hell-2,hell))%hell;
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    cout<<Solve(n,k)<<endl;
    
}

int32_t main()
{
    IOS;
    
    pre();
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
