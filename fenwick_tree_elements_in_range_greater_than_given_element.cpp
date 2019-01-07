/*
 * Fenwick Tree to find how many elements in range are greater than the given element
 * Question:https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/vanya-and-array-4/description/
 *
 * Note: This solution used compression(using pos which was set to interating index i to identify the array as it is as in
 * the sequence given as input) since value of a is very large
 *
 *
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

class node
{
public:
    ll val;
    int pos;
    int type;
    node()= default;

    node(ll val, int pos, int type)
    {
        this->val=val;
        this->pos=pos;
        this->type=type;
    }
};

bool comp(node a,node b)
{
    if(a.val==b.val)
    {
        //we process current value after the query of current
        //since we do not require current value to be included
        return a.type>b.type;
    }
    return a.val>b.val;
}

void updateBIT(int index,int BIT[],int val,int n)
{
    //index is actually 1 based
    index++;
    while(index<=n)
    {
        BIT[index]+=val;
        index+=index&(-index);
    }
}

int queryBIT(int index,int BIT[])
{
    int ans=0;
    index++;
    while(index>0)
    {
        ans+=BIT[index];
        index-=index&(-index);
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

    int n;
    ll k;
    cin>>n>>k;
    ll a[n];
    vector<node> v;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        v.eb(node(a[i],i,0));
        v.eb(node(a[i],i,1));
    }
    sort(v.begin(),v.end(),comp);
    int BIT[n+1]={0};
    int f[n]={0};
    for(int i=0;i<v.size();++i)
    {
        if(v[i].type==0)
        {
            updateBIT(v[i].pos,BIT,1,n);
        }
        else
        {
            f[v[i].pos]=queryBIT(n-1,BIT)-queryBIT(v[i].pos,BIT);
        }
    }
    sort(f,f+n);
    ll ans=0;
    for(int i=0;i<n-1;++i)
    {
        ll req=k-f[i];
        int pos=lower_bound(f,f+n,req)-f;
        pos=max(pos,i+1);
        ans+=n-pos;
    }
    cout<<ans;

    return 0;
}