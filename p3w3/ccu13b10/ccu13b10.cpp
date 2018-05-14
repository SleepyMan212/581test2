#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int nCase;
  int num,test_num;
  int test[200000];
  bool p[210000];
  int w[200];
  std::vector<int> v;
  cin>>nCase;
  while (nCase--) {
    memset(test,0,sizeof(test));
    v.clear();
    memset(p,0,sizeof(p));
    cin>>num>>test_num;
    p[0]=1;
    for(int i=0;i<num;i++)cin>>w[i];
    for(int i=0; i<test_num; i++) cin>>test[i];
    for(int i=0; i<num; i++){
      for(int j=200000; j>=w[i]; j--){
        if(p[j-w[i]]) p[j]=1;
      }
    }

    int c=0;
    for(int i=0; i<test_num; i++){
      if(p[test[i]]) c++;
    }
    cout<<c;
    if(nCase) puts("");
  }
  return 0;
}
