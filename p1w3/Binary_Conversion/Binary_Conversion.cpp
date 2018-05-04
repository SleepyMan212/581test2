#include <iostream>
#include <cmath>
using namespace std;

int btoi(string s){
    int v=0;
    for(int i=0; i<s.size(); i++)
        v=(v*2)+s[i]-'0';
    return v;
}
int main(){
  // freopen("simulation_Binary.in","r",stdin);
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
