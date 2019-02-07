/*
 * SPARSE MATRIX FOR LCA APPLICATION
 * Link:https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/optimal-connectivity-c6ae79ca/description/
 * References:
 *  >>https://www.geeksforgeeks.org/lca-for-general-or-n-ary-trees-sparse-matrix-dp-approach-onlogn-ologn/
 *  >>Tushar Roy RMQ using Sparse Table
 *  >>https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/
 *  >>https://www.hackerearth.com/submission/22432756/
 *
 * */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mkp(a,b) make_pair(a,b)
#define PI 3.14159265359
#define MAXN 5000005
#define mset(arr,val) memset(arr,val,sizeof arr)
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

void dfs(int root,int par,vector<pll> nbs[],int rmq[][30],ll wt[][30],int level[])
{
    //storing the 1st level parent for each node
    rmq[root][0]=par;

    level[root]=level[par]+1;
    for(auto i:nbs[root])
    {
        if(i.first!=par)
        {
            //adding weight for one level connection between a parent
            // and a child
            wt[i.first][0]=i.second;
            dfs(i.first,root,nbs,rmq,wt,level);
        }
    }
}

ll lca(int u,int v,int rmq[][30],ll wt[][30],int level[],int lim)
{
    if(level[u]>level[v]) swap(u,v);


    int diff=level[v]-level[u];
    ll ans=0;

    //simple logic to bring the node v to same level
    for(int i=0;i<=lim;++i)
    {
        if((diff&1))
        {
            ans=max(ans,wt[v][i]);
            v=rmq[v][i];
        }
        diff/=2;
    }

    if(u==v) return ans;

    for(int i=lim;i>=0;--i)
    {
        //the if loop below is sensible because all parents higher than lca for u and v have same value
        if(rmq[u][i]!=rmq[v][i])
        {
            //max in range of both u's and v's 2^ith parent
            ans=max(ans,max(wt[u][i],wt[v][i]));
            u=rmq[u][i];
            v=rmq[v][i];
        }
    }
    //since after the above loop we reach to the immediate children of lca
    return max(ans,max(wt[u][0],wt[v][0]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    int n;
    cin>>n;
    vector<pll> nbs[n+1];
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--;
        v--;
        nbs[u].eb(v,w);
        nbs[v].eb(u,w);
    }
    //column size
    int lim=(int)ceil(log2((ld)n));

    int rmq[n+1][30],lvl[n+1]={0};
    ll wt[n+1][30];
    mset(rmq,0);
    mset(wt,0);

    dfs(0,0,nbs,rmq,wt,lvl);

    //preprocessing: we store 2^ith parent in rmq and the max value along the path from
    //current to that parent
    for(int i=1;i<=lim;++i)
    {
        for(int j=0;j<n;++j)
        {
            rmq[j][i]=rmq[rmq[j][i-1]][i-1];
            //2^(i-1)th parent of 2^(i-1)th parent=2^ith parents
            wt[j][i]=max(wt[j][i-1],wt[rmq[j][i-1]][i-1]);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--;
        v--;
        ll ans=lca(u,v,rmq,wt,lvl,lim);
        if(ans>w) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}