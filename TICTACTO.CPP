#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<alloc.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

void initmouse();
void setmouse(int &,int &);
void showmouse();
void getmouse();
void hidemouse();
void graph();
void startgraph();
void gameloadingscreen();
void menuscreen();
void gamescreen();
void gamescreenrecall();
void scorescreen();
void helpscreen();
void aboutscreen();
void inputnamescreen();
void exitgame();
void resetboxes();
void whichplayerturn();
void board();
void checkgamestatus();
void savescore2file(int);
void heading(char s[70]);
char* getstring(char);
void savescore2file(int gamestatus);
void backbutton();

union REGS in,out;
int px=1,py=1;
int click=0;

char box[11];
char markx0;
int playerturn=1;
char firstplayername[30]="Sagar";
char secondplayername[30]="Sarika";
char currentplayername[40]="";
char* combineplayernames();
int gamestatus=0;



void main()
{
 startgraph();
// graph();
 initmouse();
 gameloadingscreen();
 menuscreen();
// showmouse();
 getch();
 cleardevice();
 closegraph();
}

void gameloadingscreen()
{
 setbkcolor(LIGHTBLUE);
 settextstyle(8,0,5);
 setcolor(WHITE);
 outtextxy(150,100,"TIC TAC TOA");
 settextstyle(2,0,5);
 setcolor(DARKGRAY);
 outtextxy(200,160,"A Fun Moment Begining....");

 for(int y=1;y<=255;y++)
 {
  bar3d(160,400,170+y,420,0,0);
  delay(2);
 }
 cleardevice();
}

void menuscreen()
{
// cleardevice();
// graph();
// setmouse(500,400);
// showmouse();
 bar3d(230,10,410,35,5,1);
 settextstyle(1,0,1);

 setcolor(BLUE);
 outtextxy(270,10,"MAIN MENU");

 setfillstyle(1,LIGHTGRAY);
 bar(240,100,400,100+20);
 settextstyle(1,0,1);
 setcolor(BLUE);
 outtextxy(270,97,"Play Game");

 bar(240,150,400,150+20);
 settextstyle(1,0,1);
 setcolor(BLUE);
 outtextxy(292,147,"Scores");

 bar(240,200,400,200+20);
 settextstyle(1,0,1);
 setcolor(BLUE);
 outtextxy(265,197,"Input Names");

 bar(240,250,400,250+20);
 settextstyle(1,0,1);
 setcolor(BLUE);
 outtextxy(291,248,"About");

 bar(240,300,400,300+20);
 settextstyle(1,0,1);
 setcolor(BLUE);
 outtextxy(300,297,"Help");

 bar(240,350,400,350+20);
 settextstyle(1,0,1);
 setcolor(BLUE);
 outtextxy(300,347,"Exit");

 showmouse();
 while(1)
 {
  getmouse();
  if(px>=240&&px<=400&&py>=100&&py<=100+20&&click==1) //Play game
  {
   hidemouse();
   playerturn=1;
   gamestatus=0;
   resetboxes();
   gamescreen();
   break;
  }

 else if(px>=240&&px<=400&&py>=150&&py<=150+20&&click==1) //Scores
  {
   hidemouse();
   scorescreen();
   break;
  }

 else if(px>=240&&px<=400&&py>=200&&py<=200+20&&click==1) //Input names
  {
   hidemouse();
   inputnamescreen();
   break;
  }

 else if(px>=240&&px<=400&&py>=250&&py<=250+20&&click==1) //About
  {
   hidemouse();
   aboutscreen();
   break;
  }

 else if(px>=240&&px<=400&&py>=300&&py<=300+20&&click==1) //Help
  {
   hidemouse();
   helpscreen();
   break;
  }

 else if(px>=240&&px<=400&&py>=350&&py<=350+20&&click==1) //Exit
  {
   hidemouse();
   exit(1);
  }

 }

}

