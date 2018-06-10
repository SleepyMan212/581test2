using namespace std;
void swap(int &a,int &b){
  int t=a;
  b=t;
}
void print(int *data,int size){
  for(int i=0; i<size; i++){
    cout<<data[i]<<" ";
  }
  cout<<endl;
}
int partition(int *data,int left,int right){

  srand(time(NULL));
  int pivotIndex = left + rand()%(right - left + 1);
  int pivot = data[pivotIndex];
  swap(data[pivotIndex],data[right]);
  pivotIndex = right;
  int i = left -1;
  for(int j=left; j<right; j++){
    if(data[j]<=pivot){
      i++;
      swap(data[i],data[j]);
    }
  }
  swap(data[i+1],data[pivotIndex]);
  return i+1;
}
void qs(int *data,int left,int right){
  int i;
  if(left<right){
    i = partition(data,left,right);
    qs(data,left,i-1);
    qs(data,i+1,right);
  }
}
int main(int argc, char const *argv[]) {
  FILE *fout,*fin;
  fout = fopen("test.in","rb");
  fin = fopen("test.out","wb");
  if(fout == NULL || fin == NULL){
    cout<<"Open failure"<<endl;
    return 1;
  }
  int n;
  int v[100000];
  fscanf(fout,"%d",&n);
  do{
    for(int i=0; i<n; i++){
      fscanf(fout,"%d",&v[i]);
    }
    qs(v,0,n-1);
    for(int i=0; i<n; i++){
      fprintf(fin, "%d ",v[i]);
    }
    fprintf(fin, "\n");
  }while (fscanf(fout,"%d",&n)==1&&n);
  fclose(fin);
  fclose(fout);
  return 0;
}
