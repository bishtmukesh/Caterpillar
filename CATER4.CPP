#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void LINE(int x1,int y1,int x2,int y2)
{

int dx,dy,dli,m,DA1,DA2,PA,I,D;

 if(y1>y2)
 {
 y1+=y2;
 y2=y1-y2;
 y1=y1-y2;
 x1+=x2;
 x2=x1-x2;
 x1=x1-x2;
 }


dx=x2-x1;
dy=y2-y1;

 if(abs(dx)>=dy)
 {
 DA1=x1,DA2=x2,PA=y1,I=dy,D=dx;
 dli=dy-dx;
 }
 else
 {
 DA1=y1,DA2=y2,PA=x1,I=dx,D=dy;
 dli=dx-dy;
 }

 if(dx>=0)
 {
  for(int i=DA1;i<=DA2;i++)
  {

   if(I!=dx)
   putpixel(i,PA,2);
   else
   putpixel(PA,i,2);

   if(dli>=0)
   {
   PA++;
   dli-=D;
   }
  dli+=I;
  }
 }

 else if(I==dy)
 {
  for(int i=DA1;i>=DA2;i--)
  {

   if(I!=dx)
   putpixel(i,PA,2);
   else
   putpixel(PA,i,2);

   if(dli>=0)
   {
   PA++;
   dli-=D;
   }
  dli+=I;
  }
 }

 else
 {
 PA=x2;
 for(int i=DA1;i>=DA2;i++)
  {

   if(I!=dx)
   putpixel(i,PA,2);
   else
   putpixel(PA,i,2);

   if(dli>=0)
   {
   PA--;
   dli-=D;
   }
  dli+=I;
  }
 }


}

 struct pre
 {
 int world;
 int speed;
 int Level;
 int Sound;
 }oj;

 struct PART
 {
 int x;
 int y;
 }PTR;


 class cater
 {
 int pp;
 int world;
 int speed;
 int Level;
 int Sound;
 int HS;
 int iniinfo;
 int out;
 int len;

  struct part
  {
  int x;
  int y;
  part *back;
  part *next;
  };

 part *start,*ptr,*end;
 int px,py,PX,PY,time;
 char cs;

 struct high
 {
 int point;
 char name[30];
 public:
 }o[11],f[11];

 public:
 cater();
 void cancel();
 void options();
 void difficulty();
 void main_menu();
 void level();
 void help();
 void setup();
 void point(int);
 void play();
 void ini(int);
 void highscore();
 void compare();
 void get(int);
 void store();
 void name();
 void save();
 void intro();
 int score();

};



void cater::intro()
{
cleardevice();

setfillstyle(SOLID_FILL,4);
setcolor(3);
bar(getmaxx()-130,getmaxy()-40,getmaxx()-12,getmaxy()-12);

settextstyle(SMALL_FONT,HORIZ_DIR,4);
outtextxy(getmaxx()-128,getmaxy()-30,"PRESS 'esc' to skip.");

setcolor(12);
setlinestyle(SOLID_LINE,3,3);
setfillstyle(SOLID_FILL,2);
rectangle(12,12,getmaxx()-12,getmaxy()-12);

rectangle(0,0,getmaxx(),getmaxy());
rectangle(3,3,getmaxx()-3,getmaxy()-3);
rectangle(6,6,getmaxx()-6,getmaxy()-6);
rectangle(9,9,getmaxx()-9,getmaxy()-9);
rectangle(12,12,getmaxx()-12,getmaxy()-12);

int x1=getmaxx()-35,x2=15,caterx[11]={x1,x1,x2,x2,x2,x1,x2,x2,x1,x1,x2};
int catery[]={100,130,160,190,220,250,280,310,340,370,400};
int clx[11]={x1,x1,x2,x2,x2,x1,x2,x2,x1,x1,x2};
int cly[11]={100,130,160,190,220,250,280,310,340,370,400};
char *word[]={"C","A","T","E","R","P","I","L","L","A","R"};
char *coders[]={"MUKESH BISHT","AJAY KANYAL"};
char *files[]={"ca1.txt","ca2.txt","ca3.txt","ca4.txt","ca5.txt","ca6.txt","ca7.txt","ca8.txt","ca9.txt","ca10.txt","ca11.txt"};
char ch1,ch2;
int over=0;

ifstream op[11];

setcolor(2);
settextstyle(DEFAULT_FONT,HORIZ_DIR,3);

 for(int i=0;i<11;i++)
 op[i].open(files[i],ios::in);

 for(i=0;i<11;i++)
 outtextxy(caterx[i],catery[i],word[i]);

 do
 {

 over=0;

  if(kbhit())
   {
   ch2=getch();
   }

  for(i=0;i<11;i++)
  {

   if(!op[i].eof())
   {
   op[i]>>ch1;

   setcolor(0);
   outtextxy(clx[i],cly[i],word[i]);

   if(ch1=='w')
   catery[i]--;
   else if(ch1=='a')
   caterx[i]--;
   else if(ch1=='s')
   catery[i]++;
   else if(ch1=='d')
   caterx[i]++;
   else if(ch1=='e')
   caterx[i]++,catery[i]--;
   else if(ch1=='q')
   caterx[i]--,catery[i]--;
   else if(ch1=='z')
   caterx[i]--,catery[i]++;
   else if(ch1=='c')
   caterx[i]++,catery[i]++;
   }

   else
   over++;

   setcolor(2);
   outtextxy(caterx[i],catery[i],word[i]);

   clx[i]=caterx[i],cly[i]=catery[i];

   }

  delay(1);

 }while(over!=11 && ch2!=27);

  for(i=0;i<11;i++)
  op[i].close();

 part *create,*start=NULL,*end=NULL,*ptr;
 char dir='r';
 int cc=25,c=25,CO1=25,CO2=getmaxx()-300,CC1=CO1,CC2=CO2;

 if(ch2!=27)
 {

  for(i=0;i<40;i++)
  {
  create=new part;

   if(start==NULL)
   {
   start=create;
   end=create;
   start->x=20;
   start->y=50;
   start->back=NULL;
   start->next=NULL;
   }
   else
   {
   create->back=end;
   end->next=create;
   end=create;
   end->next=NULL;
   create->x=20-(i*10);
   create->y=50;
   }

  }

 setlinestyle(SOLID_LINE,1,1);

 for(i=0;i<30;i++)
 {

  ptr=end;
  while(ptr->back!=NULL)
  {
   ptr->x=ptr->back->x;
   ptr->y=ptr->back->y;
   ptr=ptr->back;
  }

  setcolor(0);
  if(end->x>20)
  circle(end->x,end->y,5);
  setcolor(2);

  ptr=start;
  while(ptr->next!=NULL)
  {
  if(ptr->x>20)
  circle(ptr->x,ptr->y,5);
  ptr=ptr->next;
  }
  if(dir=='r')
  start->x+=10;
  else if(dir=='l')
  start->x-=10;
  else if(dir=='u')
  start->y-=10;
  else
  start->y+=10;

 delay(40);

 }

 }



 while(ch2!=27)
 {

  if(kbhit())
   {
   ch2=getch();
   }

  ptr=end;
  while(ptr->back!=NULL)
  {
   ptr->x=ptr->back->x;
   ptr->y=ptr->back->y;
   ptr=ptr->back;
  }

  setcolor(0);
  if(end->x>20)
  circle(end->x,end->y,5);
  setcolor(2);

  ptr=start;
  while(ptr->next!=NULL)
  {
  if(ptr->x>20)
  circle(ptr->x,ptr->y,5);
  ptr=ptr->next;
  }
  if(dir=='r')
  start->x+=10;
  else if(dir=='l')
  start->x-=10;
  else if(dir=='u')
  start->y-=10;
  else
  start->y+=10;

  if(start->x==430)
  dir='d';
  if(start->x==430 && start->y==90)
  dir='l';
  if(start->x==160 && start->y==90)
  dir='u';
  if(start->x==160 && start->y==50)
  dir='r';

  if(c<200)
  {
  setcolor(0);
  outtextxy(cc,150,"CODED BY:");
  setcolor(4);
  outtextxy(c,150,"CODED BY:");
  cc=c;
  c+=3;
  }

  if(c>200 && CO2>250)
  {
  setcolor(0);
  outtextxy(CC1,220,coders[0]);
  outtextxy(CC2,300,coders[1]);
  setcolor(3);
  outtextxy(CO1,220,coders[0]);
  outtextxy(CO2,300,coders[1]);
  CC1=CO1;
  CC2=CO2;
  CO1+=1;
  CO2-=1;
  }

  if(CO2==250)
  {
  setfillstyle(SOLID_FILL,0);
  bar(getmaxx()-130,getmaxy()-40,getmaxx()-12,getmaxy()-12);
  setlinestyle(SOLID_LINE,3,3);
  setcolor(12);
  rectangle(12,12,getmaxx()-12,getmaxy()-12);
  setcolor(14);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  outtextxy(250,420,"PRESS 'ESC'");
  setlinestyle(SOLID_LINE,1,1);
  CO2--;
  }

 delay(40);

 }

 ptr=start;
 while(ptr!=NULL)
 {
 part *del=ptr;
 ptr=ptr->next;
 delete del;
 }

}


