#include <stdio.h>

// 素数
#define N 2999

int A[N];
int B[(N+4)/5];
// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int median(int A[], int n, int k){
  int i;
  if(n <= 5){
    int tmp;
      for(int a = 0;a < n;a++){
        for(int b = 0;b < n-a-1;b++){
          if(A[b] >= A[b+1]){
            tmp = A[b+1];
            A[b+1] = A[b];
            A[b] = tmp;
          }
        }
      }
      return A[k];//バブルソートでAの長さが5以下の時中央値を求める
    }else{//長さが5より長い

    int bsize = (n+4)/5;
      for(i = 0;i < n/5;i++){
        B[i] = median(A+i*5, 5, 2);//長さ5づつに分割して中央値を計算、代入
      }

    int c = n%5;
    if(c != 0){
      B[bsize-1] = median(A+n/5*5, c, c/2);//余りの分の計算
    }

    int pivot = median(B, bsize, bsize/2);//中央値をピボットとする
    
    for(i = 0;i < n;i++){
      if(A[i] == pivot){
        swap(A, A+i);//中央値を先頭に持ってくる
        break;
      }
    }


    int j, s;
    for(i = j = 1; i < n; i++){//2つの配列に分割する
      if(A[i] <= pivot){
        swap(A + i, A + j);
        j++;
      }
    }

    if(j-1 == k) return pivot;
    else if(j-1 < k) median(A+j, n-j, k-j);
    else median(A+1, j-1, k);

}}

int quick_select(int A[], int n, int k){
  int i, j, pivot;

// 真ん中の要素をピボットとする
  /* pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;*/
  pivot = median(A, N, N/2);
  for(i = 0;i < n;i++){
      if(A[i] == pivot){
        swap(A, A+i);//中央値を先頭に持ってくる
        break;
      }
    }
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k) return pivot;
  else if(j < k) return quick_select(A+j, n-j, k-j-1);
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
