#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
ll wei[100000000];

vector<ll> v[25];

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin>>n&&n) {
    int N=pow(2,n);
    for(int i=0; i<N; i++){
      cin>>wei[i];
    }

    int t=1;
    ll max_num;
    for(int i=1; i<N; i++){
      t=1; max_num=-1e9;
      while(1){
        ll tmp=i^t;
        t*=2;
        if(tmp>=N) break;
        if(tmp>i) continue;
        // find the maximim value brfore go to i
        max_num=max(max_num,wei[tmp]);
      }
      //record
      wei[i]+=max_num;
    }
    cout<<wei[N-1]<<endl;

  }

    return 0;
}
