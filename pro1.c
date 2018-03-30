#include<unistd.h>
#include<stdio.h>
int ct[40]={0},qt,qas[40]={0},c=0,st,btm[40]={0},tt, wt,at[40],bt[40],zz;
void queue1(int fin,int tm);
void queue2(int fin, int tm);
void pop(int fin);
void pop(int fin){
qas[ee]=fin+1;
ee++;
}
void queue1(int fin,int tm){
for(int x=fin+1;x<4;x++){
if(at[x]<=tm){
qas[ee]=x+1;
ee++;}
}
}
void queue2(int fin, int tm){
for(int x=fin+1;x<4;x++){
int fl=0;
for(int y=0;y<ee;y++){
if(qas[y]==x+1){
fl++;}}
if(at[x]<=tm && fl==0 && btm[x]!=0){
qas[ee]=x+1;
ee++;}
}
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
