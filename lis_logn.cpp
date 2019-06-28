/*
 * Reference : GeeksforGeeks
 * */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mkp(a,b) make_pair(a,b)
#define PI 3.14159265359
#define mset(arr,val) memset(arr,val,sizeof arr)
#define MAXN (ll)2e5+1
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

int getLIS(vector<ll> a) {
    int n = a.size();
    int last[n];
    int len = 0;
    int prev[n];
    mset(prev,-1);
    last[0]=0;
    for(int i=1;i<n;++i) {
        int start = 0;
        int end = len;
        int match = -1;
        while(start<=end) {
            int mid = (start + end)/2;
            if(a[last[mid]]<a[i]) {
                match = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        if(match == -1) {
            prev[i] = -1;
            last[0] = i;
        } else {
            prev[i] = last[match];
            last[match+1] = i;
            if(match == len) ++len;
        }
    }
    return len+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;++i) {
            cin>>a[i];
        }
        cout<<getLIS(a)<<endl;
    }

    return 0;
}