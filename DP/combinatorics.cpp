/*
 problem 560 E codeforces
 no of ways to reach from 1,1 to h,w without passing through n given points 1<=n<=1000;1<=h<=1e5;1<=w<=1e5
 */
#include "stdc++.h"
//#include <bits/stdc++.h>
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
//#define sz(x) (int)(x.size())
#define ff first
#define ss second
#define endl "\n"
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD =1000000007 ;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
#define pi 3.141592653589793238462
#define int  long long
int f[200001],inf[200001];
int C(int i,int j)
{
    int ans=f[i];
    ans=(ans%MOD*inf[j]%MOD)%MOD;
    ans=(ans%MOD*inf[i-j]%MOD)%MOD;
    return ans;
}
int32_t main()
{
    
    IOS;
    f[0]=1;
    for(int i=1;i<200001;i++)
        f[i]=(f[i-1]*i)%MOD;
    inf[200000]=power(f[200000],MOD-2,MOD);
    for(int i=200000-1;i>=0;i--)
        inf[i]=((i+1)*inf[i+1])%MOD;
    int h,n,w,x,y;
    cin>>h>>w>>n;
    pair<int,int> p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first;
        cin>>p[i].second;
    }
    sort(p,p+n);
    int ways[n];
    for(int i=0;i<n;i++)
    {
        x=p[i].first;
        y=p[i].second;
        ways[i]=C(x+y-2,x-1);
        for(int j=0;j<i;j++)
        {
            if(p[j].second<=p[i].second)
            {
                ways[i]=(ways[i]%MOD-(ways[j]%MOD*C(x+y-(p[j].first+p[j].second),x-p[j].first)%MOD)%MOD+MOD)%MOD;
            }
        }
    }
    int ans=C(h+w-2,h-1);
    for(int i=0;i<n;i++)
    {
        ans=(ans-(ways[i]%MOD*C(h+w-(p[i].first+p[i].second),h-p[i].first)%MOD)%MOD+MOD)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}

