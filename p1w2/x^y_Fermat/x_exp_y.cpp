#include <iostream>
// #include <time.h>
using namespace std;
// double START,END;
int main(){
	// freopen("power.in","r",stdin);
  // double START = clock();
	long long a,b,p;
	string x,y;
	long long result;
	while(cin>>x>>y>>p){
			a=b=0;
			for(int i=0; i<x.size(); i++){
				a=(a*10+x[i]-'0')%p;
			}
			for(int i=0; i<y.size(); i++){
				b=(b*10+y[i]-'0')%(p-1);
			}
			// cout<<a<<" "<<b<<"WW"<<endl;
	    result=1;
			while(b){
					if(b&1){
							result=(a%p)*(result%p)%p;
							// result%=p;
					}
					a=(a%p)*(a%p);
					b>>=1;
			}
			cout<<result%p<<endl;
}
	return 0;
}
