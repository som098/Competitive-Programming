#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define LL long long
#define int long long
#define PB push_back
#define N 300001
#define LG 22
#define MXQ 200001
#define M 1000000007
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define LD double
#define F first
#define S second
#define ll long long
#define inf LLONG_MAX
#define endl "\n"
#define mx 1001
#define T long long
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

/**
https://codeforces.com/gym/100753/submission/51577660*/
bool ar[mx];
vector<ll>prime = {2};
void sieve(){
    for(ll i = 3; i*i<=mx ; i+=2)if(!ar[i]) for(ll j = i*i; j<mx; j+=2*i)   ar[j] = true;
    for(ll i = 3; i<mx; i+=2)   if(!ar[i])  prime.push_back(i);
}

using u64 = uint32_t;
using u128 = __uint64_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < 30; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
bool isSq(ll n){
    ll s = sqrtl(n);
    return s*s==n;
}

ll go(ll n){
    ll ans = 1;
    for(ll i:prime){
        if(i*i*i>n) break;
        ll cnt = 1;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        ans*=cnt;
    }
    if(n==1)    return ans;
    if(MillerRabin(n))   return ans*2;
    if(isSq(n)) return ans*3;
    return ans*4;
}


/* https://www.geeksforgeeks.org/number-of-elements-greater-than-k-in-the-range-l-to-r-using-fenwick-tree-offline-queries/*/

// Structure which will store both 
// array elements and queries. 
struct node { 
    int pos; 
    int l; 
    int r; 
    int val,xval; 
}; 
  
// Boolean comparator that will be used 
// for sorting the structural array. 
bool comp(node a, node b) 
{ 
    // If 2 values are equal the query will 
    // occur first then array element 
    if (a.val == b.val) 
        return a.l < b.l; 
  
    // Otherwise sorted in descending order. 
    return a.val < b.val; 
} 
  
// Updates the node of BIT array by adding 
// 1 to it and its ancestors. 
void update(int* BIT, int n, int idx,int val) 
{ 
    while (idx <= n) { 
        BIT[idx]^=val; 
        idx += idx & (-idx); 
    } 
} 
// Returns the count of numbers of elements 
// present from starting till idx. 
int query(int* BIT, int idx) 
{ 
    int ans = 0; 
    while (idx) { 
        ans ^= BIT[idx]; 
  
        idx -= idx & (-idx); 
    } 
    return ans; 
} 
int QueryL[N]; 
int QueryR[N];
int QueryK[N];
int ans[N];
// Function to solve the queries offline 
void solveQuery(int arr[], int n, int q, int vals[]) 
{ 
    // create node to store the elements 
    // and the queries 
    node a[n + q + 1];
    // 1-based indexing. 
    unordered_map<LL,LL> mp;
    LL mpct=1; 
    ordered_set occ[n+1];
    // vector<LL> occ[n+1];
    // traverse for all array numbers 
    for (int i = 1; i <= n; ++i) { 
        // cout<<arr[i-1]<<" ";
        if(mp[vals[i-1]]==0)
            mp[vals[i-1]]=mpct++;
        // occ[mp[vals[i-1]]].PB(i);
        a[i].val = arr[i - 1];
        a[i].xval=vals[i-1];
        a[i].pos = 0; 
        a[i].l = 0; 
        a[i].r = i; 
        // cout<<a[i].val<<" "<<a[i].xval<<endl;;
    } 
    // cout<<endl;
    // for(int i=1;i<=mpct;i++)
    // {
    //     for(int j=0;j<occ[i].size();j++)
    //         cout<<occ[i][j]<<" ";
    //     cout<<endl;  
    // }          
    // iterate for all queries 
    for (int i = n + 1; i <= n + q; ++i) { 
        a[i].pos = i - n; 
        a[i].val = QueryK[i - n - 1]; 
        a[i].l = QueryL[i - n - 1]; 
        a[i].r = QueryR[i - n - 1]; 
    } 
  
    // In-built sort function used to 
    // sort node array using comp function. 
    sort(a + 1, a + n + q + 1, comp); 
  
    // Binary Indexed tree with 
    // initially 0 at all places. 
    int BIT[n + 1]; 
  
    // initially 0 
    memset(BIT, 0, sizeof(BIT)); 
  
  
    // traverse for numbers and query 
    for (int i = 1; i <= n + q; ++i) { 
        // cout<<a[i].pos<<" "<<a[i].l<<" "<<a[i].r<<endl;
        if (a[i].pos != 0) { 
            // cout<<"q "<<" "<<a[i].pos<<endl;
            // call function to returns answer for each query 
            int cnt = query(BIT, a[i].r) ^ query(BIT, a[i].l - 1);
            LL fres; 
            if(mp[cnt]==0)
                fres=0;
            else
            {
                LL cr=mp[cnt];
                fres=occ[cr].order_of_key(a[i].r+1)-occ[cr].order_of_key(a[i].l);
            }
            // This will ensure that answer of each query 
            // are stored in order it was initially asked. 
            ans[a[i].pos] = fres; 
        } 
        else { 
            // a[i].r contains the position of the 
            // element in the original array. 
            // cout<<"a "<<a[i].val<<" "<<a[i].xval<<endl;
            occ[mp[a[i].xval]].insert(a[i].r);
            update(BIT, n, a[i].r,a[i].xval); 
        } 
    } 
    // Output the answer array 
    for (int i = 1; i <= q; ++i) { 
        cout << ans[i] << endl; 
    } 
} 

int32_t main()
{
    LL i,j,lt,d,z,v,c,r,l,k,q,x,y,m,n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    sieve();
    cin>>n;
    srand(time(NULL));
    LL px[n+1],py[n+1];
    for(i=0;i<n;i++)
    {
        cin>>px[i]>>py[i];
        // px[i]=0;
        // py[i]=M;
        py[i]=go(py[i]);
        // cout<<py[i]<<" ";
    }
    // cout<<py[0]<<endl;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>QueryL[i]>>QueryR[i]>>QueryK[i];
    }
    solveQuery(px,n,q,py);
}       