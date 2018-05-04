#include "bits/stdc++.h"

using namespace std;
int jobs[100000];
int f(int job_num,int machine_num){
  priority_queue <int> pq;
  //initialize
  for(int i=0; i<machine_num; i++) pq.push(0);
  // simulation machines work
  for(int i=0; i<job_num; i++){
    int t=pq.top()-jobs[i];
    pq.pop();
    pq.push(t);
  }
  // find the last machine time of work
  for(int i=0; i<machine_num-1; i++) pq.pop();

  return (-pq.top());
}
int main(int argc, char const *argv[]) {
  // freopen("greedy_FCFS.in","r",stdin);
  int T,job_num,deadline;
  while (cin>>T) {
    while (T--) {
      int machine_num=0;
      //input
      cin>>job_num>>deadline;
      int total_time=0;
      for (size_t i = 0; i < job_num; i++){
        cin>>jobs[i];
        total_time+=jobs[i];
      }
      bool over_deadline=false;
      // if a job > deadline then it can't be finished
      if(*max_element(jobs,jobs+job_num)>deadline) over_deadline=true;
      int up=job_num,down=total_time/deadline;
      // binary search
      if(!over_deadline){
        while (down<up) {
          int s=(down+up)/2;
          int m=f(job_num,s);
          if(m<=deadline) up=s;
          else down=s+1;
        }
        cout<<up;
      }else cout<<"-1";
      if(T) puts("");
    }
  }
  return 0;
}
