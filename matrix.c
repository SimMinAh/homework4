#include <stdio.h>
#include <stdlib.h>

void print_matrix();//행렬을 출력한다
void addition_matrix(); //행렬을 더한다
void subtraction_matrix(); //행렬을 뺀다
void transpose_matrix(); //A의 전치행렬을 구한다
void multiply_matrix(); //A*B를 구한다 
void free_matrix(); //동적할당을 해제한다

int main()
{
    printf("[----- [simmina] [2022041070] -----]\n");
    int n, m;
    printf("n*m행렬을 생성할 때 n과 m의 값을 입력하세요 :\n");
    scanf("%d %d", &n, &m);
    int** arrA; //2중 포인터를 사용해 2차원 배열 동적할당을 받는다
    arrA = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        arrA[i] = (int*)malloc(sizeof(int) * m);
    }

    printf("행렬 A의 값을 입력하세요 :"); //이중 for문을 사용해 행렬 A의 값을 받는다
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arrA[i][j]);
        }
        
    }
    int** arrB; //2중 포인터를 사용해 2차원 배열 동적할당을 받는다
    arrB = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        arrB[i] = (int*)malloc(sizeof(int) * m);
    }
    
    printf("행렬 B의 값을 입력하세요 :"); //이중 for문을 사용해 행렬 B의 값을 받는다
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arrB[i][j]);
        }
   
    }
    
    print_matrix(arrA,arrB, n, m);
    addition_matrix(arrA, arrB, n, m);
    subtraction_matrix(arrA, arrB, n, m);
    transpose_matrix(arrA, n, m);
    multiply_matrix(arrA, arrB, n, m);
    free_matrix(arrA, arrB, n, m);
}
void print_matrix(int **arrA[], int **arrB[], int n, int m) {
  for (int i = 0; i < n; i++) { //이중 for문을 사용해 행렬 A를 출력한다
        for (int j = 0; j < m; j++) {
            printf("%d ", arrA[i][j]);
        }
        printf("\n");
    }
  
  printf("\n");

  for (int i = 0; i < n; i++) { //이중 for문을 사용해 행렬 B를 출력한다
      for (int j = 0; j < m; j++) {
          printf("%d ", arrB[i][j]);
      }
      printf("\n");
  }
}
void addition_matrix(int **arrA[], int **arrB[], int n, int m) {
    int** arrC; //계산한 값을 받을 배열 C을 동적할당 받는다
    arrC = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        arrC[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) { //배열 A와 B의 합을 C에 넣는다
        for (int j = 0; j < m; j++) {
            arrC[i][j] =arrA[i][j]+arrB[i][j];
        }
    }
    for (int i = 0; i < n; i++) {//C의 동적할당을 해제한다
        free(arrC[i]);
    }
    free(arrC);

}
void subtraction_matrix(int **arrA[], int **arrB[], int n, int m) {
    int** arrC; //계산한 값을 받을 배열 C을 동적할당 받는다
    arrC = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        arrC[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) { //배열 A와 B의 차를 C에 넣는다
        for (int j = 0; j < m; j++) {
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
    for (int i = 0; i < n; i++) {//C의 동적할당을 해제한다
        free(arrC[i]);
    }
    free(arrC);

}
void transpose_matrix(int** arrA[], int n, int m) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        // 전치를 한줄씩row 할 때마다 전치해야 할 줄과 컬럼이 하나씩  줄어든다
        for (int j = 0 + i; j < n; j++) {
            tmp = arrA[i][j];
            arrA[i][j] = arrA[j][i]; // 행과 열 인덱스를 바꾸어 저장한다
            arrA[j][i] = tmp;
        }
    }

}
void multiply_matrix(int **arrA[], int **arrB[], int n, int m) {
    int** arrC; //계산한 값을 받을 배열 C을 동적할당 받는다
    arrC = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        arrC[i] = (int*)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) { //배열 A와 B의 곱을 C에 넣는다
        for (int j = 0; j < m; j++) {
            arrC[i][j] = arrA[i][j] * arrB[i][j];;
        }
    }
    for (int i = 0; i < n; i++) { //C의 동적할당을 해제한다
        free(arrC[i]);
    }
    free(arrC);

}
void free_matrix(int arrA[], int arrB[], int n, int m) {
    for (int i = 0; i < n; i++) { //A의 동적할당을 해제한다
        free(arrA[i]);
    }
    free(arrA);

    for (int i = 0; i < n; i++) { //B의 동적할당을 해제한다
        free(arrB[i]);
    }
    free(arrB);

}