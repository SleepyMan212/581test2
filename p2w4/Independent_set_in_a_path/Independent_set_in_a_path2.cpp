#include "bits/stdc++.h"
using namespace std;
int weight[1007];
deque<int> G[1007];
int vis[1007];
int max_value;

int main(int argc, char const *argv[]) {
  freopen("DP_indepOnPath.in","r",stdin);
  int value[1007];
  int n;
  while (cin>>n&&n) {
    memset(weight,0,sizeof(weight));
    for(int i=0; i<n; i++){
      cin>>weight[i];
    }
    max_value=-1e9;
    memcpy(value,weight,sizeof(weight));
    for(int i=0; i<n; i++){
      for(int j=i+2; j<n; j++){
        value[j]=max(value[j],weight[j]+value[i]);
      }
      // for(int t=0; t<n; t++) cout<<value[t]<<" ";
      // cout<<endl;
    }
    cout<<*max_element(value,value+n)<<endl;
  }
  return 0;
}
