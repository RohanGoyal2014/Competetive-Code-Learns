#include <bits/stdc++.h>
using namespace std;
typedef unsigned long l;
typedef long double ld;
void quick_sort(vector<int> &v,int start,int end)
{
    int pivot=end;
    end--;
    int i=start-1;
    for(int j=start;j<=end;++j)
    {
        if(v[j]<=v[pivot])
        {
            ++i;
            swap(v[i],v[j]);
        }
    }
    swap(v[pivot],v[i+1]);
    if(end-start+1>=2)
    {
        if(start<=i)
        {
            quick_sort(v,start,i);
        }
        if(i+2<=pivot)
        {
            quick_sort(v,i+2,pivot);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    quick_sort(v,0,v.size()-1);
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
