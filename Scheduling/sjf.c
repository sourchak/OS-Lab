#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

struct process
{
    char id[10];
    int at,bt,ft;
    int finished;
} *p; 

int t=0;
int n=0;

int scheduler()
{
    int temp=INT_MAX,P=-1;
    for(int i=0;i<n;i++)
        if(!(p[i].finished) && p[i].at<=t  && temp>p[i].bt)
        {
            temp=p[i].bt;
            P=i;
        }
    return P;
}

int main()
{
    int total_bt=0;
    int P,i;
    char* order[10];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    p=(struct process*)calloc(n,sizeof(struct process));
    for(i=0;i<n;i++)
    {
        printf("Enter id, arrival time, and burst times of process %d: ",i+1); // input to be as char int int
        scanf("%s %d %d",p[i].id,&p[i].at,&p[i].bt);
        p[i].finished=0;
        total_bt+=p[i].bt;
    }
    i=0;
    while(i<n)
    {
        P=scheduler();
        if(P==-1)
            t+=1;
        else
        {
            p[P].finished=1; //this process will not be considered again
            t+=p[P].bt;
            p[P].ft=t;
            order[i]=(char*)calloc(10,sizeof(char));
            strcpy(order[i],p[P].id);
            i++;
        }
    }
    printf("Order:");
    for(i=0;i<n;i++)
        printf("%s\t",order[i]);
    printf("\nID\tBT\tFT\tTT\tWT\n");//ID   Burst-Time  Finish-Time Turn-around-time    Waiting-time
    for(i=0;i<n;i++)
        printf("%s\t%d\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].ft,p[i].ft-p[i].at,p[i].ft-p[i].at-p[i].bt);
}
