#include<stdio.h>  // HEADER FILE FOR STANDARD I/0
#include<graphics.h> // HEADER FILE FOR GRAPHICS MODE
#include<dos.h>     //  HEADER FILE FOR ENABLING SOUND
#include<conio.h>  // HEADER FILE FOR CONSOLE I/O
#include<stdlib.h> // HEADER FILE FOR LIBRARY FUNCTIONS

union REGS i,o;

void initmouse();        // FUNCTION TO INITIALIZE MOUSE POINTER
void showmouseptr();   // FUNCTION TO SHOW POINTER
void restrictmouseptr(int,int,int,int); // FUNCTION TO RESTRICT POINTER
void getmousepos(int *,int *,int *); // TO GET POINTER POSITION
void format();     // FUNCTION TO DRAW LAYOUT OF EVM
void graph();      // FUNCTION TO DISPLAY RESULT AS GRAPH
void welcome();    // FUNCTION TO DISPLAY WELCOME MESSAGE
void boundry();

int vote1=0,vote2=0,vote3=0,vote4=0,vote5=0;  // VARIABLES TO HOLD VOTES FOR COUNTRIES
int button,x,y;

void main()
{      int  gd=DETECT,gm;
       initgraph(&gd,&gm,"c:\\turboc3\\bgi");  // INITIALIZING GRAPHICS MODE
       randomize();
       boundry();
     initmouse();
     welcome();                // CALLING WELCOME FUNCTION
     cleardevice();            // CLEARING THE SCREEN
     format();                 // CALLING FORMAT FUNCTION
     showmouseptr();
     restrictmouseptr(0,0,675,435);    // RESTRICTING MOUSE POINTER WITHIN SCREEN
do
{
getmousepos(&button,&x,&y);
 if((button&1)==1&&x>475&&x<580&&y>250&&y<280)
{   break;}
else if((button&1)==1&&x>280&&x<380&&y>105&&y<125)
{  setcolor(GREEN);circle(270,115,5);
   sound(2000);
   delay(500);
   nosound();
   setcolor(BLACK);circle(270,115,5);
   vote1++;   }
else if((button&1)==1&&x>280&&x<380&&y>155&&y<175)
{  setcolor(GREEN);circle(270,165,5);
   sound(2000);
   delay(500);
   nosound();
   setcolor(BLACK);circle(270,165,5);
   vote2++;   }
else if((button&1)==1&&x>280&&x<380&&y>205&&y<225)
{  setcolor(GREEN);circle(270,215,5);
   sound(2000);
   delay(500);
   nosound();
   setcolor(BLACK);circle(270,215,5);
   vote3++;   }
else if((button&1)==1&&x>280&&x<380&&y>255&&y<275)
{  setcolor(GREEN);circle(270,265,5);
   sound(2000);
   delay(500);
   nosound();
   setcolor(BLACK);circle(270,265,5);
   vote4++;   }
else if((button&1)==1&&x>280&&x<380&&y>305&&y<325)
{  setcolor(GREEN);circle(270,315,5);
   sound(2000);
   delay(500);
   nosound();
   setcolor(BLACK);circle(270,315,5);
   vote5++;   }
}
while(1);
 cleardevice();

 showmouseptr();
  boundry();
 graph();
 getch();
}

void boundry()
{
   setcolor(1+random(14));
   rectangle(0,0,635,475);
   setcolor(1+random(14));
   rectangle(3,3,632,472);
}

void welcome()
{ randomize();
  settextstyle(8,0,4);
  setcolor(1+random(14));
  outtextxy(100,10,"THIS WILL DECIDE THE");
  outtextxy(150,50,"WORLDS FUTURE");
  outtextxy(250,100,"WELCOME");
  setcolor(1+random(14));
  outtextxy(250,160,"TO");
  setcolor(1+random(14));
  outtextxy(50,220,"ELECTRONIC VOTING SYSTEM");
  while(!kbhit())
  {  setcolor(1+random(14));
     outtextxy(50,400,"Press any key to continue.....");
     delay(500);
     setcolor(BLACK);
     outtextxy(50,400,"Press any key to continue.....");
     delay(500);
  }


}

