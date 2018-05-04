#include "bits/stdc++.h"
using namespace std;
int LIS(vector<int> &v){
  vector<int> ans;
  ans.push_back(v[0]);
  for(int i=1; i<v.size(); i++){
    int n=v[i];
    if(n>ans.back())
      ans.push_back(n);
    else
      *lower_bound(ans.begin(),ans.end(),n)=n;
  }
  return ans.size();
}
int main(int argc, char const *argv[]) {
  int nCase,n;
  std::vector<int> v;
  while (cin>>nCase) {
    while (nCase--) {
      v.clear();
      cin>>n;
      int tmp;
      for(int i=0; i<n; i++){
        cin>>tmp;
        v.push_back(tmp);
      }
      cout<<LIS(v);
      if(nCase) puts("");
    }
  }
  return 0;
}
