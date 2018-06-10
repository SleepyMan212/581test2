#include <bits/stdc++.h>
using namespace std;
FILE* openFile(const char* file_name,const char* mode){
  FILE* file = fopen(file_name,mode);
  if(!file){
    cout << "Open file fail" << endl;
  }
  return file;
}
void swapRow(double matrix[][101],int r1,int r2,int n){
  double tmp[n+1];
  for(int i=0; i<n+1; ++i) tmp[i]=matrix[r1][i];
  for(int i=0; i<n+1; ++i) matrix[r1][i]=matrix[r2][i];
  for(int i=0; i<n+1; ++i) matrix[r2][i]=tmp[i];

}
int  determinant(double matrix[][101],int n){
  double ans = 1;
  int swap_count = 0;
  for(int i=0; i<n; i++){
    // check the pivot
    if(abs(matrix[i][i]) < 1e-6){
      for(int j=i+1; j<n; j++){
        if(matrix[i][j] >= 1e-3 ){
          swapRow(matrix,i,j,n);
          ++swap_count;
        }
      }
    }
    // elimination
    for(int j=i+1; j<n; j++){
      double factor_a = matrix[j][i];
      double factor_b = matrix[i][i];
      double tmp[n+1];
      for(int k=i; k<n+1; k++){
        matrix[j][k] = (matrix[i][k] * factor_a *(-1) + matrix[j][k] * factor_b);
        if(matrix[j][k] != 0) matrix[j][k] /= factor_b;
        // make too small be zero
        matrix[j][k] = abs(matrix[j][k]) < 1e-5 ? 0. : matrix[j][k];
      }
    }

    // make pivot be 1
    double factor = matrix[i][i];
    for(int j=0; j<n+1; j++){
      if(matrix[i][j]!=0)
        matrix[i][j]/=factor;
    }
    ans*=factor;
  }
  return ans*(swap_count%2?-1:1);
}
bool getX(double X[101], double matrix[][101],int n){
  bool success = true;
  double tmp[n][n+1];

  // copy matrix to tmp
  for(int i=0; i<n; i++){
    for(int j=0; j<n+1; j++){
      tmp[i][j] = matrix[i][j];
    }
  }
  // back replace
  for(int i=n-1; i>=0; i--){
    if(tmp[i][i] == 0){
      success = false;
      break;
    }
    // cal x
    X[i] = tmp[i][n] / tmp[i][i];
    for(int j=i-1; j>=0; j--){
      for(int k=n-1; k>=i; k--){
        tmp[j][n] -= X[k] * tmp[j][k];
        tmp[j][k] = 0;
      }
    }
  }

  return success;
}
bool vaild(double matrix[][101],double X[101],int n){
  bool is_success = true;

  for(int i=0; i<n; i++){
    double tmp = 0;
    for(int j=0; j<n; j++){
      tmp += matrix[i][j]*X[j];
    }
    if(abs(tmp - matrix[i][n]) < 1e-6){
      is_success = false;
      break;
    }
  }
}
int main(int argc, char const *argv[]) {
  // initialize
  FILE *fin,*fout;
  int n,tmp,nc=0;
  if(!argv[1]||!argv[2]){
    printf("%s\n","Please input the input file and output file");
    return 1;
  }
  fin = openFile(argv[1],"r");
  fout = openFile(argv[2],"w+");
  // end initialize
  while (fscanf(fin,"%d",&n)==1&&n) {
    fprintf(fout,"Case %d: n=%d\n\n",++nc,n);
    double matrix[100][101];
    // input
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        fscanf(fin,"%lf",&matrix[i][j]);
      }
    }
    for(int i=0; i<n; i++){
      fscanf(fin,"%lf",&matrix[i][n]);
    }
    // end input

    // calculate
    double deter = determinant(matrix,n);
    double X[101];
    memset(X,0,sizeof(X));
    bool sol = getX(X,matrix,n);
    bool success = vaild(matrix,X,n);
    // end calculate

    // output
    for(int i=0; i<n; ++i){
      for(int j=0; j<n+1; ++j){
        fprintf(fout,"%lf ", matrix[i][j]);
      }
      fprintf(fout,"\n");
    }
    if(deter == 0){
      fprintf(fout,"\n%s\n","Determinant is zero ");
    }else{
      fprintf(fout,"\n%s%lf\n","Determinant = ",deter);
    }
    if(success == false){
      printf("%s\n","The result is not the solution for X" );
    }else if(sol == true){
      fprintf(fout,"%s", " X= ");
      for(int i=0; i<n; i++){
        fprintf(fout,"%lf ", X[i]);
      }
      fprintf(fout,"\n");
    }
    fprintf(fout,"%s\n","------------------------------------");
    // end output
  }
  return 0;
}
