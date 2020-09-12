 /*
 We have to increase weights of some edges so that MST is unique
 cost of increasing the weight by 1 is 1
 we have to tell the minimum cost
 https://codeforces.com/contest/1108/problem/F
 */
//#include "stdc++.h"
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
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
int main()
{
    IOS;//ifstream fin("input.txt");ofstream fout("output.txt");/*
    int n,m;
    cin>>n>>m;
    pair<ll,pair<int,int> > edge[m];ll w;int u,v,x,y;
    for(int i=0;i<m;i++)
    {
        cin>>edge[i].second.first>>edge[i].second.second;
        cin>>edge[i].first;
    }
    sort(edge,edge+m);
    subset subsets[n+1];bool can[m+1];
    memset(can,0,sizeof(can));
    vector<pair<pair<int,int>,ll> >edges;
    for(int i=0;i<=n;i++)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    int j;int ans=0;
    for(int i=0;i<m;)
    {
        j=i;
        while(j<m&&(edge[j].first==edge[i].first))
            j++;
        for(int k=i;k<j;k++)
        {
            x=find(subsets,edge[k].second.first);
            y=find(subsets,edge[k].second.second);
            if(x!=y)
                can[k]=1;
        }
        for(int k=i;k<j;k++)
        {
            x=find(subsets,edge[k].second.first);
            y=find(subsets,edge[k].second.second);
            if(x==y&&can[k])
                ans++;
            if(x!=y)
            {
                Union(subsets,x,y);
            }
        }
        i=j;
    }
    cout<<ans<<endl;
    return 0;
}
