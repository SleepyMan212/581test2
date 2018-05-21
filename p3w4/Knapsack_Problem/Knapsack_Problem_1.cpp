
#include "bits/stdc++.h"
#define INF 100000007
// #define INF 10
using namespace std;
typedef long long ll;
int item_num;
int least_item,up,down;
int is_continue=0;
ll dp[INF];
int cnt[INF];

vector<pair<ll,ll> > item;
void init(){
  item.clear();
  memset(dp,0,sizeof(dp));
  memset(cnt,0,sizeof(cnt));
  // dp[0]=1;
}
void sol(){
  cin>>item_num>>least_item>>down>>up;
  ll v,w;
  for(int i=0; i<item_num; i++){
    cin>>v>>w;
    item.push_back(make_pair(w,v));
  }
  float ans=0;
  for(int i=0; i<1<<item_num; i++){
    if(__builtin_popcount(i)<least_item)
      continue;
  float total_value=0,total_weight=0;
    for(int j=0; j<item_num; j++){
      if((i>>j)&1){
        total_value+=item[j].second;
        total_weight+=item[j].first;
      }
    }
    if(down<=total_weight&&total_weight<=up)
      ans=max(ans,ceil(total_value / total_weight));
  }
  if(ans==0){
    cout<<"-1"<<endl;
  }else{
    cout<<ans<<endl;
  }
  // cout<<"==============="<<endl;
}
int main(int argc, char const *argv[]) {
  do{
    init();
    sol();



    cin>>is_continue;
  }while (is_continue==0);
  return 0;
}
/*
2 1 1 18
1 1
2 1
0
3 2 1 20
1 1
1 1
1 1
-1
*/
