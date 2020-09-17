ll gcd(ll a,ll b)
{
if(a==0)
return b;
else 
return gcd(b%a,a);
}