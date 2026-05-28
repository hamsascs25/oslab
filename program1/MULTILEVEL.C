#include <stdio.h>
#include <string.h>

struct process {
    int pid, at, bt;
    char type[10];
    int wt, tat, ct;
};

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n], temp;

  
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess %d Type (System/User): ", i + 1);
        scanf("%s", p[i].type);

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((strcmp(p[i].type, "User") == 0 && strcmp(p[j].type, "System") == 0) ||
                (strcmp(p[i].type, p[j].type) == 0 && p[i].at > p[j].at)) {

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = 0;

    for (i = 0; i < n; i++) {
        if (time < p[i].at)
            time = p[i].at;

        p[i].wt = time - p[i].at;
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
    }

   
    float total_wt = 0, total_tat = 0;

    printf("\nPID\tType\tAT\tBT\tWT\tTAT\tCT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].type, p[i].at, p[i].bt,
               p[i].wt, p[i].tat, p[i].ct);

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage WT = %.2f", total_wt / n);
    printf("\nAverage TAT = %.2f\n", total_tat / n);

    return 0;
}

