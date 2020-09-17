/*
 finding (a*b)%m 1<=m<=1e18
 */
//#include "sourabh.bhai.h"
#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;


ll multiply(ll a,ll b,ll m)
{
    ll j=1,ans=0;
    while(j<=a)
    {
        if(j&a)
            ans=(ans%m+b%m)%m;
        b=(b*2)%m;
        j=j<<1;
    }
    return ans;
}
int main()
{
    ll a,b,m;
    cin>>a>>b>>m;
    ll ans=multiply(a,b,m);
    cout<<ans<<endl;
    return 0;
}



