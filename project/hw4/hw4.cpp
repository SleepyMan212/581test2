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
void integrate(poly p,double from,double to){
  double d=0.0001;
  double sum=0;
  // Riemann integral
  for(double i=from; i<=to; i+=d){
    sum+=(p(i)*d);
  }

  printf("The integration is : %.3llf\n",sum);
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
      <<"2. abs(x)"<<endl
      <<"3. sqrt(x)"<<endl
      <<"4. custom"<<endl
      <<"input your choice:";
}
int main(int argc, char const *argv[]) {
  int choice;
  double from,to;
  instruction();
  cin>>choice;
  cout<<"Input your range begin and end: ";
  cin>>from>>to;
  switch (choice) {
    case 1:
      integrate(sin,from,to);
      break;
    case 2:
      integrate(fabs,from,to);
      break;
    case 3:
      integrate(sqrt,from,to);
      break;
    case 4:
      cout<<"A"<<endl;
      integrate(f,from,to);
      break;
    default:
      cout<<"Please input the correctly choice"<<endl;
  }
  return 0;
}
