#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  // freopen("graph_diameter.in","r",stdin);
  int nCase;
  int num;
  cin>>nCase;
  int parent[100000];
  int len[100000];
  bool is_par[100000];
  while (nCase--) {
      cin>>num;
      // cout<<num<<"AA"<<endl;
      int par,chi;
      memset(parent,0,sizeof(parent));
      memset(is_par,0,sizeof(is_par));
      memset(len,0,sizeof(len));
      for(int i=0; i<num; i++) parent[i]=i;
      for(int i=0; i<num-1; i++){
        cin>>par>>chi;
        parent[chi]=par;
        is_par[par]=true;
      }
      cout<<"AAAAAAAAAAAAAAAAAAAA"<<endl;
      int h1=-1e9,h2=-1e9;
      for(int i=0; i<num; i++){
        if(!is_par[i]){
          int t=i;
          int l=0;
          while (parent[t]!=t) {
            l++;
            t=parent[t];
          }
          cout<<i<<" "<<l<<endl;
          if(l>h1){
            h2=h1;
            h1=l;
          }else if(l>h2) h2=l;
        }
      }
      cout<<h1+h2;
    if(nCase)puts("");
  }
  return 0;
}
