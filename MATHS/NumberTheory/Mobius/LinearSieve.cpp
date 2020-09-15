/*
 Linear Sieve - using  multiplicative property of u,phi
 calculating phi,u,spf for 1<=i<=n , n<=1e7
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
#define MAXN 10000005
int mark[MAXN+1],prime[MAXN+1],sz;
int u[MAXN+1],phi[MAXN+1],spf[MAXN+1];


void linearsieve()
{
    u[1]=1;
    phi[1]=1;
    for(int i=1;i<=MAXN;i++)
        spf[i]=i;
    for(int i=2;i<=MAXN;i++)
    {
        if(!mark[i])
        {
            u[i]= -1;
            phi[i]= i-1;
            prime[sz++]=i;
        }
        for(int j=0;j<sz && (prime[j]*i)<=MAXN ;j++)
        {
            mark[i*prime[j]]=1;
            if(!(i%prime[j]))
            {
                u[i*prime[j]]=0;
                phi[i*prime[j]]=phi[i]*prime[j];
                spf[i*prime[j]]=spf[i];
                break;
            }
            u[i*prime[j]]= -u[i];
            phi[i*prime[j]]= phi[i]*(prime[j]-1);
            if(spf[i*prime[j]]==(i*prime[j]))
                spf[i*prime[j]]=prime[j];
        }
        
    }
    
    
    
    
    
}



void solve()
{
    linearsieve();
    
}




int32_t main()
{
    IOS;
    
    startTime=clock();
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    //cout<<getCurrentTime()<<endl;
    return 0;
}

