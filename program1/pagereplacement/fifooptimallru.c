#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, choice;
    int i, j, k, found, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("\n1. FIFO");
    printf("\n2. LRU");
    printf("\n3. Optimal");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\t");
    for(i = 0; i < f; i++)
        printf("F%d\t", i + 1);
    printf("Status\n");

    // FIFO
    if(choice == 1)
    {
        int front = 0;

        for(i = 0; i < n; i++)
        {
            found = 0;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == pages[i])
                {
                    found = 1;
                    break;
                }
            }

            if(!found)
            {
                frames[front] = pages[i];
                front = (front + 1) % f;
                faults++;
            }

            printf("%d\t", pages[i]);

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                    printf("-\t");
                else
                    printf("%d\t", frames[j]);
            }

            if(found)
                printf("Hit\n");
            else
                printf("Fault\n");
        }

        printf("\nFIFO Page Faults = %d\n", faults);
    }

    // LRU
    else if(choice == 2)
    {
        int recent[10];

        for(i = 0; i < f; i++)
            recent[i] = -1;

        for(i = 0; i < n; i++)
        {
            found = 0;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == pages[i])
                {
                    found = 1;
                    recent[j] = i;
                    break;
                }
            }

            if(!found)
            {
                int pos = 0;

                for(j = 1; j < f; j++)
                {
                    if(recent[j] < recent[pos])
                        pos = j;
                }

                frames[pos] = pages[i];
                recent[pos] = i;
                faults++;
            }

            printf("%d\t", pages[i]);

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                    printf("-\t");
                else
                    printf("%d\t", frames[j]);
            }

            if(found)
                printf("Hit\n");
            else
                printf("Fault\n");
        }

        printf("\nLRU Page Faults = %d\n", faults);
    }

    // Optimal
    else if(choice == 3)
    {
        for(i = 0; i < n; i++)
        {
            found = 0;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == pages[i])
                {
                    found = 1;
                    break;
                }
            }

            if(!found)
            {
                int empty = -1;

                for(j = 0; j < f; j++)
                {
                    if(frames[j] == -1)
                    {
                        empty = j;
                        break;
                    }
                }

                if(empty != -1)
                {
                    frames[empty] = pages[i];
                }
                else
                {
                    int pos = -1, farthest = -1;

                    for(j = 0; j < f; j++)
                    {
                        int nextUse = 9999;

                        for(k = i + 1; k < n; k++)
                        {
                            if(frames[j] == pages[k])
                            {
                                nextUse = k;
                                break;
                            }
                        }

                        if(nextUse > farthest)
                        {
                            farthest = nextUse;
                            pos = j;
                        }
                    }

                    frames[pos] = pages[i];
                }

                faults++;
            }

            printf("%d\t", pages[i]);

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                    printf("-\t");
                else
                    printf("%d\t", frames[j]);
            }

            if(found)
                printf("Hit\n");
            else
                printf("Fault\n");
        }

        printf("\nOptimal Page Faults = %d\n", faults);
    }

    return 0;
}
