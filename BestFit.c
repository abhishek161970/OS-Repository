#include <stdio.h>

int main()
{
    int blocks[10], processes[10];
    int allocation[10];
    int m, n, i, j;

    printf("Abhishek G ---> 1BM24CS009\n");

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter sizes of %d memory blocks:\n", m);

    for(i = 0; i < m; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter sizes of %d processes:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &processes[i]);

        allocation[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        int best = -1;

        for(j = 0; j < m; j++)
        {
            if(blocks[j] >= processes[i])
            {
                if(best == -1 || blocks[j] < blocks[best])
                {
                    best = j;
                }
            }
        }

        if(best != -1)
        {
            allocation[i] = best;

            blocks[best] -= processes[i];
        }
    }

    printf("\n----- Best Fit -----\n");

    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t",
               i + 1,
               processes[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    printf("\nAbhishek G ---> 1BM24CS009\n");

    return 0;
}
