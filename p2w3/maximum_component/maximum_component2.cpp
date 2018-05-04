#include "bits/stdc++.h"

using namespace std;
#ifndef MAX
#define MAX 50007
#endif
int max_sum;
vector<int> G[MAX];
bool vis[MAX];
int weight[MAX];
int sum;
void DFS(int n){
  sum+=weight[n];
  if(sum>max_sum) max_sum=sum;
  for (size_t i = 0; i <G[n].size(); i++) {
    if(!vis[G[n][i]]){
      vis[G[n][i]]=true;
      DFS(G[n][i]);
    }
  }
}
int main(int argc, char const *argv[]) {
  int nCase;
  int node_num,edge_num;
  cin>>nCase;
  while (nCase--) {
    max_sum=-1e9;
    cin>>node_num>>edge_num;
    for (size_t i = 0; i < node_num; i++){
      cin>>weight[i];
      G[i].clear();
      vis[i]=0;
    }
    for (size_t i = 0; i < edge_num; i++) {
      int a,b;
      cin>>a>>b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    for (size_t i = 0; i < node_num; i++) {
        sum=0;
        if(!vis[i]){
          vis[i]=true;
          DFS(i);
        }
    }
    cout<<max_sum;
    if (nCase) puts("");
  }
  return 0;
}
