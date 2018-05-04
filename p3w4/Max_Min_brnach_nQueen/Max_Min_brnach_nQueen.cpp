#include "bits/stdc++.h"
using namespace std;
int w[8][8];
int q[8];
int n;
int max_num,min_num;
int num=0;
void qn(int cur,int num){// (q[j],j) (i,cur)
  if(cur<n){
    for(int i=0; i<n; i++){
      for(int j=0; j<cur; j++){
        if(q[j]==i) break; // 判斷是否在同一列
        if(((q[j]-i)==(cur-j))||((q[j]-i)==(j-cur))) break; //是否在對角線
        if(j==cur-1){
          q[cur]=i;
          qn(cur+1,num+w[cur][i]);
        }
      }
    }
  }else{
    if(num>max_num) max_num=num;
    if(num<min_num) min_num=num;
  }
}
int main(int argc, char const *argv[]) {
  int nCase;
  cin>>nCase;
  while (nCase--) {
    cin>>n;
    max_num=0;
    min_num=1e9;
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++) cin>>w[i][j];

  for(int i=0; i<n; i++){
    q[0]=i;
    qn(1,w[0][i]);
  }
  cout<<(max_num!=0?max_num:-1);
  cout<<" "<<(min_num!=1e9?min_num:-1);
    if(nCase) puts("");
  }
  return 0;
}
