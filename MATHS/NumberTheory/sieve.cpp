// calculating prime no's upto n;

bool p[n+1]={0};
for(int i=2;i<=sqrt(n);i++)
{
if(!p[i])
{
for(int j=2*i;j<=n;j+=i)
p[j]=1;
}
}
