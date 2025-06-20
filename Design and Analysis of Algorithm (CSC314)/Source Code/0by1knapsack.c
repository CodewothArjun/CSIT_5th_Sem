#include <stdio.h>
#include <stdlib.h>

// Function to return max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Knapsack function using Dynamic Programming
int knapsack(int capacity, int weight[], int value[], int n) {
    int i, w;
    int K[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][capacity];
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int value[n], weight[n];

    printf("Enter values of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &value[i]);
    }

    printf("Enter weights of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weight[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    int maxProfit = knapsack(capacity, weight, value, n);
    printf("\nMaximum value that can be obtained: %d\n", maxProfit);

    return 0;
}

