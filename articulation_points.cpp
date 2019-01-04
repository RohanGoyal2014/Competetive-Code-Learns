/*
 * Articulation Points in a graph
 * Link:https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/
 * For tutorial refer to GFG,Tushar Roy and William Fiset
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
set<int> articulationPoints;
void dfs(int root,int parent,bool visited[],int low[],int disc_time[],vector<int> nbs[])
{
    visited[root]=true;
    low[root]=disc_time[root]=currTime;
    ++currTime;
    int child=0;
    for(auto i:nbs[root])
    {
        if(i==parent)
        {
            continue;
        }
        if(!visited[i])
        {
            // incrementing child inside visited[i]==false block so that
            // only independent children are counted which are dependent on current node
            // for connectivity
            child++;
            dfs(i,root,visited,low,disc_time,nbs);
            low[root]=min(low[root],low[i]);
            if(parent==-1 && child>=2)
            {
                articulationPoints.insert(root);
            }
            else if(parent!=-1 && disc_time[root]<=low[i])
            {
                //implies that back edge does not exist
                articulationPoints.insert(root);
            }
        }
        else
        {
            low[root]=min(low[root],disc_time[i]);
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
    //looping because the graph may be disconnected iniatially
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        dfs(i, -1, vis, low, disc_time, nbs);
    }

    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        x--;
        if(articulationPoints.find(x)==articulationPoints.end())
        {
            cout<<"Not Satisfied\n";
        }
        else
        {
            cout<<"Satisfied "<<nbs[x].size()<<"\n";
        }
    }

    return 0;
}