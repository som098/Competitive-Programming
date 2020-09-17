/*
 given an array a of n numbers 1<=n<=1e6 a[i]<=1e9
 we have to find no of triplets such that i<j<k and a[i]>a[j]>a[k]
 */

#include "std.h"
//#include<bits/stdc++.h>
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
ll bit1[1000005],bit2[1000005];
const int N=1000004;
int getparent(int i)                   // getting parent of i
{
    return i-(i&(-i));
}
int getnext(int i)
{
    return i+(i&(-i));
}
ll getsum1(int r)            // calculating sum from 1-r
{
    ll sum=0;
    while(r>0)
    {
        sum=sum+bit1[r];
        r=getparent(r);
    }
    return sum;
}
ll getsum2(int r)            // calculating sum from 1-r
{
    ll sum=0;
    while(r>0)
    {
        sum=sum+bit2[r];
        r=getparent(r);
    }
    return sum;
}
void update1(int i,int value)    //   updating index i
{
    while(i<=1000004)
    {
        bit1[i]+=value;
        i=getnext(i);
    }
}
void update2(int i,ll value)
{
    while(i<=1000004)
    {
        bit2[i]+=value;
        i=getnext(i);
    }
}
int main()
{
    IOS;
    int n;
    cin>>n;
    int a[n+1];ll s,ans=0;
    map<int,int>mp;
    map<int,int>::iterator it;
    for(int i=1;i<=n;i++)
    {cin>>a[i];
        mp.insert(m1(a[i],0));
    }
    it=mp.begin();int k=1;
    while(it!=mp.end())
    {
        mp[it->first]=k;
        k++;
        it++;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=mp[a[i]];
        s=getsum2(N);
        s=s-getsum2(a[i]);
        ans+=s;
        s=getsum1(N);
        s=s-getsum1(a[i]);
        update1(a[i],1);
        update2(a[i],s);
    }
    cout<<ans<<endl;
    return 0;
}


