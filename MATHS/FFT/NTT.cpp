/*
 NTT-
 Multiplying two polynomials under MOD;
 */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define  int long long int
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
#define sz(x) (int)(x.size())
#define ff first
#define ss second
#define endl "\n"
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD =998244353;
const ll hell=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int phiFunc(int n) {
    int result = n;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) { result -= result / i; while (n % i == 0) n /= i; }
    }
    if (n > 1) result -= result / n; return result;
}
int generator(int p) {
    vector <int> fact; int phi = phiFunc(p), n = phi;   // Finding Primitive root of p;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) { fact.push_back(i); while (n % i == 0) n /= i; }
    }
    if (n > 1) fact.push_back(n);
    for (int res = 2; res <= p; ++res) {
        bool ok = true; for (auto i : fact) ok &= (power(res, phi / i, p) != 1); if (ok) return res;
    }
    return -1;
}
int root,root1,rootPW;
void ntt(vector<ll> &a,bool invert)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root1 : root;
        for (int i = len; i < rootPW; i <<= 1) wlen = wlen*1ll*wlen % MOD;
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = a[i + j + len / 2] * 1ll * w % MOD;
                a[i + j] = (u + v) % MOD; a[i + j + len / 2] = (u - v + MOD) % MOD; w = w*1ll*wlen % MOD;
            }
        }
    }
    if (invert) {
        int nrev = power(n, MOD - 2, MOD);
        for (int i = 0; i < n; ++i) a[i] = a[i] * 1ll * nrev % MOD;
    }
    
}
vector<ll> multiply(vector<ll> a,vector<ll> b)
{
    
    int n=1;
    while(n<(a.size()+b.size()))
        n=n<<1;
    a.resize(n);
    b.resize(n);
    ntt(a,false);
    ntt(b,false);
    vector<ll> c(n,0);
    for(int i=0;i<n;i++)
        c[i]=(a[i]*b[i])%MOD;
    ntt(c,true);
    while(c.size()>1&&(c.back()==0))
        c.pop_back();
    return c;
}
vector<ll> Power(vector<ll> a,int n,int MOD)
{
    if(n==1)
        return a;
    vector<ll> p=Power(a,n/2,MOD);
    p=multiply(p,p);
    if(n%2)
        p=multiply(p,a);
    return p;
}
int32_t main()
{
    IOS;
    
    int g = generator(MOD);  // storing Primitive root of MOD
    rootPW = (1 << 20);
    root = power(g, (MOD - 1) / rootPW, MOD);   //  r^c
    root1 =power(root, MOD - 2, MOD);           // inverse of r^c
    
    
    return 0;
}

