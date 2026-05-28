#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;

    int arrival[10], burst[10], deadline[10];
    int remaining[10];

    printf("Abhishek G ---> 1BM24CS009\n");

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nTask %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);

        printf("Burst Time: ");
        scanf("%d", &burst[i]);

        printf("Deadline: ");
        scanf("%d", &deadline[i]);

        remaining[i] = burst[i];
    }

    printf("\nScheduling:\n\n");

    while(completed < n)
    {
        int min_deadline = 9999;
        int selected = -1;

        for(i = 0; i < n; i++)
        {
            if(arrival[i] <= time &&
               remaining[i] > 0 &&
               deadline[i] < min_deadline)
            {
                min_deadline = deadline[i];
                selected = i;
            }
        }

        if(selected == -1)
        {
            printf("%dms : CPU is idle\n", time);
        }
        else
        {
            printf("%dms : Task %d is running\n",
                   time, selected + 1);

            remaining[selected]--;

            if(remaining[selected] == 0)
                completed++;
        }

        time++;
    }

    printf("\nAbhishek G ---> 1BM24CS009\n");

    return 0;
}
