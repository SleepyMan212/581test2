#include "bits/stdc++.h"
using namespace std;
int weight[1007];
deque<int> G[1007];
int vis[1007];
int max_value;
void DFS(int n,int sum){
  if(sum>max_value) max_value=sum;
  for (int i = 0; i < G[n].size(); i++) {
    if(!vis[G[n][i]]){
      vis[G[n][i]]=1;
      if(G[n][i]+1<n) vis[G[n][i]+1]=1;
      if(G[n][i]-1>=0) vis[G[n][i]-1]=1;
      DFS(G[n][i],sum+weight[G[n][i]]);
      // vis[G[n][i]]=0;
      // if(i+1<n) vis[G[n][i+1]]=0;
      // if(i-1>=0) vis[G[n][i-1]]=0;
    }
  }
}
int main(int argc, char const *argv[]) {
  freopen("DP_indepOnPath.in","r",stdin);
  int value[1007][1007];
  int n;
  while (cin>>n&&n) {
    memset(weight,0,sizeof(weight));
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++){
      cin>>weight[i];
    }
    max_value=-1e9;
    // vector<int> v[n];
    // bool is_finish=false;
    // while (!is_finish) {
      // cout<<"W"<<endl;
    //   max_value+=(*max_element(weight,weight+n));
    //   int t=max_element(weight,weight+n)-weight;
    //   vis[t]=1; weight[t]=0;
    //   if(vis[t+1]<n) vis[t+1]=1;
    //   if(vis[t-1]>=0) vis[t-1]=1;
    //   bool is_exit=false;
    //   for(int i=0; i<n; i++){
    //     if(vis[i]=0) is_exit=true;
    //   }
    //   if(is_exit) is_finish=true;
    // }
    // for (size_t i = 0; i < n; i++) {
    //   for(int j=i; j<n; j+=2){
    //     value[i][j]=max(value[i][j],value[i][j]+weight[j]);
    //
    //   }
    // }
    // int t=n*n;
    // for(int i=0; i<n; i++){
    //   max_value=max(max_value,*max_element(value[i],value[i]+n));
    // }
    // cout<<max_value<<endl;;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(!(j<=i+1&&j>=i-1))
          G[i].push_back(j);
      }
    }
    for(int i=0; i<n; i++){
      memset(vis,0,sizeof(vis));
      // if(!vis[i]){
        vis[i]=1;
        if(vis[i+1]<n) vis[i+1]=1;
        if(vis[i-1]>=0) vis[i-1]=1;
        DFS(i,weight[i]);
        // vis[i]=0;
        // if(vis[i+1]<n) vis[i+1]=0;
        // if(vis[i-1]>=0) vis[i-1]=0;
      // }
    }
    // cout<<max_value<<endl;
  }
  return 0;
}
