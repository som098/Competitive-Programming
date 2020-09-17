/*
 Dominating Element in a range wth update queries
 Problem - https://www.codechef.com/problems/CHEFLKJ
 
 Given an array A and you have to process q queries
 
 1 x y - Assign value y to x-th element in array A, i.e. Ax = y.
 2 l r - print "Yes" if subarray A[l..r] is dominating, "No" otherwise

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

const int N=100005;

struct node{
    
    int d= -1;
    map<int,int> mp;
};
node st[4*N];int a[N+1];vi dominating;

void merge(int i,int lft,int rgt,int l,int r)
{
    for(int j=l;j<=r;j++)
        st[i].mp[a[j]]++;
    int d1=st[lft].d,d2=st[rgt].d;
    int th=(r-l+1)/2 +1;
    if(st[i].mp[d1]>=th)
        st[i].d=d1;
    else if(st[i].mp[d2]>=th)
        st[i].d=d2;
}
void change(int i,int lft,int rgt,int in,int x,int l,int r)
{
    
    st[i].mp[x]++;
    st[i].mp[a[in]]--;
    st[i].d=-1;
    int d1=st[lft].d,d2=st[rgt].d;
    int th=(r-l+1)/2 +1;
    if(st[i].mp[d1]>=th)
        st[i].d=d1;
    else if(st[i].mp[d2]>=th)
        st[i].d=d2;
}
void update(int i,int l,int r,int in,int x)
{
    if(in>r||in<l)
        return;
    if(l==r)
    {
        st[i].d=x;
        st[i].mp[a[l]]--;
        st[i].mp[x]++;
        return;
    }
    int m=(l+r)/2;
    update(2*i+1,l,m,in,x);
    update(2*i+2,m+1,r,in,x);
    change(i,2*i+1,2*i+2,in,x,l,r);
    
}
void constructtree(int i,int l,int r)
{
    if(l==r)
    {
        st[i].d=a[l];
        st[i].mp[a[l]]++;
        return;
    }
    int m=(l+r)/2;
    constructtree(2*i+1,l,m);
    constructtree(2*i+2,m+1,r);
    merge(i,2*i+1,2*i+2,l,r);
}
void query(int i,int l,int r,int qs,int qe)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        if(st[i].d != -1)
        dominating.pb(st[i].d);
        return;
    }
    int m=(l+r)/2;
    query(2*i+1,l,m,qs,qe);
    query(2*i+2,m+1,r,qs,qe);
}
int count(int i,int l,int r,int qs,int qe,int x)
{
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
    {
        return st[i].mp[x];
    }
    int m=(l+r)/2;
    return count(2*i+1,l,m,qs,qe,x)+count(2*i+2,m+1,r,qs,qe,x);
}
void solve()
{
    
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    constructtree(0,0,n-1);
    
    int t,l,r,x,y;
    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            x--;
            update(0,0,n-1,x,y);
            a[x]=y;
        }
        else
        {
            cin>>l>>r;
            l--;r--;
            dominating.clear();
            query(0,0,n-1,l,r);
            int th=(r-l+1)/2;
            th++;
            int pos=0;
            for(int x:dominating)
            {
                if(count(0,0,n-1,l,r,x)>=th)
                {
                    cout<<"Yes"<<endl;
                    pos=1;
                    break;
                }
            }
            if(!pos)
                cout<<"No"<<endl;
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