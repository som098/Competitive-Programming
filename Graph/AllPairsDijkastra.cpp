const int N=1000;
int dp[1001][1001];vector<pii> adj[N+1];
void dijkastra(int src,int n)
{
    for(int i=1;i<=n;i++)
    {
        dp[src][i]= INF;
    }
    dp[src][src]=0;
    set<pii>s;
    s.insert(m1(dp[src][src],src));
    while(!s.empty())
    {
        auto it=(s.begin());
        int u=(*it).se;
        s.erase(s.begin());
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].fi,w=adj[u][i].se;
            if(dp[src][v]>(dp[src][u]+w))
            {
                if(s.find(m1(dp[src][v],v))!=s.end())
                    s.erase(s.find(m1(dp[src][v],v)));
                dp[src][v]=dp[src][u]+w;
                s.insert(m1(dp[src][v],v));
            }
        }
        
    }
}
