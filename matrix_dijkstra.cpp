//Matrix traversal from one point to another
//Uses dijkstra algorithm
//I tried first constructing adjacency but it consumed time
//so I found neighbours while computing
#include<bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator() (pair<long,pair<long,long>> a,pair<long,pair<long,long>> b)
    {
        return a.first>b.first;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,m,q;
    cin>>n>>m>>q;
    string a[n];
    for(long i=0;i<n;++i)
    {
        cin>>a[i];
    }
//    vector<pair<long,long>> v;
//    for(long i=0;i<n;++i)
//    {
//        for(long j=0;j<m;++j)
//        {
//            if(a[i][j]=='O')
//            {
//                v.emplace_back(make_pair(i,j));
//            }
//        }
//    }
    long sx,sy;
    cin>>sx>>sy;
    sx--;
    sy--;
    //dijkstra algo starts here:
    pair<long,long> src=make_pair(sx,sy);
    priority_queue<pair<long,pair<long,long>>,vector<pair<long,pair<long,long>>>,compare> pq;
    long long plen[1001][1001],ans[1001][1001];
    long count=0;
    for(long i=0;i<n;++i)
    {
        for(long j=0;j<m;++j)
        {
            if(a[i][j]=='O')
            {
                count++;
            }
            plen[i][j]=LONG_MAX;
            ans[i][j]=-1;
        }
    }
    pq.push(make_pair(0,src));
    plen[src.first][src.second]=0;
    long visited[1001][1001]={0};
    for(long it=0;it<count;++it)
    {
        pair<long,pair<long,long>> p=pq.top();
        //cout<<"Traversed:("<<p.second.first<<","<<p.second.second<<"):"<<p.first<<endl;
        visited[p.second.first][p.second.second]=1;
        pq.pop();
        ans[p.second.first][p.second.second]=p.first;
        pair<long,long> node=p.second;
        vector<pair<long,long>> nbs=
                {
                        make_pair(node.first,node.second-1),
                        make_pair(node.first,node.second+1),
                        make_pair(node.first-1,node.second),
                        make_pair(node.first+1,node.second)
                };
        for(long i=0;i<nbs.size();++i)
        {
            if(nbs[i].first==-1 || nbs[i].second==-1 || nbs[i].first==n || nbs[i].second==m)
            {
                continue;
            }
            else if(a[nbs[i].first][nbs[i].second]!='O')
            {
                continue;
            }
            if(visited[nbs[i].first][nbs[i].second]==0)
            {
                //else
                if (p.first + 1 < plen[nbs[i].first][nbs[i].second])
                {
                    //cout<<"Entered\n";
                    plen[nbs[i].first][nbs[i].second]= p.first + 1;
                    pq.push(make_pair(p.first+1,nbs[i]));
                }
            }
        }
    }
    while(q--)
    {
        long dx,dy;
        cin>>dx>>dy;
        dx--;
        dy--;
        if(dx==sx && dy==sy)
        {
            cout<<"0\n";
        }
        else
        {
            long it=ans[dx][dy];
            cout<<it<<endl;
        }
    }
}