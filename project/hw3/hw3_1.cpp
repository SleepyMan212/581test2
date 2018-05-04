#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
enum Sex{female,male};
typedef struct {
  char name[100];
  int age;
  Sex sex;
}person;
void input(person *p,int &size,int &counter);
void print(person *p ,int counter);
void resize(person *p,const int counter,int &size){
  if(size!=counter) return;

  cout<<"queue/stack full, allocate double size "<<endl;

  // request memory
  p = (person*)realloc(p,size*2*sizeof(person));

  if(p==NULL){
    cout<<"fail"<<endl;
    return;
  }else{
    size*=2;
  }
}

int main(int argc, char const *argv[]) {
  freopen("data.in","r",stdin);
  // array size
  int size=1;
  // data size
  int counter=0;
  person *p = NULL;

  // memory allocation
  p = (person *)malloc(size*sizeof(person));

  input(p,size,counter);

  print(p,counter);

  return 0;
}
void input(person *p,int &size,int &counter){
  char s[100];
  while (fgets(s,100,stdin)!=NULL) {
    char name[100];
    // spilt the data
    int flag=0,i,j;
    for(j=i=0; i<strlen(s); i++){
      if(s[i]=='\"'){
        flag++;
        if(flag==2){
          name[j]='\0';
          break;
        }
      }else
        name[j++]=s[i];
    }
    char *age=strtok(s+i,", \"");
    char *sex=strtok(NULL,", \"");

    strcpy(p[counter].name,name);
    p[counter].age=atoi(age);
    sex=="female"?p[counter].sex=female:p[counter].sex=male;
    counter++;

    resize(p,counter,size);
  }
}
void print(person *p ,int counter){
  cout<<endl<<"The following is data"<<endl;
  for(int i=0; i<counter; i++){
    cout<<"-------------------------\n";
    cout<<"name:"<<p[i].name<<endl;
    cout<<"age:"<<p[i].age<<endl;
    cout<<"sex:"<<(p[i].sex==Sex(1)?"male":"female")<<endl;
  }
  cout<<"-------------------------\n";
}
