#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  char s;
  while ((s=getchar())!=EOF) {
    if(isdigit(s)){
      s=(s-'0'+1)%10+'0';
    }else if(isalpha(s)){
      int d=s-'a';
      s='Z'-d;
    }
    cout<<s;
  }
  return 0;
}
