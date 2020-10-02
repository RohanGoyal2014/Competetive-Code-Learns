#include <bits/stdc++.h>
using namespace std;

void shell_sort(int a[], int n)
{
  // Starting with gap n/2
  int gap = n/2;
  while(gap>=1)
  {
    for(int i=0,j=gap;j<n;j++)
    {
      for(int k=j;k-gap>=0 && a[k]<a[k-gap];k-=gap)
      {
        swap(a[k],a[k-gap]);
      }
    }
    // Reducing the gap by half
    gap /= 2;
  }
}

int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  shell_sort(a,n);
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}
