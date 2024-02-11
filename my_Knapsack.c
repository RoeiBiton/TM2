#include <stdio.h>
#define NUM_ITEMS 5
#define MAX_WEIGHT 20

int max(int a, int b){
    return (a>b) ? a : b;
}

int KnapSack(int weights[NUM_ITEMS], int values[NUM_ITEMS], int selected_bool[NUM_ITEMS]) {
    int profitChart[NUM_ITEMS + 1][MAX_WEIGHT + 1];

    for(int i=0; i<NUM_ITEMS+1; i++){
        for(int w=0; w<MAX_WEIGHT+1; w++){
            if(i==0 || w==0){ profitChart[i][w] = 0;}
            else if(weights[i-1]<=w) {
                profitChart[i][w] = max(profitChart[i - 1][w], values[i - 1] + profitChart[i - 1][w - weights[i - 1]]);
            }
            else{
                profitChart[i][w] = profitChart[i-1][w];
            }
        }
    }
    int num=NUM_ITEMS;
    int wLim = MAX_WEIGHT;

    while(num>0 && wLim>0){
        if(profitChart[num][wLim] != profitChart[num-1][wLim]){
            selected_bool[num-1] = 1;
            wLim= wLim-weights[num-1];
        }
        num= num-1;
    }

    return profitChart[NUM_ITEMS][MAX_WEIGHT];
}

void scanItemsFromUser(char names[NUM_ITEMS], int values[NUM_ITEMS], int weights[NUM_ITEMS]){
    for(int i=0; i<NUM_ITEMS; i++){
        scanf(" %c" , &names[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
}

void printSelectedItems(int selected_bool[NUM_ITEMS], char names[NUM_ITEMS]){
    printf("Selected items:");
    for(int i=0; i<NUM_ITEMS; i++){
        if(selected_bool[i]==1){
            printf(" %c", names[i]);
        }
    }
}



int main(){
    char names[NUM_ITEMS];
    int values[NUM_ITEMS];
    int weights[NUM_ITEMS];
    int selected_bool[NUM_ITEMS];
    scanItemsFromUser(names, values, weights);
    int maxProfit = KnapSack(weights,values,selected_bool);
    printf("Maximum profit: %d\n", maxProfit);
    printSelectedItems(selected_bool,names);

    return 0;
}