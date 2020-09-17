/**
 Persistent Segment Tree-Using Array
 Problem : https://www.spoj.com/problems/MKTHNUM/
 **/

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
//#define int long long int
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

#define fi first
#define se second
#define endl "\n"
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>

inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p%m*p%m)%m;if(n%2) return (p%m*a%m)%m;else return p;}
const ll MOD =998244353;
const ll hell=1000000007;
const int INF = 1e7;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int N=100005;
int lft[8*N*18],rgt[8*N*18],Node=0,st[8*N*18];// size - 8*N*logN
int newleaf(int x)
{
    int node=(++Node);
    st[node]=x;
    return node;
}
int newparent(int l,int r)
{
    int node= ++Node;
    lft[node]=l;
    rgt[node]=r;
    st[node]=st[l]+st[r];
    return node;
}
int build(int l,int r)
{
    if(l==r)
    {
        return newleaf(0);   //initializing
    }
    int m=(l+r)/2;
    return newparent(build(l,m),build(m+1,r));
}
int getsum(int root,int l,int r,int qs,int qe)   //range sum
{
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
        return st[root];
    int m=(l+r)/2;
    return getsum(lft[root],l,m,qs,qe)+getsum(rgt[root],m+1,r,qs,qe);
}
int update(int root,int l,int r,int pos,int x)  /// Point update
{
    if(pos<l||pos>r)
        return root;
    if(l==r)
    {
        return newleaf(st[root]+x);
    }
    int m=(l+r)/2;
    return newparent(update(lft[root],l,m,pos,x),update(rgt[root],m+1,r,pos,x));
}
int query(int root1,int root2,int l,int r,int k)  //finding kth minimum
{
    if(l==r)
        return l;
    int cnt=st[lft[root1]]-st[lft[root2]];
    int m=(l+r)/2;
    if(cnt>=k)
        return query(lft[root1],lft[root2],l,m,k);
    else
        return   query(rgt[root1],rgt[root2],m+1,r,k-cnt);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    map<int,int>mp,mp1;map<int,int>::iterator it;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=1;
    }
    it=mp.begin();int k=1;
    while(it!=mp.end())
    {
        it->second=k;
        mp1[k]=it->first;
        k++;it++;
    }
    for(int i=0;i<n;i++)
        a[i]=mp[a[i]];
    int rt[n+1];
    rt[0]=build(0,n);
    for(int i=0;i<n;i++)
        rt[i+1]=update(rt[i],0,n,a[i],1);
    int l,r;
    while(m--)
    {
        cin>>l>>r>>k;
        cout<<mp1[query(rt[r],rt[l-1],0,n,k)]<<endl;
    }
    
}
int32_t main()
{
    IOS;
    
    int t;
    t=1;
    /// cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

