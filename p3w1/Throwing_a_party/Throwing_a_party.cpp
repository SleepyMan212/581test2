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
  // memset(dp,0,sizeof(dp));
  // cout<<dp[2][1]<<endl;
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
    // if(last!=u){
    //   dp[par[last]][1]+=w[par[last]];
    //   last=u;
    // }
    dp[par[u]][0]+=max(dp[u][0],dp[u][1]);
    dp[par[u]][1]+=dp[u][0];
    // cout<<"par[u] : "<<par[u]<<endl<<"0 : "<<dp[par[u]][0]<<endl<<"1 : "<<dp[par[u]][1]<<endl;
    deg[par[u]]--;
    if(deg[par[u]]==0&&par[u]!=1) q.push(par[u]);
  }
  // dp[par[last]][1]+=w[par[last]];
  // for(int i=n; i>1; i++){
  //   for(int j=n; j>1; j++){
  //     if(deg[n==0])
  //     int tmp=j;
  //     dp[par[tmp]][1]+=dp[tmp][0];
  //   }
  //   dp[par[tmp]][1]+=w[];
  // }
  // for(int i=n; i>1; i--){
  //
  //   if(!vis[i]){
  //   int tmp=i;
  //   // cout<<w[tmp]<<endl;
  //   dp[tmp][1]=w[tmp];
  //     while (par[tmp]!=tmp) {
  //       vis[tmp]=true;
  //       dp[par[tmp]][0]=max(dp[tmp][0],dp[tmp][1]);
  //       dp[par[tmp]][1]=(dp[tmp][0]+w[par[tmp]]);
  //       tmp=par[tmp];
  //     }
  //     // cout<<"AAW "<<dp[1][1]<<endl;
  //   }
  // }
  // for (size_t i = 0; i <=n; i++) {
    // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
  // }
  cout<<max(dp[1][0],dp[1][1]);
}
int main(int argc, char const *argv[]) {
  freopen("DP_indepTree.in","r",stdin);
  int nCase;
  cin>>nCase;
  while (nCase--) {
    solve();
    if(nCase) puts("");
  }
  return 0;
}
