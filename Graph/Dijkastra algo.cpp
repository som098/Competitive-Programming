#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long int
#define m1 make_pair
/*
DIJKASTRA'S ALGORITHM
DATE:3/10/18
TIME:
*/
/*
GRAPH IS UNDIRECTED AND WEIGHTED AND CAN CONTAINS LOOPS AND MULTIEDGES:
N vertices and M EDGES
*/
int main()
{
    
    int n,m;
    cin>>n>>m;int u,v;ll w; vector<pair<int,ll>> adj[n+1];
    for(int i=0;i<=m-1;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back(m1(v,w));
        adj[v].push_back(m1(u,w));
    }
   ll inf=10000000000000000;
    set<pair<ll,int>>st;
    pair<ll,int>p;
    ll d[n+1];
    for(int i=0;i<=n;i++)
    {
        d[i]=inf;
    }
    d[1]=0;  // 1 is the starting vertex
    st.insert(m1(d[1],1));int parent[n+1];int f[n+1]={0};
    parent[1]=-1;
    while(!st.empty())
    {
        p=*(st.begin());
     //   ans[p.second]=p.first;
     st.erase(st.begin());
        u=p.second;
        f[u]=-1;
        //d[u]=p.first;
        for(int j=0;j<adj[u].size();j++)
        {
            v=adj[u][j].first;w=adj[u][j].second;
            if(d[v]>d[u]+w&&f[v]!=-1)
            {
                if(d[v]!=inf)
                {
                    st.erase(st.find(m1(d[v],v)));
                }
                d[v]=d[u]+w;
                st.insert(m1(d[v],v));
                parent[v]=u;
            }
        }
    }
    /*
    d[i] stores the shortest distance from 1 to vertex i  :
    parent[i] stores the parent of i int the path from 1 to i :
    */
    if(d[n]==inf)
    cout<<"-1";
    else
    {
    
        int j=n;stack<int>s;
        s.push(n);
        while(parent[j]!=-1)
        {
            s.push(parent[j]);
            j=parent[j];
        }
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    cout<<endl;

    return 0;
}
