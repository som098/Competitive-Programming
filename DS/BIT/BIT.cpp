
/*
                                         IMPLEMENTATION OF BINARY INDEXED TREE
                                              SUM AND UPDATE QUERY IN BIT
                                               ASSUMING 1-BASED INDEXING
 */
#include<bits/stdc++.h>
using namespace std;

int n;
int getparent(int i)                   // getting parent of i
{
    return i-(i&(-i));
}
int getnext(int i)
{
    return i+(i&(-i));
}
ll getsum(ll bit[],int r)            // calculating sum from 1-r
{
    ll sum=0;
    while(r>0)
    {
        sum=sum+bit[r];
        r=getparent(r);
    }
    return sum;
}
void update(ll bit[],int i,int value)    //   updating index i
{
    while(i<=n)
    {
        bit[i]+=value;
        i=getnext(i);
    }
}
int main()
{
    cin>>n;
    int a[n+1];int bit[n+1];
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        update(bit,i,a[i]);     // constructing BIT
    return 0;
}
