#include <bits/stdc++.h>
using namespace std;
int wei[20][20];
int position[20];
int max_row_value[20];
int max_sum,min_sum;
int n;
void init(){
  memset(wei,0,sizeof(wei));
  memset(max_row_value,0,sizeof(max_row_value));
  max_sum = n;
  min_sum = 9*n;
}
void queen1(int curStep,int value){
  if(value+max_row_value[curStep] <= max_sum ) return;
  if(curStep==n){
    min_sum = min_sum < value ? min_sum : value;
    max_sum = max_sum > value ? max_sum : value;
  }else{
    for(int i=0;i<n; i++){
      for(int j=0; j<curStep; j++){
          if(position[j]==i) break;
          if(abs(position[j]-i)==abs(j-curStep)) break;   //((j,position[j]),(cur,i))
          if(j==curStep-1){
            position[curStep] = i;
            queen1(curStep+1,value + wei[curStep][i]);
          }
      }
    }
  }
}
void queen2(int curStep,int value){
  if(value >= min_sum) return;
  if(curStep==n){
    min_sum = min_sum < value ? min_sum : value;
    max_sum = max_sum > value ? max_sum : value;
  }else{
    for(int i=0;i<n; i++){
      for(int j=0; j<curStep; j++){
          if(position[j]==i) break;
          if(abs(position[j]-i)==abs(j-curStep)) break;   //((j,position[j]),(cur,i))
          if(j==curStep-1){
            position[curStep] = i;
            queen2(curStep+1,value + wei[curStep][i]);
          }
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  freopen("eq_20.in","r",stdin);
  // freopen("Branch_8Queen.in","r",stdin);
  int nc;
  cin>>nc;
  while (nc--) {
    cin>>n;
    init();
    int tmp=0,tmp_sum=0;;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> wei[i][j];
      }
    }
    for(int i=n-1; i>=0; i--){
      tmp = -1e9;
      for(int j=0; j<n; j++){
        tmp = tmp < wei[i][j] ? wei[i][j] : tmp;
      }
      tmp_sum += tmp;
      max_row_value[i] = tmp_sum;
    }

    for(int i=0; i<n; i++){
      position[0]=i;
      queen1(1,wei[0][i]);
      queen2(1,wei[0][i]);
    }
    cout<<(max_sum!=-1e9?max_sum:-1);
    cout<<" "<<(min_sum!=1e9?min_sum:-1);
    if(nc) puts("");
  }
  return 0;
}
