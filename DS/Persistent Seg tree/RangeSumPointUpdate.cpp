/**
 Persistent Segment Tree
 Problem: https://www.spoj.com/problems/MKTHNUM/
 1.Finding kth min in the given range l to r

 use coordinate compression
 Maintain new segment tree for each prefix
 Time - O(nlogn)
 Space- O(nlogn)
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
#define int long long int
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
const int INF = 1e17;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int N=200005;
struct node
{
    node* left;node* right;
    int s;
    node(int x): left(NULL),right(NULL),s(x){}
    node(node* l,node* r): left(l),right(r),s(0){
        if(l)
            s+=(l->s);
        if(r)
            s+=(r->s);
    }
};
node* build(int l,int r)
{
    if(l>r)
        return NULL;
    if(l==r)
    {
        return new node(0);
    }
    int m=(l+r)/2;
    return new node(build(l,m),build(m+1,r));
}
node* update(node* root,int l,int r,int pos,int x) // point update
{
    if(l>pos||pos>r)
        return root;
    if(l==r)
    {
        return new node(root->s+x);
    }
    int m=(l+r)/2;
    return new node(update(root->left,l,m,pos,x),update(root->right,m+1,r,pos,x));
}
int getsum(node* root,int l,int r,int qs,int qe)
{
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
        return root->s;
    int m=(l+r)/2;
    return getsum(root->left,l,m,qs,qe)+getsum(root->right,m+1,r,qs,qe);
}
int query(node* root1,node* root2,int l,int r,int k)
{
    if(l==r)
        return l;
    int cnt=0;
    if(root1->left)
        cnt+=(root1->left)->s;
    if(root2->left)
        cnt-=(root2->left)->s;
    
    int m=(l+r)/2;
    if(cnt>=k)
    {
        return query(root1->left,root2->left,l,m,k);
    }
    else
        return query(root1->right,root2->right,m+1,r,k-cnt);
    
}
void solve()
{
    int n;
    int m;
    cin>>n>>m;
    int a[n];map<int,int>mp;map<int,int>mp1;
    map<int,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=0;
    }
    it=mp.begin();int k=1;
    while(it!=mp.end())
    {
        it->second=k;
        mp1[k]=it->first;
        k++;
        it++;
    }
    node* rt[n+1];
    for(int i=0;i<n;i++)
        a[i]=mp[a[i]];
    rt[0]=build(0,n);
    for(int i=0;i<n;i++)
        rt[i+1]=update(rt[i],0,n,a[i],1);
    int l,r;
    while(m--)
    {
        cin>>l>>r>>k;
        l--;r--;
        cout<<mp1[query(rt[r+1],rt[l],0,n,k)]<<endl;
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

