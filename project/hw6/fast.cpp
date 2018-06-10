#include <bits/stdc++.h>
using namespace std;
int wei[20][20];
int max_row_value[20];
int max_sum,min_sum;
bool slash[41],back_slash[41],pos[20];
int n;
void init(){
  memset(slash,0,sizeof(slash));
  memset(back_slash,0,sizeof(back_slash));
  memset(pos,0,sizeof(pos));
  max_sum = n;
  min_sum = 9*n;
  memset(max_row_value,0,sizeof(max_row_value));
  memset(wei,0,sizeof(wei));
}
void qn(int row,int value){
  // cut branch
  if(value+max_row_value[row] <= max_sum && value+n-row >= min_sum) return;
  if(row == n){
    min_sum = min_sum < value ? min_sum : value;
    max_sum = max_sum > value ? max_sum : value;
    return;
  }

  int p,q;
  for(int col=0; col<n; col++){
    // check queen pos
    if(pos[col])continue;
    p = row + col; q = n - 1 - row + col;
    if(slash[p]||back_slash[q]) continue;

    // DFS
    pos[col]=slash[p]=back_slash[q]=true;
    qn(row+1,value+wei[row][col]);
    pos[col]=slash[p]=back_slash[q]=false;
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
    // upperbound
    for(int i=n-1; i>=0; i--){
      tmp = -1e9;
      for(int j=0; j<n; j++){
        tmp = tmp < wei[i][j] ? wei[i][j] : tmp;
      }
      tmp_sum += tmp;
      max_row_value[i] = tmp_sum;
    }

    qn(0,0);
    //output
    cout<<(max_sum!=n?max_sum:-1);
    cout<<" "<<((min_sum!=9*n)?min_sum:-1);
    if(nc) puts("");
  }
  return 0;
}
