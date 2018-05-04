#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  while (cin>>n&&n) {
    int a[n+1][n+1]={0};
    memset(a,0,sizeof(a));
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        cin>>a[i][j];
    int DP_table[n+1][n+1]={0};
    memset(DP_table,0,sizeof(DP_table));
    // cout<<"====================================\n";
    for(int i=1;i<=n; i++){
      for(int j=1; j<=n; j++){
        // for(int k=0; k<n; k++){
        //   if(i<=k&&j<=k)
        //     DP_table[i][k]=max(a[i][k]+a[k][j]+a[i][j],DP_table[i][j]);
        // }
        DP_table[i][j]=max(DP_table[i-1][j],DP_table[i][j-1])+a[i][j];
      }
      for(int t=1; t<=n; t++){
        for(int b=1; b<=n; b++)
          cout<<DP_table[t][b]<<" ";
        cout<<endl;
      }
      cout<<endl;
    }
    cout<<DP_table[n][n]<<endl;;
  }
  return 0;
}
