/*
 RMQ using sparse table
 */
const int N=200005;
int a[N];int sp[N][21];int lg2[N];// for storing log2
void buildSparse(int n)
{
    for(int i=0;i<n;i++)
        sp[i][0]=a[i];
    for(int j=1;j<=20;j++)
    {
        for(int i=0;(i+(1<<j))<=n;i++)
            sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
}

int query(int l,int r)
{
    int len=lg2[r-l+1];
    return min(sp[l][len],sp[r-(1<<len)+1][len]);
}
