#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdio>
using namespace std;
#ifndef pi
#define pi 3.1415913
#endif
typedef double (*poly)(double);
static bool is_def=false;
void integrate(poly p,double from,double to,double d){
  // double d=0.0000001;
  d=0.0000001;
  bool is_neg=false;
  if(from>to){
    is_neg=true;
    double tmp = from;
    from=to;
    to=tmp;
  }
  double sum=0;
  // Riemann integral
  for(double i=from; i<=to; i+=d){
    sum+=(p(i)*d);
  }

  printf("The integration is : %.5llf\n",sum*(is_neg?-1:1));
}
void create_poly(double *poly,int &index){
  index=0;
  char s[100];
  cout<<"input the poly from high power (if not exist then set value be 0)"<<endl;
  scanf("\n");
  fgets(s,100,stdin);
  char *p;
  p=strtok(s," ");
  while (p!=NULL) {
    poly[index++]=atof(p);
    p=strtok(NULL," ");
  }
}
double f(double x){
  double poly[100];
  int index;
  if(!is_def){
    // create the custom poly
    create_poly(poly,index);
    is_def=true;
  }
  double sum=0;
  int j;
  for(int i=0,j=index-1; i<index; i++){
    sum+=(pow(x,i)*poly[j--]);
  }
  return sum;

}
void instruction(){
  cout<<"It's a integration calculator "<<endl
      <<"1. sin(x)"<<endl
      <<"2. cos(x)"<<endl
      <<"3. sqrt(x)"<<endl
      <<"4. abs(x)"<<endl
      <<"5. custom"<<endl
      <<"input your choice:";
}
int main(int argc, char const *argv[]) {
  int choice;
  double from,to,d;
  instruction();
  cin>>choice;
  cout<<"Input your range begin and end: ";
  cin>>from>>to;
  cout<<"Input the deleta: ";
  cin>>d;
  switch (choice) {
    case 1:
      integrate(sin,from,to,d);
      break;
    case 2:
      integrate(cos,from,to,d);
      break;
    case 3:
      integrate(sqrt,from,to,d);
      break;
    case 4:
      integrate(fabs,from,to,d);
      break;
    case 5:
      integrate(f,from,to,d);
      break;
    default:
      cout<<"Please input the correctly choice"<<endl;
  }
  return 0;
}