void cater::cancel()
{
int i;

 for(i=0;i<11;i++)
 {
 o[i].point=0;
 o[i].name[0]='\0';
 f[i].point=0;
 f[i].name[0]='\0';
 }
}

cater::cater()
{

 start=NULL;
 Sound=0;
 world=0;
 speed=100;
 Level=1;
 pp=0;
 iniinfo=0;
 out=0;
 time=100;
 cs='n';
 px=0,py=0,PX=0,PY=0;
 len=0;

}

void cater::save()
{

cleardevice();

ofstream save("SA.dat",ios::out);

 if(out==0)
 {

 settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
 outtextxy(200,200,"SAVING");

 ptr=start;

  while(ptr->next!=NULL)
  {

  PTR.x=ptr->x;
  PTR.y=ptr->y;

  save.write((char*)&PTR,sizeof(PART));

  ptr=ptr->next;

  }

 ofstream cor("zcx.dat",ios::out);

 cor<<px<<" "<<py<<" "<<time<<" "<<cs<<" "<<pp<<" "<<PX<<" "<<PY<<" "<<len;

 cor.close();

 }

 else
 {
 PTR.x=-100;
 PTR.y=-100;

 save.write((char*)&PTR,sizeof(PART));

 }

 if(out==0)
 {

 setcolor(0);
 outtextxy(200,200,"SAVING");
 setcolor(4);

  if(Sound==1)
  sound(300);

  settextstyle(GOTHIC_FONT,HORIZ_DIR,5);

  outtextxy(200,200,"GAME SAVED");

  delay(500);

 }

 nosound();

 save.close();

}

int cater::score()
{
int hs;

 if(world==0)
 {
 hs=o[Level].point;
 }
 else if(world==1)
 {
 hs=f[Level].point;
 }

return hs;
}

void cater::name()
{
cleardevice();
setcolor(2);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
gotoxy(1,1);
outtextxy(100,150,"HIGHSCORE");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
setcolor(2);
outtextxy(250,350,"Press 'enter'");

char ch;

 do
 {
 ch=getch();
 }while(ch!='\r');

setcolor(0);
outtextxy(250,350,"Press 'enter'");

cout<<"Enter your name\n";

 if(world==0)
 {
 cin.getline(o[Level].name,30);
  if(speed==100)
  {
  strcat(o[Level].name,"(EA)");
  }
  else if(speed==80)
  {
  strcat(o[Level].name,"(M)");
  }
  else if(speed==60)
  {
  strcat(o[Level].name,"(H)");
  }
  else
  {
  strcat(o[Level].name,"(EX)");
  }
 }
 else if(world==1)
 {
 cin.getline(f[Level].name,30);
 if(speed==100)
  {
  strcat(f[Level].name,"(EA)");
  }
  else if(speed==80)
  {
  strcat(f[Level].name,"(M)");
  }
  else if(speed==60)
  {
  strcat(f[Level].name,"(H)");
  }
  else
  {
  strcat(f[Level].name,"(EX)");
  }
 }

}

void cater::store()
{
int i;

fstream oval,flat;

  if(speed==100)
  {
  oval.open("EASY1.txt",ios::out);
  flat.open("EASY2.txt",ios::out);
  }
  else if(speed==80)
  {
  oval.open("MEDIUM1.txt",ios::out);
  flat.open("MEDIUM2.txt",ios::out);
  }
  else if(speed==60)
  {
  oval.open("HARD1.txt",ios::out);
  flat.open("HARD2.txt",ios::out);
  }
  else if(speed==40)
  {
  oval.open("EXTREME1.txt",ios::out);
  flat.open("EXTREME2.txt",ios::out);
  }

 for(i=0;i<11;i++)
 oval.write((char*)&o[i],sizeof(o[i]));

 oval.close();

 for(i=0;i<11;i++)
 flat.write((char*)&f[i],sizeof(f[i]));

 flat.close();

}

void cater::get(int cl)
{
int i;

 if(cl!=0)
 {

  oj.world=0;
  oj.speed=100;
  oj.Level=1;
  oj.Sound=0;

  ofstream  give("QWE.dat",ios::noreplace);

  give.write((char*)&oj,sizeof(oj));

  give.close();

  ifstream take("QWE.dat",ios::in);

  take.read((char*)&oj,sizeof(oj));
  world=oj.world;
  speed=oj.speed;
  Level=oj.Level;
  Sound=oj.Sound;

  take.close();

 }

 fstream oval,flat;

  if(speed==100)
  {
  oval.open("EASY1.txt",ios::in);
  flat.open("EASY2.txt",ios::in);
  }
  else if(speed==80)
  {
  oval.open("MEDIUM1.txt",ios::in);
  flat.open("MEDIUM2.txt",ios::in);
  }
  else if(speed==60)
  {
  oval.open("HARD1.txt",ios::in);
  flat.open("HARD2.txt",ios::in);
  }
  else if(speed==40)
  {
  oval.open("EXTREME1.txt",ios::in);
  flat.open("EXTREME2.txt",ios::in);
  }

 for(i=0;i<11;i++)
 oval.read((char*)&o[i],sizeof(o[i]));

 oval.close();

 for(i=0;i<11;i++)
 flat.read((char*)&f[i],sizeof(f[i]));

 flat.close();

}

