
#include "stdc++.h"
//#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef vector<int> vi;
#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))
#define sz(x) (int)(x.size())
#define ff first
#define ss second
#define endl "\n"
#define int long long int
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
/*
 shuffle(x,x+n,rng) // shuffling elements of x in random order
 */
/*
 calculating nth fibonacci % 1000000007 no By MATRIX EXPO in O(logn)
 */
int m[2][2];int pr[2][2];
void cal(int n)
{
    if(n==0)
    {
        return;
    }
    if(n==1)
    {
        pr[0][0]=m[0][0];
        pr[0][1]=m[0][1];
        pr[1][0]=m[1][0];
        pr[1][1]=m[1][1];
        return;
    }
    cal(n/2);
    int a,b,c,d,a00,a01,a10,a11;
    a=pr[0][0];
    b=pr[0][1];
    c=pr[1][0];
    d=pr[1][1];
    a00=((a%MOD*a%MOD)%MOD+(b%MOD*c%MOD)%MOD)%MOD;
    a01=((a%MOD*b%MOD)%MOD+(b%MOD*d%MOD)%MOD)%MOD;
    a10=((a%MOD*c%MOD)%MOD+(c%MOD*d%MOD)%MOD)%MOD;
    a11=((b%MOD*c%MOD)%MOD+(d%MOD*d%MOD)%MOD)%MOD;
    pr[0][0]=a00;pr[0][1]=a01;pr[1][0]=a10;pr[1][1]=a11;
    if(n%2)
    {
        a=pr[0][0];
        b=pr[0][1];
        c=pr[1][0];
        d=pr[1][1];
        a00=(a%MOD+b%MOD)%MOD;
        a01=(a%MOD);
        a10=(c%MOD+d%MOD)%MOD;
        a11=(c%MOD);
        pr[0][0]=a00;pr[0][1]=a01;pr[1][0]=a10;pr[1][1]=a11;
        return;
    }
    else
        return;
}
int fib(int n)
{
    cal(n);
    return pr[0][1]%MOD;
}
int32_t main()
{
    
    IOS;
    m[0][0]=1;
    m[0][1]=1;
    m[1][0]=1;
    m[1][1]=0;
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}

