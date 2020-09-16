/*
 Union of Sets
 Total time complexity - nlogn^2
 Dynamic Segment Tree (point update, kth smallest element, merge two segment trees)
 
 update - logn
 merge- worst o(n)
 kth smallest logn
 Problem - https://www.codechef.com/problems/CHEFDTRE
 
 */

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
const double EPS = 1e-9;
const ll MOD =998244353;
const ll hell=1000000007;
const int INF = 1e18;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

double startTime;
double getCurrentTime() {
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}


const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

const int N=200005;

struct node
{
    int cnt;node* lft;node* rgt;
    node()
    {
        cnt=0;lft=NULL;rgt=NULL;
    }
    
};
node* st[N];
int getcount(node* root)
{
    int ans=0;
    if(root->lft)
        ans+=root->lft->cnt;
    if(root->rgt)
        ans+=root->rgt->cnt;
    return ans;
}
void update(node* root,int l,int r,int in,int x)
{
    if(in>r||in<l)
        return;
    if(l==r)
    {
        root->cnt+=x;
        return;
    }
    int m=(l+r)/2;
    if(in<=m)
    {
        if(!root->lft)
            root->lft=new node();
        update(root->lft,l,m,in,x);
        
    }
    else
    {
        if(!root->rgt)
            root->rgt=new node();
        update(root->rgt,m+1,r,in,x);
    }
    root->cnt=getcount(root);
}
void merge(node* root1,node* root2,int l,int r)
{
    if(!root2)
        return;
    root1->cnt+=root2->cnt;
    int m=(l+r)/2;
    if(root1->lft)
    {
        merge(root1->lft,root2->lft,l,m);
    }
    else
        root1->lft=root2->lft;
    if(root1->rgt)
    {
        merge(root1->rgt,root2->rgt,m+1,r);
    }
    else
        root1->rgt=root2->rgt;
}
int query(node* root,int l,int r,int k)
{
    
    if(l==r)
        return l;
    int cnt=0;int m=(l+r)/2;
    if(root&&root->lft)
        cnt+=root->lft->cnt;
    if(cnt>=k)
        return query(root->lft,l,m,k);
    else
        return query(root->rgt,m+1,r,k-cnt);
}

void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        st[i]=new node();
        update(st[i],0,n,i,1);
    }
    int a,b;string t;int k;
    int sz=n+1;
    while(q--)
    {
        cin>>t;
        if(t[0]=='U')
        {
            cin>>a>>b;
            int sz1=st[a]->cnt;
            int sz2=st[b]->cnt;
            if(sz1<sz2)
            {
                st[sz++]=st[b];
                merge(st[b],st[a],0,n);
            }
            else
            {
                st[sz++]=st[a];
                merge(st[a],st[b],0,n);
            }
        }
        else
        {
            cin>>a>>k;
            cout<<query(st[a],0,n,k)<<endl;
        }
    }
    
}

int32_t main()
{
    IOS;
    
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
