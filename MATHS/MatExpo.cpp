/*
 Given a Matrix M calculate M^n %hell
 result is stored in matrix F;
 */
const int k=4;
matrix M(k,vector<int>(k,0));matrix F(k,vector<int>(k,0));

matrix matmul(matrix a,matrix b)
{
    
    matrix x(k,vector<int>(k,0));
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int l=0;l<k;l++)
            {
                x[i][j]=(x[i][j]%hell+(a[i][l]*b[l][j])%hell)%hell;
            }
        }
    }
    return x;
}
void matexpo(int n)
{
    if(n==1)
    {
        F=M;
        return;
    }
    //matrix c(4,vector<int>(4,0));
    matexpo(n/2);
    F=matmul(F,F);
    if(n%2)
        F=matmul(F,M);
}
