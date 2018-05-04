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
    for(int i=0;i<num;i++)cin>>w[i];
    for(int i=0; i<test_num; i++) cin>>test[i];
    for(int i=0; i<num; i++){
      // p[w[i]]=1;
      for(int j=200000; j>0; j--){
        if(j==w[i]&&p[w[i]]==0) p[w[i]]=1;
        else if(p[j]) p[j+w[i]]=1;
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
