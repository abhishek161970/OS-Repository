#include <stdio.h>
#include <string.h>

struct Process
{
    int pid;
    int at, bt, ct, tat, wt;
    char type[10];
};

int main()
{
    struct Process sq[10], uq[10];
    int ns = 0, nu = 0;
    int n, i, current_time = 0;

    printf("Abhishek G ---> 1BM24CS009\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        struct Process p;

        printf("\nEnter Process ID: ");
        scanf("%d", &p.pid);

        printf("Enter Arrival Time: ");
        scanf("%d", &p.at);

        printf("Enter Burst Time: ");
        scanf("%d", &p.bt);

        printf("Enter Type (System/User): ");
        scanf("%s", p.type);

        if(strcmp(p.type, "System") == 0)
        {
            sq[ns++] = p;
        }
        else
        {
            uq[nu++] = p;
        }
    }

    // Execute System Queue first
    for(i = 0; i < ns; i++)
    {
        if(current_time < sq[i].at)
            current_time = sq[i].at;

        current_time += sq[i].bt;

        sq[i].ct = current_time;
        sq[i].tat = sq[i].ct - sq[i].at;
        sq[i].wt = sq[i].tat - sq[i].bt;
    }

    // Execute User Queue
    for(i = 0; i < nu; i++)
    {
        if(current_time < uq[i].at)
            current_time = uq[i].at;

        current_time += uq[i].bt;

        uq[i].ct = current_time;
        uq[i].tat = uq[i].ct - uq[i].at;
        uq[i].wt = uq[i].tat - uq[i].bt;
    }

    float avgwt = 0, avgtat = 0;
    int total = ns + nu;

    printf("\n\nSYSTEM QUEUE PROCESSES\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < ns; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               sq[i].pid,
               sq[i].at,
               sq[i].bt,
               sq[i].ct,
               sq[i].tat,
               sq[i].wt);

        avgwt += sq[i].wt;
        avgtat += sq[i].tat;
    }

    printf("\nUSER QUEUE PROCESSES\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < nu; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               uq[i].pid,
               uq[i].at,
               uq[i].bt,
               uq[i].ct,
               uq[i].tat,
               uq[i].wt);

        avgwt += uq[i].wt;
        avgtat += uq[i].tat;
    }

    printf("\nAverage Turnaround Time = %.2f", avgtat / total);
    printf("\nAverage Waiting Time = %.2f\n", avgwt / total);

    printf("\nAbhishek G ---> 1BM24CS009\n");

    return 0;
}
