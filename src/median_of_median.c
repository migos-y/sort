#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int midian(int A[], int k){
  int n = sizeof(A);
  int tmp;
  if(n <= 5){
      for(int a = 0;a < n;a++){
        for(int b = 0;b < n-a-1;b++){
          if(A[b] >= A[b+1]){
            tmp = A[b+1];
            A[b+1] = A[b];
            A[b] = tmp;
          }
        }
      }
      return A[k];
    }

  }else{
  int A2[(n+4)/5];

}}

int quick_select(int A[], int n, int k){
  int i, j, pivot;

// 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k+1) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+1, j-1, k);
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
