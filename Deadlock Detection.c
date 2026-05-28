#include <stdio.h>

int main()
{
    int n, m, i, j;

    printf("Abhishek G ---> 1BM24CS009\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[10][10], request[10][10];
    int avail[10];

    int finish[10] = {0};

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
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");

    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
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
                    if(request[i][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    for(j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    int deadlock = 0;

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            deadlock = 1;
            printf("\nProcess P%d is deadlocked.", i);
        }
    }

    if(deadlock == 0)
    {
        printf("\nNo Deadlock detected.");
    }

    printf("\n\nAbhishek G ---> 1BM24CS009\n");

    return 0;
}
