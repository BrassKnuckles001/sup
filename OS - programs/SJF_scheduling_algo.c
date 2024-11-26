#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Process {
    int id;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

void calculateTimes(struct Process p[] , int n)
{
    int completed = 0 , time = 0;
    for (int i = 0; i < n ; i++)
    {
        p[i].CT = 0;
    }

    while(completed < n){

        int idx = -1;
        int minBT = 9999;

        for (int i = 0; i < n; i++)
        {
            if(p[i].AT <= time && p[i].CT == 0)
            { 
                if(p[i].BT < minBT)
                {
                    minBT = p[i].BT;
                    idx = i;
                }
            }
        }

        if(idx != -1){
            time += p[idx].BT;
            p[idx].CT = time;
            completed++; 
        }
        else
        {
            time++;
        }

    }
    
    for (int i = 0; i < n; i++)
    {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
    }
    
}

void printTimes(struct Process p[],int n){
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",p[i].id,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT);
    }
}


int main()
{
    int n;
    printf("ENTER the NO of processes :\n");
    scanf("%d",&n);

    struct Process p[n];

    
    for (int i = 0; i < n; i++)
    {
        p[i].id = i+1;
        printf("\nEnter the 'AT' & 'BT' for process P%d :",p[i].id);
        scanf("%d %d", &p[i].AT , &p[i].BT);  
    }

    calculateTimes(p,n);
    printTimes(p,n);

    return 0;
}