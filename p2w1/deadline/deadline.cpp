/*
  first finish the deadline coming
*/
#include "bits/stdc++.h"
using namespace std;
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
  return a.second<b.second;
}
int main(int argc, char const *argv[]) {
  // freopen("greedy_deadline.in","r",stdin);
  int times;
  cin>>times;
  // while (cin>>times) {
    while (times--) {
      int n;
      cin>>n;
      int a[n],b[n];
      for(int i=0; i<n; i++) cin>>a[i];
      for(int i=0; i<n; i++) cin>>b[i];
      std::vector<pair<int,int> > v;
      v.clear();
      for(int i=0; i<n; i++){
        v.push_back(make_pair(a[i],b[i]));
      }

      sort(v.begin(),v.end(),cmp);

      bool out_deadline=false;
      int total_time=0;
      for(int i=0; i<n;i++){

        total_time+=v[i].first;
        // cout<<total_time<<" "<<v[i].second<<endl;
        if(v[i].second<total_time){
          out_deadline=true;
          break;
        }
      }
      if(out_deadline) cout<<"No";
      else cout<<"Yes";
      if(times) puts("");
    }
  // }
  return 0;
}
