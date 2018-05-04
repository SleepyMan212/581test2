#include "bits/stdc++.h"
using namespace std;
int num[1000000];

int main(int argc, char const *argv[]) {

  freopen("DP_Farthest.in","r",stdin);
  int n;
  vector<pair<pair<int,int>,int> > min_pair,max_pair;
  std::vector<pair<pair<int,int>,int> > table;
  while (cin>>n&&n) {
    int tmp;
    memset(num,0,sizeof(num));
    table.clear();
    for(int i=0; i<n; i++) cin>>num[i];

    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        if(i==j) continue;
        if(num[i]==num[j]){
          table.push_back(make_pair(make_pair(i,j),num[i]));
        }
      }
    }
    int max_a,max_b,max_index,max_num = -1e9;
    int min_a,min_b,min_index,min_num = 1e9;
    bool find_min=false,find_max=false;
    for(int i=0; i<table.size(); i++){
      int d=table[i].first.second-table[i].first.first;
      if(!find_max&&d>max_num){
        // find_max=true;
        max_num=d;
        max_a=table[i].first.first;
        max_b=table[i].first.second;
        max_index=table[i].second;
      }
      // if(!find_min&&d<min_num){
      //   // find_min=true;
      //   min_num=d;
      //   min_a=table[i].first.first;
      //   min_b=table[i].first.second;
      //   min_index=table[i].second;
      // }
      // if(find_max&&find_min) break;
    }
    // cout<<min_a<<" "<<min_b<<" "<<min_index<<endl;
    // if(min_num==1e9) min_pair.push_back(make_pair(make_pair(0,0),0));
    // else
    //   min_pair.push_back(make_pair(make_pair(min_a,min_b),min_index));
    if(max_num==-1e9) max_pair.push_back(make_pair(make_pair(0,0),0));
    else
      max_pair.push_back(make_pair(make_pair(max_a,max_b),max_index));


  }
  // cout<<"For problem 19:\n\n";
  // for(int i=0; i<min_pair.size(); i++){
  //   cout<<i<<" ";
  //   if(min_pair[i].first.first==0&&min_pair[i].first.second==0) cout<<"No solution"<<endl;
  //   else cout<<"("<<min_pair[i].first.first<<","<<min_pair[i].first.second<<"):"<<min_pair[i].second<<endl;;
  // }
  cout<<endl;
  cout<<"For problem 20:\n\n";
  for(int i=0; i<max_pair.size(); i++){
    if(max_pair[i].first.first==0&&max_pair[i].first.second==0) cout<<"No solution"<<endl;
    else cout<<"("<<max_pair[i].first.first<<","<<max_pair[i].first.second<<"):"<<max_pair[i].second<<endl;
  }

  return 0;
}
