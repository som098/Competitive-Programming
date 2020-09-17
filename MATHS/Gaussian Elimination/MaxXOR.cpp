/*****
 GAUSSIAN ELIMINATION- Max XOR Subset
 https://www.spoj.com/problems/XMAX/
 Basis Approach
 Basis of vector space=minimal set to span entire vector space
 no of distinct xor =2^basissize
 *****/


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
const int INF = 1e7;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int N=100005;
int basis[64];
void insertvector(int mask)
{
    for(int i=63;i>=0;i--)
    {
        if(!(mask&(1LL<<i)))
            continue;
        if(!basis[i])
        {
            basis[i]=mask;
            return;
        }
        mask=mask^basis[i];
    }
}
void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    for(int i=n-1;i>=0;i--)
        insertvector(a[i]);
    int ans=0;
    for(int i=63;i>=0;i--)
    {
        if(!(ans&(1LL<<i)))
        {
            ans=ans^basis[i];
        }
    }
    cout<<ans<<endl;
    
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
