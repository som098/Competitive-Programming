void constructtree(int st[],int l,int r,int i,int a[])

{
    if(l==r)
        
    {
        st[i]=a[l];
        
        return;
        
    }
    
    int mid=(l+r)/2;
    
    constructtree(st,l,mid,2*i+1,a1);
    
    constructtree(st,mid+1,r,2*i+2,a1);
    
    st[i]=st[2*i+1]+st[2*i+2];
    
}
void update(int st[],int l,int r,int i,int in1,ll diff)
{
    if(l>r)
        return;
    if(in1>r||in1<l)
        return;
    if(l==r)
    {
        st[i]+=diff;
        return;
    }
    int m=(l+r)/2;
    update(st,l,m,2*i+1,in1,x);
    update(st,m+1,r,2*i+2,in1,x);
    st[i]=st[2*i+1]+st[2*i+2];
}
int RMQ(int st[],int l,int r,int i,int qs,int qe)

{
    
    if(qs>r||qe<l)
        
        return 0;
    
    else if(qs<=l&&qe>=r)
        
        return st[i];
    
    int mid=(l+r)/2;
    
    return (RMQ(st,l,mid,2*i+1,qs,qe)+RMQ(st,mid+1,r,2*i+2,qs,qe));
    
}

