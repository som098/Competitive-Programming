#include<iostream>
using namespace std;
//#include "stdc++.h"
#include<bits/stdc++.h>
/*
 LCA  BY BINARY LIFTING WHEN ROOT CHANGES IN EVERY QUERY 1<=N<=200000,1<=Q<=200000
 Author: Vishal Som
 */
int up[2000001][21];int tin[200001],tout[200001];int Time=0;
void dfs(vector<int> adj[],int u,int parent)
{
    tin[u]= ++Time;
    up[u][0]=parent;
    for(int i=1;i<=20;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(int i=0;i<adj[u].size();i++)
        if(adj[u][i]!=parent)
            dfs(adj,adj[u][i],u);
    tout[u]= ++Time;
}
int is_ancestor(int u,int v)
{
    if(u==0)
        return 1;
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int lca(int u,int v)
{
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    for(int i=20;i>=0;i--)
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}
int main()
{
    int n;
    cin>>n;
    vector<int> adj[n+1];int u,v;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,1,1);int q,root;
    cin>>q;
    while(q--)
    {
        cin>>root>>u>>v;
        int u1=lca(root,u);
        int v1=lca(root,v);
        if(u1==v1)
            cout<<lca(u,v);
        else
        {
            if(is_ancestor(u1,v1))
                cout<<v1;
            else
                cout<<u1;
        }
        cout<<endl;
    }
    return 0;
}

