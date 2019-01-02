/*
dp[i]=dp[i-1]+dp[i-2]
dp[1]=2;
dp[2]=3;
1<=i<=10^18
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mkp(a,b) make_pair(a,b)
#define eb emplace_back
#define mod (long long)(1e9+7)
#define FILE_READ freopen("input.txt","r",stdin)
#define FILE_WRITE freopen("output.txt","w",stdout)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long ul;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>> tmp={{0,0},{0,0}};
    tmp[0][0]=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod;
    tmp[0][1]=((a[0][0]*b[0][1])%mod+a[0][1]*b[1][1]%mod)%mod;
    tmp[1][0]=((a[1][0]*b[0][0])%mod+a[1][1]*b[1][0]%mod)%mod;
    tmp[1][1]=((a[1][0]*b[0][1])%mod+a[1][1]*b[1][1]%mod)%mod;
    return tmp;
}

void matrixExponentation(vector<vector<ll>> a,vector<vector<ll>> mat_exp[])
{
    mat_exp[0]=a;
    for(int i=1;i<100000;++i)
    {
        mat_exp[i]=multiply(mat_exp[i-1],a);
    }
}
vector<vector<ll>> perform(ll n,vector<vector<ll>> mat_exp[])
{
    if(n<=100000)
    {
        return mat_exp[n-1];
    }
    vector<vector<ll>> _=perform(n/2,mat_exp);
    if(n%2==0)
    {
        return multiply(_,_);
    }
    return multiply(multiply(_,_),mat_exp[0]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    vector<vector<ll>> a={{1,1},{1,0}};
    vector<vector<ll>> mat_exp[100000];
    matrixExponentation(a,mat_exp);

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        auto res=perform(n-2,mat_exp);
        ll ans=(res[0][0]+res[1][0])%mod;
        cout<<ans<<endl;
    }

    return 0;
}
