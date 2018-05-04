#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
	int n,m;

//	freopen("simulation_frog.in","r",stdin);
//		freopen("test.txt","r",stdin);
	while(cin>>n>>m){
        if(!n) break;
        int r[10000]={0};
        for(int i=0; i<n; i++){
            cin>>r[i];
        }
//        int s[m][2];
        int a,b;
        for(int i=0; i<m; i++){
//            cin>>s[i][0]>>s[i][1];
            cin>>a>>b;
            int t=a;
            int step[10000]={0};
            int o[10000]={0};
            int c=1;
            step[t]=c++;
            o[t]=b;
//            cout<<t<<endl;
//            t=t+r[t]*b;
//            if(r[a]*b>0) b=1;
//            step[t]=c++;
//            cout<<t<<endl;
//            int times=1;
            while(t>=0&&t<n){
//                cout<<"AA"<<endl;
//                if(r[t]<0){
//                    t=t+r[t]*b;
//                    b*=-1;
//                }else if(r[t])>0){
//
//                }
                int x=t;
//                cout<<c-1<<": "<<t<<endl;
                t=t+r[t]*b;
                if(r[x]<0) b*=-1;
//                o[x]=b;
//                cout<<x<<" "<<o[t]<<" "<<b<<endl;
                if(step[t]!=0&&o[x]==b)
                    break;
                else
                    step[t]=c++;
                o[x]=b;
//                if(r[x]<0) b*=-1;
//                else if(r[t]<0) b*=1;
//                times++;
//                if(a==t) break;
            }
//            cout<<t<<endl;
            if(t<0){
                cout<<"Backward"<<endl;
            }else if(t>=n){
                cout<<"Forward"<<endl;
            }else{
                cout<<"Cycle "<<abs(step[t]-c)<<endl;
            }
        }

	}
	return 0;
}
