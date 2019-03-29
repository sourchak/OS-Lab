#include<stdio.h>
#include<limits.h>

struct process
{
    char id[10];
    int at,bt,ft;
    int finished;
} p[10]; //p will have to be replaced by a pointer to struct process if you want arbitary number of processes

int t=0;

int scheduler()
{
    int temp=INT_MAX,P=0;
    for(int i=0;i<10;i++)
        if(!(p[i].finished) && temp>p[i].bt)
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
    for(i=0;i<10;i++)
    {
        printf("Enter id, arrival time, and burst times of process %d: ",i+1); // input to be as char int int
        scanf("%s %d %d",p[i].id,&p[i].at,&p[i].bt);
        p[i].finished=0;
        total_bt+=p[i].bt;
    }
    while(t<total_bt)
    {
        P=scheduler();
        p[P].finished=1; //this process will not be considered again
        t+=p[P].bt;
        p[P].ft=t;
    }
    printf("ID\tBT\tFT\tWT\n");
    for(i=0;i<10;i++)
        printf("%s\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].ft,p[i].ft-p[i].at-p[i].bt);
}
