#include <stdio.h>

int main()
{
    int n, m, i, j;

    printf("Abhishek G ---> 1BM24CS009\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10];
    int finish[10] = {0};
    int safeSeq[10];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    safeSeq[count++] = i;

                    for(j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    if(count == n)
    {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");

        for(i = 0; i < n; i++)
        {
            printf("P%d ", safeSeq[i]);
        }
    }
    else
    {
        printf("\nSystem is NOT in safe state.\n");
    }

    printf("\n\nAbhishek G ---> 1BM24CS009\n");

    return 0;
}
