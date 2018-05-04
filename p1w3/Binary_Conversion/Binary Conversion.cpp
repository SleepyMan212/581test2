#include <iostream>
#include <cmath>
using namespace std;

int btoi(string s){
    int v=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1')
//            cout<<i<<" "<<pow(2,s.size()-i-1)<<endl;
            v=v+pow(2,s.size()-i-1);
    }
    return v;
}
int main(){
	int n;
	int sum;
	string s;
	while(cin>>n){
        if(!n) break;
        sum=0;
        for(int i=0; i<n; i++){
            cin>>s;
            sum+=btoi(s);
        }
        cout<<sum<<endl;
	}
	return 0;
}
