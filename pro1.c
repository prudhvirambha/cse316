#include<unistd.h>
#include<stdio.h>
int ct[40]={0},qt,qas[40]={0},c=0,st,btm[40]={0},tt, wt,at[40],bt[40],zz;
void queue1(int fin,int tm);
void queue2(int fin, int tm);
void pop(int fin);
float att, awt;
int flg=0,tm=0,ee=0,fin=0;
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
printf("\n Gantt Chart \n {%d",at[0]);
do{
if(flg==0){
st=at[0];
if(btm[0]<=qt){
tm=st+btm[0];
btm[0]=0;
queue1(fin,tm);}
else{
btm[0]=btm[0]-qt;
tm=st+qt;
queue1(fin,tm);
pop(fin);}
}
else{
fin=qas[0]-1;
st=tm;
for(int x=0;x<ee && ee!=1;x++){
qas[x]=qas[x+1];}
ee--;
if(btm[fin]<=qt){
tm=st+btm[fin];
btm[fin]=0;
queue2(fin, tm);}
else{
btm[fin]=btm[fin]-qt;
tm=st+qt;
queue2(fin, tm);
pop(fin);}
}
if(btm[fin]==0){
ct[fin]=tm;
}
flg++;
printf("}->P%d<-{%d",fin+1,tm);
}while(ee!=0);
printf("}  ");
printf("\n\nProcess \t Arrival Time\t Burst Time \t Completition Time\t Turn Around Time\t Waiting Time\n");
for(int x=0;x<zz;x++){
tt=ct[x]-at[x];
wt=tt-bt[x];
printf("P%d\t\t  %d\t\t  %d\t\t  %d\t\t\t   %d\t\t\t     %d\n",x+1,at[x],bt[x],ct[x],tt,wt);
awt=awt+wt;
att=att+tt;
}
printf("\nAverage Turn Around Time: %f\nAverage Waiting Time: %f",att/4,awt/4);
}
