/*
Innerve Summer18 :Skill Input
Concept Used:Sorted Segment Tree
*/

#include<bits/stdc++.h>
using namespace std;
void build_tree(long start,long end,long long a[],long node,multiset<long long> tree[])
{
    if(start==end)
    {
        tree[node].insert(a[start]);
        return;
    }
    long mid=(start+end)/2;
    build_tree(start,mid,a,2*node,tree);
    build_tree(mid+1,end,a,2*node+1,tree);
    tree[node].insert(tree[2*node].begin(),tree[2*node].end());
    tree[node].insert(tree[2*node+1].begin(),tree[2*node+1].end());
}
long long query_tree(long start,long end,long l,long r,long node,multiset<long long> tree[],long long k)
{
    // cout<<start<<" "<<end<<endl;
    if(l>end || r<start)
    {
        return LONG_LONG_MIN;
    }
    if(l<=start && end<=r)
    {
        auto it=tree[node].lower_bound(k);
        if(it==tree[node].end())
        {
            return *tree[node].rbegin();
        }
        if(it==tree[node].begin())
        {
            return *it;
        }
        it--;
        auto j=it;
        it++;
        if(k-*j<*it-k)
        {
            return *j;
        }
        return *it;
    }
    long mid=(start+end)/2;
    long long left=query_tree(start,mid,l,r,2*node,tree,k);
    long long right=query_tree(mid+1,end,l,r,2*node+1,tree,k);
    if(left==LONG_LONG_MIN)
    {
        return right;
    }
    if(right==LONG_LONG_MIN)
    {
        return left;
    }
    if(abs(left-k)<abs(right-k))
    {
        return left;
    }
    return right;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,q;
    cin>>n>>q;
    long long a[n];
    for(long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    multiset<long long> tree[10*n];
    build_tree(0,n-1,a,1,tree);
    while(q--)
    {
        long l,r;
        long long k;
        cin>>l>>r>>k;
        l--;
        r--;
        k=1000000000-k;
        long long closest=query_tree(0,n-1,l,r,1,tree,k);
        cout<<closest<<endl;
        // break;
    }
}
