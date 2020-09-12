/*
 GCD query st is the global array to store nodes
 and a is array storing values
 */
void constructtree(int i,int l,int r)
{
    if(r<l)
        return;
    if(l==r)
    {
        st[i]=a[l];
        return;
    }
    int m=(l+r)/2;
    constructtree(2*i+1,l,m);
    constructtree(2*i+2,m+1,r);
    st[i]=gcd(st[2*i+1],st[2*i+2]);
}
int query(int i,int l,int r,int qs,int qe)
{
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
        return st[i];
    int m=(l+r)/2;
    return gcd(query(2*i+1,l,m,qs,qe),query(2*i+2,m+1,r,qs,qe));
}
void update(int i,int l,int r,int index,int value)
{
    if(index<l||index>r)
        return;
    if(index<=l&&index>=r)
    {
        a[l]=value;
        st[i]=value;
        return;
    }
    int m=(l+r)/2;
    update(2*i+1,l,m,index,value);
    update(2*i+2,m+1,r,index,value);
    st[i]=gcd(st[2*i+1],st[2*i+2]);
}
