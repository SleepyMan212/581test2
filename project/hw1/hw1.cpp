#include <iostream>
#include <regex>
#include <cstdio>
#include <vector>
#include <cctype>
using namespace std;
bool comp_username(pair<string,string>&a,pair<string,string>&b){
  int i,j;
  i=j=0;
  string tmp_a=a.first,tmp_b=b.first;
  for(int i=0; i<tmp_a.size(); i++)tmp_a[i]=tolower(tmp_a[i]);
  for(int i=0; i<tmp_b.size(); i++)tmp_b[i]=tolower(tmp_b[i]);
  return tmp_a<tmp_b;
}
bool comp_username_domain(pair<string,string>&a,pair<string,string>&b){
  int i,j;
  i=j=0;
  string tmp_a_user=(a.first),tmp_b_user=(b.first);
  string tmp_a_domain=(a.second),tmp_b_domain=(b.second);
  reverse(tmp_a_user.begin(),tmp_a_user.end());
  reverse(tmp_a_user.begin(),tmp_a_user.end());
  for(int i=0; i<tmp_a_user.size(); i++)tmp_a_user[i]=tolower(tmp_a_user[i]);
  for(int i=0; i<tmp_b_user.size(); i++)tmp_b_user[i]=tolower(tmp_b_user[i]);
  for(int i=0; i<tmp_a_domain.size(); i++)tmp_a_domain[i]=tolower(tmp_a_domain[i]);
  for(int i=0; i<tmp_b_domain.size(); i++)tmp_b_domain[i]=tolower(tmp_b_domain[i]);
  //first compare the domain , if domain are equals than compare account
  return tmp_a_domain==tmp_b_domain?tmp_a_user<tmp_b_user:tmp_a_domain<tmp_b_domain;
}
void verfication_mail(string mail,vector<pair<string,string> >&emails){
  smatch email_content;
  regex ver_mail("^([a-zA-Z0-9_]+[.]?[a-zA-Z0-9_]+)@([a-zA-Z0-9]+[.]?[a-zA-Z0-9]+)$");
  if(regex_match(mail,email_content,ver_mail)){
    cout<<"It is a valid email!"<<endl;
    emails.push_back(make_pair(email_content[1],email_content[2]));
  }else{
    cout<<"It is not a valid email~~"<<endl;
  }
}
void print(vector<pair<string,string> > emails){
  cout<<"sort by User "<<endl;
  sort(emails.begin(),emails.end(),comp_username);
  for(int i = 0; i<emails.size(); i++){
    cout<<emails[i].first<<" "<<emails[i].second<<endl;
  }
  cout<<"sort by Domain+Username "<<endl;
  sort(emails.begin(),emails.end(),comp_username_domain);
  for(int i = 0; i<emails.size(); i++){
    cout<<emails.at(i).first<<" "<<emails.at(i).second<<endl;
  }
}
void solve(){
  int nCase;
  string mail;
  cin>>nCase;
  scanf("\n");
  // first  =  account
  // second =  domain
  std::vector<pair<string,string> > emails;
  while (nCase--) {
    getline(cin,mail);
    verfication_mail(mail,emails);
  }

  print(emails);

}
int main(int argc, char const *argv[]) {
  solve();
  return 0;
}
