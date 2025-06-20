#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))

int min(int a, int b, int c) {
    return MIN(MIN(a, b), c);
}

int editDistance(char str1[], char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];

    // Fill dp[][] bottom up
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, insert all characters of second
            if (i == 0)
                dp[i][j] = j;
            // If second string is empty, remove all characters of first
            else if (j == 0)
                dp[i][j] = i;
            // If last characters are the same, ignore and recur for remaining
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            // If last characters are different, consider all possibilities
            else
                dp[i][j] = 1 + min(dp[i][j - 1],    // Insert
                                   dp[i - 1][j],    // Remove
                                   dp[i - 1][j - 1] // Replace
                                  );
        }
    }
    return dp[m][n];
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int distance = editDistance(str1, str2);
    printf("\nMinimum Edit Distance = %d\n", distance);
    return 0;
}
