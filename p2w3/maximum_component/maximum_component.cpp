#include "bits/stdc++.h"
#include <map>
using namespace std;
#ifndef MAX
#define MAX 50007
#endif
int weight[MAX];
deque <int>G[MAX*2];
bool vis[MAX];
int max_sum;
map<pair<int,int>,int> mp;
map<pair<int,int>,int> dmp;
void DFS(int n,int sum){

  if(sum>max_sum) max_sum=sum;
  for(int i=0; i<G[n].size(); i++){
    // pair <int,int> p(n>G[n][i]?n:G[n][i],n>G[n][i]?G[n][i]:n);
    pair <int,int> p(n,G[n][i]);
    if(dmp.at(p)){
      std::cout <<G[n][i]<<" "<<sum+weight[G[n][i]]<< '\n';
      dmp[p]--;
      DFS(G[n][i],sum+weight[G[n][i]]);
    }
  }
}
int main(int argc, char const *argv[]) {
  int nCase;
  // std::map<key, valu> map;

  cin>>nCase;
  while (nCase--) {
    max_sum=-1e9;
    mp.clear();
    int node_num,edge_num;
    cin>>node_num>>edge_num;
    for (size_t i = 0; i < node_num; i++){
      cin>>weight[i];
      vis[i]=false;
    }

    for (size_t i = 0; i < edge_num; i++) {
      int a,b;
      cin>>a>>b;
      // G[b].push_back(a);
      // if(G[a].find(b)==-1)
        // G[a].push_back(b);
      // pair<int,int> p(a>b?a:b,a>b?b:a);
      pair <int,int> p(a,b);
      if(!mp.count(p)){
        mp[p]=0;
      }
      mp[p]++;
    }
    for (auto& x: mp) {
      G[x.first.first].push_back(x.first.second);
      G[x.first.second].push_back(x.first.first);
      // cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
       // std::cout << x[i] << ": " << x[i] << '\n';
       // cout<<mp<<endl;
    }
    // cout<<mp.size()<<endl;
    // int a=1;
    // for (int i = 0; i < mp.size(); i++) {
    //   cout<<mp.first;
    // }
    for (int i = 0; i < node_num; i++){
      // if(!vis[i]){
      //   vis[i]=true;
        dmp=mp;
        std::cout << "===================" << '\n';
        // DFS(i,weight[i]);
        // cout<<i<<" "<<max_sum<<endl;
        DFS(i,0);
        std::cout << "===================" << '\n';

      // }
    }
    cout<<max_sum;
    if(nCase) puts("");
    for (size_t i = 0; i < node_num; i++) G[i].clear();
  }
  return 0;
}
