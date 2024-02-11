#include <stdio.h>
#include <ctype.h>
#include "my_mat.h"
int main() {

    char userInput;
    int arr[10][10];

    while (userInput != 'D') {
        scanf("%c", &userInput);
        if (userInput == 'D') { return 0; }
        if (userInput == 'A') { matrixBuild(arr);}
        if (userInput == 'B') { isB(arr); }
        if (userInput == 'C') {isC(arr);}
    }
}



