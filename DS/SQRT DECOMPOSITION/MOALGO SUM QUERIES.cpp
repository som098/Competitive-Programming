/*
 
 */

//#include "stdc++.h"
#include <bits/stdc++.h>
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
#define int long long
int bsz;
struct Query
{
    int l;int r;int id;
};
bool compare(Query &q1,Query &q2)
{
    int bn1=q1.l/bsz;
    int bn2=q2.l/bsz;
    if(bn1!=bn2)
        return (bn1<bn2);
    else
        return (q1.r<q2.r);
}
int32_t main()
{
    IOS;
    int n,t;int l,r,id;
    cin>>n;  // no of elements
    bsz=(int)sqrt(n);
    int a[n];
    reset(a,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>t;     // no of queries
    Query queries[t];ll ans[t];
    for(int i=0;i<t;i++)
    {
        cin>>l>>r;
        l--;r--;
        queries[i].l=l;
        queries[i].r=r;
        queries[i].id=i;
    }
    sort(queries,queries+t,compare);
    int cl=0,cr=0;ll sum=0;int s;int cnt=0;
    for(int i=0;i<t;i++)
    {
        l=queries[i].l;
        r=queries[i].r;
        id=queries[i].id;
        //cout<<id<<endl;
        
        while(cl<l)
        {
            s=a[cl];
            
            f[s]--;
            if(f[s]%2)
                cnt++;
            else
                cnt--;
            
            cl++;
        }
        while(cl>l)
        {
            s=a[cl-1];
            
            f[s]++;
            if(f[s]%2)
                cnt++;
            else
                cnt--;
            cl--;
        }
        while(cr<=r)
        {
            s=a[cr];
            f[s]++;
            if(f[s]%2)
                cnt++;
            else
                cnt--;
            cr++;
        }
        while(cr>r+1)
        {
            s=a[cr-1];
            f[s]--;
            if(f[s]%2)
                cnt++;
            else
                cnt--;
            cr--;
        }
        ans[id]=cnt;
    }
    for(int i=0;i<t;i++)
        cout<<ans[i]<<endl;
    
    return 0;
}