void cater::compare()
{

 if(world==0)
 {
  if(pp>o[Level].point)
  {
  o[Level].point=pp;
  name();
  store();
  }
 }

 else
 if(world==1)
 {
  if(pp>f[Level].point)
  {
  f[Level].point=pp;
  name();
  store();
  }
 }

}

void cater::help()
{
char ch;

cleardevice();
setlinestyle(SOLID_LINE,3,3);
setcolor(GREEN);

rectangle(0,0,getmaxx(),getmaxy());
rectangle(3,3,getmaxx()-3,getmaxy()-3);
rectangle(6,6,getmaxx()-6,getmaxy()-6);
rectangle(9,9,getmaxx()-9,getmaxy()-9);
rectangle(12,12,getmaxx()-12,getmaxy()-12);

setcolor(GREEN);
rectangle(1,1,getmaxx(),getmaxy());
settextstyle(SMALL_FONT,HORIZ_DIR,6);
setcolor(121);

outtextxy(20,15,"->DIRECT THE CATERPILLER USING ARROW KEYS.");
outtextxy(20,30,"->COLLECT THE POINTS BY EATING FOOD.");
outtextxy(20,45,"->EARN MORE POINTS TO ACHIEVE HIGH-SCORE.");
outtextxy(20,60,"->BEWARE OF THE OBSTACLES!!!");
outtextxy(20,75,"->YOU CAN TRY VARIOUS DIFFICULTY LEVELS.");
outtextxy(20,90,"->CHOOSE YOUR DESIRED DESTINATION.");
outtextxy(20,105,"->YOU CAN CHOOSE TO BE FREE OR CAGED.");
outtextxy(20,130,"->PRESS 'ESC' TO DISPLAY OPTIONS.");
setcolor(GREEN);
outtextxy(200,200,"BEST OF LUCK!!!!");

 do
 {
 ch=getch();
 }while(ch!=27);

}


void cater::options()
{
int y=117,cy=117,y1=110,cy1=110;
char ch1,ch2;

 do
 {
 cleardevice();
 setlinestyle(SOLID_LINE,3,3);
 setcolor(GREEN);

 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(3,3,getmaxx()-3,getmaxy()-3);
 rectangle(6,6,getmaxx()-6,getmaxy()-6);
 rectangle(9,9,getmaxx()-9,getmaxy()-9);
 rectangle(12,12,getmaxx()-12,getmaxy()-12);

 setlinestyle(SOLID_LINE,1,1);

 setcolor(3);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);

 outtextxy(220,100,"SOUND");
 setcolor(6);
 outtextxy(220,200,"HELP");
 setcolor(5);
 outtextxy(220,300,"BACK");

 setcolor(RED);
 settextstyle(SMALL_FONT,HORIZ_DIR,6);

 outtextxy(500,110,"ON");
 outtextxy(500,130,"OFF");

 setcolor(121);
 circle(550,120,5);
 circle(550,140,5);

 setlinestyle(SOLID_LINE,3,3);

 setcolor(YELLOW);
  if(Sound==1)
  circle(550,120,1);
  else
  circle(550,140,1);
  do
  {

  setcolor(0);
  outtextxy(150,cy,"->");
  setcolor(CYAN);
  outtextxy(150,y,"->");

  cy=y;

  ch1=getch();

   if(ch1==0)
   {
   ch2=getch();
    if(ch2==72)
    {
     if(y==117)
     y=317;
     else
     y-=100;
    }
    else if(ch2==80)
    {
     if(y==317)
     y=117;
     else
     y+=100;
    }
   }

   if(ch1=='\r' && y==117)
   {
    setcolor(0);
    outtextxy(150,cy,"->");

     do
     {

     setcolor(0);
     outtextxy(480,cy1,"->");
     setcolor(40);
     outtextxy(480,y1,"->");

     cy1=y1;

     ch1=getch();

      if(ch1==0)
      {
       ch2=getch();
	if(ch2==72 || ch2==80)
	{
	 if(y1==110)
	 y1=130;
	 else
	 y1=110;
	}
      }
      else if(ch1=='\r')
      {
       setlinestyle(SOLID_LINE,3,3);
       if(y1==110 && Sound==0)
       {
       setcolor(0);
       circle(550,140,1);
       setcolor(YELLOW);
       circle(550,120,1);
       Sound=1;
       }
       else if(y1==130 && Sound==1)
       {
       setcolor(0);
       circle(550,120,1);
       setcolor(YELLOW);
       circle(550,140,1);
       Sound=0;
       }
      }

     }while(ch2!=75);

    setcolor(0);
    outtextxy(480,y1,"->");

    }

  }while(ch1!='\r');

  if(y==217)
  help();

 }while(y!=317);;

}

