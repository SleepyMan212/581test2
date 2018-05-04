#include "bits/stdc++.h"
using namespace std;
deque<int> G[5007];
int vis[5007];
map<pair<int,int>,int> edge;
int weight[5007];
int par[5007];
int sum;
// double timeStart, timeEnd;
void DFS(int n,int value){
  sum+=value;
  for(int i=0; i<G[n].size(); i++){
    if(!vis[G[n][i]]){
      vis[G[n][i]]=1;
      DFS(G[n][i],value+edge[make_pair(G[n][i],n)]);
    }
  }
}
int main(int argc, char const *argv[]) {
  freopen("graph_distanceTree2.in","r",stdin);
  int nCase,n;
  // timeStart = clock();
  cin>>nCase;
  while (nCase--) {
    cin>>n;
    memset(vis,0,sizeof(vis));
    memset(weight,0,sizeof(weight));
    memset(par,0,sizeof(par));
    for(int i=0; i<5007; i++)G[i].clear();
    int tmp;
    for(int i=2; i<=n; i++){
      cin>>tmp;
      par[i]=tmp;
      G[i].push_back(tmp);
      G[tmp].push_back(i);
    }
    for(int i=1;i<n; i++){
    //   cin>>tmp;
      cin>>weight[i];
    //   edge[make_pair(i,par[i])]=tmp;
    //   edge[make_pair(par[i],i)]=tmp;
    }
    sum=0;
    for(int i=1; i<n; i++){
      if(par[n-i]=n)
      sum+=(2*n*(n-i)*weight[n-i]);
    }
    cout<<sum;
    if(nCase) puts("");
  }
  // timeEnd = clock();
  return 0;
}
