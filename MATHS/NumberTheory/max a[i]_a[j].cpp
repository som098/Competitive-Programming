/*
 PROBLEM LINK: http://codeforces.com/contest/484/problem/B
 */
//#include "stdc++.h"
#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tuple<int, int, int> t3;
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
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0) return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p; }
#define flush fflush(stdout)

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 11;
int findfloor(int a[],int x,int l,int r)
{
    int m;int ans;
    if(a[r]<=x)
        return r;
    while(r>=l)
    {
        m=(l+r)/2;
        if(a[m]>x)
        {
            r=m-1;
        }
        else if(a[m]==x)
            return m;
        else
        {
            ans=m;
            l=m+1;
        }
    }
    return ans;
}
int main()
{
    int n;IOS;
    cin>>n;
    int a[n];int M=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        M=max(M,a[i]);
    }
    sort(a,a+n);M=2*M;
    int x[M+1];
    for(int i=a[0]+1;i<=M;i++)
    {
        x[i]=a[findfloor(a,i-1,0,n-1)];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=1&&(i==n-1||(a[i]!=a[i+1])))
            for(int j=2*a[i];j<=M;j+=a[i])
            {
                if(x[j]>a[i])
                {
                    ans=max(ans,x[j]%a[i]);
                }
            }
    }
    cout<<ans<<endl;
}
 
