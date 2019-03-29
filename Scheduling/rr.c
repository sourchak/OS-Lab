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

void sorter()
{
    int i,j,key=INT_MAX;
    struct process temp;
    for(i=0;i<n-1;i++)
    {
        key=i;
        for(j=i+1;j<n;j++)
            if(p[key].at>p[j].at)
                key=j;
        if(key!=i)
        {
            temp=p[i];
            p[i]=p[key];
            p[key]=temp;
        }
    }
}

int main()
{
    int total_bt=0;
    int P,i,t_0;
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
    t_0=0;
    i=0;
    sorter();
    printf("Order: ");
    t=p[0].at;
    while(t_0<total_bt)
    {
        if(!(p[i].finished) && p[i].at<=t)
        {  
            if(p[i].rt-quantum <= 0 )
            {
                p[i].finished=1; //this process will not be considered again      
                t+=p[i].rt;
                p[i].ft=t;
                t_0+=p[i].rt;
                p[i].rt=0;
            }
            else
            {
                t+=quantum;
                p[i].rt-=quantum;
                t_0+=quantum;
            }
            printf("\t%s",p[i].id);
        }
        i=(i+1)%n;
    }
    printf("\nID\tBT\tFT\tTT\tWT\n");//ID   Burst-Time  Finish-Time Turn-around-time    Waiting-time
    for(i=0;i<n;i++)
        printf("%s\t%d\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].ft,p[i].ft-p[i].at,p[i].ft-p[i].at-p[i].bt);
}