void resetboxes()
{
 box[0]='0';
 box[1]='1';
 box[2]='2';
 box[3]='3';
 box[4]='4';
 box[5]='5';
 box[6]='6';
 box[7]='7';
 box[8]='8';
 box[9]='9';
 box[10]=NULL;
}

void gamescreen()
{
 cleardevice();
 setfillstyle(1,WHITE);
 bar3d(230,8,420,34,5,1);
 settextstyle(1,0,2);
 outtextxy(240,8,"==TIC TAC TOE==");

 setcolor(WHITE);
 outtextxy(35,30,combineplayernames());

 whichplayerturn();
 board();

 settextstyle(1,0,2);
 bar3d(40,430,40+100,430+30,5,1);
 outtextxy(70,430,"Back...");

 checkgamestatus();
 setmouse(300,450);
 showmouse();
 while(1)
 {
  getmouse();
  checkgamestatus();
  if(gamestatus==1||gamestatus==2)
  {
   goto end;
  }
  if(px>=40&&px<=140&&py>=80&&py<=180&&click==1&&box[1]=='1')
  {
   box[1]=markx0;
   gamescreen();
  }

  if(px>=150&&px<=250&&py>=80&&py<=180&&click==1&&box[2]=='2')
  {
   box[2]=markx0;
   gamescreen();
  }

  if(px>=260&&px<=360&&py>=80&&py<=180&&click==1&&box[3]=='3')
  {
   box[3]=markx0;
   gamescreen();
  }

  if(px>=40&&px<=140&&py>=190&&py<=290&&click==1&&box[4]=='4')
  {
   box[4]=markx0;
   gamescreen();
  }

  if(px>=150&&px<=250&&py>=190&&py<=290&&click==1&&box[5]=='5')
  {
   box[5]=markx0;
   gamescreen();
  }

  if(px>=260&&px<=360&&py>=190&&py<=290&&click==1&&box[6]=='6')
  {
   box[6]=markx0;
   gamescreen();
  }

  if(px>=40&&px<=140&&py>=300&&py<=400&&click==1&&box[7]=='7')
  {
   box[7]=markx0;
   gamescreen();
  }

  if(px>=150&&px<=250&&py>=300&&py<=400&&click==1&&box[8]=='8')
  {
   box[8]=markx0;
   gamescreen();
  }

  if(px>=260&&px<=360&&py>=300&&py<=400&&click==1&&box[9]=='9')
  {
   box[9]=markx0;
   gamescreen();
  }

  if(px>=40&&px<=140&&py>=430&&py<=460&&click==1)
  {
   hidemouse();
   cleardevice();
   menuscreen();
  }

 }

 end:
 char str[70];
 if(gamestatus==1)
 {
  int t=1;

  settextstyle(1,0,3);
  setcolor(BLUE);

  strcpy(str,"");
  if(t==1)
     whichplayerturn();
  t++;
  strcat(str,currentplayername);
  strcat(str," Win...");

  setfillstyle(1,WHITE);
  bar3d(410,60,620,250,10,1);
  outtextxy(420,75,str);

  circle(520,190,50);
  circle(500,170,10);
  circle(540,170,10);
  ellipse(520,210,180,360,30,15);
  savescore2file(gamestatus);
 }
 else if(gamestatus==2)
 {
  char str[30];
  settextstyle(1,0,3);
  setcolor(GREEN);

  strcpy(str,"");
  strcat(str,"Game Draw...");
  setfillstyle(1,WHITE);
  bar3d(410,60,620,250,10,1);
  outtextxy(420,80,str);

  circle(520,190,50);
  circle(500,170,10);
  circle(540,170,10);
  ellipse(520,210,0,180,30,15);
  savescore2file(gamestatus);
 }
 setcolor(BLUE);
 bar3d(450,430,450+170,430+30,5,1);
 outtextxy(475,430,"Play Again...");
// static int tt=1;
// if(tt==1)
//  whichplayerturn();
// tt++;
 while(1)
 {
  getmouse();
  if(px>=40&&px<=140&&py>=430&&py<=460&&click==1)
  {
   hidemouse();
   cleardevice();
   menuscreen();
  }
  if(px>=450&&px<=450+170&&py>=430&&py<=430+30&&click==1)
  {
   hidemouse();
   cleardevice();
   gamescreenrecall(); break;
  }
 }

// hidemouse();
// manuscreen();
}

