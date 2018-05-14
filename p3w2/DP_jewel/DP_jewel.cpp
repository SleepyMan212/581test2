#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  long long n;
  while (cin>>n&&n) {
    long long a[n+1][n+1]={0};
    memset(a,0,sizeof(a));
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        cin>>a[i][j];
    long long DP_table[n+1][n+1]={0};
    memset(DP_table,0,sizeof(DP_table));
    for(int i=1;i<=n; i++){
      for(int j=1; j<=n; j++){
        DP_table[i][j]=max(DP_table[i-1][j],DP_table[i][j-1])+a[i][j];
      }
    }
    cout<<DP_table[n][n]<<endl;;
  }
  return 0;
}
