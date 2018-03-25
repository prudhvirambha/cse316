#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
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
