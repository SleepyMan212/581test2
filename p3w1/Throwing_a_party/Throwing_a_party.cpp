#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  // dp[i][0] is a tree,then root=i and not select node i
  // dp[i][1] is a tree,then root=i and select node i
  int par[n+1],dp[n+1][2]={0},deg[n+1]={0};
  bool vis[n+1]={0};
  for(int i=1; i<=n; i++) par[i]=i;
  cin>>dp[1][1];
  for(int i=2; i<=n; i++){
    cin>>par[i]>>dp[i][1];

    deg[par[i]]++;
  }
  queue<int> q;
  for(int i=2; i<=n; i++){
    if(deg[i]==0)
      q.push(i);
  }
  int last=q.front();
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    dp[par[u]][0]+=max(dp[u][0],dp[u][1]);
    dp[par[u]][1]+=dp[u][0];
    deg[par[u]]--;
    if(deg[par[u]]==0&&par[u]!=1) q.push(par[u]);
  }

  cout<<max(dp[1][0],dp[1][1]);
}
int main(int argc, char const *argv[]) {
  int nCase;
  cin>>nCase;
  while (nCase--) {
    solve();
    if(nCase) puts("");
  }
  return 0;
}