void gamescreenrecall()
{
 resetboxes();
 gamescreen();
}

void scorescreen()
{
 cleardevice();
 setfillstyle(1,WHITE);
 bar3d(230,8,420,34,5,1);
 settextstyle(1,0,1);
 outtextxy(239,8,"==SCORE SCREEN==");

 settextstyle(2,0,5);
 setcolor(WHITE);

 ifstream ifs;
 ifs.open("score.txt",ios::in);

 char line[200];
 int i=0;
 int serialno=1;
 char msg[205]="";

 if(ifs==NULL||ifs.eof()!=0)
 {
  outtextxy(20,80,"Score List Is Empty....");
  goto end;
 }
 while(ifs.eof()==0)
 {
  delay(100);
  ifs.getline(line,200);
  if(strcmp(line,"")==0) continue;
  sprintf(msg,"%d.) %s",++serialno,line);
  outtextxy(48,80+i,msg);
  i+=20;
 }

 end:
 settextstyle(1,0,2);
 setcolor(BLUE);
 bar3d(40,430,40+100,430+30,5,1);
 outtextxy(70,430,"Back...");

 showmouse();

 while(1)
 {
  getmouse();
  if(px>=40&&px<=140&&py>=430&&py<=460&&click==1)
  {
   hidemouse();
   cleardevice();
   menuscreen();
   break;
  }
 }

}

void inputnamescreen()
{
 cleardevice();
 setfillstyle(1,WHITE);
 bar3d(230,8,420,34,5,1);
 settextstyle(1,0,1);
 outtextxy(239,8,"==INPUT NAME==");

 bar(100,120,380,150);
 outtextxy(109,123,"Enter First Player's Name:- ");
 gotoxy(50,9);
 fflush(stdin);
 gets(firstplayername);
 fflush(stdin);

 bar(100,167,380,197);

 outtextxy(109,170,"Enter Second Player's Name:- ");
 gotoxy(50,12);
 gets(secondplayername);
 fflush(stdin);

 sleep(1);
 cleardevice();
 menuscreen();
}

void aboutscreen()
{
 cleardevice();
 setfillstyle(1,WHITE);
 bar3d(230,8,420,34,5,1);
 settextstyle(1,0,1);
 outtextxy(267,8,"==ABOUT==");


 setcolor(WHITE);
 outtextxy(270,100,"Tic Tac Toe");
 char dis1[]="1.> This Application Is developed only for fun";
 char dis2[]=" and Good quality graphices is used in this application.";
 outtextxy(70,140,dis1);
 outtextxy(70,160,dis2);
 char dis3[]="2.> This Game (tic tac toe) is developed in c++ language.";
 outtextxy(70,200,dis3);
 char dis4[]="3.> There are two player in this GAME, and both has";
 char dis5[]="own identity. First player has 'X' sign & second player has";
 char dis6[]="'0' sign object. If three same sign is matched then game is";
 char dis7[]="Win by last sign is filled in the box.";
 outtextxy(70,240,dis4);
 outtextxy(70,260,dis5);
 outtextxy(70,280,dis6);
 outtextxy(70,300,dis7);
 char me1[]="This Game is developed by...";
 char me2[]="Sagar Kumar(BCA 4th Sem)";
 outtextxy(70,350,me1);
 outtextxy(70,370,me2);


 settextstyle(1,0,2);
 setcolor(BLUE);
 bar3d(40,430,40+100,430+30,5,1);
 outtextxy(70,430,"Back...");

 showmouse();

 while(1)
 {
  getmouse();
  if(px>=40&&px<=140&&py>=430&&py<=460&&click==1)
  {
   hidemouse();
   cleardevice();
   menuscreen();
   break;
  }
 }

}

