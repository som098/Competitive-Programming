/*
 Persistent 0-1 Trie
 Problem - https://www.codechef.com/problems/XRQRS
 
 */

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
const int INF = 1e16;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

double startTime;
double getCurrentTime() {
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
const int N=1000005;

typedef struct node
{
    node* bit[2];
    int cnt=0;
} Trie;
Trie* root[N];

Trie* get(Trie* cur,int bt)
{
    if(!cur||(!cur->bit[bt]))
        return NULL;
    return cur->bit[bt];
}
int getcount(Trie* cur,int bt)
{
    if(!cur||(!cur->bit[bt]))
        return 0;
    else
        return cur->bit[bt]->cnt;
}
void insert(Trie* old,Trie *cur,int x,int i)
{
    if(i<0)
        return;
    int bt=(x>>i)&1;
    cur->bit[bt]=new Trie();
    cur->bit[bt]->cnt++;
    
    if(old&&old->bit[bt])
        cur->bit[bt]->cnt+=old->bit[bt]->cnt;
    cur->bit[!bt]=get(old,!bt);
    insert(get(old,bt),cur->bit[bt],x,i-1);
}
int maxxor(Trie* cur1,Trie* cur2,int x,int i)
{
    if(i<0)
        return 0;
    int bt=(x>>i)&1;
    int cnt1=getcount(cur2,!bt)-getcount(cur1,!bt);
    if(cnt1>0)
        return (1LL<<i)+maxxor(get(cur1,!bt),get(cur2,!bt),x,i-1);
    else
        return maxxor(get(cur1,bt),get(cur2,bt),x,i-1);
}
int countless(Trie* cur1,Trie* cur2,int x,int i)
{
    if(i<0)
        return 0;
    int bt=(x>>i)&1;
    
    if(!i)
    {
        if(bt)
        {
            if(cur1&&cur2)
                return (cur2->cnt)-(cur1->cnt);
            else if(cur2)
                return cur2->cnt;
            else
                return 0;
        }
        else
        {
            return getcount(cur2,0)-getcount(cur1,0);
        }
        if(cur1)
            return ((cur2->cnt)-(cur1->cnt));
        else
            return (cur2->cnt);
    }
    
    if(bt)
    {
        int cnt1=getcount(cur2,0)-getcount(cur1,0);
        return cnt1+countless(get(cur1,1),get(cur2,1),x,i-1);
    }
    else
    {
        return countless(get(cur1,0),get(cur2,0),x,i-1);
    }
}

int kth(Trie* cur1,Trie* cur2,int k,int i)
{
    if(i<0)
        return 0;
    int cnt1=getcount(cur2,0)-getcount(cur1,0);
    if(cnt1>=k)
    {
        return kth(get(cur1,0),get(cur2,0),k,i-1);
    }
    else
    {
        return (1LL<<i)+kth(get(cur1,1),get(cur2,1),k-cnt1,i-1);
    }
    
}

void solve()
{
    root[0]=new Trie();
    int rear=0;
    int m;
    cin>>m;
    int t,x,l,r,k;
    
    while(m--)
    {
        cin>>t;
        if(t==0)
        {
            cin>>x;
            Trie* cur=new Trie();
            insert(root[rear],cur,x,22);
            root[rear+1]=cur;
            rear++;
        }
        else if(t==1)
        {
            cin>>l>>r>>x;
            cout<<(x^maxxor(root[l-1],root[r],x,22))<<endl;
        }
        else if(t==2)
        {
            cin>>k;
            rear-=k;
        }
        else if(t==3)
        {
            cin>>l>>r>>x;
            cout<<countless(root[l-1],root[r],x,22)<<endl;
        }
        else
        {
            cin>>l>>r>>k;
            cout<<kth(root[l-1],root[r],k,22)<<endl;
        }
    }
    
}

int32_t main()
{
    
    startTime=clock();
    IOS;
    //FILE *fin = freopen("in","r",stdin);
    //FILE *fout = freopen("out","w",stdout);
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