void cater::level()
{

int page,x,y,cx,cy,x1,y1,cx1,cy1,le;
char ch1,ch2;

 if(world==0)
 page=1;
 else
 page=3;
 if(Level==0 || Level==10)
 page++;

 do
 {
  cleardevice();
  setlinestyle(SOLID_LINE,3,3);
  setcolor(RED);
  rectangle(0,0,getmaxx(),getmaxy());
  rectangle(3,3,getmaxx()-3,getmaxy()-3);
  rectangle(6,6,getmaxx()-6,getmaxy()-6);
  rectangle(9,9,getmaxx()-9,getmaxy()-9);
  rectangle(12,12,getmaxx()-12,getmaxy()-12);
  setcolor(121);

   if(page==1 || page==3)
   {
   for(int i=40,j=40;j<=320;i+=200)
   {
   rectangle(i,j,i+150,j+100);
    if(i==440)
    {
    j+=140;
    i=-160;
    }
   }
  setcolor(WHITE);
  line(313,70,313,110);

  line(513,75,513,115);
  line(488,75,538,75);

  line(510,205,490,205);
  line(490,205,490,225);
  line(490,230,490,250);
  line(490,250,510,250);
  line(515,250,535,250);
  line(535,250,535,230);
  line(535,225,535,205);
  line(535,205,515,205);
  }

  if(page==1)
  {
  setcolor(WHITE);

  line(42,227,188,227);

  line(242,210,388,210);
  line(260,250,388,250);

  line(42,340,188,340);
  line(42,370,160,370);
  line(70,400,188,400);

  line(313,350,313,380);
  line(280,322,280,350);
  line(280,350,242,350);
  line(350,322,350,350);
  line(350,350,378,350);
  line(280,418,280,390);
  line(280,390,242,390);
  line(350,418,350,390);
  line(350,390,388,390);

  line(462,345,588,345);
  line(442,370,588,370);
  line(452,400,588,400);
  line(540,322,540,345);
  line(490,322,490,336);
  line(490,372,490,400);
  line(540,372,540,390);
  line(520,345,520,370);

  }

  else if(page==3)
  {
  setcolor(WHITE);

  line(65,230,90,230);
  line(130,230,155,230);
  line(110,190,110,215);
  line(110,270,110,245);

  line(273,205,273,235);
  line(323,205,323,235);
  line(298,225,298,255);
  line(348,225,348,255);

  line(60,351,170,351);
  line(60,371,170,371);
  line(60,391,170,391);

  line(270,350,360,350);
  line(270,390,360,390);
  line(290,370,340,370);
  line(270,350,270,355);
  line(360,350,360,360);
  line(270,390,270,380);
  line(360,390,360,380);

  line(470,340,470,400);
  line(500,340,500,400);
  line(530,340,530,400);
  line(560,340,560,400);

  }

   else if(page==4)
  {
  setcolor(7);

  line(300,40,300,100);
  line(300,100,360,100);
  line(300,80,360,80);
  line(300,60,360,60);
  line(360,60,360,50);
  line(325,125,360,125);
  line(300,125,270,125);
  line(270,125,270,95);
  line(300,125,300,110);
  line(255,125,255,95);
  line(255,85,255,60);
  line(255,85,285,85);
  line(285,85,285,60);

  line(180,250,450,250);
  line(180,390,450,390);
  line(160,260,160,380);
  line(470,260,470,380);
  line(260,280,260,360);
  line(360,250,360,390);
  line(290,260,290,290);
  line(290,290,330,290);
  line(330,290,330,260);
  line(290,350,330,350);
  line(290,350,290,380);
  line(330,350,330,380);
  line(290,335,330,335);
  line(290,320,330,320);
  line(290,305,330,305);
  line(210,300,240,300);
  line(240,300,240,330);
  line(240,330,210,330);
  line(420,300,390,300);
  line(390,300,390,330);
  line(390,330,420,330);
  line(420,285,390,285);
  line(420,270,390,270);
  line(390,355,420,355);
  line(390,370,420,370);
  line(210,285,240,285);
  line(210,270,240,270);
  line(210,355,240,355);
  line(210,370,240,370);

  }

  if(page==2 || page==4)
  {
  setcolor(121);
  rectangle(240,40,390,140);
  setcolor(YELLOW);
  rectangle(150,240,480,400);
  }

  if(page==2)
  {
  setcolor(WHITE);

  line(280,42,280,70);
  line(280,70,242,70);
  line(350,42,350,70);
  line(350,70,378,70);
  line(280,138,280,110);
  line(280,110,242,110);
  line(350,138,350,110);
  line(350,110,388,110);
  line(295,70,335,70);
  line(295,70,295,110);
  line(295,110,310,110);
  line(335,70,335,110);
  line(335,110,320,110);
  line(305,100,325,100);
  line(305,100,305,80);
  line(325,100,325,80);
  line(325,80,320,80);
  line(305,80,310,80);
  line(312,88,312,93);
  line(312,88,317,88);
  line(312,93,317,93);

  line(265,80,265,100);
  line(365,80,365,100);
  line(290,55,340,55);
  line(290,125,340,125);


  line(150,320,480,320);
  line(260,240,260,385);
  line(360,260,360,400);
  line(150,260,220,260);
  line(190,275,260,275);
  line(210,290,210,320);
  line(170,340,170,360);
  line(240,340,240,360);
  line(190,350,220,350);
  line(150,370,195,370);
  line(215,370,320,370);
  line(300,385,360,385);
  line(260,335,320,335);
  line(300,355,360,355);
  line(260,260,340,260);
  line(280,275,360,275);
  line(260,290,300,290);
  line(325,285,325,320);
  line(280,300,280,320);
  line(390,240,390,300);
  line(420,260,420,340);
  line(440,280,480,280);
  line(390,355,450,355);
  line(400,365,400,400);
  line(440,365,440,400);

  }

   if( (page==1 ||page==3) && (Level!=10 && Level!=0) )
   {
    x=y=x1=y1=cx1=cy1=40;
    cx=Level%3;
    cy=(Level/3)+1;
     if(cx==0)
     {
     cx=3;
     cy--;
     }
    for(int i=1;i<cy;i++)
    y+=140;
    for(i=1;i<cx;i++)
    x+=200;
    setcolor(2);
    circle(x+73,y-10,3);
    x+=73,y-=10;
   }
   else if((page==2 || page==4))
   {
   setcolor(2);
   x1=240,y1=40;
   cx1=x1,cy1=y1;
    if(Level==0)
    {
    circle(310,230,3);
    x=310;
    y=230;
    }
    else if(Level==10)
    {
    circle(313,30,3);
    x=313,y=30;
    }
   }
   else x1=y1=cx1=cy1=40;


   if(page==1 || page==3)
   le=1;
   else le=10;

   do
   {

   setcolor(121);
   if(page==1 || page==3 || cx1==240)
   rectangle(cx1,cy1,cx1+150,cy1+100);
   else
   {
   setcolor(YELLOW);
   rectangle(cx1,cy1,cx1+330,cy1+160);
   }
   setcolor(2);
   if(page==1 || page==3 || x1==240)
   rectangle(x1,y1,x1+150,y1+100);
   else
   rectangle(x1,y1,x1+330,y1+160);

   cx1=x1,cy1=y1;

   ch1=getch();

    if(ch1==0)
    {
    ch2=getch();
     if(ch2==72)
     {
      if(page==1 ||page==3)
      {
       if(y1==40)
       {
       le+=6;
       y1=320;
       }
       else
       {
       le-=3;
       y1-=140;
       }
      }
      else
      {
       if(x1==240)
       {
       le=0;
       x1=150;
       y1=240;
       }
       else
       {
       le=10;
       x1=240;
       y1=40;
       }
      }
     }
     else if(ch2==75)
     {
      if(page==1 || page==3)
      {
       if(x1==40)
       {
       x1=440;
       le+=2;
       }
       else
       {
       le--;
       x1-=200;
       }
      }
     }
     else if(ch2==77)
     {
      if(page==1 || page==3)
      {
       if(x1==440)
       {
       x1=40;
       le-=2;
       }
       else
       {
       x1+=200;
       le++;
       }
      }
     }
     else if(ch2==80)
     {
      if(page==1 ||page==3)
      {
       if(y1==320)
       {
       le-=6;
       y1=40;
       }
       else
       {
       le+=3;
       y1+=140;
       }
      }
      else
      {
       if(x1==240)
       {
       le=0;
       x1=150;
       y1=240;
       }
       else
       {
       le=10;
       x1=240;
       y1=40;
       }
      }
     }
    }
    else if(ch1=='\r')
    {
    setcolor(0);
    circle(x,y,3);

    setcolor(3);

    Level=le;

     if(page==1 ||page==3&& (Level!=10 && Level!=0) )
     {
     x=y=40;
     cx=Level%3;
     cy=(Level/3)+1;
      if(cx==0)
      {
      cx=3;
      cy--;
      }
     for(int i=1;i<cy;i++)
     y+=140;
     for(i=1;i<cx;i++)
     x+=200;
     setcolor(2);
     circle(x+73,y-10,3);
     x+=73,y-=10;
    }
    else if((page==2 || page==4))
    {
    setcolor(2);
     if(Level==0)
     {
     circle(310,230,3);
     x=310,y=230;
     }
     else if(Level==10)
     {
     circle(313,30,3);
     x=313,y=30;
     }
    }
   }

  }while(ch1!=27 && ch1!='p');

  if(ch1=='p')
  {
   if(world==0)
   {
    if(page==1)
    page=2;
    else
    page=1;
   }
   else
   {
    if(page==3)
    page=4;
    else
    page=3;
   }
  }

 }while(ch1!=27);

}

