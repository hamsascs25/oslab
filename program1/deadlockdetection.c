

#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], req[n][m], avail[m];
    int finish[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &req[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int found;

    for(k = 0; k < n; k++)
    {
        found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(req[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    finish[i] = 1;
                    found = 1;

                    printf("Process P%d completed\n", i);
                }
            }
        }

        if(found == 0)
            break;
    }

    int deadlock = 0;

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            deadlock = 1;
            printf("Process P%d is in Deadlock\n", i);
        }
    }

    if(deadlock == 0)
        printf("\nNo Deadlock Detected\n");

    return 0;
}
