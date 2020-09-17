const int N=1000005;
int st[4*N];
int lazy[4*N];
void update(int i,int l,int r,int qs,int qe,int v)
{
    if(lazy[i]!=0)
    {
        st[i]+=lazy[i];
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
        st[i]+=v;
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
    st[i]=max(st[2*i+1],st[2*i+2]);
}
int query(int i,int l,int r,int qs,int qe)
{
    if(lazy[i]!=0)
    {
        st[i]+=lazy[i];
        if(l!=r)
        {
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(qs>r||qe<l)
        return -INF;
    if(qs<=l&&qe>=r)
        return st[i];
    int m=(l+r)/2;
    return max(query(2*i+1,l,m,qs,qe),query(2*i+2,m+1,r,qs,qe));
}
