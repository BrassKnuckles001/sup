#include<stdio.h>

struct Process{
    int id;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

void calculateTimes(struct Process p[], int n)
{
 p[0].CT=p[0].AT + p[0].BT;
 for(int i=1;i<n;i++)
 {
  p[i].CT=p[i-1].CT + p[i].BT;
 }
 for(int i=0;i<n;i++)
 {
  p[i].TAT=p[i].CT - p[i].AT;
  p[i].WT=p[i].TAT - p[i].BT;
 }
}

void printProcessinfo(struct Process p[], int n)
{
 printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
 for(int i=0;i<n;i++)
 {
  printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
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
 int n;
 printf("Enter no. of processes:");
 scanf("%d",&n);
 struct Process p[n];
 for(int i=0;i<n;i++)
 {
  p[i].id=i+1;
  printf("Enter AT and BT time for process %d:",p[i].id);
  scanf("%d %d",&p[i].AT,&p[i].BT);
 }
 calculateTimes(p,n);
 printProcessinfo(p,n);
 return 0;
}