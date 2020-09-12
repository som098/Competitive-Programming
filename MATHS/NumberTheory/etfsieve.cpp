/*
 calculating   phi(n) for 1<=n<=100000 by Seive
 */
ll phi[100001];
void etf()
{
    for(int i=1;i<=100000;i++)
        phi[i]=i;
    for(int i=2;i<=sqrt(100000);i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=100000;j+=i)
            {phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}
