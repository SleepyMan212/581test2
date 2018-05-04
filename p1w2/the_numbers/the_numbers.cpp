#include <iostream>
//#include
using namespace std;

int main(){
	string f,s;
	while(cin>>f>>s){
        int t=0;
        while(s.find(f)!=string::npos){

//            cout<<s.find(f)<<endl;
            s=s.substr(s.find(f)+1);
            t++;
        }
    cout<<t<<endl;
	}
	return 0;
}
