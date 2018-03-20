/*
 * This is to find the longest path in a multichildren tree
 * where the path has all the elements divisible by k
 * I have used boolean array and stored true when a[i] is divisible by k
 * otherwise stored false
 * The approach is to start incrementing the ans updating the function as when
 * max length so far becomes greater than it. We compute all consecutive 1s
 * and for each node whose value is 1 we take its 2 max children and check if
 * max1+max2+1 is greater than m. and we return max1+1(since max1 was highest and
 * node is also 1 resulting in increment of 1 in that range)
 * If the node is 0,if compare only max1 with ans and return 0 because 0 brings the
 * break in the path of consecutive dividends. Thus we assume the 0 valued node to be the point of
 * division of tree into 2 disjoint trees in a forest.
 */
#include<bits/stdc++.h>
using namespace std;
long length(long node,bool a[],vector<long> edge[],long &ans,long par)
{
    if(edge[node].size()==1 && edge[node][0]==par)
    {
        //cout<<node<<" ";
        if(a[node])
        {
            ans=max(1L,ans);
            //cout<<"1\n";
            return 1;
        }
        //cout<<"0\n";
        return 0;
    }
    vector<long> filt;
    for(long i=0;i<edge[node].size();++i)
    {
        if(edge[node][i]!=par)
        {
            filt.push_back(edge[node][i]);
        }
    }
    vector<long> l;
    for(long i=0;i<filt.size();++i)
    {
        long len=length(filt[i],a,edge,ans,node);
        l.push_back(len);
    }
    if(l.size()==1)
    {
        long max_=l[0];
        if(a[node])
        {
            max_++;
        }
        ans=max(ans,max_);
        if(!a[node])
        {
            return 0;
        }
        return max_;
    }
    long max1,max2;
    auto it_max1=max_element(l.begin(),l.end());
    max1=*it_max1;
    *it_max1=-1;
    auto it_max2=max_element(l.begin(),l.end());
    max2=*it_max2;
    if(a[node])
    {
        ans=max(ans,max1+max2+1);
        return max1+1;
    }
    ans=max(max1,ans);
    return 0;

}
int main()
{
    long n,k;
    cin>>n>>k;
    bool a[2*n+1];
    for(long i=1;i<=n;++i)
    {
        long u;
        cin>>u;
        if(u%k==0)
        {
            a[i]=true;
        }
        else
        {
            a[i]=false;
        }
    }
    bool ok=false;
    for(int i=1;i<=n;++i)
    {
        if(a[i])
        {
            ok=true;
            break;
        }
    }
    if(!ok)
    {
        cout<<"0";
        exit(0);
    }
    if(n==1)
    {
        cout<<"0\n";
        exit(0);
    }
    vector<long> edge[n+1];
    for(long i=0;i<n-1;++i)
    {
        long u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    long ans=0;
    length(1,a,edge,ans,-1);
    cout<<ans-1;
}
