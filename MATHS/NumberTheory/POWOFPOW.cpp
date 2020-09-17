//calculating : ((n1^k1)^(n2^k2))%n;
/*
CREATED BY VISHAL SOM:
*/
ll gcd(ll a,ll b)
{
    if(a==0)
    return b;
  else
  return gcd(b%a,a);

    
}
ll power(ll a,ll n,ll m)
{
    if(n==0)
    return 1;
    ll p=(power(a,n/2,m));
    p=(p*p)%m;
    if(n%2)
    return (p*a)%m;
    else
    return p;
}
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
int isequal(ll a,ll b,ll offset)
{
    if(offset==0)
    return 1;
    ll p=1;
    int cnt=1;
    while(cnt<=b)
    {
       p=p*a;
       if(p>offset)
       break;
       cnt++;
    }
    if(p==offset)
    return 0;
    else
    return 1;
    
}
ll solve(ll base,ll a,ll b,int offset,ll n)
{
      double d;
    if(offset)
   d=b*(double)log(a)-(double)log(offset);
    else
    d=1;
    if(d==0)
    {
        return 1;
    }
      if(gcd(base,n)==1)
      {
          ll phi=phin(n);
          ll pr=power(a,b,phi);
          pr=(pr-offset%phi+phi)%phi;
          return power(base,pr,n);
      }
      ll g=gcd(base,n);
      ll y=n/g;
      ll z=base/g;
      return (g*((solve(z,a,b,offset,y)*solve(g,a,b,offset+1,y))%y))%n;
}
int main()
{
   
   ll n1,k1,n2,k2,n,base;
 
       cin>>n1>>k1>>n2>>k2>>n;
       base=power(n1,k1,n);
       if(base==1)
       {
           cout<<1%n;
       }
       else if(n==1)
       {
           cout<<"0";
       }
       else if(base==0)
       {
          if(n2)
           cout<<"0";
           else if(n2==0&&k2==0)
           cout<<"0";
           else
           cout<<"1";
       }
       else if(n2==0&&k2!=0)
       {
           cout<<1%n;
       }
       else if((n2==0&&k2==0)||n2==1)
       {
           cout<<base%n;
       }
       else
       {
           cout<<solve(base,n2,k2,0,n);
       }
     //  cout<<endl;
   
    return 0;
    
}
