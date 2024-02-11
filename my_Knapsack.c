#include <stdio.h>

#define NUM_ITEMS 5
#define MAX_WEIGHT 20

// Function to find the maximum of two integers
int max(int a, int b){
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int KnapSack(int weights[NUM_ITEMS], int values[NUM_ITEMS], int selected_bool[NUM_ITEMS]) {
    int profitChart[NUM_ITEMS + 1][MAX_WEIGHT + 1];

    // Build profit chart using dynamic programming
    for(int i = 0; i < NUM_ITEMS + 1; i++) {
        for(int w = 0; w < MAX_WEIGHT + 1; w++) {
            if(i == 0 || w == 0) {
                profitChart[i][w] = 0; // Base case where theres no items or no weight
            }
            else if(weights[i - 1] <= w) {
                // If current item can be included, update profitChart
                profitChart[i][w] = max(profitChart[i - 1][w],
                                        values[i - 1] + profitChart[i - 1][w - weights[i - 1]]);
            }
            else {
                // If current item's weight exceeds current limit, exclude it
                profitChart[i][w] = profitChart[i - 1][w];
            }
        }
    }

    // some actions to find the selected items which will marked as 1 in selected_bool
    int num = NUM_ITEMS;
    int wLim = MAX_WEIGHT;
    while(num > 0 && wLim > 0) {
        if(profitChart[num][wLim] != profitChart[num - 1][wLim]) {
            selected_bool[num - 1] = 1; // Mark item as selected
            wLim = wLim - weights[num - 1]; // Update remaining weight
        }
        num = num - 1; // Move to the previous item
    }

    // Return the maximum profit
    return profitChart[NUM_ITEMS][MAX_WEIGHT];
}

// Function to scan the input items from the user
void scanItemsFromUser(char names[NUM_ITEMS], int values[NUM_ITEMS], int weights[NUM_ITEMS]) {
    for(int i = 0; i < NUM_ITEMS; i++) {
        scanf(" %c" , &names[i]); // Input item name
        scanf("%d", &values[i]); // Input item value
        scanf("%d", &weights[i]); // Input item weight
    }
}

// Function to print selected items
void printSelectedItems(int selected_bool[NUM_ITEMS], char names[NUM_ITEMS]) {
    printf("Selected items:");
    for(int i = 0; i < NUM_ITEMS; i++) {
        if(selected_bool[i] == 1) {
            printf(" %c", names[i]); // Print selected item names
        }
    }
}

int main(){
    // Defining the arrays of names, values, weights and the selected items array that named selected_bool
    char names[NUM_ITEMS];
    int values[NUM_ITEMS];
    int weights[NUM_ITEMS];
    int selected_bool[NUM_ITEMS];
    // Scan the items from the use
    scanItemsFromUser(names, values, weights);
    // Calculate the max profit that can be achieved in that weight limit
    int maxProfit = KnapSack(weights,values,selected_bool);
    // Print results
    printf("Maximum profit: %d\n", maxProfit);
    printSelectedItems(selected_bool,names);

    return 0;
}