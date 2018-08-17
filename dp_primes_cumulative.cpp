/*
 * Dynamic Programming
 * Question:https://www.hackerrank.com/contests/coding-club-delhi-contest/challenges/bhawana-with-her-new-game/submissions/code/1309662131
 * */

#include<bits/stdc++.h>
using namespace std;
typedef long l;
typedef long double ld;
int main()
{
    vector<l> pre;
    for(l i=0;i<=5000000;++i)
    {
        pre.push_back(1);
    }
    for(l i=2;i*i<=5000000;++i)
    {
        if(pre[i]==1)
        {
            l j=2;
            while(i*j<=5000000)
            {
                pre[i*j]=0;
                ++j;
            }
        }
    }
    for(l i=2;i*i<=5000000;++i)
    {
        if(pre[i]==1)
        {
            l j=2;
            while(i*j<=5000000)
            {
                pre[i*j]=pre[i]+pre[j];
                ++j;
            }
        }
    }

    for(l i=2;i<=5000000;++i)
    {
        pre[i]+=pre[i-1];
    }

    l t;
    cin>>t;
    while(t--)
    {
        l a,b;
        cin>>a>>b;
        l ans=pre[a]-pre[b];
        cout<<ans<<"\n";
    }
}