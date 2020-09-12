#include "stdc++.h"
//#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
#define int long long int
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
/*
 shuffle(x,x+n,rng) // shuffling elements of x in random order
 */
/*
 HEAVY LIGHT DECOMPOSITION
 Source : QTREE-Spoj
 
 */
const int N=100004;
vector<pair<int,int> > adj[N+1];int st[4*N];int up[N+1][20];int tin[N+1],tout[N+1];int Time=0;
int a[N+1];int head[N+1];
int heavy[N+1],pos[N+1],currentpos=0;
int value[N+1];int depth[N+1];
int sz[N+1],parent[N+1];int n;
struct queries
{
    int e,a,b,t1,Time,index;
};
bool compare(queries &q1,queries &q2)
{
    return (q1.Time<=q2.Time);
}
void swap(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
}
void constructtree(int i,int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        st[i]=value[a[l]];
        return;
    }
    int m=(l+r)/2;
    constructtree(2*i+1,l,m);
    constructtree(2*i+2,m+1,r);
    st[i]=max(st[2*i+1],st[2*i+2]);
}
void hld(int u,int h)
{
    head[u]=h;int v;
    pos[u]=currentpos;
    a[currentpos]=u;
    currentpos++;
    if(heavy[u]!=-1)
    {
        hld(heavy[u],h);
    }
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i].first;
        //w=adj[u][i].second;
        if(v!=parent[u]&&v!=heavy[u])
            hld(v,v);
    }
}
void dfs(int u,int p)
{
    parent[u]=p;sz[u]=1;int mx=0,v,w;
    tin[u]=(++Time);
    up[u][0]=p;
    for(int i=1;i<=19;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i].first;w=adj[u][i].second;
        if(p!=v)
        {
            depth[v]=1+depth[u];
            value[v]=w;
            dfs(v,u);
            sz[u]+=sz[v];
            if(sz[v]>mx)
            {
                mx=sz[v];
                heavy[u]=v;
            }
        }
    }
    tout[u]=(++Time);
}
int getmax(int i,int l,int r,int qs,int qe)
{
    if(qs>r||qe<l)
        return -1000000000;
    if(qs<=l&&qe>=r)
        return st[i];
    int m=(l+r)/2;
    return max(getmax(2*i+1,l,m,qs,qe),getmax(2*i+2,m+1,r,qs,qe));
}
int query(int u,int v)
{
    int ans=0,mx=0;
    while(head[u]!=head[v])
    {
        if(depth[u]>depth[v])
            swap(u,v);
        mx=getmax(0,0,n-1,pos[head[v]],pos[v]);
        ans=max(ans,mx);
        v=parent[head[v]];
    }
    if(depth[u]>depth[v])
        swap(u,v);
    if(pos[v]>=pos[u]+1)
        mx=getmax(0,0,n-1,pos[u]+1,pos[v]);
    ans=max(ans,mx);
    return ans;
}
void update(int i,int l,int r,int qs,int qe,int v)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        value[a[l]]=v;
        st[i]=v;
        return;
    }
    int m=(l+r)/2;
    update(2*i+1,l,m,qs,qe,v);
    update(2*i+2,m+1,r,qs,qe,v);
    st[i]=max(st[2*i+1],st[2*i+2]);
}
int is_ancestor(int u,int v)
{
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int lca(int u,int v)
{
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    for(int i=19;i>=0;i--)
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}
int32_t main()
{
    IOS;
    int u,v,w;int t;string s,blank;int ans,id,lc,q;
    int t=1;
    while(t--)
    {
        //getline(cin,blank);
        memset(heavy,-1,sizeof(heavy));currentpos=0;Time=0;
        for(int i=0;i<=N;i++)
            adj[i].clear();
        cin>>n;vector<pair<int,int> >edge;
        for(int i=0;i<n-1;i++)
        {
            cin>>u>>v;
            w=0;
            adj[u].pb(m1(v,w));
            adj[v].pb(m1(u,w));
            edge.pb(m1(u,v));
        }
        
        value[1]=0;
        depth[1]=0;
        dfs(1,1);
        hld(1,1);
        constructtree(0,0,n-1);
        ///for(int i=0;i<n;i++)
        // cout<<a[i]<<" ";
        //cout<<endl;
        
        cin>>q;
        queries query[q];
        for(int i=0;i<q;i++)
        {
            cin>>query[i].t1;
            cin>>query[i].Time;
            query[i].index=i+1;
            if(query[i].t1==1)
            {
                cin>>query[i].e;
            }
            else
            {
                cin>>query[i].a;
                cin>>query[i].b;
            }
            
        }
        sort(query,query+q,compare);
        int cnt[q+1];
        memset(cnt,-1,sizeof(cnt));
        for(int i=0;i<q;i++)
        {
            
            if(query[i].t1==2)
            {
                u=query[i].a;
                v=query[i].b;
                lc=lca(u,v);
                if(depth[u]>depth[v])
                    swap(u,v);
                if(parent[v]==u)
                    ans=getmax(0,0,n-1,pos[v],pos[v]);
                else
                    ans=max(query(u,lc),query(v,lc));
                if(ans==0)
                    cnt[query[i].index]=1;
                else
                    cnt[query[i].index]=0;
            }
            else
            {
                id=query[i].e;
                w=1;
                id--;
                u=edge[id].first;
                v=edge[id].second;
                if(depth[u]>depth[v])
                    swap(u,v);
                update(0,0,n-1,pos[v],pos[v],w);
                
            }
            
        }
        for(int i=1;i<=q;i++)
        {
            if(cnt[i]!=-1)
                cout<<cnt[i]<<endl;
        }
    }
    return 0;
}

