/*
 * Question: https://codeforces.com/contest/1131/problem/F
 * dsu using weighted union method in linked list representation of dsu.
 * First element contains length and last element apart from next and first.
 * This list is actually a circular list
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

class data {
public:
    int next,first=-1,last,len;
    data()= default;
    data(int next, int first, int last,int len) : next(next), first(first), last(last), len(len){}

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    int n;
    cin>>n;
    data lst[n+1];
    for(int i=1;i<=n;++i) {
        lst[i]=data(i,i,i,1);
    }
    for(int i=0;i<n-1;++i) {
        int u,v;
        cin>>u>>v;
        int firstu=lst[u].first;
        int lenu=lst[firstu].len;
        int firstv=lst[v].first;
        int lenv=lst[firstv].len;
        int lastv=lst[firstv].last;
        int lastu=lst[firstu].last;
        if(lenu<lenv) {
            lst[firstv].len+=lenu;
            lst[firstv].last=lastu;
            lst[lastv].next=firstu;
            lst[lastu].next=firstv;
            int curr=firstu;
            while(curr!=firstv) {
                lst[curr].first=firstv;
                curr=lst[curr].next;
            }
        } else {
            lst[firstu].len+=lenv;
            lst[firstu].last=lastv;
            lst[lastu].next=firstv;
            lst[lastv].next=firstu;
            int curr=firstv;
            while(curr!=firstu) {
                lst[curr].first=firstu;
                curr=lst[curr].next;
            }
        }
    }
    int curr=lst[1].first;
    int first=curr;
    cout<<first<<" ";
    curr=lst[curr].next;
    while(curr!=first) {
        cout<<curr<<" ";
        curr=lst[curr].next;
    }

    return 0;
}