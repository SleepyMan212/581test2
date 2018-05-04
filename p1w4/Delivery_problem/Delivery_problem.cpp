#include <iostream>
#include <bits/algorithmfwd.h>
#include <algorithm>
using namespace std;

int main(){
	int t;
	int n;
	while(cin>>t){
        while(t--){
            cin>>n;
            int box[n];
            for(int i=0; i<n; i++){
                cin>>box[i];
            }
            sort(box,box+n);
            int sum=0;
            int time=0;
            for(int i=0; i<n; i++){
                time+=box[i];
                sum+=time;
                if(i!=n-1)
                time+=box[i];
            }
            cout<<sum;
            if(t)
                cout<<endl;

        }
	}
	return 0;
}
