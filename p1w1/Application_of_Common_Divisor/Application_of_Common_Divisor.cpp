#include <iostream>
using namespace std;

int main(){
	int a,b;
	int p,q;
	int x,y;
	int n,mi;
	int i;
	bool first;
	while(cin>>n){
        while(n--){
            cin>>a>>p>>b>>q;
            x=a-p;
            y=b-q;
            mi=(x>y)?y:x;
            first=true;
            for(i=1; i<=mi; i++){
                if(first&&x%i==0&&y%i==0){
                    first=false;
                    cout<<i;
                }else if(x%i==0&&y%i==0)
                    cout<<" "<<i;
            }
            if(n!=0)
                cout<<endl;

        }

	}
	return 0;
}
