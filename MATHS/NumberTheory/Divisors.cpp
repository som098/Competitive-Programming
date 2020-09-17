/*
 finding no of divisors by factorization method
 */
vector<pair<int,int> >factors;vector<int> divisors;int m;
void setDivisors(int n, int i) {
    int j, x, k;
    for (j = i; j<factors.size(); j++) {
        x = factors[j].first * n;
        for (k = 0; k<factors[j].second; k++) {
            if(x<=m&&x>=2)
            {
                divisors.push_back(x);
            }
            setDivisors(x, j + 1);
            
            x *= factors[j].first;
        }
    }
}

int main()
{
    cin>>m;
    primefactors(m);
    setDivisors(1,0);
    divisors.pb(1);
    return 0;
}
