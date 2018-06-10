#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int comp(void* a,void* b){
  int x = *(int*)a;
  int y = *(int*)b;
  return x < y;

}
void swap(void *a,void *b,size_t size){
  void *tmp = malloc(size);

  memcpy(tmp,b,size);
  memcpy(b,a,size);
  memcpy(a,tmp,size);

  free(tmp);
}
void print(int *data,int size){
  for(int i=0; i<size; i++){
    // cout<<data[i]<<" ";
    printf("%d ",data[i]);
  }
  printf("\n");
}
int partition(void *data,int left,int right,size_t size,int (*cmp)(void*,void*)){
  // random pivot
  srand(time(NULL));
  int pivotIndex = left + rand()%(right - left + 1);
  // make pivot to left
  swap(data+pivotIndex*size,data+right*size,size);
  char *pivot = data+right*size;
  pivotIndex = right;
  int i = left -1;

  for(int j=left; j<right; j++){
    if(cmp(data+j*size,pivot)){
      i++;
      swap(data+i*size,data+j*size,size);
    }
  }
  // make pivot to the correct position
  swap(data+(i+1)*size,data+pivotIndex*size,size);
  // return pivot position
  return i+1;
}
void qs(int *data,int left,int right,size_t size,int (*cmp)(void*,void*)){
  int i;
  if(left<right){
    i = partition(data,left,right,size,cmp);
    qs(data,left,i-1,size,cmp);
    qs(data,i+1,right,size,cmp);
  }
}
int main(int argc, char const *argv[]) {
  FILE *fout,*fin;
  // initialize
  fout = fopen("test.in","rb");
  fin = fopen("test.out","wb");
  if(fout == NULL || fin == NULL){
    puts("Open failure");
    return 1;
  }
  int n;
  fscanf(fout,"%d",&n);
  do{
    int v[100000];
    for(int i=0; i<n; i++){
      fscanf(fout,"%d",&v[i]);
    }
    qs(v,0,n-1,sizeof(int),comp);
    for(int i=0; i<n; i++){
      fprintf(fin, "%d ",v[i]);
    }
    fprintf(fin, "\n");
  }while (fscanf(fout,"%d",&n)==1&&n);
  // close resource
  fclose(fin);
  fclose(fout);
  return 0;
}
