#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int> > min_pair,max_pair;
void solve(int n){
  int max_last[2001]={0};
  int min_last[2001]={0};
  int min_l,min_r,min_val=1e9,min_num;
  int max_l,max_r,max_val=-1e9,max_num;
  int tmp;
  for(int i=1; i<=n; i++){
    cin>>tmp;
    if(min_last[tmp]==0){
      min_last[tmp]=i;
    }else{
      if(min_val>i-min_last[tmp]){
        min_val=i-min_last[tmp];
        min_l=min_last[tmp];
        min_r=i;
        min_num=tmp;
      }
      min_last[tmp]=i;
    }
    if(max_last[tmp]==0){
      max_last[tmp]=i;
    }else{
      if(max_val<i-max_last[tmp]){
        max_val=i-max_last[tmp];
        max_l=max_last[tmp];
        max_r=i;
        max_num=tmp;
      }
      // max_last[tmp]=i;
    }
  }
  // cout<<max_l<<" "<<max_r<<" "<<max_num<<endl;
  if(min_val!=1e9)
    min_pair.push_back(make_pair(make_pair(min_l-1,min_r-1),min_num));
  else
    min_pair.push_back(make_pair(make_pair(0,0),0));
  if(max_val!=-1e9)
    max_pair.push_back(make_pair(make_pair(max_l-1,max_r-1),max_num));
  else
    max_pair.push_back(make_pair(make_pair(0,0),0));
}
int main(int argc, char const *argv[]) {
  int n;
  while (cin>>n&&n) {
    solve(n);
  }
  cout<<"For problem 19:\n\n";
  for(int i=0; i<min_pair.size(); i++){
    if(min_pair[i].first.first==0&&min_pair[i].first.second==0) cout<<"No solution"<<endl;
    else cout<<"("<<min_pair[i].first.first<<","<<min_pair[i].first.second<<"):"<<min_pair[i].second<<endl;;
  }
  cout<<endl;
  cout<<"For problem 20:\n\n";
  for(int i=0; i<max_pair.size(); i++){
    if(max_pair[i].first.first==0&&max_pair[i].first.second==0) cout<<"No solution"<<endl;
    else cout<<"("<<max_pair[i].first.first<<","<<max_pair[i].first.second<<"):"<<max_pair[i].second<<endl;
  }
  return 0;
}