void format()
{   setcolor(6);
    settextstyle(0,0,5);

    rectangle( 90,30,400,380);
    rectangle( 87,27,403,383);
    line(90,80,400,80);

    outtextxy(140,40,"E V M");

    settextstyle(8,0,2);

    outtextxy(100,100,"USA");
    rectangle(95,100,250,130);
    arc(290,115,90,270,10);
    arc(370,115,270,90,10);
    line(290,105,370,105);
    line(290,125,370,125);
    outtextxy(300,100,"VOTE");

    outtextxy(100,150,"INDIA");
    rectangle(95,150,250,180);
    arc(290,165,90,270,10);
    arc(370,165,270,90,10);
    line(290,155,370,155);
    line(290,175,370,175);
    outtextxy(300,150,"VOTE");

    outtextxy(100,200,"USSR");
    rectangle(95,200,250,230);
    arc(290,215,90,270,10);
    arc(370,215,270,90,10);
    line(290,205,370,205);
    line(290,225,370,225);
    outtextxy(300,200,"VOTE");

    outtextxy(100,250,"CHINA");
    rectangle(95,250,250,280);
    arc(290,265,90,270,10);
    arc(370,265,270,90,10);
    line(290,255,370,255);
    line(290,275,370,275);
    outtextxy(300,250,"VOTE");

    outtextxy(100,300,"JAPAN");
    rectangle(95,300,250,330);
    arc(290,315,90,270,10);
    arc(370,315,270,90,10);
    line(290,305,370,305);
    line(290,325,370,325);
    outtextxy(300,300,"VOTE");

    rectangle(475,250,580,280);
    outtextxy(480,250,"RESULTS");

}
void showmouseptr()
{
i.x.ax=1;
int86(0x33,&i,&o);
}
void restrictmouseptr(int x1, int y1, int x2, int y2)
{    i.x.ax=7;
     i.x.cx=x1;
     i.x.dx=x2;
     int86(0x33,&i,&o);
     i.x.ax=8;
     i.x.cx=y1;
     i.x.dx=y2;
     int86(0x33,&i,&o);
}
void getmousepos(int *button, int *x, int *y)
{   i.x.ax=3;
    int86(0x33,&i,&o);
    *button=o.x.bx;
    *x=o.x.cx;
    *y=o.x.dx;
}
void graph()
{  int country1,country2,country3,country4,country5;
    char str1[20],str2[20],str3[20],str4[20],str5[20];
    outtextxy(200,100,"RESULTS");
    country1=((vote1*100)/(vote1+vote2+vote3+vote4+vote5));
    country2=((vote2*100)/(vote1+vote2+vote3+vote4+vote5));
    country3=((vote3*100)/(vote1+vote2+vote3+vote4+vote5));
    country4=((vote4*100)/(vote1+vote2+vote3+vote4+vote5));
    country5=((vote5*100)/(vote1+vote2+vote3+vote4+vote5));
    setcolor(2);
    rectangle(100,300,130,300-country1);outtextxy(100,300,"USA");
    sprintf(str1,"%d",vote1);
    outtextxy(100,330,str1);
    rectangle(200,300,230,300-country2);outtextxy(200,300,"INDIA");
    sprintf(str2,"%d",vote2);
    outtextxy(200,330,str2);
    rectangle(300,300,330,300-country3);outtextxy(300,300,"USSR");
    sprintf(str3,"%d",vote3);
    outtextxy(300,330,str3);
    rectangle(400,300,430,300-country4);outtextxy(400,300,"CHINA");
    sprintf(str4,"%d",vote4);
    outtextxy(400,330,str4);
    rectangle(500,300,530,300-country5);outtextxy(500,300,"JAPAN");
    sprintf(str5,"%d",vote5);
    outtextxy(500,330,str5);

    setcolor(1+random(14));
    rectangle(545,400,600,430);
    outtextxy(550,400,"EXIT");

    do
{
getmousepos(&button,&x,&y);
 if((button&1)==1&&x>545&&x<600&&y>400&&y<430)
{   break;}
}
while(1);


}
void initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
//return(o.x.ax);
if(o.x.ax==0)
   printf("mouse driver not loaded");
}
