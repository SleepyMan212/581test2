#include "bits/stdc++.h"

using namespace std;
int main(int argc, char const *argv[]) {
  int totalTri;
  int n;
  while (cin>>n&&n) {
    int edges[n];
    totalTri=0;


    for(int i=0; i<n; i++) cin>>edges[i];
    sort(edges,edges+n);

    for(int i=0; i<n; i++)
      for(int j=i+1; j<n;j++)
        for(int k=j+1; k<n; k++)
          if((edges[i]+edges[j])>edges[k])
            totalTri++;

    cout<<totalTri<<endl;
  }
  return 0;
}
