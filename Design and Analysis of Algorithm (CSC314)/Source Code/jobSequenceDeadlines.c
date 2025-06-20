#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Job structure
typedef struct {
    char id[5];
    int deadline;
    int profit;
} Job;

// Comparison function to sort jobs by profit (descending)
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare); // Sort jobs by profit descending

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    char schedule[maxDeadline + 1][5];  // Store job ids
    int slot[maxDeadline + 1];         // Track free slots

    for (int i = 1; i <= maxDeadline; i++)
        slot[i] = 0;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline); j >= 1; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                strcpy(schedule[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Jobs in sequence:\n");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i])
            printf("Time Slot %d: Job %s\n", i, schedule[i]);
    }

    printf("Total Profit: %d\n", totalProfit);
}

int main() {
    int n;
    Job jobs[MAX];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter job details (ID Deadline Profit):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}
