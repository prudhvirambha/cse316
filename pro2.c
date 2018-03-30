#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define size 40
#define info 42567
int time;
typedef struct process
{
	int pid,AT,BT,CT,TAT,WT,RT,type;
}process;
typedef struct queue{
	int q[size];
	int f,r;
}queue;

void ins(queue *t,int ele)
{
	t->r++;
	t->q[t->r] = ele;
}
int qf(queue *t)
{
	return t->q[t->f];
}
void output(process p[],int n)
{
	int i;
	printf("Process Id Arrival Time Brust Time Complition Time Turn Around Time Waiting Timr   Types\n");
	for(i=0;i<n;i++)
	{
		printf("%10d %10d %10d %10d %10d %20d %20d\n",p[i].pid,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].type);
	}
	printf("\n");
}
int main()
{
	int i,n,q,chart[size];
	process p[size];
	float avg_tat,avg_wt;
	printf("Enter no. of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter type of process: 1.Queue1 2.Queue2 \n>>>");
		scanf("%d",&p[i].type);
		printf("Enter arrival and burst time for p%d: ",i+1);
		scanf("%d%d",&p[i].AT,&p[i].BT);
		p[i].pid = i+1;
		p[i].RT = p[i].BT;
	}

	printf("Enter time quantum: ");
	scanf("%d",&q);
}
