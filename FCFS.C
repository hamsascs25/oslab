#include <stdio.h>


int main()
{
    int n, i;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    float atat = 0, awt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        atat += tat[i];
        awt += wt[i];
    }

    atat = atat / n;
    awt = awt / n;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time (ATAT) = %.2f", atat);
    printf("\nAverage Waiting Time (AWT) = %.2f", awt);

    return 0;
}
