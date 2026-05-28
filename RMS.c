#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int n, i, time;
    int bt[10], period[10], remain[10];
    int hyper = 1;

    printf("Abhishek G ---> 1BM24CS009\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter CPU burst times:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        remain[i] = bt[i];
    }

    printf("Enter time periods:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &period[i]);
        hyper = lcm(hyper, period[i]);
    }

    printf("\nLCM = %d\n", hyper);

    printf("\nRate Monotonic Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, bt[i], period[i]);
    }

    printf("\nScheduling occurs for %d ms\n\n", hyper);

    for(time = 0; time < hyper; time++)
    {
        for(i = 0; i < n; i++)
        {
            if(time % period[i] == 0)
                remain[i] = bt[i];
        }

        int selected = -1;
        int minPeriod = 9999;

        for(i = 0; i < n; i++)
        {
            if(remain[i] > 0 && period[i] < minPeriod)
            {
                minPeriod = period[i];
                selected = i;
            }
        }

        if(selected != -1)
        {
            printf("%dms onwards : Process %d running\n",
                   time, selected + 1);
            remain[selected]--;
        }
        else
        {
            printf("%dms onwards : CPU is idle\n", time);
        }
    }

    printf("\nAbhishek G ---> 1BM24CS009\n");

    return 0;
}
