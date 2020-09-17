/*
 FFT
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
const ll hell =1000000007;
const ll Hell=998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


vector<cd> fft(vector<cd> a,bool invert)
{
    int n=a.size();
    if(n==1)
        return vector<cd>(1,a[0]);
    vector<cd> a0,a1;
    for(int i=0;i<n;i+=2)
        a0.pb(a[i]);
    for(int i=1;i<n;i+=2)
        a1.pb(a[i]);
    a0=fft(a0,invert);
    a1=fft(a1,invert);
    vector<cd> res(n);
    double ang;
    if(invert)
        ang=(-1)*((2*pi)/n);
    else
        ang=(2*pi)/n;
    cd w(cos(ang),sin(ang));
    cd w1=1;
    for(int i=0;i<n/2;i++)
    {
        res[i]=a0[i]+w1*a1[i];
        res[i+n/2]=a0[i]-w1*a1[i];
        w1=w1*w;
    }
    return res;
}
vector<ll> multiply(vector<ll> a,vector<ll> b)   // multiplying two ploynomials in cofficient form FFT
{
    vector<cd> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    int n=1;
    while(n<(a.size()+b.size()))
        n=n<<1;
    fa.resize(n);
    fb.resize(n);
    fa=fft(fa,false);
    fb=fft(fb,false);
    vector<cd> fc(n);
    for(int i=0;i<n;i++)
        fc[i]=fa[i]*fb[i];
    fc=fft(fc,true);
    vector<ll> c(n,(ll)0);
    for(int i=0;i<n;i++)
    {fc[i]=fc[i]/n;
        c[i]=round(fc[i].real());
    }
    return c;
}
int32_t main()
{
    IOS;
    vector<ll> a(3),b(3);
    a[0]=1;a[1]=2;
    a[2]=3;b[0]=2;b[1]=3;b[2]=4;
    vector<ll>c;
    c=multiply(a,b);
    for(int i=0;i<c.size();i++)
        cout<<c[i]<<" "<<endl;
    return 0;
}

