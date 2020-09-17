struct subset
{
    int parent,rank;
};
int find(int i)
{
    if(subsets[i].parent==i)
    return i;
    subsets[i].parent=find(subsets[i].parent);
    return subsets[i].parent;
}
void Union(int x,int y)
{
    if(subsets[x].rank>subsets[y].rank)
    {
        subsets[y].parent=x;
    }
    else if(subsets[x].parent<subsets[y].parent)
    {
        subsets[x].parent=y;
    }
    else
    {
        subsets[y].parent=x;
        subsets[x].rank++;
    }
}
int main()
{
    IOS;
    int x,y,z;
    cin>>x>>y>>z;
    int a,b,c;
    cin>>a>>b>>c;
    
    return 0;
}
