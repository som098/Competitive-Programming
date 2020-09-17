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
#define debug(x) (cerr << #x << ": " << x)
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
const int N=505;
int a[N][N];int st[4*N][4*N];int n,m; // size n*m

void construct1d(int i1,int j,int i,int l,int r)
{
    if(l==r)
    {
        st[i1][i]=a[j][l];
        return;
    }
    int mid=(l+r)/2;
    construct1d(i1,j,2*i+1,l,mid);
    construct1d(i1,j,2*i+2,mid+1,r);
    st[i1][i]=max(st[i1][2*i+1],st[i1][2*i+2]);
}
void construct2d(int i,int l,int r)
{
    if(l==r)
    {
        construct1d(i,l,0,0,m-1);
        return;
    }
    
    int mid=(l+r)/2;
    construct2d(2*i+1,l,mid);
    construct2d(2*i+2,mid+1,r);
    for(int j=0;j<4*N;j++)
        st[i][j]=max(st[2*i+1][j],st[2*i+2][j]);
}
int getmax1d(int i,int j,int l,int r,int qs,int qe)
{
    
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
    {
        return st[i][j];
    }
    int mid=(l+r)/2;
    return max(getmax1d(i,2*j+1,l,mid,qs,qe),getmax1d(i,2*j+2,mid+1,r,qs,qe));
}
int getmax2d(int r1,int c1,int r2,int c2,int i,int l,int r)
{
    if(r1<0||r2<0||c1<0||c2<0||r1>r2||c1>c2)
        return 0;
    if(r1>r||r2<l)
        return 0;
    if(r1<=l&&r2>=r)
    {
        return getmax1d(i,0,0,m-1,c1,c2);
    }
    int mid=(l+r)/2;
    
    return max(getmax2d(r1,c1,r2,c2,2*i+1,l,mid),getmax2d(r1,c1,r2,c2,2*i+2,mid+1,r));
}
void update1d(int i,int j,int l,int r,int pos,int x)
{
    if(pos>r||pos<l)
        return;
    if(l==r)
    {
        st[i][j]=x;
        return;
    }
    int mid=(l+r)/2;
    update1d(i,2*j+1,l,mid,pos,x);
    update1d(i,2*j+2,mid+1,r,pos,x);
    st[i][j]=max(st[i][2*j+1],st[i][2*j+2]);
}
void update2d(int row,int column,int i,int l,int r,int x)
{
  if(row>r||row<l)
      return;
    if(l==r)
    {
        update1d(i,0,0,m-1,column);
        return;
    }
    int mid=(l+r)/2;
    update2d(row,column,2*i+1,l,mid,x);
    update2d(row,column,2*i+2,mid+1,r,x);
    for(int j=0;j<4*N;j++)
        st[i][j]=max(st[2*i+1][j],st[2*i+2][j]);
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    construct2d(0,0,n-1);
    //cout<<getmax(row1,row2,column1,column2,0,0,n-1);
    
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