void cater::difficulty()
{
cleardevice();
int y,cy,y1=155,cy1=155;
char ch1,ch2;

setlinestyle(SOLID_LINE,3,3);
setcolor(2);
rectangle(0,0,getmaxx(),getmaxy());
rectangle(3,3,getmaxx()-3,getmaxy()-3);
rectangle(6,6,getmaxx()-6,getmaxy()-6);
rectangle(9,9,getmaxx()-9,getmaxy()-9);
rectangle(12,12,getmaxx()-12,getmaxy()-12);

setlinestyle(SOLID_LINE,3,3);

settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
setcolor(4);

outtextxy(230,155,"Easy");
outtextxy(230,190,"Medium");
outtextxy(230,225,"Hard");
outtextxy(230,260,"Extreme");

 if(speed==100)
 y=180;
 else if(speed==80)
 y=215;
 else if(speed==60)
 y=250;
 else if(speed==40)
 y=285;

setcolor(1);
circle(500,y,2);

cy=y;

 do
 {

 setcolor(0);
 outtextxy(150,cy1,"->");
 setcolor(YELLOW);
 outtextxy(150,y1,"->");

 cy1=y1;

 ch1=getch();

  if(ch1==0)
  {
  ch2=getch();
   if(ch2==72)
   {
    if(y1==155)
    y1=260;
    else
    y1-=35;
   }
   else if(ch2==80)
   {
    if(y1==260)
    y1=155;
    else
    y1+=35;
   }
  }

  else if(ch1=='\r')
  {
   if(y1==155)
   {
   speed=100;
   y=180;
   }
   else if(y1==190)
   {
   speed=80;
   y=215;
   }
   else if(y1==225)
   {
   speed=60;
   y=250;
   }
   else
   {
   speed=40;
   y=285;
   }
   cancel();
   get(0);
   setcolor(0);
   circle(500,cy,2);
   setcolor(1);
   circle(500,y,2);
   cy=y;
  }

 }while(ch1!=27);

}
void cater::highscore()
{
int i;
char ch,c[10],cc[10];
cleardevice();
setlinestyle(SOLID_LINE,3,3);
setcolor(2);
rectangle(0,0,getmaxx(),getmaxy());
rectangle(3,3,getmaxx()-3,getmaxy()-3);
rectangle(6,6,getmaxx()-6,getmaxy()-6);
rectangle(9,9,getmaxx()-9,getmaxy()-9);
rectangle(12,12,getmaxx()-12,getmaxy()-12);
setcolor(9);
setfillstyle(SOLID_FILL,9);
rectangle(50,50,570,420);
rectangle(60,60,560,410);
rectangle(220,60,230,410);
rectangle(400,60,410,410);
floodfill(52,52,9);
floodfill(222,62,9);
floodfill(402,62,9);
setcolor(2);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
outtextxy(70,70,"LEVEL");
outtextxy(240,70,"ROUND");
outtextxy(420,70,"FLAT");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
for(i=0;i<11;i++)
{
itoa(i,c,10);
outtextxy(70,70+((i+1)*30),"LEVEL");
outtextxy(120,70+((i+1)*30),c);
}
for(i=0;i<11;i++)
{
itoa(o[i].point,c,10);
itoa(f[i].point,cc,10);
outtextxy(240,70+((i+1)*30),o[i].name);
outtextxy(360,70+((i+1)*30),c);
outtextxy(420,70+((i+1)*30),f[i].name);
outtextxy(520,70+((i+1)*30),cc);
}

 do
 {
 ch=getch();
 }while(ch!=27);

}

void cater::main_menu()
{

ifstream take("QWE.dat",ios::in);

 take.read((char*)&oj,sizeof(oj));
 world=oj.world;
 speed=oj.speed;
 Level=oj.Level;
 Sound=oj.Sound;

 take.close();

char ch1,ch2;
int x[5]={21,31,41,51,61},y[5]={70,70,70,70,70},cx1,cx2,y1=230,cy1;

 do
 {
 cleardevice();
 setlinestyle(SOLID_LINE,3,3);
 setcolor(6);
 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(3,3,getmaxx()-3,getmaxy()-3);
 rectangle(6,6,getmaxx()-6,getmaxy()-6);
 rectangle(9,9,getmaxx()-9,getmaxy()-9);
 rectangle(12,12,getmaxx()-12,getmaxy()-12);

 setcolor(GREEN);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,5);

 outtextxy(100,140,"CATERPILLER");

 setcolor(YELLOW);
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 outtextxy(250,230,"Continue");
 outtextxy(250,250,"New game");
 outtextxy(250,270,"Level");
 outtextxy(250,290,"World");
 outtextxy(250,310,"Options");
 outtextxy(250,330,"Difficulty");
 outtextxy(250,350,"Highscore");
 outtextxy(250,370,"Quit");

 settextstyle(SMALL_FONT,HORIZ_DIR,6);

  do
  {
  setlinestyle(SOLID_LINE,1,1);

  cx1=x[0];
  cx2=x[4];


   for(int i=0;i<5;i++)
   x[i]+=10;

   for(i=0;i<5;i++)
   {
    if(x[i]==621)
    x[i]=21;
   }

  setcolor(0);
  outtextxy(cx2+2,53,".");
  line(cx2,73,cx2+3,73);
  circle(cx1,70,5);

   for(i=0;i<5;i++)
   {
   setcolor(2);
   circle(x[i],y[i],5);
   }

  setcolor(RED);
  outtextxy(x[4]+2,y[4]-17,".");
  line(x[4],y[4]+3,x[4]+3,y[4]+3);

  cy1=y1;

   if(kbhit())
   {
   ch1=getch();
    if(ch1==0)
    {
    ch2=getch();
     if(ch2==72)
     {
      if(y1==230)
      y1=370;
      else
      y1-=20;
     }
     else if(ch2==80)
     {
     if(y1==370)
     y1=230;
     else
     y1+=20;
     }
    }

   }

  setcolor(0);
  outtextxy(200,cy1,"->");
  setcolor(5);
  outtextxy(200,y1,"->");

   if(ch1=='\r' && y1==290)
   {
    int y=293,cy=293;
    settextstyle(SMALL_FONT,HORIZ_DIR,4);

     if(world==0)
     setcolor(RED);
     else
     setcolor(WHITE);
     outtextxy(400,293,"OVERLAPPING");

     if(world==1)
     setcolor(RED);
     else
     setcolor(WHITE);
     outtextxy(400,305,"FLAT");

     setcolor(GREEN);
     outtextxy(380,y,"->");

      do
      {
       ch2='q';
       cy=y;
       ch1=getch();
	if(ch1==0)
	{

	 ch2=getch();
	 if(ch2==72 || ch2==80)
	 {
	  if(y==305)
	  y=293;
	  else
	  y=305;
	 }
	}
	else if(ch1=='\r')
	{
	 if(y==305 && world==0)
	 {
	 setcolor(WHITE);
	 outtextxy(400,293,"OVERLAPPING");
	 setcolor(RED);
	 outtextxy(400,305,"FLAT");
	 world=1;
	 }
	 if(y==293 && world==1)
	 {
	 setcolor(RED);
	 outtextxy(400,293,"OVERLAPPING");
	 setcolor(WHITE);
	 outtextxy(400,305,"FLAT");
	 world=0;
	 }
	}

       setcolor(0);
       outtextxy(380,cy,"->");

       setcolor(GREEN);
       outtextxy(380,y,"->");

      }while(ch2!=75);

    setcolor(0);
    outtextxy(400,293,"OVERLAPPING");
    outtextxy(400,305,"FLAT");
    outtextxy(380,y,"->");

    settextstyle(SMALL_FONT,HORIZ_DIR,6);
    ch1='q';
   }

  delay(50);

  }while(ch1!='\r');

  if(y1==370)
  break;

  else if(y1==250)
  break;

  else if(y1==230)
  {
  ifstream check("SA.dat",ios::in);

  check.read((char*)&PTR,sizeof(PART));

  check.close();

  if(PTR.x!=-100)
  {
  ifstream  give1("QWE.dat",ios::in);

  give1.read((char*)&oj,sizeof(oj));

   if(oj.world!=world || oj.Level!=Level || oj.speed!=speed)
   {

   settextstyle(SMALL_FONT,HORIZ_DIR,4);

   setcolor(43);
   outtextxy(400,230,"LEVEL,SPEED OR WORLD ARE CHANGED.");

   delay(500);

   setcolor(0);

   outtextxy(400,230,"LEVEL,SPEED OR WORLD ARE CHANGED.");

   }

   else
   {
   iniinfo=1;
   break;
   }

  }

  else
  {

  settextstyle(SMALL_FONT,HORIZ_DIR,4);

  setcolor(43);
  outtextxy(400,230,"NO SAVED GAME");

  delay(500);

  setcolor(0);

  outtextxy(400,230,"NO SAVED GAME");

  }

  }

  else if(y1==330)
  difficulty();

  else if(y1==350)
  highscore();

  else if(y1==270)
  level();

  else if(y1==310)
  options();

  ch1='q';

 }while(1);

 oj.world=world;
 oj.speed=speed;
 oj.Level=Level;
 oj.Sound=Sound;

