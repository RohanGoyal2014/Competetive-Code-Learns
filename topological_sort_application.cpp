#include<bits/stdc++.h>
#define mkp(a,b) make_pair(a,b)
#define eb emplace_back
#define mod (long long)(1e9+7)
using namespace std;
typedef long long l;
typedef unsigned long ul;
typedef pair<l,l> pll;
typedef pair<int,int> pii;
typedef long double ld;

class data
{
public:
    int val;
    int d;
    int pi;
    data()= default;
    data(int val,int d,int pi)
    {
        this->val=val;
        this->d=d;
        this->pi=pi;
    }
};
class compare
{
public:
    bool operator() (data a,data b)
    {
        return a.d>b.d;
    }
};

void traverse(int root,int pi[],vector<int> nbs[],int visited[],int ins[],vector<int> mst[],set<pii> &directions)
{
    for(int i=0;i<mst[root].size();++i)
    {
        traverse(mst[root][i],pi,nbs,visited,ins,mst,directions);
    }
    visited[root]=1;
    for(int i=0;i<nbs[root].size();++i)
    {
        if(!visited[nbs[root][i]] && pi[root]!=nbs[root][i])
        {
            directions.insert(mkp(root,nbs[root][i]));
            ins[nbs[root][i]]++;
        }
    }
}
void traverse2(int root,vector<int> mst[],int ins[],int pi[],set<pii> &directions)
{
    for(int i=0;i<mst[root].size();++i)
    {
        traverse2(mst[root][i],mst,ins,pi,directions);
    }
//    cout<<"At "<<root<<endl;
    if(ins[root]%2==0)
    {
        if(root!=1)
        {
            directions.insert(mkp(root,pi[root]));
            ins[pi[root]]++;
        }
    }
    else
    {
        if(root!=1)
        {
            directions.insert(mkp(pi[root],root));
            ins[root]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> nbs[n+1],mst[n+1];
        vector<pii> edges;
        for(int i=0;i<m;++i)
        {
            int u,v;
            cin>>u>>v;
            nbs[u].eb(v);
            nbs[v].eb(u);
            edges.eb(u,v);
        }
        int visited[n+1]={0};
        int pi[n+1]={0};
        priority_queue<data,vector<data>,compare> pq;
        pq.push(data(1,0,-1));
        int d[n+1];
        for(int i=0;i<=n;++i)
        {
            d[i]=INT_MAX;
        }
        while(!pq.empty())
        {
            data curr=pq.top();
            pq.pop();
            if(visited[curr.val])
            {
                continue;
            }
            visited[curr.val]=1;
            if(curr.pi!=-1)
            {
                pi[curr.val]=curr.pi;
                mst[curr.pi].eb(curr.val);
            }
            for(int i=0;i<nbs[curr.val].size();++i)
            {
                if(!visited[nbs[curr.val][i]])
                {
                    pq.push(data(nbs[curr.val][i],1,curr.val));
                }
            }
        }
        set<pii> directions;
        memset(visited,0, sizeof(visited));
        int ins[n+1]={0};
        traverse(1,pi,nbs,visited,ins,mst,directions);
        traverse2(1,mst,ins,pi,directions);
        if(ins[1]%2==1)
        {
            cout<<"-1\n";
            continue;
        }
        for(auto i:edges)
        {
//            cout<<i.first<<" "<<i.second<<endl;
            if(directions.find(i)!=directions.end())
            {
                cout<<"0 ";
            }
            else
            {
                cout<<"1 ";
            }
        }
        cout<<endl;
    }

    return 0;
}