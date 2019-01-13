/*
 * Classical Coin Change Problem
 * Question Example:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/accomodation-a5c006f3/
 * References: GFG + https://www.youtube.com/watch?v=jaNZ83Q3QGc
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    int m,n;
    cin>>m>>n;
    int a[m];
    for(int i=0;i<m;++i)
    {
        cin>>a[i];
    }
    int dp[n+1]={0};
    dp[0]=1;
    for(int i=0;i<m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(j<a[i]) continue;
            dp[j]+=dp[j-a[i]];
        }
    }
    cout<<dp[n];
    return 0;
}