
  /*
   calculating SMALLEST PRIME FACTOR OF EACH n from 1-100000
   */
int spf[100001];
void SPF()
{
    for(int i=1;i<=100000;i++)
        spf[i]=i;
    for(int i=2;i<=sqrt(100000);i++)
    {
        if(spf[i]==i)
        {
            for(int j=2*i;j<=100000;j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}
