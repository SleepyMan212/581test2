#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  while (cin>>n&&n) {
    int a[n]={0},b[n]={0};
    a[0]=b[0]=1000;
    for(int i=1; i<=n; i++){
      cin>>a[i]>>b[i];
    }
    int min__value=1e9;
    int value=1000;
    int t1=0,t2=0;
    for(int i=1;i<=n; i++){
      int x1,x2,y1,y2;
      x1=t1+abs(a[i]-a[i-1]);
      y1=t2+abs(a[i]-b[i-1]);
      x2=t1+abs(b[i]-a[i-1]);
      y2=t2+abs(b[i]-b[i-1]);
      t1=min(x1,y1);
      t2=min(x2,y2);
    }
    cout<<min(t1,t2)<<endl;

  }
  return 0;
}
