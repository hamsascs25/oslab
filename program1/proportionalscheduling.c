
#include <stdio.h>
struct process
{
    int pid, tickets;
};

int main()
{int n, i, total = 0, lucky;
printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter number of tickets for P%d: ", p[i].pid);
        scanf("%d", &p[i].tickets);
        total += p[i].tickets;
    }
    printf("\nTotal Tickets = %d\n", total);

    printf("Enter lucky ticket number: ");
    scanf("%d", &lucky);
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += p[i].tickets;
        if(lucky <= sum)
        {
            printf("\nProcess P%d gets CPU\n", p[i].pid);
            break;
        }
    }

    return 0;
}
