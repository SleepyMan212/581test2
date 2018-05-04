#include <stdio.h>
// int *a=&a;

void swap(int *a,int *b){
  printf("%d\n",*a );  // 6
  printf("%p\n",a );   // memory 0061FF2C 
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
// void swap(int a,int b){
//   int tmp;
//   tmp=a;
//   a=b;
//   b=tmp;
// }
int main(int argc, char const *argv[]) {
  int a,b;
  scanf("%d%d", &a,&b);
  printf("%d  %d\n", a,b);
  swap(&a,&b);
  printf("%d  %d\n", a,b);
  return 0;
}
