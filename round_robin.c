#include <stdio.h>

int main() {
    int at[10], bt[10], wt[10], st[10], tat[10], n, tq;
    int i, count = 0, swt = 0, stat = 0, temp, sq = 0, j, temp1, temp2;
    float awt = 0.0, atat = 0.0;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Sort by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp1 = at[i];
                at[i] = at[j];
                at[j] = temp1;

                temp2 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp2;
            }
        }
    }

    for (i = 0; i < n; i++) {
        st[i] = bt[i];
        printf("Process %d - Arrival Time: %d, Burst Time: %d\n", i + 1, at[i], bt[i]);
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &tq);

    // Round Robin Scheduling
    while (1) {
        count = 0;
        for (i = 0; i < n; i++) {
            temp = tq;
            if (st[i] == 0) {
                count++;
                continue;
            }

            if (st[i] > tq) {
                st[i] -= tq;
            } else {
                temp = st[i];
                st[i] = 0;
            }

            sq += temp;
            tat[i] = sq - at[i];
        }

        if (count == n) {
            break;
        }
    }

    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        swt += wt[i];
        stat += tat[i];
    }

    awt = (float)swt / n;
    atat = (float)stat / n;

    printf("\nProcess No\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time: %.2f\n", awt);
    printf("Average turn-around time: %.2f\n", atat);

    return 0;
}
OUTPUT:
Enter number of processes:
3
Enter burst times:
1
2
3
Enter arrival times:
4
5
6
Process 1 - Arrival Time: 4, Burst Time: 1
Process 2 - Arrival Time: 5, Burst Time: 2
Process 3 - Arrival Time: 6, Burst Time: 3

Enter time quantum: 4

Process No      Arrival Time    Burst Time      Waiting Time    Turnaround Time
1               4               1               -4              -3
2               5               2               -4              -2
3               6               3               -3              0

Average waiting time: -3.67
Average turn-around time: -1.67
