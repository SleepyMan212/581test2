#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  int a[57];
  int count=1;
  while (cin>>n&&n) {
    int sum=0,ave;
    for(int i=0; i<n; i++){
      cin>>a[i];
      sum+=a[i];
    }
    ave=sum/n;
    int move=0;
    for(int i=0; i<n; i++){
      move+=(abs(a[i]-ave));
    }
    cout<<"Set #"<<count++<<endl;
    cout<<"The minimum number of moves is "<<move/2<<"."<<endl<<endl;;
  }
  return 0;
}
