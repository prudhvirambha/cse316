#include<unistd.h>
#include<stdio.h>
int ct[40]={0},qt,qas[40]={0},c=0,st,btm[40]={0},tt, wt,at[40],bt[40],zz;
int main()
{
printf("\nEnter time slice:");
scanf("%d",&qt);
printf("Enter no of process");
scanf("%d",&zz);
for(int x=0;x<zz;x++){
printf("\n Process %d",x+1);
printf("\n Arrival Time=");
scanf("%d",&at[x]);
printf(" Burst Time=");
scanf("%d",&bt[x]);
btm[x]=bt[x];}
}
