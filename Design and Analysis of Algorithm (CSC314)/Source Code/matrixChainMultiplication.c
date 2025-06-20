#include <stdio.h>
#include <limits.h>

// Function to find minimum number of multiplications
int matrixChainOrder(int dims[], int n) {
    int m[n][n];  // m[i][j] stores minimum multiplications from matrix i to j

    // Set diagonal to 0 (only one matrix, no multiplication)
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // l is chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];  // minimum cost to multiply from M1 to Mn-1
}

int main() {
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int dims[n + 1];

    printf("Enter dimensions (P0 P1 ... Pn) such that matrix i has dimension Pi-1 x Pi:\n");
    for (int i = 0; i <= n; i++) {
        printf("P%d: ", i);
        scanf("%d", &dims[i]);
    }

    int minMultiplications = matrixChainOrder(dims, n + 1);
    printf("\nMinimum number of multiplications: %d\n", minMultiplications);

    return 0;
}
