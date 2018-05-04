#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	int n;
	// freopen("greedy_matchPoint.in","r",stdin);
	while(cin>>n){

        for(int u=0; u<n; u++){
            if(u==0)
                cin.ignore();
            vector<int> a,b;
            a.clear(); b.clear();
            string s;
            getline(cin,s);
            stringstream ss(s);
//            int k=0;
            int tmp;
            while(ss>>tmp){
                a.push_back(abs(tmp));
            }

            s.clear();
            getline(cin,s);
//            cout<<s<<endl;
            ss.clear();
            ss.str(s);
//            cout<<s<<endl;
//            k=0;
            while(ss>>tmp){
                b.push_back(abs(tmp));
            }

            sort(a.begin(),a.end());
            sort(b.begin(),b.end());

            double sum=0;
            for(int i=0; i<a.size(); i++){
            	sum+=sqrt(pow(a[i],2)+pow(b[b.size()-i-1],2));
			}
//            while(!a.empty()){
//                int n=a.size();
//                if((a.size())%2==1){
//                    sum=sum+(sqrt(pow(a[(n)/2],2)+pow(b[(n)/2],2)));
//                    a.erase(a.begin()+(n)/2);
//                    b.erase(b.begin()+(n)/2);
//                    sort(a.begin(),a.end());
//                    sort(b.begin(),b.end());
//
//                }else{
//                    sum=sum+(sqrt(pow(a[(n)/2],2)+pow(b[(n)/2-1],2)));
//                    sum=sum+(sqrt(pow(b[(n)/2],2)+pow(a[(n)/2-1],2)));
//                    a.erase(a.begin()+(n)/2);
//                    b.erase(b.begin()+(n)/2);
//                    a.erase(a.begin()+(n)/2-1);
//                    b.erase(b.begin()+(n)/2-1);
//                    sort(a.begin(),a.end());
//                    sort(b.begin(),b.end());
//                }
//
//            }
            cout<<(int)(sum);
            if(u!=n-1)
                cout<<endl;
        }
	}
	return 0;
}
