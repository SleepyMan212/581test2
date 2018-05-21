/*
The bigO od this programe is O(n)
//prove
num = n

 G(n)=200000*n
 We can find a C*F(n) >= G(n) >= 0
 when C = 200001 , all n >= n0 = 1
 So F(n) = n , O(F(n)) = G(n)

// problem
It is a simplify Knapsack Problem

Give some weight of object and check they whether can add to specific weight
Finally output the successly case

//sample

//input
2
2 5
3 5
1 5 2 7 8
3 5
2 5 2
20 1 2 4 9

// output
2
3
*/


#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int nCase;
  int num,test_num;
  int test[200000];
  bool p[210000];
  int w[200];
  std::vector<int> v;
  cin>>nCase;
  while (nCase--) {
    memset(test,0,sizeof(test));
    // initialize
    v.clear();
    memset(p,0,sizeof(p));
    p[0]=1;
    //input
    cin>>num>>test_num;
    for(int i=0;i<num;i++)cin>>w[i];
    for(int i=0; i<test_num; i++) cin>>test[i];
    // deal with the programe
    for(int i=0; i<num; i++){
      for(int j=200000; j>=w[i]; j--){
        if(p[j-w[i]]) p[j]=1;
      }
    }
    // analysis the output
    int c=0;
    for(int i=0; i<test_num; i++){
      if(p[test[i]]) c++;
    }
    //output
    cout<<c;
    if(nCase) puts("");
  }
  return 0;
}
