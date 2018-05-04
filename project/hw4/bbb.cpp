#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define w first
#define from second.first
#define to second.second
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> G;
int par[1001],num[1001];
int findPar(int x){
  return x==par[x]?x:(par[x]=findPar(par[x]));
}
void solve(){
  // initializing
  G.clear();
  int n,e;
  cin>>n>>e;
  for(int i=0; i<n; i++){
    num[i]=1;
    par[i]=i;
  }
  int a,b,w;
  for(int i=0; i<e; i++){
    cin>>a>>b>>w;
    G.push_back(make_pair(w,make_pair(a,b)));
  }
  // priority_queue<iii,vector<iii>,greater<iii> > pq;
  sort(G.begin(),G.end(),greater<iii>());
  int edge=0,sum=0;
  for(int i=0; i<e&&edge<n-1; i++){
    int a=findPar(G[i].from);
    int b=findPar(G[i].to);
    if(a!=b){
      if(num[a]>num[b]){
        par[b]=a;
        num[a]+=b;
      }else{
        par[a]=b;
        num[b]+=a;
      }
      // cout<<"WWWW "<<G[i].w<<endl;
      sum+=G[i].w;
      edge++;
    }
  }
  if(edge!=n-1){
    cout<<"-1"<<endl;
  }else{
    cout<<sum<<endl;
  }
}
int main(int argc, char const *argv[]) {
  int nCase;
  cin>>nCase;
  while (nCase--) {
    solve();
  }
  return 0;
}
