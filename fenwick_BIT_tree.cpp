/*
 * Use of BIT
 * Question:https://www.hackerearth.com/challenge/college/codezilla-prelims/algorithm/childhood/
 */
#include<bits/stdc++.h>
using namespace std;
typedef long l;
void update_BIT(int pos,int BIT[],int msz,int val=1)
{
    while(pos<=msz)
    {
        BIT[pos]+=val;
        pos+=pos&(-pos);
    }
}
int getSum(int pos,int BIT[])
{
    int sum=0;
    while(pos!=0)
    {
        sum+=BIT[pos];
        pos-=pos&(-pos);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int g[n];
        int f[n];
        map<int,int> mp;
        for(int i=0;i<n;++i)
        {
            cin>>g[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>f[i];
        }
        for(int i=0;i<n;++i)
        {
            mp[f[i]]=g[i];
        }
        l ans=0;
        int BIT[100005]={0};
        for(auto i=mp.rbegin();i!=mp.rend();++i)
        {
            int c=i->second;
            ans+=abs(i->first-c+getSum(i->second-1,BIT));
            update_BIT(i->second,BIT,n);
        }
        cout<<2*ans<<endl;
    }
    return 0;
}