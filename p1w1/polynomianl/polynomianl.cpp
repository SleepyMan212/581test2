#include "bits/stdc++.h"
using namespace std;
void print(int ans[][22],int e){
  int i;
  for(i=21; ans[e][i]==0; i--);
  for(;i>0; i--){
    cout<<ans[e][i]<<" ";
  }
  cout<<ans[e][0];
}
void slove(){
  int poly[3];
  int ans[10][22]={0};
  int e;
  ans[0][0]=1;
  cin>>poly[2]>>poly[1]>>poly[0]>>e;
  for(int i=0; i<e; i++){
    for(int j=0;ans[i][j]!=0; j++){
      for(int k=2; k>=0; k--){
          ans[i+1][j+k]+=ans[i][j]*poly[k];
      }
    }
    // print(ans,i);
    cout<<endl;
  }
  print(ans,e);
}

int main(int argc, char const *argv[]) {
  int nCase;
  cin>>nCase;
  while (nCase) {
    slove();
    if(nCase)cout<<endl;
  }
  return 0;
}
