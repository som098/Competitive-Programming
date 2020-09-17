
const int k=2;
struct matrix
{
    int m[k][k];
    matrix()
    {
        memset(m,0,sizeof(m));
    }
} M,I;
matrix matmul(matrix a,matrix b)
{
    matrix x;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int l=0;l<k;l++)
            {
                x.m[i][j]=(x.m[i][j]%hell+(a.m[i][l]%hell*b.m[l][j]%hell)%hell)%hell;
            }
        }
    }
    return x;
}
matrix matexpo(int n)
{
    if(n==0)
    {
        return I;
    }
    matrix F;
    F=matexpo(n/2);
    F=matmul(F,F);
    if(n%2)
        F=matmul(F,M);
    return F;
}
matrix ADD(matrix M1,matrix M2)
{
    matrix M3;
    for(int r=0;r<2;r++)
        for(int c=0;c<2;c++)
        {
            M3.m[r][c]=(M1.m[r][c]%hell+M2.m[r][c]%hell)%hell;
        }
    return M3;
}
