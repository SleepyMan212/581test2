#include "bits/stdc++.h"
using namespace std;
#ifndef MAXIMUM
#define MAXIMUM 0x3f3f3f3f
#endif
int cost[1007][1007];
int len,num,cut_node[1007];
int dp(int l,int r){
  if(cost[l][r]!=0x3f3f3f3f) return cost[l][r];
  bool is_fund=false;
  for(int i=0; i<num; i++){
    if(cut_node[i]>l&&cut_node[i]<r){
      is_fund=true;
      cost[l][r]=min(cost[l][r],dp(l,cut_node[i])+dp(cut_node[i],r)+r-l);
    }
  }
  if(!is_fund) cost[l][r]=0;
  return cost[l][r];
}
int main(int argc, char const *argv[]) {
  while (cin>>len&&len) {
    cin>>num;
    for(int i=0; i<num; i++) cin>>cut_node[i];
    memset(cost,MAXIMUM,sizeof(cost));
    cout<<"The minimum cutting is "<<dp(0,len)<<"."<<endl;

  }
  return 0;
}
