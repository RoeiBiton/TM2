#include <stdio.h>
#include <ctype.h>
#include "my_mat.h"
int main() {
    //Defining user input and the matrix
    char userInput;
    int arr[10][10];
    //a running loop that respond to A, B, C and D
    while (userInput != 'D') {
        scanf("%c", &userInput);
        if (userInput == 'D') { return 0; } //End the program
        if (userInput == 'A') { matrixBuild(arr);}
        if (userInput == 'B') { isB(arr); }
        if (userInput == 'C') {isC(arr);}
    }
}



