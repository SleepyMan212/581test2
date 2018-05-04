#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int nCase;
  int num;

  vector<pair<int,int> > v;
  cin>>nCase;
  while (nCase--) {
    cin>>num;
    for (size_t i = 0; i < num; i++) {
      int a,b;
      cin>>a>>b;
      v.push_back(make_pair(a,b));
      v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());
    int height=v[v.size()-1].second;
    for (int i = v.size()-2; i>=0; i--) {

      if(v[i].first==v[i+1].first) continue;
      height+=v[i].second;
    }
    cout<<height;
    v.clear();
    if (nCase) puts("");
  }
  return 0;
}
