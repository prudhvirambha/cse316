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

void ins(queue *t,int ele)
{
	t->r++;
	t->q[t->r] = ele;
}
int qf(queue *t)
{
	return t->q[t->f];
}
int del1(queue *t){
	int i=t->f;
	int z=t->q[t->f];
	while(i < t->r){
		t->q[i] = t->q[i+1];
		i++;
	}
	t->r--;
	return z;
}

void sort(process p[],int n)
{
	int i,j;
	process val;
	for(i=0;i<n-1;i++)
	{
		val = p[i+1];
		for(j=i;j>=0;j--)
			if(val.type<p[j].type)
				p[j+2] = p[j+1];
			else 
				break;
		p[j+1] = val;
	}
}
void atsort(process p[],int n)
{
	int i,j;
	process val;
	for(i=0;i<n-1;i++)
	{
		val = p[i+1];
		for(j=i;j>=0;j--)
			if(val.AT<p[j].AT)
				p[j+1] = p[j];
			else 
				break;
		p[j+1] = val;
	}
}

int pop(process p[],int n,int time)
{
	int min=info,pos;

	for(int i=0;i<n;i++)
	{
		
			if(p[i].AT <= time&&p[i].RT != 0)
				if(p[i].RT<min)
				{
					min = p[i].RT;
					pos = i;
				}
		if(p[i].AT>time)
			break;
	}
	return pos;
}	
void mqu(process p[],int n,int tq,int chart[])
{
	int t,i,j,T=0,hp; 
	int cur_pid;
	queue x;
	x.f = 0;
	x.r = -1;
	for(i=0;i<n;i++)
		T += p[i].BT;
	atsort(p,n);
	sort(p,n);
	for(t=0;t<T;t++)
	{
		for(i=0;i<n;i++)
			if(p[i].type == 2&&p[i].AT==t)
				ins(&x,p[i].pid);
    	for(i=0;i<n;i++)
            if(p[i].AT <= t&&p[i].RT != 0)
                break;
		if(i==n)
			break;
		switch(p[i].type)
		{
			case 1 :cur_pid = tnt(p,n,t);
					break;
			case 2 :cur_pid = rr(p,&x,tq,n,t);
					break;
			
			default:printf("Invalid Type!\n");
					exit(1);
		}
		chart[t] = cur_pid;
	}
}
int tnt(process p[],int n,int time)
{
	int i = pop(p,n,time);
	p[i].RT--;
	if(p[i].RT == 0)
	{
		p[i].CT  = time+1;
		p[i].TAT = p[i].CT - p[i].AT;
		p[i].WT  = p[i].TAT - p[i].BT;
	}
	return p[i].pid;
}


float avgTAT(process p[],int n)
{
	int i;
	float avg=0;
	for(i=0;i<n;i++)
		avg += p[i].TAT;
	avg = avg / n;
	return avg;
}
float avgWT(process p[],int n)
{
	int i;
	float avg=0;
	for(i=0;i<n;i++)
		avg += p[i].WT;
	avg = avg / n;
	return avg;
}

int rr(process p[],queue *t,int tq,int n,int time)
{
	int i,runTime,cp;
	cp = qf(t);
	
	p[i].RT--;
	runTime = p[i].BT-p[i].RT;
	if(runTime%tq == 0 && p[i].RT != 0)
	{
		del1(t);
		ins(t,cp);
	}
	if(p[i].RT == 0)
	{
		p[i].CT  = time+1;
		p[i].TAT = p[i].CT - p[i].AT;
		p[i].WT  = p[i].TAT - p[i].BT;
		del1(t);
	}
	return p[i].pid;
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

	mqu(p,n,q,chart);
	output(p,n);

	
}
