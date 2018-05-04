#include "bits/stdc++.h"
using namespace std;
class Num{
public:
  Num(string v ,int b){
    value=v;
    base=b;
  }
  void setBase(int b){base=b;}
  int getBase(){return base;}
  string getValue(int);
  static string add(string, string,int,int);  //x.size()>y.size()
  friend Num operator+(Num&,Num&);
private:
  int base;
  string value;
};
string Num::getValue(int b=0){
  int val=0;
  if(b==10){
    for(int i=0; i<value.size(); i++){
      val=val*(base)+value[i]-48;
    }
    char s[10000];
    sprintf(s,"%d",val);
    return string(s);
  }else{
    return value;
  }
}
string Num::add(string x,string y,int a_base,int b_base){  //x.size()>y.size()
  if(a_base!=b_base){
    cout<<"兩者基底不同"<<endl;
    return "";
  }
  reverse(y.begin(),y.end());
  reverse(x.begin(),x.end());
  string ans="";
  int carry=0;
  int i;
  // 0=48
  for(i=0; i<y.size(); i++){
    x[i]=x[i]+(y[i]-48)+carry;
    carry=(x[i]-48)/a_base;
    x[i]=(((x[i]-48)%a_base)+48);
  }
  if(carry!=0)
    x+=(carry+48);
  cout<<x<<endl;

  while ((x[x.size()-1]-48)>a_base) {
    x+=((x[x.size()-1]-48)/a_base+48);
    x[x.size()-2]=((x[x.size()-2]-48)%a_base)+48;
  }
  reverse(x.begin(),x.end());
  return x;
}
Num operator+(Num &a,Num &b){
  string ans;
  if(a.value.size()>b.value.size()){
    ans=Num::add(a.value,b.value,a.base,b.base);
  }else{
    ans=Num::add(b.value,a.value,b.base,a.base);
  }
  return Num(ans,a.base);
}
int main(int argc, char const *argv[]) {
  Num a("0",atoi(argv[1]));
  for(int i=2; i<argc; i++){
    string s;
    s.assign(argv[i]);
    Num b(s,atoi(argv[1]));
    a=a+b;
  }
  cout<<argv[1]<<"-carry : "<<a.getValue()<<endl;
  if(atoi(argv[1])!=10)
    cout<<"10-carry : "<<a.getValue(10)<<endl;

  return 0;
}