ofstream  give1("QWE.dat",ios::out);

 give1.write((char*)&oj,sizeof(oj));

 give1.close();

 if(y1==370)
 {
 delete this;
 exit(0);
 }

}


void cater::point(int s=0)
{
int x,y,i;
char go='y';

 randomize();
 if(s==0)
 {
 x=((rand()%50)+6)*10;
 y=((rand()%35)+6)*10;
 }

 else if(s==1)
 {
 x=(random(50)+6)*10;
 y=(random(35)+6)*10;
 }

 do
 {

  if( (getpixel(x,y)==7) || (getpixel(x,y)==YELLOW) || (getpixel(x,y)==4) || (getpixel(x+5,y)==10 && getpixel(x-5,y)==10 && getpixel(x,y+5)==10 && getpixel(x,y-5)==10)
      || (getpixel(x+5,y)==4 && getpixel(x-5,y)==4 && getpixel(x,y+5)==4 && getpixel(x,y-5)==4))

  go='z';
  else
  go='y';

  if(go=='z')
  {
   if(x==560)
   x=200;
   else if(x==60)
   x=300;
   else if(y==410)
   y=200;
   else if(y==60)
   y=300;
   else
   {
    x+=10;
    y+=10;
   }
  }

 }while(go!='y');


 if(s==0)
 {
 px=x;
 py=y;
 setfillstyle(SOLID_FILL,4);
 setcolor(4);
 circle(x,y,5);
 floodfill(x,y,4);
 }

 else if(s==1)
 {
 PX=x;
 PY=y;
 setfillstyle(SOLID_FILL,YELLOW);
 setcolor(YELLOW);
 circle(x,y,5);
 floodfill(x,y,YELLOW);
 }

}

void cater::ini(int info)
{

 if(info==0)
 {
  for(int i=0;i<3;i++)
  {

    ptr=new part;

    if(start==NULL)
    {
     start=ptr;
     start->x=80;
     start->y=60;
     start->next=NULL;
     start->back=NULL;
     end=ptr;
    }
    else
    {
     ptr->back=end;
     end->next=ptr;
     end=ptr;
     end->next=NULL;
     end->x=80-(10*i);
     end->y=60;
    }

  }

 }

 else
 {

 ifstream take("SA.dat",ios::in);

  while(take)
  {
   ptr=new part;
   take.read((char*)&PTR,sizeof(PART));
   if(start==NULL)
    {
     start=ptr;
     start->x=PTR.x;
     start->y=PTR.y;
     start->next=NULL;
     start->back=NULL;
     end=ptr;
    }
    else
    {
     ptr->back=end;
     end->next=ptr;
     end=ptr;
     end->next=NULL;
     end->x=PTR.x;
     end->y=PTR.y;
    }
   }

 }

}

