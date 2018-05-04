#include "bits/stdc++.h"
using namespace std;

int comp(const void *a,const void *b){
    return (*(int *)a<*(int *)b);
}

void st(int *w,int n){
    int tmp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(w[j]<w[j+1]){
                tmp=w[j+1];
                w[j+1]=w[j];
                w[j]=tmp;
            }
        }
    }
}
int main(){
   // freopen("greedy_oneOnOne.in","r",stdin);
	int n;
	int i,j;
	int t;
  std::vector<int> a,b;;
	while(cin>>n){
        if(!n){
            break;
        }
        a.clear();
        b.clear();
        int tmp;
        for(j=0; j<n; j++){
          cin>>tmp;
          a.push_back(tmp);
        }
        for(j=0; j<n; j++){
          cin>>tmp;
          b.push_back(tmp);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        t=0;
        int x,y;
        x=y=0;
        while(y<n){
            if(b[y]>a[x]){
                t++;
                y++; x++;
            // if not to next warrior
            }else
                y++;
        }
        cout<<t<<endl;
	}
	return 0;
}
