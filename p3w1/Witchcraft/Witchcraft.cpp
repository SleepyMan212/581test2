#include "bits/stdc++.h"
using namespace std;
int cnt[3],wei[3];
bool vis[101][101][101];
bool is_find;
void DFS(int a, int b, int c, int tar, int value){
  if(tar<value||is_find||vis[a][b][c]) return;
  vis[a][b][c]=true;
  if(tar==value){
    cout<<"yes";
    is_find = true;
    return;
  }
  if(a<cnt[0]) DFS(a+1,b,c,tar,value+wei[0]);
  if(b<cnt[1]) DFS(a,b+1,c,tar,value+wei[1]);
  if(c<cnt[2]) DFS(a,b,c+1,tar,value+wei[2]);
}
void solve(){
  int target;
  cin>>target;
  is_find = false;
  memset(vis,0,sizeof(vis));
  for(int i=0; i<3; i++) cin>>cnt[i];
  for(int i=0; i<3; i++) cin>>wei[i];
  DFS(0,0,0,target,0);
  if(!is_find) cout<<"no";
}
int main(int argc, char const *argv[]) {

  int nCase;
  int i=0;
  cin>>nCase;
  while (nCase--) {
    cout<<++i<<": ";
    solve();

    if(nCase) cout<<endl;
  }
  return 0;
}
