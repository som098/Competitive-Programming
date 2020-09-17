vi sg[1000000];  //vi stands for vector<int> sg is seg. tree
int a[100001];  // array storing the values
void merge(int i1,int i2,int i3)
{
    int n1=sg[i2].size();
    int n2=sg[i3].size();
    int i=0,j=0;
    while(i<n1&&j<n2)
    {
        if(sg[i2][i]<=sg[i3][j])
        {
            sg[i1].pb(sg[i2][i]);
            i++;
        }
        else
        {
            sg[i1].pb(sg[i3][j]);
            j++;
        }
    }
    while(i<n1)
    {
        sg[i1].pb(sg[i2][i]);
        i++;
    }
    while(j<n2)
    {
        sg[i1].pb(sg[i3][j]);
        j++;
    }
}
void constructsortedtree(int i,int l,int r)
{
    if(r<l)
        return;
    if(l==r)
    {
        sg[i].pb(a[l]);
        return;
    }
    int m=(l+r)/2;
    constructsortedtree(2*i+1,l,m);
    constructsortedtree(2*i+2,m+1,r);
    merge(i,2*i+1,2*i+2);
}
int query2(int i,int l,int r,int qs,int qe,int x)  // query to find no of elements equal to x from range qs to qe
{
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
    {
        return (upper_bound(sg[i].begin(),sg[i].end(),x)-lower_bound(sg[i].begin(),sg[i].end(),x));
    }
    int m=(l+r)/2;
    return query2(2*i+1,l,m,qs,qe,x)+query2(2*i+2,m+1,r,qs,qe,x);
}
