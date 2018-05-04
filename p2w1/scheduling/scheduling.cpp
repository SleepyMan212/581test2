#include "bits/stdc++.h"
using namespace std;
int machines[10000];
int jobs[100000];
int main(int argc, char const *argv[]) {
  // freopen("greedy_schedule.in","r",stdin);

  int times;
  int job_num,machine_num;
  while (cin>>times) {
    while (times--) {
      cin>>job_num>>machine_num;

      for (size_t i = 0; i < job_num; i++) {
        cin>>jobs[i];
      }

      int totalTime=0;

      int i,j;
      int finish_job=0;
      for(i=j=0; i<machine_num; i++){
        machines[i]=jobs[j++];
      }
      while (finish_job<job_num) {
        for(int k=0; k<machine_num; k++){
          machines[k]--;
          // when finish a job
          if(machines[k]==0){
            machines[k]=jobs[j++];
            finish_job++;
          }
        }
        totalTime++;
      }
      std::cout << totalTime;
      if(times) cout<<endl;
    }
  }
  return 0;
}
