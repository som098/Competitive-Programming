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
  
st[i]=min(st[2*i+1],st[2*i+2]);

}
int RMQ(int st[],int l,int r,int i,int qs,int qe)

{
   
 if(qs>r||qe<l)
    
return 100000000;
    
else if(qs<=l&&qe>=r)
    
return st[i];
    
int mid=(l+r)/2;
    
return min(RMQ(st,l,mid,2*i+1,qs,qe),RMQ(st,mid+1,r,2*i+2,qs,qe));

}
