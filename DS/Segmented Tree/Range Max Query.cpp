const int N=100001;
int st[4*N];
void constructtree(int i,int l,int r)
{
    if(l==r)
{
        st[i]=a[l];
        return;
}
int mid=(l+r)/2;
constructtree(2*i+1,l,mid);
 constructtree(2*i+2,mid+1,r);
st[i]=max(st[2*i+1],st[2*i+2]);
}
void update(int i,int l,int r,int in,int x)
{
    if(l>r)
        return;
    if(in>r||in<l)
        return;
    if(l==r)
    {
        st[i]=x;
        return;
    }
    int m=(l+r)/2;
    update(2*i+1,l,m,in,x);
    update(2*i+2,m+1,r,in,x);
    st[i]=max(st[2*i+1],st[2*i+2]);
}
int query(int i,int l,int r,int qs,int qe)

{
 if(qs>r||qe<l)
return -INF;
else if(qs<=l&&qe>=r)
return st[i];
int mid=(l+r)/2;
return max(query(2*i+1,l,mid,qs,qe),query(2*i+2,mid+1,r,qs,qe));
}
