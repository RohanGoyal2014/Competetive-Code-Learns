/*
 * BIT application
 * Question:https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/suarez/
 * Reference:https://www.hackerearth.com/submission/19243171/   --see the comment
 */
#include <bits/stdc++.h>
using namespace std;
typedef long l;
struct data
{
    l val;
    l sz;
    int pos;
};
bool comp_by_sz(data a,data b)
{
    return a.sz<b.sz;
}
bool comp_by_val(data a,data b)
{
    return a.val<b.val;
}
void update_BIT(int i,int BIT[],int sz,int val)
{
    while(i<=sz)
    {
        BIT[i]+=val;
        i+=i&(-i);
    }
}
int query_BIT(int i,int BIT[])
{
    int sum=0;
    while(i!=0)
    {
        sum+=BIT[i];
        i-=i&(-i);
    }
    return sum;
}
int findAns(int L,int R,int k,int BIT[])
{
    if(query_BIT(R,BIT)<k)
    {
        return -1;
    }
    if(R-L<2)
    {
        if(query_BIT(L,BIT)==k)
        {
            return L;
        }
        if(query_BIT(R,BIT)==k)
        {
            return R;
        }
        return -1;
    }
    int mid=(L+R)/2;
    if(query_BIT(mid,BIT)<k)
    {
        L=mid+1;
    }
    else
    {
        R=mid;
    }
    return findAns(L,R,k,BIT);

}
int main()
{
    int n;
    cin>>n;
    vector<data> vs(n),ve(n);
    vector<l> buff(n);
    for(int i=0;i<n;++i)
    {
        cin>>vs[i].val>>ve[i].val;
        vs[i].sz=ve[i].sz=ve[i].val-vs[i].val+1;
    }
    sort(vs.begin(),vs.end(),comp_by_sz);
    sort(ve.begin(),ve.end(),comp_by_sz);
    for(int i=0;i<n;++i)
    {
        vs[i].pos=ve[i].pos=i;
        buff[i]=ve[i].sz;
//        cout<<buff[i]<<" ";
    }
    sort(vs.begin(),vs.end(),comp_by_val);
    sort(ve.begin(),ve.end(),comp_by_val);
    int q;
    cin>>q;
    vector<data> vq(q);
    for(int i=0;i<q;++i)
    {
        cin>>vq[i].sz>>vq[i].val;
        vq[i].pos=i;
    }
    sort(vq.begin(),vq.end(),comp_by_val);
    int j=0,k=0;
    int BIT[1000001]={0};
    l ans[q];
    for(int i=0;i<q;++i)
    {
        while(j<n && vs[j].val<=vq[i].val)
        {
            update_BIT(vs[j].pos+1,BIT,n,1);
            ++j;
        }
        while(k<n && ve[k].val<vq[i].val)
        {
            update_BIT(ve[k].pos+1,BIT,n,-1);
            ++k;
        }
        int res=findAns(1,n,vq[i].sz,BIT);
        if(res==-1)
        {
            ans[vq[i].pos]=-1;
        }
        else
        {
            // cout<<"Res:"<<res<<endl;
            ans[vq[i].pos]=buff[res-1];
        }
    }
    for(int i=0;i<q;++i)
    {
        cout<<ans[i]<<"\n";
    }

}