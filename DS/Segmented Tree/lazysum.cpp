const int N=200001;
int st[4*N];int lazy[4*N];int a[N+1];
/*
 given an array we have to perform two operations
 1 given x l r we have to add x to all elements in the range l to r;
 2 given l and r find sum from l to r
 */
void update(int i,int l,int r,int qs,int qe,int v)
{
    if(lazy[i]!=0)
    {
        st[i]+=(r-l+1)*lazy[i];
        if(l!=r)
        {
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        st[i]+=(r-l+1)*v;
        if(l!=r)
        {
            lazy[2*i+1]+=v;
            lazy[2*i+2]+=v;
        }
        lazy[i]=0;
        return;
    }
    int m=(l+r)/2;
    update(2*i+1,l,m,qs,qe,v);
    update(2*i+2,m+1,r,qs,qe,v);
    st[i]=st[2*i+1]+st[2*i+2];
}
int getsum(int i,int l,int r,int qs,int qe)
{
    if(lazy[i]!=0)
    {
        st[i]+=(r-l+1)*lazy[i];
        if(l!=r)
        {
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
        return st[i];
    int m=(l+r)/2;
    return getsum(2*i+1,l,m,qs,qe)+getsum(2*i+2,m+1,r,qs,qe);
}
void constructtree(int l,int r,int i)

{
    if(l==r)
        
    {
        st[i]=a[l];
        
        return;
        
    }
    
    int mid=(l+r)/2;
    
    constructtree(l,mid,2*i+1);
    
    constructtree(mid+1,r,2*i+2);
    
    st[i]=st[2*i+1]+st[2*i+2];
    
}
