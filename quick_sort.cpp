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
//    for(int i=0;i<v.size();++i)
//    {
//        cout<<v[i]<<" ";
//    }
    cout<<endl;
    if(end-start>=2)
    {
        quick_sort(v,start,i);
        quick_sort(v,i+2,pivot);
    }
}
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
    vector<int> v={5,3,1,8,6,8,6,9,4};
    quick_sort(v,0,v.size()-1);
    return 0;
}