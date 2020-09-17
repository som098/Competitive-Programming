// calculating phi(n)

ll phin(ll n)
{
ll phi=n;
int z=0;ll x=n;
for(int i=2;i<=sqrt(x);i++)
 {
z=0;
while((n%i)==0)
 {
 n=n/i;
     z=1;
 }
  if(z)
{
     phi=(phi*(i-1))/i;
}
}
  if(n>1)
{
  phi=(phi*(n-1))/n;
}
 return phi;
}
