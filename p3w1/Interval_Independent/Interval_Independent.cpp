#include <bits/stdc++.h>

using namespace std;

struct interval{
  int a,b;
  int w;
  bool operator<(const interval &rhs)const{
    if(b==rhs.b) return a<rhs.a;
    return b<rhs.b;
  }
};
interval a[10000000];
long long dp[100000000];
void init(){
  memset(dp,0,sizeof(dp));
}
void sol(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i].a>>a[i].b>>a[i].w;

  sort(a+1,a+n+1);

  a[0].b=-1;

  int i,j;
  for(i=1; i<=n;i++){
    int l=0,r=i-1;
    int x;
    while (r-l>1) {
      x=(r+l)/2;
      if(a[x].b<=a[i].a) l=x;
      else r=x-1;
    }
    x=a[r].b<=a[i].a ? r:l;
    // for(j=0; j<i; j++){
    //   if(a[i].a<a[j].b) break;
    // }
    // int x=j-1;
    dp[i]=max(dp[i-1],dp[x]+a[i].w);
  }

  cout<<dp[n]<<endl;

}
int main(int argc, char const *argv[]) {
  int nc;
  cin>>nc;
  while (nc--) {
      init();
      sol();
  }
  return 0;
}
/*
2
4
1 2 50
3 5 20
6 19 100
2 100 200
4
0 1 4000
2 5 100
1 4 3000
4 5 2500
Output
250
9500
*/
