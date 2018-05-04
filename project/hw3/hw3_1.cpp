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


  // request memory
  void *new_p = realloc(p,size*2*sizeof(person));

  if(new_p==NULL){
    cout<<"fail for allocation double size"<<endl;
    return;
  }else{
    p=(person*)new_p;
    cout<<"queue/stack full, allocate double "<<size*2<<endl;
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

  free(p);
  return 0;
}
void input(person *p,int &size,int &counter){
  char s[100];
  while (fgets(s,100,stdin)!=NULL) {
    string name;
    // spilt the data
    int flag=0,i;
    for(i=0; i<strlen(s); i++){
      if(s[i]=='\"'){
        flag++;
        if(flag==2){
          // name[j]='\0';
          break;
        }
      }else
        name+=s[i];
    }
    char *age=strtok(s+i,", \"");
    char *sex=strtok(NULL,", \"");

    strcpy(p[counter].name,name.c_str());
    p[counter].age=atoi(age);
    strcmp(sex,"female\n")==0?p[counter].sex=female:p[counter].sex=male;
    counter++;
    // print(p,counter);
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
