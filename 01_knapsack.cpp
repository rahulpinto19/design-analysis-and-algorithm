#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack function
int knapsack(int capacity, int weights[], int values[], int numItems) {
    int dp[numItems + 1][capacity + 1];

    for (int i = 0; i <= numItems; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[numItems][capacity];
}

int main() {
    int numItems = 4;
    int capacity = 5;
    int values[] = {10, 40, 30, 50};
    int weights[] = {5, 4, 6, 3};

    int maxValue = knapsack(capacity, weights, values, numItems);

    printf("Maximum value that can be obtained: %d\n", maxValue);

    return 0;
}
