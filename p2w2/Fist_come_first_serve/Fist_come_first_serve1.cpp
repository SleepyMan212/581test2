#include "bits/stdc++.h"

using namespace std;
int machines[100000];
int jobs[100000];
int main(int argc, char const *argv[]) {
  priority_queue <int> pq;
  pq.push(5);
  pq.push(4);
  pq.push(78);
  cout<<pq.top();
  freopen("greedy_FCFS.in","r",stdin);
  int T,job_num,deadline;
  while (cin>>T) {
    while (T--) {
      /* code */
      cin>>job_num>>deadline;
      int total_time=0;
      for (size_t i = 0; i < job_num; i++){
        cin>>jobs[i];
        total_time+=jobs[i];
      }
      // cout<<total_time<<endl;
      bool over_deadline=false;
      if(*max_element(jobs,jobs+job_num)>deadline) over_deadline=true;
      if(!over_deadline){
        cout<<(total_time/deadline)+1;
      }else cout<<"-1";
      if(T) puts("");
    }
  }
  return 0;
}
