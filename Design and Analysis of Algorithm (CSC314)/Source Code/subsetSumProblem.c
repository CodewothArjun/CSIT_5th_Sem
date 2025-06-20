#include <stdio.h>
#define MAX 100

int subsetSum(int set[], int n, int sum) {
    int dp[n+1][sum+1];

    // Initialize dp[0][...] = 0 and dp[...][0] = 1
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - set[i-1]];
        }
    }

    return dp[n][sum];
}

int main() {
    int set[MAX], n, sum;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    if (subsetSum(set, n, sum))
        printf("Subset with given sum exists.\n");
    else
        printf("No subset with given sum found.\n");

    return 0;
}
