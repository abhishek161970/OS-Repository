#include <stdio.h>

int main()
{
    int n,i,time=0,completed=0;
    int pid[20],at[20],bt[20],pr[20];
    int rt[20],ct[20],tat[20],wt[20],start[20];
    int priority_choice;
    float avg_tat=0,avg_wt=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter priorities (1 for higher number means higher priority, 2 for lower number means higher priority): ");
    scanf("%d",&priority_choice);
    printf("Enter arrival times:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);
    printf("Enter burst times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("Enter priorities:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pr[i]);
    for(i=0;i<n;i++){
        pid[i]=i+1;
        start[i]=-1;
    }
    while(completed<n)
    {
        int idx=-1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(idx==-1)
                    idx=i;
                else
                {
                    if(priority_choice==1)
                    {
                        if(pr[i] > pr[idx])
                            idx=i;
                    }
                    else
                    {
                        if(pr[i] < pr[idx])
                            idx=i;
                    }
                }
            }
        }
        if(idx!=-1)
        {
            if(start[idx]==-1)
                start[idx]=time;
            rt[idx]--;
            time++;
            if(rt[idx]==0)
            {
                ct[idx]=time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
                avg_tat+=tat[idx];
                avg_wt+=wt[idx];
                completed++;
            }
        }
        else
            time++;
    }
    printf("\nPriority scheduling (Pre-Emptive):\n");
    printf("PID\tPrior\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
    {
        int response = start[i]-at[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],pr[i],at[i],bt[i],ct[i],tat[i],wt[i],response);
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("\nAverage turnaround time: %.6f\n",avg_tat);
    printf("\nAverage waiting time: %.6f\n",avg_wt);
    return 0;
}