void helpscreen()
{
 cleardevice();
 setfillstyle(1,WHITE);
 bar3d(230,8,420,34,5,1);
 settextstyle(1,0,1);
 outtextxy(274,8,"==HELP==");

 setcolor(WHITE);
 outtextxy(270,100,"Tic Tac Toe");
 char dis1[]="1.> Use your mouse cursor/pointer to play this game";
 char dis2[]=" Warning...........You Can't use use your Keyboard Button";
 char dis22[]="to play this game Keyboard button aren't work here.";
 outtextxy(70,140,dis1);
 outtextxy(70,160,dis2);
 outtextxy(70,180,dis22);
 char dis3[]="2.> You can't click already clicked box.";
 outtextxy(70,220,dis3);
 char dis4[]="3.> If you have any proble to play this game than you can ";
 char dis5[]="Email me...........";
 char dis6[]="Email Id:- Sagarprins@58@gmail.com";
 char dis7[]="Have fun Guys.............";
 outtextxy(70,260,dis4);
 outtextxy(70,280,dis5);
 outtextxy(70,300,dis6);
 outtextxy(70,320,dis7);


 settextstyle(1,0,2);
 setcolor(BLUE);
 bar3d(40,430,40+100,430+30,5,1);
 outtextxy(70,430,"Back...");

 showmouse();

 while(1)
 {
  getmouse();
  if(px>=40&&px<=140&&py>=430&&py<=460&&click==1)
  {
   hidemouse();
   cleardevice();
   menuscreen();
   break;
  }
 }
}


void savescore2file(int gamestatus)
{
 time_t t1;
 t1=time(NULL);
 ofstream ofs;
 ofs.open("Score.txt",ios::app);
 char msg[70];

 if(gamestatus==1)
 {
  ofs<<"\n"<<firstplayername<<" v/s "<<secondplayername<<" and Win by "<<currentplayername<<" DATE: "<<ctime(&t1);
 }
 else if(gamestatus==2)
 {
  ofs<<"\n"<<firstplayername<<" v/s "<<secondplayername<<" and Game Draw..."<<" DATE: "<<ctime(&t1);
 }
 ofs.close();
}

char* combineplayernames()
{
 char *str;
 strcpy(str,"");
 strcat(str,"For ");
 strcat(str,firstplayername);
 strcat(str,": X");
 strcat(str," And ");
 strcat(str,secondplayername);
 strcat(str,": 0");
 return str;
}

void whichplayerturn()
{
// graph();
 if(playerturn==1)
 {
  setcolor(GREEN);
  markx0='X';
  playerturn=2;
  strcpy(currentplayername,firstplayername);
 }
 else if(playerturn==2)
 {
  setcolor(GREEN);
  markx0='0';
  playerturn=1;
  strcpy(currentplayername,secondplayername);
 }

 bar3d(420,70,580,140,0,0);
 settextstyle(1,0,3);
 setcolor(GREEN);
 char msg[30];
 strcpy(msg,"");
 strcat(msg," Now ");
 strcat(msg,currentplayername);
 outtextxy(430,80,msg);
 char msg2[10];
 strcpy(msg2,"");
 strcat(msg2," Turn...");
 outtextxy(450,100,msg2);
}

char* getstring(char a)
{
 char *s;

 switch(a)
 {
  case '0': s="0"; break;
  case 'X': s="X"; break;
  case '1': s="1"; break;
  case '2': s="2"; break;
  case '3': s="3"; break;
  case '4': s="4"; break;
  case '5': s="5"; break;
  case '6': s="6"; break;
  case '7': s="7"; break;
  case '8': s="8"; break;
  case '9': s="9"; break;
 }
 return s;
}

