#include "bits/stdc++.h"
using namespace std;
int max_value;
deque<int> G[5007];
int weight[5007];
bool v[5007];
void DFS(int n){
  if(weight[n]>max_value) max_value=weight[n];
  for(int i=0; i<G[n].size(); i++){
    if(!v[G[n][i]]){
      v[G[n][i]]=true;
      DFS(G[n][i]);
    }
  }
}
int main(int argc, char const *argv[]) {
  int n,m,t;

  std::vector<int> statrCity;
  while (cin>>n>>m>>t&&n&&m&&t) {
    statrCity.clear();
    memset(v,0,sizeof(v));
    for(int i=0; i<5007; i++) G[i].clear();
    int tmp;
    for(int i=0; i<t; i++){
      cin>>tmp;
      statrCity.push_back(tmp);
    }
    for(int i=0; i<n; i++) cin>>weight[i];
    int a,b;
    for(int i=0; i<m; i++){
      cin>>a>>b;
      G[a].push_back(b);
    }
    max_value=-1e9;
    for(int i=0; i<statrCity.size(); i++){
      if(!v[statrCity[i]]){
        v[statrCity[i]]=true;
        DFS(statrCity[i]);
      }
    }
    cout<<max_value<<endl;
  }
  return 0;
}
