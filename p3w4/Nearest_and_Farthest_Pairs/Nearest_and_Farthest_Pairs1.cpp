#include "bits/stdc++.h"
using namespace std;
bool p[2000];
std::vector<pair<pair<int,int>,int> > min_pair;
int main(int argc, char const *argv[]) {
  int n;
  while (cin>>n&&n) {
    int tmp;
    int min_a,min_b,min_num=1e9;
    for(int i=0; i<2000; i++) p[i]=-1;
    // cout<<p[0]<<endl;
    for(int i=0; i<n; i++){
      cin>>tmp;
      if(p[tmp]==-1) p[tmp]=i;
      else{
        if(i-p[tmp]<min_num){
          cout<<i<<" "<<p[tmp]<<endl;
          min_num=i-p[tmp];
          min_a=p[tmp];
          min_b=i;
          p[tmp]=i;
        }
      }
    }
    if(min_num==1e9)
      min_pair.push_back(make_pair(make_pair(0,0),0));
    else
      min_pair.push_back(make_pair(make_pair(min_a,min_b),p[min_a]));
  }
  cout<<"For problem 19:\n\n";
  for(int i=0; i<min_pair.size(); i++){
    cout<<i<<" ";
    if(min_pair[i].first.first==0&&min_pair[i].first.second==0) cout<<"No solution"<<endl;
    else cout<<"("<<min_pair[i].first.first<<","<<min_pair[i].first.second<<"):"<<min_pair[i].second<<endl;;
  }
  return 0;
}