void cater::setup()
{
 cleardevice();

 setlinestyle(SOLID_LINE,3,3);
 setcolor(4);
 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(3,3,getmaxx()-3,getmaxy()-3);
 rectangle(6,6,getmaxx()-6,getmaxy()-6);
 rectangle(9,9,getmaxx()-9,getmaxy()-9);
 rectangle(12,12,getmaxx()-12,getmaxy()-12);

  if(world==1)
  setcolor(RED);
  else
  setcolor(121);
  rectangle(50,50,570,420);

 setcolor(7);
 setfillstyle(SOLID_FILL,7);

 if(Level==2)
 {
  bar(310,150,320,320);
 }

 else if(Level==3)
 {
 bar(300,160,330,320);
 bar(210,130,410,160);
 }

 else if(Level==4 && world==0)
 {
  bar(50,230,570,240);
 }


 else if(Level==5 && world==0)
 {
  bar(50,180,570,190);
  bar(150,300,570,310);
 }

 else if(Level==6)
 {
  bar(190,140,290,150);
  bar(330,140,430,150);
  bar(190,150,200,200);
  bar(420,150,430,200);
  bar(190,230,200,280);
  bar(420,230,430,280);
  bar(200,270,290,280);
  bar(330,270,420,280);
 }

 else if(Level==7 && world==0)
 {
  bar(50,130,570,140);
  bar(50,230,470,240);
  bar(150,330,570,340);
 }

 else if(Level==8 && world==0)
 {
  bar(220,50,230,170);
  bar(50,160,220,170);
  bar(400,50,410,170);
  bar(410,160,520,170);
  bar(220,300,230,420);
  bar(50,300,220,310);
  bar(400,300,410,420);
  bar(410,300,570,310);
  bar(310,170,320,300);
 }

 else if(Level==5 && world==1)
 {
 bar(150,100,160,300);
 bar(250,170,260,370);
 bar(350,100,360,300);
 bar(450,170,460,370);
 }

 else if(Level==8 && world==1)
 {
 bar(150,170,470,180);
 bar(150,290,470,300);
 bar(200,230,420,240);
 bar(150,180,160,210);
 bar(460,180,470,210);
 bar(150,290,160,260);
 bar(460,290,470,260);
 }

 else if(Level==7 && world==1)
 {
 bar(100,140,520,150);
 bar(100,230,520,240);
 bar(100,320,520,330);
 }

 else if(Level==9 && world==0)
 {
 bar(150,130,570,140);
 bar(50,230,570,240);
 bar(150,330,570,340);
 bar(220,50,230,100);
 bar(390,50,400,130);
 bar(300,140,310,230);
 bar(220,240,230,330);
 bar(390,240,400,300);
 }

 else if(Level==0 && world==1)
 {
 bar(120,120,190,130);
 bar(120,150,190,160);
 bar(120,190,190,200);
 bar(180,200,190,270);
 bar(180,270,120,260);
 bar(120,340,190,350);
 bar(120,320,190,310);
 bar(260,100,270,160);
 bar(260,160,340,170);
 bar(330,160,340,100);
 bar(430,120,500,130);
 bar(430,150,500,160);
 bar(430,190,500,200);
 bar(430,200,440,270);
 bar(440,260,500,270);
 bar(260,300,340,310);
 bar(260,310,270,370);
 bar(330,310,340,370);
 bar(430,340,500,350);
 bar(260,230,340,240);
 bar(70,100,80,370);
 bar(540,100,550,370);
 bar(120,70,500,80);
 bar(120,390,500,400);
 bar(430,320,500,310);
 bar(260,190,340,200);
 bar(260,270,340,280);
 bar(380,80,390,390);
 bar(220,120,230,350);
 }

 else if(Level==10 && world==1)
 {
 bar(250,50,260,300);
 bar(260,300,520,290);
 bar(260,220,520,230);
 bar(260,140,520,150);
 bar(510,140,520,90);
 bar(80,120,90,250);
 bar(90,240,220,250);
 bar(210,240,220,120);
 bar(150,280,160,380);
 bar(160,370,250,380);
 bar(240,370,250,330);
 bar(350,370,520,380);
 bar(80,280,90,380);
 }

 else if(Level==10 && world==0)
 {
 bar(200,120,420,130);
 bar(200,130,210,360);
 bar(410,130,420,360);
 bar(250,300,370,310);
 bar(250,170,260,300);
 bar(360,170,370,300);
 bar(290,210,300,270);
 bar(300,210,330,220);
 bar(300,260,330,270);
 bar(210,350,280,360);
 bar(340,350,410,360);
 bar(260,170,290,180);
 bar(330,170,360,180);
 bar(150,50,160,130);
 bar(50,120,150,130);
 bar(460,50,470,130);
 bar(470,120,520,130);
 bar(150,350,160,420);
 bar(50,350,150,360);
 bar(460,350,470,420);
 bar(470,350,570,360);
 bar(110,150,120,330);
 bar(500,150,510,330);
 bar(180,80,440,90);
 bar(180,380,440,390);
 }

 else if(Level==4 && world==1)
 {
 bar(140,230,250,240);
 bar(360,230,470,240);
 bar(300,110,310,200);
 bar(300,270,310,360);
 }

 else if(Level==9 && world==1)
 {
 bar(150,80,160,390);
 bar(250,80,260,390);
 bar(350,80,360,390);
 bar(450,80,460,390);
 }

 else if(Level==0 && world==0)
 {
 bar(50,230,570,240);
 bar(220,50,230,230);
 bar(50,90,180,100);
 bar(100,130,220,140);
 bar(130,160,140,230);
 bar(220,240,230,400);
 bar(80,260,90,330);
 bar(180,260,190,330);
 bar(110,290,160,300);
 bar(50,360,120,370);
 bar(150,360,220,370);
 bar(390,100,400,230);
 bar(230,100,360,110);
 bar(260,130,390,140);
 bar(230,170,310,180);
 bar(340,170,350,230);
 bar(260,210,270,230);
 bar(390,240,400,420);
 bar(230,270,350,280);
 bar(260,310,390,320);
 bar(230,360,330,370);
 bar(260,390,390,400);
 bar(430,50,440,190);
 bar(480,90,490,230);
 bar(520,140,570,150);
 bar(480,240,490,290);
 bar(440,320,530,330);
 bar(450,360,460,420);
 bar(510,360,520,420);
 }

}



