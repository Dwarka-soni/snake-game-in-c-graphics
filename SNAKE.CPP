#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
void food();
void snake();
void set();
int xar [100][4] = {{100,100,110,110},{90,100,100,110},{80,100,90,110}};
int ch=77;
int r1,r2;
int sp=200;
int n=3;
char n1[5];
int x1=95;
int y1=105;
void main()
{
int x,y;
x=DETECT;
clrscr();
initgraph(&x,&y,"");
r1=random(200);
r2=random(280);

outtextxy(200,200,"press s to start");
do{
snake();
ch=getch();
}while(ch!='a');
getch();
}

void snake() {
int i;

while(!kbhit())
{
rectangle(0,0,570,470);
settextstyle(3,0,1);
setcolor(4);
outtextxy(580,70,"score");
rectangle(575,65,635,100);
sprintf(n1,"%d",(n-3)*10);
outtextxy(600,100,n1);
setcolor(15);
settextstyle(10,0,4);
outtextxy(600,150,"s");
outtextxy(600,200,"n");
outtextxy(600,250,"a");
outtextxy(600,300,"k");
outtextxy(600,350,"e");
for(i=0;i<n;i++)
{
setcolor(i);
rectangle(xar[i][0],xar[i][1],xar[i][2],xar[i][3]);
circle(x1,y1,2);
food();

if(r1==xar[0][0]&&r2==xar[0][1])
{
n++;
r1= random(200);
r2= random(280);
food();
}}



set();
if(ch==77)
{
xar[0][0]=xar[0][0]+10;
xar[0][2]=xar[0][2]+10;
 }

if(ch==75)
{
xar[0][0]=xar[0][0]-10;
xar[0][2]=xar[0][2]-10;
}
if(ch==72)
{
xar[0][1]=xar[0][1]-10;
xar[0][3]=xar[0][3]-10;

}

if(ch==80)
{
xar[0][1]=xar[0][1]+10;
xar[0][3]=xar[0][3]+10;

}


//if(n==sp)
//{//
//sp=20;
delay(100);
cleardevice();
if(xar[0][0]==-10||xar[0][1]==-10||xar[0][2]==570||xar[0][3]==470)
{
ch='a';
setcolor(10);
settextstyle(10,0,3);
outtextxy(170,200,"END GAME");
rectangle(162,292,382,371);
rectangle(160,290,380,370);
}}
 }


void set()
{
int i,j;
for(i=n-1;i>0;i--)
{
for(j=0;j<4;j++)
{
xar[i][j]=xar[i-1][j];
}
}

//cleardevice();
}

void food(){
r1=r1-r1%10;
r2=r2-r2%10;
rectangle(r1,r2,r1+10,r2+10);
}