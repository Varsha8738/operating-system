#include<stdio.h> 
#define max 20 
int main(){ 
    int bt[max], at[max], ft[max], wt[max], tat[max]; 
    int i, j, x = 0, y = 0, z = 0, min = 0, temp1, temp2, k, l; 
    int n; 
    float t, u; 
    printf("Enter number of processes to be executed:\n"); 
    scanf("%d", &n); 
    for(i = 1; i <= n; i++) { 
        printf("Enter the burst time for process-%d:\n", i); 
        scanf("%d", &bt[i]); 
        printf("Enter the arrival time for process-%d:\n", i); 
        scanf("%d", &at[i]); 
    } 
    for(i = 1; i < n; i++) { 
        for(j = i + 1; j <= n; j++) { 
            if(at[i] > at[j]) { 
                temp1 = at[i]; 
                at[i] = at[j]; 
                at[j] = temp1; 
                temp2 = bt[i]; 
                bt[i] = bt[j]; 
                bt[j] = temp2; 
            } 
            else if(at[i] == at[j] && bt[i] > bt[j]) { 
                temp1 = at[i]; 
                at[i] = at[j]; 
                at[j] = temp1; 
                temp2 = bt[i]; 
                bt[i] = bt[j]; 
                bt[j] = temp2; 
            } 
        } 
    } 
    for(i = 1; i <= n; i++) { 
        min = min + bt[i];   
        for(j = i + 1; at[j] <= min; j++) { 
            for(k = j + 1; at[k] <= min; k++) { 
                if(bt[k] < bt[j]) { 
                    temp1 = bt[k]; 
                    bt[k] = bt[j]; 
                    bt[j] = temp1; 
                    temp2 = at[k]; 
                    at[k] = at[j]; 
                    at[j] = temp2; 
                } 
            } 
        } 
    } 
    for(i = 1; i <= n; i++) { 
        x = x + bt[i]; 
        ft[i] = x; 
        if(i == 1) 
            wt[i] = 0; 
        else 
            wt[i] = ft[i - 1] - at[i]; 
 
        tat[i] = bt[i] + wt[i]; 
    } 
    for(i = 1; i <= n; i++) { 
        y = y + tat[i]; 
        z = z + wt[i];   
    } 
    for(i = 1; i <= n; i++) { 
        printf("\nProcess:%d --> at: %d\n, bt: %d\n, ft: %d\n,wt: %d\n,tat: %d\n", 
                i, at[i], bt[i], ft[i], wt[i], tat[i]); 
    } 
    printf("\nAverage Waiting Time: %.2f", (float)z/n); 
    printf("\nAverage Turnaround Time: %.2f", (float)y/n); 
 
    return 0; 
}
OUTPUT:
Enter number of processes to be executed:
3
Enter the burst time for process-1:
1
Enter the arrival time for process-1:
2
Enter the burst time for process-2:
3
Enter the arrival time for process-2:
4
Enter the burst time for process-3:
5
Enter the arrival time for process-3:
6

Process:1 --> at: 2
, bt: 1
, ft: 1
,wt: 0
,tat: 1

Process:2 --> at: 4
, bt: 3
, ft: 4
,wt: -3
,tat: 0

Process:3 --> at: 6
, bt: 5
, ft: 9
,wt: -2
,tat: 3

Average Waiting Time: -1.67
Average Turnaround Time: 1.33
