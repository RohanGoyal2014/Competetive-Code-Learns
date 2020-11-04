/*
 * Bridges in a graph
 * Link:https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-hackerearth-3/description/
 * For tutorial refer to Tushar Roy and William Fiset
 * https://www.youtube.com/watch?v=K2rkXGltHXQ
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

int currTime=0;
set<pii> bridges;
void dfs(int root,int parent,bool visited[],int low[],int disc_time[],vector<int> nbs[])
{
    visited[root]=true;
    low[root]=disc_time[root]=currTime;
    ++currTime;
    for(auto i:nbs[root])
    {
        if(i==parent)
        {
            continue;
        }
        if(!visited[i])
        {
            dfs(i,root,visited,low,disc_time,nbs);
            low[root]=min(low[root],low[i]);
            if(disc_time[root]<low[i])
            {
                //had it been greater, back edge would have existed
                bridges.insert({root,i});
            }
        }
        else
        {
            low[root]=min(low[root],low[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    int n,m;
    cin>>n>>m;
    vector<pii> edges(m);
    vector<int> nbs[n];
    int disc_time[n],low[n];
    bool vis[n]={0};
    for(int i=0;i<m;++i)
    {
        cin>>edges[i].first>>edges[i].second;
        edges[i].first--;
        edges[i].second--;
        nbs[edges[i].first].eb(edges[i].second);
        nbs[edges[i].second].eb(edges[i].first);
    }
    //Graph is initially disconnected so we loop through vertices
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        dfs(i, -1, vis, low, disc_time, nbs);
    }

    int q;
    cin>>q;
    while(q--)
    {
        int edge;
        cin>>edge;
        edge--;
        int mem1=edges[edge].first;
        int mem2=edges[edge].second;
        if(bridges.find({mem1,mem2})!=bridges.end() || bridges.find({mem2,mem1})!=bridges.end())
        {
            cout<<"Unhappy\n";
        }
        else
        {
            cout<<"Happy\n";
        }
    }

    return 0;
}
