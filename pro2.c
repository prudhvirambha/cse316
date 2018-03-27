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
