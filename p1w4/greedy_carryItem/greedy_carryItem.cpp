#include <iostream>
#include <vector>
#include <algorithm>
//#define  sz(x) (int(x.size()))
#include <stdio.h>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
int main(){
	int t;
	int n,m;
	// freopen("greedy_carryItem.in","r",stdin);
	vector<int> weight ,item;
	while(cin>>t){
        while(t--){
            cin>>n>>m;
            item.clear(); weight.clear();
            for(int i=0; i<n; i++){
                int tmp;
                cin>>tmp;
                item.push_back(tmp);
            }
            for(int i=0; i<m; i++){
                int tmp;
                cin>>tmp;
                weight.push_back(tmp);
            }
            sort(item.begin(),item.end(),cmp);
            sort(weight.begin(),weight.end());
            int sum=0;
//            for(int i=0; i<item.endl(); i++){
                for(int j=0; j<weight.size(); j++){
                    if(weight[j]>=item.back()){
                        sum=sum+weight.at(j);
                        item.pop_back();
                    }
//                }
                }
//            for(vector<int>::iterator i=item.begin(); i!=item.end(); i++){
//                cout<<"TTT  "<<*i<<" ";
//            }
//            cout<<endl;
            if(item.empty()){
                cout<<sum;
            }else cout<<"-1";
            if(t)
                cout<<endl;

        }
	}
	return 0;
}
