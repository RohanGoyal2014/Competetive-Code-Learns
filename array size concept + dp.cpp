/*
 * Problem:https://www.spoj.com/problems/COUNT/
 * References:https://brilliant.org/wiki/identical-objects-into-identical-bins/
 *
 *
 * Key Point: array of size 5000*5000 worked globally but did not work locally
 *            Further map<pii,int> and vector<int> dp[] were slow so did not work
 * */
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
int dp[5001][5001],cum[5001][5001];
ll solve(int n,int r)
{
    if(n<r)
    {
        return 0;
    }
    if(n==r || r==1 || n==r+1)
    {
        return 1;
    }
    if(r==2)
    {
        return n/2;
    }
    ll ans=0;
    for(int i=1;i<=r;++i)
    {
        ans=ans+solve(n-r,i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;
    int mod2=1988;
    memset(cum,0,sizeof(cum));
    for(int i=1;i<=5000;++i)
    {
        for(int j=1;j<=5000;++j)
        {
            if(j==1)
            {
                dp[i][j]=1;
            }
            else if(j>i)
            {
                dp[i][j]=0;
            }
            else if(j==2)
            {
                dp[i][j]=i/2;
            }
            else if(i==j || i==j+1)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=cum[i-j][j];
            }
            cum[i][j]=(cum[i][j-1]+dp[i][j])%mod2;
        }
    }
//    for(int i=1;i<=7;++i)
//    {
//        for(int j=1;j<=4;++j)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    while(1)
    {
        int a,b;
        cin>>a>>b;
        if(a==0 && b==0)
        {
            break;
        }
        cout<<dp[a][b]<<endl;
    }


    return 0;
}