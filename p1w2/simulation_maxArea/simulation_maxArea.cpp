#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n,m;
	int max_area;
	while(cin>>n){
        while(n--){
            cin>>m;
            max_area=0;
            int a[55][2]={0};
            for(int i=0; i<m; i++){
                cin>>a[i][0]>>a[i][1];
                for(int j=0; j<i; j++){
                    if((abs(a[i][1]-a[j][1])*abs(a[i][0]-a[j][0]))>max_area){
                        max_area=abs(a[i][1]-a[j][1])*abs(a[i][0]-a[j][0]);
                    }

                }
            }
            cout<<max_area;
            if(n)
                cout<<endl;
        }
	}
	return 0;
}