void board()
{
 settextstyle(4,0,5);
 setcolor(BLUE);
 setfillstyle(1,GREEN);
 bar3d(40-10,80-10,360+10,400+10,20,1);
 setfillstyle(1,GREEN);
 floodfill(60,60,BLUE);
 floodfill(380,140,BLUE);

 setfillstyle(1,WHITE);
 bar(40,80,140,180);
 outtextxy(40+50-9,80+50-28,getstring(box[1]));

 bar(150,80,250,180);
 outtextxy(150+50-9,80+50-28,getstring(box[2]));

 bar(260,80,360,180);
 outtextxy(260+50-9,80+50-28,getstring(box[3]));

 bar(40,190,140,290);
 outtextxy(40+50-9,190+50-28,getstring(box[4]));

 bar(150,190,250,290);
 outtextxy(150+50-9,190+50-28,getstring(box[5]));

 bar(260,190,360,290);
 outtextxy(260+50-9,190+50-28,getstring(box[6]));

 bar(40,300,140,400);
 outtextxy(40+50-9,300+50-28,getstring(box[7]));

 bar(150,300,250,400);
 outtextxy(150+50-9,300+50-28,getstring(box[8]));

 bar(260,300,360,400);
 outtextxy(260+50-9,300+50-28,getstring(box[9]));
}

void checkgamestatus()
{
 if(
    (box[1]==box[2]&&box[2]==box[3])||
    (box[4]==box[5]&&box[5]==box[6])||
    (box[7]==box[8]&&box[8]==box[9])||
    (box[1]==box[4]&&box[4]==box[7])||
    (box[2]==box[5]&&box[5]==box[8])||
    (box[3]==box[6]&&box[6]==box[9])||
    (box[1]==box[5]&&box[5]==box[9])||
    (box[3]==box[5]&&box[5]==box[7])
   )
   {
    gamestatus=1;
    return;
   }

   if(box[1]!='1'&&box[2]!='2'&&box[3]!='3'&&box[4]!='4'&&box[5]!='5'&&
   box[6]!='6'&&box[7]!='7'&&box[8]!='8'&&box[9]!='9')
   {
    gamestatus=2;
   }
   else
   {
    gamestatus=0;
   }

}

void initmouse()
{
 in.x.ax=0;
 int86(51,&in,&out);
}

void showmouse()
{
 in.x.ax=1;
 int86(51,&in,&out);
}

void hidemouse()
{
 in.x.ax=2;
 int86(51,&in,&out);
}

void getmouse()
{
 in.x.ax=3;
 int86(51,&in,&out);
 click=out.x.bx;
 px=out.x.cx;
 py=out.x.dx;
}

void setmouse(int &px,int &py)
{
 in.x.ax=4;
 in.x.cx=px;
 in.x.dx=py;
 int86(51,&in,&out);
}


void startgraph()
{
 int gd=DETECT;
 int gm,errorcode;

 initgraph(&gd,&gm,"c:\\turboc3\\bgi");

 errorcode=graphresult();

 if(errorcode!=grOk)
 {
  cout<<"Error Massage: "<<grapherrormsg(errorcode)<<endl;
  getch();
  exit(1);
 }
}


void graph()
{
 int x;
 int y;
 int i;
 char xsg[10];
 char ysg[10];

 setbkcolor(DARKGRAY);
 settextstyle(2,0,2);

 for(x=0,y=0;x<=639;x=x+20,y=y+20)
 {
  //for x axis
  setcolor(WHITE);
  line(x,0,x,479);
  sprintf(xsg,"%d",x);
  outtextxy(x+2,0,xsg);

  //for y axis
  setcolor(WHITE);
  line(0,y,639,y);
  sprintf(ysg,"%d",y);
  outtextxy(0+2,y+1,ysg);

  //RED color for x,y axis
  setcolor(RED);
  line(x+10,0+10,x+10,479);
  line(0+10,y+10,639,y+10);
 }
}
