#include "bits/stdc++.h"
using namespace std;
vector<pair<int,int> > v;
int min_num;
bool compare(pair<int,int> &a,pair<int,int>&b){
  if(a.first==b.first) return b.second<a.second;
  return a.first<b.first;
}
void slove(int n,int r,int total_num){
  if(r==199){
    min_num = min(min_num,total_num);
    return;
  }
  for(int i=n; i<v.size(); i++){
    if(v[i].first==v[i-1].first) continue;
    if(r+1>=v[i].first&&r<v[i].second){
      slove(i+1,v[i].second,total_num+1);
    }
  }

}
int main(int argc, char const *argv[]) {
  freopen("greedy_babysitter.in","r",stdin);
  int nCase;

  cin >> nCase;
  scanf("\n");
  scanf("\n");
  while (nCase--) {
    v.clear();
    char s[1000];
    while (gets(s)) {

      if(s[0]=='\0'){
        break;
      }
      int a = atoi(strtok(s," "));
      int b = atoi(strtok(NULL," "));
      v.push_back(make_pair(a>b?b:a,a>b?a:b));
    }
    sort(v.begin(),v.end(),compare);
    int r=v[0].second,l=v[0].first;

    int i;
    for(i=1; i<v.size(); i++)
      if(v[i].first!=v[i-1].first) break;
    min_num=1e9;
    slove(i,r,1);

    cout<<min_num;
    if(nCase)cout<<endl;
  }
  return 0;
}
