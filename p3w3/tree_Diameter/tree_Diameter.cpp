#include "bits/stdc++.h"
using namespace std;
queue<int> q;
int degree[100007];
int level[100007];
std::vector<int> G[100007];
int main(int argc, char const *argv[]) {
  int nCase;
  int num;
  cin>>nCase;
  while (nCase--) {
    memset(degree,0,sizeof(degree));
    memset(level,0,sizeof(level));
    cin>>num;
    for(int i=0; i<num; i++) G[i].clear();

    int a,b;
    for(int i=0; i<num-1; i++){
      cin>>a>>b;

      G[a].push_back(b);
      G[b].push_back(a);
      degree[a]++;
      degree[b]++;

    }
    for(int i=0; i<num; i++){
      if(degree[i]==1)
        q.push(i);
    }
    int maxlevel=-1e9;
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for(int i=0; i<G[v].size(); i++ ){
          int t=G[v][i];
          degree[t]--;
          if(degree[t]==1){
            q.push(t);
            level[t]=level[v]+1;
            maxlevel=max(maxlevel,level[t]);
          }
      }
    }
    int c=0;
    for(int i=0; i<num; i++){
      if(level[i]==maxlevel) c++;
    }
    // diameter(G)=level(G)*2+|c|-1
    cout<<maxlevel*2+c-1<<endl;
  }
  return 0;
}
/*
2
8
0 1
0 2
0 3
7 0
1 4
1 5
3 6
4
0 1
0 2
2 3
output
4
3
*/
