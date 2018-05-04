#include <bits/stdc++.h>
using namespace std;

void solve(){
  int num;
  int par[5001],w[5001],deg[5001],cnt[5001];
  fill(cnt,cnt+5001,1);
  cin>>num;
  for(int i=2; i<=num; i++){
    cin>>par[i];
    deg[par[i]]++;
  }
  for(int i=2; i<=num; i++) cin>>w[i];

  queue<int> q;

  for(int i=1; i<=num; i++){
    if(deg[i]==0)
      q.push(i);
  }
  int sum=0;
  while (!q.empty()) {
    int tmp=q.front();
    q.pop();
    sum+=((num-cnt[tmp])*cnt[tmp]*w[tmp]);
    deg[par[tmp]]--;
    cnt[par[tmp]]+=cnt[tmp];
    if(deg[par[tmp]]==0&&par[tmp]!=1)
      q.push(par[tmp]);
  }
  cout<<sum*2;
}
int main(int argc, char const *argv[]) {
  freopen("graph_distanceTree2.in","r",stdin);
  int nCase;
  cin>>nCase;
  while (nCase--) {
    solve();
    if(nCase) puts("");
  }
  return 0;
}
