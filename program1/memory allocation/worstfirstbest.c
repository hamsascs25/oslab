#include <stdio.h>

int main()
{
    int m, n, i, j, choice;
    int block[20], process[20], temp[20];
    int allocation[20], idx;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter sizes of processes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &process[i]);

    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    for(i = 0; i < m; i++)
        temp[i] = block[i];

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    for(i = 0; i < n; i++)
    {
        idx = -1;

        if(choice == 1) // First Fit
        {
            for(j = 0; j < m; j++)
            {
                if(temp[j] >= process[i])
                {
                    idx = j;
                    break;
                }
            }
        }

        else if(choice == 2) // Best Fit
        {
            for(j = 0; j < m; j++)
            {
                if(temp[j] >= process[i])
                {
                    if(idx == -1 || temp[j] < temp[idx])
                        idx = j;
                }
            }
        }

        else if(choice == 3) // Worst Fit
        {
            for(j = 0; j < m; j++)
            {
                if(temp[j] >= process[i])
                {
                    if(idx == -1 || temp[j] > temp[idx])
                        idx = j;
                }
            }
        }

        if(idx != -1)
        {
            allocation[i] = idx;
            temp[idx] -= process[i];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
