#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;

    int at[10], bt[10], rt[10];
    int ct[10], tat[10], wt[10];

    printf("Abhishek G ---> 1BM24CS009\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nSJF Preemptive Scheduling Execution:\n\n");

    while(completed != n)
    {
        int shortest = -1;
        int min = 9999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time &&
               rt[i] > 0 &&
               rt[i] < min)
            {
                min = rt[i];
                shortest = i;
            }
        }

        if(shortest == -1)
        {
            printf("%dms : CPU is Idle\n", time);

            time++;

            continue;
        }

        printf("%dms : Process P%d is running\n",
               time,
               shortest + 1);

        rt[shortest]--;

        time++;

        if(rt[shortest] == 0)
        {
            completed++;

            ct[shortest] = time;

            tat[shortest] =
                ct[shortest] - at[shortest];

            wt[shortest] =
                tat[shortest] - bt[shortest];
        }
    }

    float avgwt = 0, avgtat = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);

        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f",
           avgwt / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           avgtat / n);

    printf("\nAbhishek G ---> 1BM24CS009\n");

    return 0;
}
