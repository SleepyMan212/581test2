#include "bits/stdc++.h"
using namespace std;
int book[100000001];
int record[10];
int main(int argc, char const *argv[]) {
  int nCase;
  memset(book,0,sizeof(book));
  for(int i=1; i<=1000000; i++){
    int tmp=i;
    bool is_different=true;
    memset(record,0,sizeof(record));
    while (tmp) {
      if(record[tmp%10]){
        is_different=false;
        break;
      }
      record[tmp%10]++;
      tmp/=10;
    }
    if(is_different){
      book[i]=book[i-1]+1;
    }else{
      book[i]=book[i-1];
    }
  }
  cin>>nCase;
  int n;
  while (nCase--) {
    cin>>n;
    cout<<book[n];
    if(nCase)puts("");
  }


  return 0;
}
