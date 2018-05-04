#include "bits/stdc++.h"

using namespace std;
#ifndef MAX
#define MAX 100007
#endif
int main(int argc, char const *argv[]) {
  // freopen("greedy_spy.in","r",stdin);
  int times;
  int spy_leader[MAX];
  bool mark[MAX];
  int spy_num;
  cin>>times;
  while (times--) {
    cin>>spy_num;
    mark[0]=false;
    for (size_t i = 1; i < spy_num; i++){
      mark[i]=false;
      cin>>spy_leader[i];
    }
    int total_phone=0;
    for (size_t i = spy_num-1; i > 0; i--) {
      if(!mark[i]) mark[spy_leader[i]]=true;
      else total_phone++;
    }
    
    std::cout << total_phone+mark[0];
    if(times) puts("");
  }
  return 0;
}
