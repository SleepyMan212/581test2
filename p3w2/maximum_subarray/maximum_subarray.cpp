#include "bits/stdc++.h"
using namespace std;
int table[600007],value[600007];
int main(int argc, char const *argv[]) {
  // freopen("array_maxConsecutiveSum.in","r",stdin);
  int n,nCase;
  cin>>nCase;
  while (nCase--) {
    cin>>n;
    memset(table,0,sizeof(table));
    memset(value,0,sizeof(value));
    for(int i=0; i<n; i++){
      cin>>value[i];
    }
    for(int i=1; i<=n; i++){
      table[i]=max(table[i-1],value[i-1])+value[i];
    }
    cout<<*max_element(table,table+n+1)<<endl;
  }
  return 0;
}
