/*
 * Game Theory : Grundy Numbers
 * Link: All 4 sets of GeeksforGeeks
 * Question : https://www.hackerearth.com/problem/algorithm/strong-contender-5b885a78/
 *
 *
 * */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mkp(a,b) make_pair(a,b)
#define PI 3.14159265359
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

const int N=(int)1e5;
int grundy[N+1];

int getGrundy(int num) {
    if(num<=N) return grundy[num];
    return getGrundy((int)sqrt(num))+1;
}

ll getMinReq(int nimsum) {
    ll curr=2;
    int sumSoFar=2;
    while(sumSoFar++<nimsum) {
        curr=curr*curr;
    }
    return curr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    grundy[0]=0;
    grundy[1]=1;
    for(int i=2;i<=N;++i) {
        grundy[i]=grundy[(int)sqrt(i)]+1;
    }
//    cout<<getMinReq(5);
//    return 0;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        int nimsum = 0;
        for (int i = 0; i < n; ++i) {
            int u;
            cin >> u;
            int gr=getGrundy(u);
            nimsum ^= gr;
        }
        if(nimsum==1) {
            cout<<"1\n";
        } else if(nimsum==0) {
            cout<<"0\n";
        } else {
            cout<<getMinReq(nimsum)<<"\n";
        }
    }

    return 0;
}