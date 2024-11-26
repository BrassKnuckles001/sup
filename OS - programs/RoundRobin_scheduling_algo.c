#include <stdio.h>

struct Process
{
    int id;
    int AT;
    int BT;
    int remaining;
    int CT;
    int TAT;
    int WT;
};

void calculateTimes(struct Process p[], int n, int quantum)
{
    int time = 0;
    int completed = 0;
    int i = 0;

    while (completed < n)
    {
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (p[i].remaining > 0)
            {
                done = 0;

                if (p[i].remaining > quantum)
                {
                    time += quantum;
                    p[i].remaining -= quantum;
                }
                else
                {

                    time += p[i].remaining;
                    p[i].remaining = 0;
                    p[i].CT = time;
                    completed++;
                }
            }
        }
        if (done == 1)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
    }
}

void printProcessInfo(struct Process p[], int n)
{
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].AT,
               p[i].BT,
               p[i].CT,
               p[i].TAT,
               p[i].WT);
    }
}

int main()
{
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("Enter AT time and BT time for Process %d: ", p[i].id);
        scanf("%d %d", &p[i].AT, &p[i].BT);
        p[i].remaining = p[i].BT;
        p[i].CT = 0;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    calculateTimes(p, n, quantum);
    printProcessInfo(p, n);
    return 0;
}