#include <iostream>
#include <string.h>
using namespace std;

int record[1000200];
int main(){
	int a,b,t;
	while(cin>>a>>b){
        if(!b) break;
        memset(record,0,sizeof(record));
        t=0; bool is_find=false;
        while(1){
            if(record[a%b]==0){
            record[a%b]=t++;
            a%=b;
            a*=10;
            }else{
                cout<<t-record[a%b]<<endl;
                break;
            }
        }
	}
	return 0;
}
