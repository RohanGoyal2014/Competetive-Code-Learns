/*
 * Question: https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
 *
 * Approach Used:Tarjan's Algorithm
 * Links:
 * https://www.youtube.com/watch?v=TyWtx7q2D7Y
 *
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

int currTime=1;
set<int> st;
void dfs(int root,vector<int> nbs[],stack<int> &stk,int onStack[],int disc_time[],int low[]) {
    disc_time[root]=low[root]=currTime;
    ++currTime;
    onStack[root]=1;
    stk.push(root);
    for(auto i:nbs[root]) {
        if(disc_time[i]==0) {
            dfs(i,nbs,stk,onStack,disc_time,low);
            low[root]=min(low[root],low[i]);
        } else if(onStack[i]) {
            low[root]=min(low[root],disc_time[i]);
        }
    }
    if(disc_time[root]==low[root]) {
        vector<int> tmp;
        while(stk.top()!=root) {
            int curr=stk.top();
            stk.pop();
            onStack[curr]=0;
            tmp.eb(curr);
        }
        onStack[stk.top()]=0;
        stk.pop();
        tmp.eb(root);
        if(tmp.size()>1) {
            for(auto i:tmp) {
                st.insert(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    int n,m;
    cin>>n>>m;
    vector<int> nbs[n+1];
    for(int i=0;i<m;++i) {
        int u,v;
        cin>>u>>v;
        nbs[u].eb(v);
    }

    int onStack[n+1]={0};
    stack<int> stk;
    int low[n+1]={0};
    int disc_time[n+1]={0};
    for(int i=1;i<=n;++i) {

        if(disc_time[i]==0) dfs(i,nbs,stk,onStack,disc_time,low);
    }
    for(int i=1;i<=n;++i) {
        if(st.find(i)!=st.end()) cout<<"1 ";
        else cout<<"0 ";
    }

    return 0;
}