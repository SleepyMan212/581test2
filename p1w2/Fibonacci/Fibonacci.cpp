#include "bits/stdc++.h"
using namespace std;
long long trans_matrix[3][3];
long long ans_matrix[3];
int n,p,a,b,c;
// matrix product about fibonacci' power
void product(){
  long long tmp_matrix[3][3];
  memcpy(tmp_matrix,trans_matrix,sizeof(trans_matrix));
  for(int i=0; i<3; i++){
    for (int j = 0; j < 3; j++) {
      long long sum=0;
      for(int k=0; k<3; k++){
        sum+=(tmp_matrix[i][k]%p)*(tmp_matrix[k][j]%p)%p;
      }
      trans_matrix[i][j]=sum%p;
    }
  }
}
int main(int argc, char const *argv[]) {
  // |0 1 0|
  // |0 0 1| =>fibonacci's transforamtiom matrix
  // |a b c|

  //|1|
  //|1|  =>ans_matrix
  //|1|
  while (cin>>n>>p>>a>>b>>c) {
    memset(trans_matrix,0,sizeof(trans_matrix));
    for (int i = 0; i < 3; i++) ans_matrix[i]=1;
    trans_matrix[0][1]=1;
    trans_matrix[1][2]=1;
    trans_matrix[2][0]=c;
    trans_matrix[2][1]=b;
    trans_matrix[2][2]=a;

    if(n<=3){
      cout<<ans_matrix[n-1]<<endl;;
      continue;
    }
    n-=3;
    // fast power
    while (n) {
      if(n&1){
        long long tmp_matrix[3];
        // copy ans_matrix to tmp_matrix
        memcpy(tmp_matrix,ans_matrix,sizeof(ans_matrix));
        for(int i=0; i<3; i++){
          long long sum=0;
          for(int j=0; j<3; j++){
            sum+=((trans_matrix[i][j]%p)*(tmp_matrix[j]%p))%p;
          }
          ans_matrix[i]=sum%p;
        }
      }
      product();
      n>>=1;
    }
    // output answer
    cout<<ans_matrix[2]%p<<endl;;
  }
  return 0;
}
