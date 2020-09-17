/*
 Convex HUll trick -
 given n lines (m,c) find max value of y in each query
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
pair<int,int> p[100001];
ldb findinter(int m1,int c1,int m2,int c2)
{
    ldb xin;
    xin=c2-c1;
    xin=(ldb)(xin)/(m1-m2);
    return xin;
}
int32_t main()
{
    
    IOS;
    int n,c;map<ldb,int>s;
    map<ldb,int>::iterator it;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n);
    
    s.insert(m1(-INF,0));int k;ldb xin;stack<pair<pair<int,int> ,ldb> >st;
    pair<pair<int,int>,ldb>pr;
    st.push(m1(m1(p[0].first,p[0].second),-INF));
    for(int i=1;i<n;i++)
    {
        if(st.empty()||st.size()==1)
        {
            if(st.size()==1)
            {
                pr=st.top();
                xin=findinter(pr.first.first,pr.first.second,p[i].first,p[i].second);
            }
            else
                xin=-INF;
            st.push(m1(m1(p[i].first,p[i].second),xin));
            s.insert(m1(xin,i));
        }
        else
        {
            pr=st.top();
            while(st.size()>=1&&(findinter(pr.first.first,pr.first.second,p[i].first,p[i].second)<=(pr.second)))
            {
                st.pop();
                s.erase(s.find(pr.second));
                pr=st.top();
            }
            pr=st.top();
            xin=findinter(pr.first.first,pr.first.second,p[i].first,p[i].second);
            st.push(m1(m1(p[i].first,p[i].second),xin));
            s.insert(m1(xin,i));
            
        }
    }
    int q,y,in,x;
    cin>>q;
    while(q--)
    {
        cin>>x;
        it=s.upper_bound(x);
        it--;
        in=it->second;
        y=p[in].first*x+p[in].second;
        cout<<y<<endl;
    }
    return 0;
}




