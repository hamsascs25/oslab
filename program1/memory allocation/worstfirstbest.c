#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, choice;
    int i, j, k, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
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

    faults = 0;

    // FIFO
    if(choice == 1) {
        int front = 0, found;

        for(i = 0; i < n; i++) {
            found = 0;

            for(j = 0; j < f; j++) {
                if(frames[j] == pages[i]) {
                    found = 1;
                    break;
                }
            }

            if(!found) {
                frames[front] = pages[i];
                front = (front + 1) % f;
                faults++;
            }
        }

        printf("\nFIFO Page Faults = %d", faults);
    }

    // LRU
    else if(choice == 2) {
        int recent[10], min, pos, found;

        for(i = 0; i < f; i++)
            recent[i] = -1;

        for(i = 0; i < n; i++) {
            found = 0;

            for(j = 0; j < f; j++) {
                if(frames[j] == pages[i]) {
                    found = 1;
                    recent[j] = i;
                    break;
                }
            }

            if(!found) {
                pos = 0;
                min = recent[0];

                for(j = 1; j < f; j++) {
                    if(recent[j] < min) {
                        min = recent[j];
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
                recent[pos] = i;
                faults++;
            }
        }

        printf("\nLRU Page Faults = %d", faults);
    }

    // Optimal
    else if(choice == 3) {
        int found, pos, farthest, next;

        for(i = 0; i < n; i++) {
            found = 0;

            for(j = 0; j < f; j++) {
                if(frames[j] == pages[i]) {
                    found = 1;
                    break;
                }
            }

            if(!found) {

                for(j = 0; j < f; j++) {
                    if(frames[j] == -1) {
                        frames[j] = pages[i];
                        faults++;
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    farthest = -1;
                    pos = -1;

                    for(j = 0; j < f; j++) {
                        next = 999;

                        for(k = i + 1; k < n; k++) {
                            if(frames[j] == pages[k]) {
                                next = k;
                                break;
                            }
                        }

                        if(next > farthest) {
                            farthest = next;
                            pos = j;
                        }
                    }

                    frames[pos] = pages[i];
                    faults++;
                }
            }
        }

        printf("\nOptimal Page Faults = %d", faults);
    }

    else {
        printf("Invalid Choice");
    }

    return 0;
}
