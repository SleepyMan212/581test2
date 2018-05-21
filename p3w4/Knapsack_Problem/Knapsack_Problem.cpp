/*
  This programe is not AC is TLE
*/

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
bool comp(const pair<int,int> &a,const pair<int,int> &b ){
  if(a.first==b.first) return a.second>b.second;

  return a.first<b.first;
}
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
  sort(item.begin(),item.end(),comp);
  // for(auto i:item){
  //   cout<<i.first<<" "<<i.second<<endl;
  // }
  ll ans=0;
  for(int i=0; i<item_num; i++){
    for(int j=INF-1;j>=item[i].first; j--){
      if(dp[j-item[i].first]+item[i].second>dp[j]){
        dp[j]=dp[j-item[i].first]+item[i].second;
        // cnt[j]=max(cnt[j],cnt[j-wei]+1);
        cnt[j]++;
        // cout<<"dp[j]:"<<dp[j]<<"cnt[j]:"<<cnt[j]<<endl;
        // cout<<up<<" "<<down<<endl;;
        if(dp[j]>down&&dp[j]<up&&least_item<=cnt[j])
          ans=max(ans,dp[j]/cnt[j]);
      }
    }
  }
  // ll sum=0;
  // for(int i=up+1; i<down; i++){
  //   sum=dp[i]/cnt[i];
  // }
  // cout<<"==============="<<endl;
  if(ans==0){
    cout<<"-1"<<endl;
  }else{
    cout<<ans<<endl;
  }
  // cout<<"==============="<<endl;
}
int main(int argc, char const *argv[]) {
  freopen("DP_knapsack.in","r",stdin);
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
