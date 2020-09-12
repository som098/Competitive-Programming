/*
 We are given a weighted graph with n nodes and m edges and we have to find for each edge the minimum cost of the spanning tree that includes this edge
1<=n<200000,1<=m<=200000
 */
/*
 /*
 ############### sabka katega ###############
 ********************************
 using DSU,LCA BY Binary Lifting
 Problem link https://codeforces.com/contest/609/problem/E
 */
//#include "stdc++.h"
#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tuple<int, int, int> t3;
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
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0) return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p; }
#define flush fflush(stdout)
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
int up[200001][20];int tin[200001],tout[200001];int Time=0;int mx[200001][20];
int prt[200001];
void dfs(vector<pair<int,int>> adj[],int u,int parent,int w1)
{
    tin[u]= ++Time;
    up[u][0]=parent;
    prt[u]=parent;
    mx[u][0]=w1;
    for(int i=1;i<=19;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        mx[u][i]=max(mx[u][i-1],mx[up[u][i-1]][i-1]);
    }
    for(int i=0;i<adj[u].size();i++)
        if(adj[u][i].first!=parent)
            dfs(adj,adj[u][i].first,u,adj[u][i].second);
    tout[u]= ++Time;
}
int is_ancestor(int u,int v)
{
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int lca(int u,int v)
{
    int ans=0;
    if(is_ancestor(u,v))
        return 0;
    //int i=0;
    for(int i=19;i>=0;i--)
    {
        if(!is_ancestor(up[u][i],v))
        {
            ans=max(ans,mx[u][i]);
            u=up[u][i];
        }
    }
    
    return max(ans,mx[u][0]);
}

struct edges
{
    int x,y,w,index;
};
bool compare(edges e1,edges e2)
{
    return (e1.w<=e2.w);
}
struct subset
{
    int rank,parent;
};
int find(subset subsets[],int i)
{
    if(subsets[i].parent==i)
        return i;
    subsets[i].parent=find(subsets,subsets[i].parent);
    return subsets[i].parent;
}
void Union(subset subsets[],int x,int y)
{
    if(subsets[x].rank>subsets[y].rank)
        subsets[y].parent=x;
    else if(subsets[y].rank>subsets[x].rank)
        subsets[x].parent=y;
    else{
        subsets[y].parent=x;
        subsets[x].rank++;
    }
}
int main()
{
    IOS;//ifstream fin("input.txt");ofstream fout("output.txt");
    int n,m;
    cin>>n>>m;vector<pair<int,int>> adj[n+1];
    edges edge[m];ll wt=0;pair<int,int> pr[m];
    for(int i=0;i<m;i++)
    {
        cin>>edge[i].x>>edge[i].y>>edge[i].w;
        pr[i].first=edge[i].w;
        pr[i].second=i;
        edge[i].index=i;
    }
    sort(pr,pr+m);
    subset subsets[n+1];
    for(int i=0;i<=n;i++)
    {
        subsets[i].rank=0;
        subsets[i].parent=i;
    }
    int x1,y1;int u,v;
    for(int i=0;i<m;i++)
    {
        u=edge[pr[i].second].x;
        v=edge[pr[i].second].y;
        x1=find(subsets,u);
        y1=find(subsets,v);
        if(x1!=y1)
        {
            wt+=edge[pr[i].second].w;
            adj[u].push_back(m1(v,edge[pr[i].second].w));
            adj[v].push_back(m1(u,edge[pr[i].second].w));
            Union(subsets,x1,y1);
        }
        
    }
    dfs(adj,1,1,0);
    ll ans[m];int mx1,mx2;int in;
    // cout<<wt<<endl;
    for(int i=0;i<m;i++)
    {
        in=i;
        u=edge[i].x;
        v=edge[i].y;
        if(prt[u]==v||prt[v]==u)
            ans[in]=wt;
        else
        {
            ans[in]=wt+edge[i].w;
            mx1=lca(u,v);
            mx2=lca(v,u);
            ans[in]-=max(mx1,mx2);
        }
    }
    for(int i=0;i<m;i++)
        cout<<ans[i]<<"\n";
    //cout<<endl;
    return 0;
    //return 0;
}

