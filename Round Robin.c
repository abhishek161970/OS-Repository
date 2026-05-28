#include <stdio.h>

int main()
{
    int n, tq;
    int bt[10], rt[10], wt[10], tat[10];
    int i, time = 0, remain;

    printf("Abhishek G ---> 1BM24CS009\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter Burst Time for each process:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);

        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nRound Robin Scheduling Execution:\n\n");

    while(remain != 0)
    {
        int done = 1;

        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0)
            {
                done = 0;

                if(rt[i] > tq)
                {
                    printf("Process P%d runs from %d to %d\n",
                           i + 1,
                           time,
                           time + tq);

                    time += tq;

                    rt[i] -= tq;
                }
                else
                {
                    printf("Process P%d runs from %d to %d\n",
                           i + 1,
                           time,
                           time + rt[i]);

                    time += rt[i];

                    wt[i] = time - bt[i];

                    rt[i] = 0;

                    tat[i] = wt[i] + bt[i];

                    remain--;
                }
            }
        }

        if(done == 1)
            break;
    }

    float avgwt = 0, avgtat = 0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1,
               bt[i],
               wt[i],
               tat[i]);

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
