// Shortest Remainging Time First

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

struct process
{
    char id[10];
    int at,bt,ft,rt;
    int finished;
} *p; 

int t=0; // time
int n=0; // number of processes
int quantum=1; // stretch of time for which a process will be executed by cpu before it is moved out

int scheduler()
{
    int temp=INT_MAX,P=-1;
    for(int i=0;i<n;i++)
        if(!(p[i].finished) && p[i].at<=t  && temp>p[i].rt)
        {
            temp=p[i].rt;
            P=i;
        }
    return P;
}

int main()
{
    int total_bt=0;
    int P,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    p=(struct process*)calloc(n,sizeof(struct process));
    for(i=0;i<n;i++)
    {
        printf("Enter id, arrival time, and burst times of process %d: ",i+1); // input to be as char int int
        scanf("%s %d %d",p[i].id,&p[i].at,&p[i].bt);
        p[i].finished=0;
        p[i].rt=p[i].bt;
        total_bt+=p[i].bt;
    }
    printf("Order: ");
    i=0;
    while(i<total_bt)
    {
        P=scheduler();
        if(P==-1)
        {
            t+=1;
        }
        else
        {
            if(p[P].rt-quantum <= 0 )
            {
                p[P].finished=1; //this process will not be considered again      
                t+=p[P].rt;
                p[P].ft=t;
                p[P].rt=0;
            }
            else
            {
                t+=quantum;
                p[P].rt-=quantum;
            }
            printf("\t%s",p[P].id);
            i++;
        } 
    }
    printf("\nID\tBT\tFT\tTT\tWT\n");//ID   Burst-Time  Finish-Time Turn-around-time    Waiting-time
    for(i=0;i<n;i++)
        printf("%s\t%d\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].ft,p[i].ft-p[i].at,p[i].ft-p[i].at-p[i].bt);
}
