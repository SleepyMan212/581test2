#include "bits/stdc++.h"
using namespace std;
int book[1000001];
int main(int argc, char const *argv[]) {
  memset(book,0,sizeof(book));
  for(int i=1; i<1000001; i++){
      int big=i%10,t=i/10;
      bool is_big=true;
      while (t) {
        if(t%10>=big){
          big=t%10;
          t/=10;
        }else{
          is_big=false;
          break;
        }
      }
      if(is_big){
        book[i]=book[i-1]+1;
      }else{
        book[i]=book[i-1];
      }
  }
  int nCase;
  cin>>nCase;
  int n;
  while (nCase--) {
    cin>>n;
    cout<<book[n];
    if(nCase) puts("");
  }
  return 0;
}
