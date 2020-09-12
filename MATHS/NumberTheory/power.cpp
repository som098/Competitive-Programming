ll power(ll a,ll n,ll m)
{
if(n==0)
return 1;
ll p=power(a,n/2,m);
p=(p*p)%m;
if(n%2)
return (p*a)%m;
else
return p;
}