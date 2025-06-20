#include <stdio.h>

struct Item {
    int weight;
    int value;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value/weight ratio in descending order
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float r1 = (float)arr[j].value / arr[j].weight;
            float r2 = (float)arr[j + 1].value / arr[j + 1].weight;
            if (r1 < r2) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to perform Fractional Knapsack
float fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortItems(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take the full item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fractional part
            float fraction = (float)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            break; // knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(items, n, capacity);
    printf("\nMaximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
