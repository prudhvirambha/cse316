#include<unistd.h>
#include<stdio.h>
int ct[40]={0},qt,qas[40]={0},c=0,st,btm[40]={0},tt, wt,at[40],bt[40],zz;
void queue1(int fin,int tm);
void queue2(int fin, int tm);
void pop(int fin);
float att, awt;
int flg=0,tm=0,ee=0,fin=0;
void pop(int fin){

void queue2(int fin, int tm){
for(int x=fin+1;x<4;x++){
int fl=0;
int f2=0;
for(int y=0;y<ee;y++){
if(qas[y]==x+1){
fl++;}}
if(at[x]<=tm && fl==0 && btm[x]!=0){
qas[ee]=x+1;
ee++;}
}
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
}
