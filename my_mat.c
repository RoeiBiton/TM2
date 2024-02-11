#include <stdio.h>
#include <ctype.h>
#include "my_mat.h"

// Function to populate a 10x10 matrix with user input
int matrixBuild(int arr[10][10]) {
    int x;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &x); // Read an integer from user input
            arr[i][j] = x; // Store the integer in the matrix
        }
    }
    return 1; // Return to main
}

// Function to check if there is a path between two vertices in the matrix
int isB(int arr[10][10]) {
    int userInput;
    int i;
    int j;
    scanf("%d %d",&i , &j); // Read two integers representing vertices from user input
    if(Dist(arr, i, j)==0){ // Check if there is no path between the vertices
        printf("False\n"); // Print "False" if there is no path
    }
    else{
        printf("True\n"); // Print "True" if there is a path between the vertices
    }
    return 1; // Return to main
}

// Function that calculate the shortest distance between two vertices in the matrix
int isC(int arr[10][10]) {
    int userInput;
    int i;
    int j;
    scanf("%d %d",&i , &j); // Read two integers representing vertices from user input
    if(Dist(arr, i ,j)!=0){ // Check if there is a path between the vertices
        printf("%d\n", Dist(arr, i, j)); // Print the shortest distance between the vertices
    }
    else{
        printf("-1\n"); // Print -1 if there is no path between the vertices
    }
    return 1; // Return to main
}

// Function to calculate the shortest distance between two vertices
int Dist(int arr[10][10], int start, int dest){
    if(start==dest){
        arr[start][dest]=0; // Set the distance between a vertex and itself to 0
        return 0; // Return 0 to indicate that the distance is 0
    }
    for(int k =0; k<10; k++){
        for(int i =0; i<10; i++){
            for(int j =0; j<10; j++){
                if(arr[i][k]==0 || arr[k][j]==0){
                    continue; // Skip if there's no direct edge between vertices i and k, or between k and j
                }
                if(arr[i][j]==0||arr[i][k]+arr[k][j]<arr[i][j]){
                    arr[i][j]=arr[i][k]+arr[k][j]; // Update the shortest distance if a shorter path is found
                }
            }
        }
    }
    return arr[start][dest]; // Return the shortest distance between the specified vertices
}