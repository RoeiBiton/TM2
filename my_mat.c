#include <stdio.h>
#include <ctype.h>
#include "my_mat.h"
int matrixBuild(int arr[10][10]) {
    int x;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &x);
           // printf("in A  [%d] [%d] = %d", i, j, x);
            arr[i][j] = x;
        }
    }
    return 1;
}
int isB(int arr[10][10]) {
    int userInput;
    int i;
    int j;
    scanf("%d %d",&i , &j);
   // printf("inside B, i = %d j =%d" ,i, j);
   if(Dist(arr, i, j)==0){
       printf("False\n");
   }
   else{
    printf("True\n");
   }
    return 1;
}
int isC(int arr[10][10]) {
    int userInput;
    int i;
    int j;
    scanf("%d %d",&i , &j);
  //  printf("inside C, i = %d j =%d" ,i, j);
    if(Dist(arr, i ,j)!=0){
        printf("%d\n", Dist(arr, i, j));
    }
    else{
        printf("-1\n");
    }
    return 1;
}
int Dist(int arr[10][10], int start, int dest){
        if(start==dest){
            arr[start][dest]=0;
            return 0;
        }
        for(int k =0; k<10; k++){
            for(int i =0; i<10; i++){
                for(int j =0; j<10; j++){
                    if(arr[i][k]==0 || arr[k][j]==0){
                        continue;
                    }
                    if(arr[i][j]==0||arr[i][k]+arr[k][j]<arr[i][j]){
                        arr[i][j]=arr[i][k]+arr[k][j];
                    }
                }
            }
        }
        return arr[start][dest];
}