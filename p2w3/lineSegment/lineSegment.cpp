#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  // freopen("greedy_lineSegment.in","r",stdin);
  int nCase;
  int line_num;
  vector<pair<int,int> > vp;
  cin>>nCase;
  while (nCase--) {
    vp.clear();
    cin>>line_num;
    for (size_t i = 0; i < line_num; i++) {
      int a,b;
      cin>>a>>b;
      vp.push_back(make_pair(a,b));
    }
    sort(vp.begin(),vp.end());
    long long len=0,total_len=0;
    // cout<<total_len<<endl;
    int l=vp[0].first,r=vp[0].second;

    for (size_t i = 1; i < vp.size(); i++) {
      if(vp[i].first>r){
        total_len+=r-l;
        l=vp[i].first;
        r=vp[i].second;
      }else{
        if(vp[i].second>r) r=vp[i].second;
      }

    }
    total_len+=(r-l);
    cout<<total_len;
    if(nCase) puts("");

  }
  return 0;
}
/*
2
4
1 2 50
3 5 20
6 19 100
2 100 200
4
0 1 4000
2 5 100
1 4 3000
4 5 2500
*/
