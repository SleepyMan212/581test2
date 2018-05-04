#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  string s;
  while (cin>>s) {
    int count=0;
    string str="";
    bool is_finish=false;
    for(int i=0; i<s.size(); i++){
      if(isdigit(s[i])){
        if(is_finish){
          for(int j=0; j<count; j++) cout<<str;
          str=""; count=0; is_finish=false;
        }
        count=count*10+s[i]-'0';
      }else if(isalpha(s[i])){
        is_finish=true;
        str+=s[i];
      }
    }
    for(int j=0; j<count; j++) cout<<str;
    cout<<endl;
  }
  return 0;
}