void cater::play()
{

cancel();

get(1);

main_menu();

setup();

ini(iniinfo);

settextstyle(SMALL_FONT,HORIZ_DIR,6);

setlinestyle(SOLID_LINE,1,1);

char ch1,ch2,dir='q';
int over,col;

char ch[10];
HS=score();

setlinestyle(SOLID_LINE,1,1);

 setcolor(4);
 circle(start->x,start->y,5);

 setcolor(LIGHTGREEN);

 ptr=start->next;
 while(ptr->next!=NULL)
 {
 circle(ptr->x,ptr->y,5);
 ptr=ptr->next;
 }

  if(iniinfo==0)
 point();
 else
 {

 setcolor(4);

 ifstream cor("zcx.dat",ios::in);

 cor>>px;
 cor>>py;
 cor>>time;
 cor>>cs;
 cor>>pp;
 cor>>PX;
 cor>>PY;
 cor>>len;

 cor.close();

 setfillstyle(SOLID_FILL,4);
 circle(px,py,5);
 setcolor(4);
 floodfill(px,py,4);
 }

 if(PX!=0)
 {

  setcolor(YELLOW);

  circle(PX,PY,5);

  setfillstyle(SOLID_FILL,YELLOW);

  floodfill(PX,PY,YELLOW);

  setcolor(6);
  itoa(time,ch,10);
  outtextxy(420,430,ch);

 }

 setcolor(2);
 outtextxy(50,30,"Level:-");
 if(Level==0)
 outtextxy(115,30,"TWILIGHT");
 else
 {
 itoa(Level,ch,10);
 outtextxy(115,30,ch);
 }

setcolor(YELLOW);
outtextxy(220,30,"WORLD:-");
 if(world==1)
 outtextxy(290,30,"FLAT");
 else
 outtextxy(290,30,"OVERLAPPING");

setcolor(3);
outtextxy(470,30,"POINT:-");
itoa(pp,ch,10);
outtextxy(535,30,ch);

setcolor(1);
outtextxy(200,430,"HIGH-SCORE:-");
itoa(HS,ch,10);
outtextxy(320,430,ch);

 setcolor(RED);
 settextstyle(SMALL_FONT,HORIZ_DIR,4);

 outtextxy(265,52,"PRESS CORRECT KEY.");

 do
 {

 ch1=getch();

    if(ch1==0)
    {
     ch2=getch();

      if(ch2==75&&dir!='r')
      dir='l';
      else if(ch2==80&&dir!='u')
      dir='d';
      else if(ch2==77&&dir!='l')
      dir='r';
      else if(ch2==72&&dir!='d')
      dir='u';
     }

 }while(ch1!=0);

 setcolor(0);
 outtextxy(265,52,"PRESS CORRECT KEY.");

 settextstyle(SMALL_FONT,HORIZ_DIR,6);

 setfillstyle(SOLID_FILL,4);
 circle(px,py,5);
 setcolor(4);
 floodfill(px,py,4);

 do
 {


   if(kbhit())
  {


   ch1=getch();

    if(ch1==0)
    {
     ch2=getch();

      if(ch2==75&&dir!='r')
      dir='l';
      else if(ch2==80&&dir!='u')
      dir='d';
      else if(ch2==77&&dir!='l')
      dir='r';
      else if(ch2==72&&dir!='d')
      dir='u';
     }

    else if(ch1==27)
    {

     settextstyle(SMALL_FONT,HORIZ_DIR,4);

     setcolor(5);
     outtextxy(265,52,"ARE YOU SURE(y/n)");

     do
     {

     ch2=getch();

     if(ch2=='y')
     goto DEL;

     }while(ch2!='v');

     setcolor(0);
     outtextxy(265,52,"ARE YOU SURE(y/n)");

     settextstyle(SMALL_FONT,HORIZ_DIR,6);

    }
   }

  ptr=end;
  while(ptr->back!=NULL)
  {
   ptr->x=ptr->back->x;
   ptr->y=ptr->back->y;
   ptr=ptr->back;
  }

 if(dir=='r')
 start->x+=10;
 else if(dir=='l')
 start->x-=10;
 else if(dir=='u')
 start->y-=10;
 else
 start->y+=10;

 if(start->x==570)
  {
   if(!world)
   start->x=60;
   else
   {
   out=1;
   goto DEL;
   }
  }
  if(start->x==50)
  {
   if(!world)
   start->x=560;
   else
   {
   out=1;
   goto DEL;
   }
  }
  if(start->y==420)
  {
   if(!world)
   start->y=60;
   else
   {
   out=1;
   goto DEL;
   }
  }
  if(start->y==50)
  {
   if(!world)
   start->y=410;
   else
   {
   out=1;
   goto DEL;
   }
  }

 if(getpixel(start->x,start->y)==7)
 {
 out=1;
 goto DEL;
 }

 col=getpixel(start->x+5,start->y)+getpixel(start->x-5,start->y)+getpixel(start->x,start->y+5)+getpixel(start->x,start->y-5);

 if(col==40 || col==34)
 {
  if(start->x!=end->x || start->y!=end->y)
  {
  out=1;
  goto DEL;
  }
 }


  setcolor(0);
  circle(end->x,end->y,5);

  if(end->x==px+10 || end->y==py+10 || end->x==px-10 || end->y==py-10)
  {
  setfillstyle(SOLID_FILL,4);
  circle(px,py,5);
  setcolor(4);
  floodfill(px,py,4);
  }

  if(end->x==PX+10 || end->y==PY+10 || end->x==PX-10 || end->y==PY-10)
  {
  setcolor(YELLOW);
  setfillstyle(SOLID_FILL,YELLOW);
  circle(PX,PY,5);
  setcolor(YELLOW);
  floodfill(PX,PY,YELLOW);
  }

 setcolor(4);
 circle(start->x,start->y,5);

 setcolor(LIGHTGREEN);
 ptr=start->next;
 while(ptr->next!=NULL)
 {
 circle(ptr->x,ptr->y,5);
 ptr=ptr->next;
 }

 if((start->x==px && start->y==py))
 {

  if(Sound==1)
  sound(700);

 len++;

 setcolor(10);
 setfillstyle(SOLID_FILL,0);
 circle(px,py,5);
 floodfill(px,py,10);
 setcolor(4);
 circle(px,py,5);
 setcolor(LIGHTGREEN);
 circle(end->x,end->y,5);
 ptr=new part;
 ptr->back=end;
 end->next=ptr;
 end=ptr;
 end->next=NULL;
 point();
 setcolor(0);
 itoa(pp,ch,10);
 outtextxy(535,30,ch);
 pp+=10;
 setcolor(3);
 itoa(pp,ch,10);
 outtextxy(535,30,ch);

 if(HS<=pp)
 {
 setcolor(0);
 itoa(HS,ch,10);
 outtextxy(320,430,ch);
 setcolor(1);
 itoa(pp,ch,10);
 outtextxy(320,430,ch);
 HS=pp;
 }

 setcolor(10);

 }

 if(start->x==PX && start->y==PY)
 {

  if(Sound==1)
  sound(1000);

 len++;

 setcolor(4);
 circle(PX,PY,5);
 setfillstyle(SOLID_FILL,0);
 floodfill(PX,PY,4);

 ptr=new part;
 ptr->back=end;
 end->next=ptr;
 end=ptr;
 end->next=NULL;

 setcolor(0);
 itoa(pp,ch,10);
 outtextxy(535,30,ch);
 pp+=time;
 setcolor(3);
 itoa(pp,ch,10);
 outtextxy(535,30,ch);

  if(HS<=pp)
  {
  setcolor(0);
  itoa(HS,ch,10);
  outtextxy(320,430,ch);
  setcolor(1);
  itoa(pp,ch,10);
  outtextxy(320,430,ch);
  HS=pp;
  }

 setcolor(10);

 PX=0;PY=0;
 cs='n';
 setcolor(0);
 itoa(time,ch,10);
 outtextxy(420,430,ch);

 time=100;

 }

 if(cs=='y')
 {

  time--;

  if(time==0)
  {
  cs='n';
  setfillstyle(SOLID_FILL,0);
  setcolor(1);
  circle(PX,PY,5);
  floodfill(PX,PY,1);
  setcolor(0);
  circle(PX,PY,5);
  setcolor(10);
  PX=0,PY=0;
  time=100;
  setcolor(0);
  outtextxy(420,430,"100");
  }

  else
  {
  setcolor(0);
  itoa(time+1,ch,10);
  outtextxy(420,430,ch);

  setcolor(6);
  itoa(time,ch,10);
  outtextxy(420,430,ch);
  }

  }

 if( ((len%5==0)) && (over!=pp) && (pp!=0) && PX==0)
 {
 point(1);
 over=pp;
 cs='y';
 }


 if(ch1=='p')
 {
  nosound();

  settextstyle(SMALL_FONT,HORIZ_DIR,4);

  setcolor(5);
  outtextxy(265,52,"TO RESUME(PRESS:-r).");

  do
  {
  ch2=getch();
  }while(ch2!='r');

  setcolor(0);
  outtextxy(265,52,"TO RESUME(PRESS:-r).");

  ch1='w';

  settextstyle(SMALL_FONT,HORIZ_DIR,6);

 }

 delay(speed);

 nosound();

 }while(1);

DEL:

 save();

 compare();

 ptr=start;
 while(ptr!=NULL)
 {
 part *del=ptr;
 ptr=ptr->next;
 delete del;
 }

}


 void main()
 {
 clrscr();
 int a=DETECT,b=3;
 initgraph(&a,&b,"c:\\turboc3\\bgi");
 cater *game;

 game=new cater;

 game->intro();

 delete game;

 while(1)
 {

 game=new cater;

 game->play();

 delete game;

 }

 }
