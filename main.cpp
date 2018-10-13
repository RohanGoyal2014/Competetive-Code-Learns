/*
 * Flat earth society
 * Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/flat-earth-society/
 * min(l,r) :
 * let l>r then (i-l-1)+r>=i but we can select current segment first and left segment later thus l
 * similar for l<r
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        long hash[100002]={0},dp[100002]={0};
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            hash[tmp]+=tmp;
        }
        for(int i=1;i<=100001;++i)
        {
            int m=i-min(l,r)-1;
            if(m>=0)
            {
                dp[i]=max(dp[i-1],hash[i]+dp[m]);
                // cout<<i<<":"<<dp[i]<<endl;
            }
            else
            {
                dp[i]=max(dp[i-1],hash[i]);
            }

        }
        cout<<dp[100001]<<endl;
    }
}