#include <iostream>
using namespace std;
int main(){
	long long x,y,p;
	long long result;
	int n;
	//input data
  while(cin>>x>>y>>p){
    result=1;
		//fast power
    while(y){
        if(y&1){
            result*=x;
            result%=p;
        }
        x=(x%p)*(x%p);
        y/=2;
    }
		//output
    cout<<result%p<<endl;
		}
}
