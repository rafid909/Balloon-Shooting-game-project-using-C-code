#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>


void draw_screen();
void show_score(int chance,int success,int score,int shaft,int color);
void draw_shaft(int x,int y,int c);
void draw_baloon(int x,int y,int c);
void start();
void main()
{
   int gd=0,gm;
   initgraph(&gd,&gm,"c:\\tc\\bgi");
   start();
   draw_screen();
   int chance=0,success=0,score=0,chance_end=0,ball_diff=30,hit=0,shaft=3,flag=0,b;
   int shaft_x=185,shaft_y=200,shaft_color=4,bonus=0;
   int baloon1_x=400;
   int baloon2_x=baloon1_x+ball_diff;
   int baloon3_x=baloon2_x+ball_diff;
   int baloon4_x=baloon3_x+ball_diff;
   int baloon_y=400,baloon_color=4;
   int baloon1=1,baloon2=1,baloon3=1,baloon4=1;
   union REGS ii,oo;
   /*show initial score*/
   show_score(chance,success,score,shaft,0);
   draw_shaft(shaft_x,shaft_y,shaft_color);

   draw_baloon(baloon1_x,baloon_y,baloon_color);
   draw_baloon(baloon2_x,baloon_y,baloon_color);
   draw_baloon(baloon3_x,baloon_y,baloon_color);
   draw_baloon(baloon4_x,baloon_y,baloon_color);

   char ch;
   while(shaft)
   {
    flag=0;
    b=0;
    chance_end=0;//initial a chance*/
    baloon1=1;baloon2=1;baloon3=1;baloon4=1;
    while(!chance_end){

       while(!kbhit()){
       delay(20); //wait 20 miliseconds
       //irrage all the ballons with screen color
       baloon_color=2;

   draw_baloon(baloon1_x,baloon_y,baloon_color);
   draw_baloon(baloon2_x,baloon_y,baloon_color);
   draw_baloon(baloon3_x,baloon_y,baloon_color);
   draw_baloon(baloon4_x,baloon_y,baloon_color);
   baloon_y--;
   baloon_color=4;

   draw_baloon(baloon1_x,baloon_y,baloon_color);
   draw_baloon(baloon2_x,baloon_y,baloon_color);
   draw_baloon(baloon3_x,baloon_y,baloon_color);
   draw_baloon(baloon4_x,baloon_y,baloon_color);

       }

	ii.h.ah=0;
	int86(22,&ii,&oo);
   if(oo.h.al==0){  //if the pressed key was a function key
     switch(oo.h.ah){
      case 72: //UP
	     /*irrage shaft from old place*/
	     shaft_color=2;
	     draw_shaft(shaft_x,shaft_y,shaft_color);
	     /*draw shaft in new place*/
	     shaft_y-=5;
	     shaft_color=4;
	     draw_shaft(shaft_x,shaft_y,shaft_color);
	     break;

      case 80: //DOWN
	  /*irrage shaft from old place*/
	     shaft_color=2;
	     draw_shaft(shaft_x,shaft_y,shaft_color);
	     /*draw shaft in new place*/
	     shaft_y+=5;
	     shaft_color=4;
	     draw_shaft(shaft_x,shaft_y,shaft_color);
	     break;

	}
}
    else{
      switch(oo.h.al){
	   case 13://Enter key was pressed to hit balon1
	   /*move both balloons and shaft*/
       do{
	    delay(20);
	  /*move baloon1 if it is ON */
	    if(baloon1==1){
		baloon_color=2;
		draw_baloon(baloon1_x,baloon_y,baloon_color);

		baloon_color=4;
		draw_baloon(baloon1_x,baloon_y-1,baloon_color);
      }
      /*move baloon2 if it is ON*/
      if(baloon2==1) {
	      baloon_color=2;
	      draw_baloon(baloon2_x,baloon_y,baloon_color);

	      baloon_color=4;
	      draw_baloon(baloon2_x,baloon_y-1,baloon_color);
    }
    /*move baloon3 if is ON*/
    if(baloon3==1){
	baloon_color=2;
	draw_baloon(baloon3_x,baloon_y,baloon_color);

	baloon_color=4;
	draw_baloon(baloon3_x,baloon_y-1,baloon_color);
    }
    /*move baloon4 if is ON*/
    if(baloon4==1){
	baloon_color=2;
	draw_baloon(baloon4_x,baloon_y,baloon_color);

	baloon_color=4;
	draw_baloon(baloon4_x,baloon_y-1,baloon_color);
    }
       baloon_y--;
       shaft_color=2;
       draw_shaft(shaft_x,shaft_y,shaft_color);
       shaft_x+=5;
       shaft_color=4;
       draw_shaft(shaft_x,shaft_y,shaft_color);
/* check if ballon1 is on and it is heated*/
    if(baloon1==1&&(shaft_x>baloon1_x-10&&shaft_x<baloon1_x+10&&shaft_y>baloon_y-10&&shaft_y<baloon_y+10))
    {
	sound(1500);
		delay(100);
		nosound();

	 baloon_color=2;
	 draw_baloon(baloon1_x,baloon_y,baloon_color);
	 shaft_color=2;
	 draw_shaft(shaft_x,shaft_y,shaft_color);
	 show_score(chance,success,score,shaft,3);
	 score+=10;
	 show_score(chance,success,score,shaft,0);
	 hit++;
	 flag=1;
	 ++b;
	 baloon1=0;
    }
   if(baloon2==1&&(shaft_x>baloon2_x-10&&shaft_x<baloon2_x+10&&shaft_y>baloon_y-10&&shaft_y<baloon_y+10))
   {
       sound(1500);
		delay(100);
		nosound();

	baloon_color=2;
	draw_baloon(baloon2_x,baloon_y,baloon_color);
	shaft_color=2;
	draw_shaft(shaft_x,shaft_y,shaft_color);
	show_score(chance,success,score,shaft,3);
	score+=10;
	show_score(chance,success,score,shaft,0);
	hit++;
	flag=1;
	++b;
	baloon2=0;
    }
    if(baloon3==1&&(shaft_x>baloon3_x-10&&shaft_x<baloon3_x+10&&shaft_y>baloon_y-10&&shaft_y<baloon_y+10))
    {
	sound(1500);
		delay(100);
		nosound();

	baloon_color=2;
	draw_baloon(baloon3_x,baloon_y,baloon_color);
	shaft_color=2;
	draw_shaft(shaft_x,shaft_y,shaft_color);
	show_score(chance,success,score,shaft,3);
	score+=10;
	show_score(chance,success,score,shaft,0);
	hit++;
	flag=1;
	++b;
	baloon3=0;
    }
    if(baloon4==1&&(shaft_x>baloon4_x-10&&shaft_x<baloon4_x+10&&shaft_y>baloon_y-10&&shaft_y<baloon_y+10))
    {
	sound(1500);
		delay(100);
		nosound();

	baloon_color=2;
	draw_baloon(baloon4_x,baloon_y,baloon_color);
	shaft_color=2;
	draw_shaft(shaft_x,shaft_y,shaft_color);
	show_score(chance,success,score,shaft,3);
	score+=10;
	show_score(chance,success,score,shaft,0);
	hit++;
	flag=1;
	++b;
	baloon4=0;
  }
   if(shaft_x>baloon4_x+200||baloon_y<0)
   {
  /*erage both baloon and shaft*/
	  baloon_color=2;
	  draw_baloon(baloon1_x,baloon_y,baloon_color);
	  draw_baloon(baloon2_x,baloon_y,baloon_color);
	  draw_baloon(baloon3_x,baloon_y,baloon_color);
	  draw_baloon(baloon4_x,baloon_y,baloon_color);

	  shaft_color=2;
	  draw_shaft(shaft_x,shaft_y,shaft_color);
	  show_score(chance,success,score,shaft,3);
	  chance++;
    if(hit)
	 success++;
    if(flag==0)
     shaft--;
	 show_score(chance,success,score,shaft,0);
	 if(b==4)
     {


	 show_score(chance,success,score,shaft,3);
	 score+=100;
	 sound(1000);
		delay(20);
		nosound();
	show_score(chance,success,score,shaft,0);
	bonus+=100;
      setcolor(14);
      char str[4];
     // settextstyle(1,0,15);
       gcvt(bonus,3,str);
      outtextxy(220,45,str);
     }
	 chance_end=1;
	 shaft_x=185;
	 shaft_y=200;
	do
	{
	baloon1_x=rand()%500;
	 }while(baloon1_x<300);

      baloon_y=400;
      baloon2_x=baloon1_x+ball_diff;
      baloon3_x=baloon2_x+ball_diff;
      baloon4_x=baloon3_x+ball_diff;
 }
 }while(!chance_end);
    break;
      case 27:
       closegraph();
       exit(1);
 }
 }
 }
 }

	clearviewport();
	setbkcolor(9);
	setcolor(10);
	settextstyle(4,0,7);
	setusercharsize(120,50,120,40);
	float octave[7] = { 130.81, 146.83, 164.81, 174.61, 196, 220, 246.94};
	outtextxy(getmaxx()/2-220,getmaxy()/2-180,"GAME OVER");

	settextstyle(8,0,1);
	setusercharsize(50,60,40,50);

	outtextxy(getmaxx()/2-100,getmaxy()/2-70,"NO MORE ARROWS");

	outtextxy(getmaxx()/2-120,getmaxy()/2-20,"YOUR SCORE IS : ");
       //	itoa(score,score,10);
       //	outtextxy(getmaxx()/2+150,getmaxy()/2-20,score);
      setcolor(15);
      char str[4];
      gcvt(score,3,str);
      outtextxy(450,220,str);

	if(score<200)
	outtextxy(getmaxx()/2-220,getmaxy()/2+20,"YOU REQUIRE TO PRACTICE MORE");
       else  if(score>200 && score<1000)
	outtextxy(getmaxx()/2-70,getmaxy()/2+20,"WELL PLAYED");
       else  if(score>1000)
	outtextxy(getmaxx()/2-220,getmaxy()/2+20,"YOU ARE AN EFFICIENT SHOOTER");

	outtextxy(getmaxx()/2-30,getmaxy()/2+50,"(Q)UIT");

	settextstyle(1,0,1);
	setusercharsize(30,65,30,60);
	outtextxy(100,400,"THIS GAME HAS BEEN DEVELOPED BY RAFID MUSTAFIZ");
	outtextxy(90,420,"STUDENT OF COMPUTER SCIENCE AND ENGINEERING AT MBSTU");

while( !kbhit() )
	{
		sound( octave[ random(7) ]*4 );
		delay(300);
	}
     nosound();
      while( getch() != 'q');


 }

void draw_screen()
{
int i;
int gd=0,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
  setfillstyle(1,0);
  bar(0,0,150,20);
  outtextxy(30,5,"Score Board");

  setfillstyle(1,3);
  bar(0,20,150,250);
  setcolor(1);
   outtextxy(30,40,"Total chance");
    outtextxy(30,90,"Success");
    outtextxy(30,140,"Score");
    outtextxy(30,190,"Chance left");
    setcolor(15);
    setfillstyle(1,0);
  bar(0,255,150,275);
  outtextxy(30,260,"Control Key");
   setfillstyle(1,3);
  bar(0,275,150,479);
  setcolor(1);
  outtextxy(30,290,"Up");
  setcolor(4);
  for(i=0;i<=5;i++)
  line(100-i,285+i,100+i,285+i);
  line(100,290,100,300);

   setcolor(1);
  outtextxy(30,330,"Down");
  setcolor(4);
  for(i=0;i<=5;i++)
  line(95+i,330+i,105-i,330+i);
  line(100,320,100,330);

   setcolor(1);
  outtextxy(30,370,"Shoot");
  setcolor(4);

  outtextxy(100,370,"Enter");
  setcolor(1);
  outtextxy(30,410,"Exit");
  setcolor(4);
 outtextxy(100,410,"Esc");
 setfillstyle(1,2);
 bar(151,0,639,479);
 setcolor(14);
 setfillstyle(2,1);
 bar(190,0,275,65);
  setcolor(15);
  setusercharsize(10,20,40,50);
  outtextxy(210,20,"Bonus");
}

void show_score(int chance,int success,int score,int shaft,int color)
{
setcolor(color);
char str[4];
gcvt(chance,3,str);
outtextxy(70,60,str);
gcvt(success,3,str);
outtextxy(70,110,str);

gcvt(score,3,str);
outtextxy(70,160,str);
gcvt(shaft,3,str);
outtextxy(70,210,str);
}
void draw_shaft(int x,int y,int c)
{
setcolor(c);
rectangle(x-1,y-1,x-30,y+1);
line(x,y,x-30,y);
line(x,y,x-6,y-4);
line(x,y,x-6,y+4);
}
void draw_baloon(int x,int y,int c)
{
setcolor(c);
setfillstyle(1,c);
sector(x,y,0,180,10,10);
for(int i=0;i<=12;i++) {
line(x-10+i,y+i,x+10-i,y+i);
//setcolor(1);
//setfillstyle(1,c);
// line(x-10+i,y+i,x+10-i,y+i);
 }
}
void start()
{
    int i,j;
	setbkcolor(0);
	settextstyle(7,0,0);
	outtextxy(10,400,"  PRESS ANY KEY TO CONTINUE....");
	settextstyle(1,0,0);
	setcolor(4);
	setusercharsize(25,15,20,4);
	outtextxy(85,120,"BALLOON SHOOTING");
	float octave[7] = { 130.81, 146.83, 164.81, 174.61, 196, 220, 246.94};
	while( !kbhit() )
	{
		sound( octave[ random(7) ]*4 );
		delay(300);
	}
	nosound();
	getch();
	clearviewport();
	setbkcolor(1);
	setcolor(14);
	settextstyle(7,0,0);
	setusercharsize(50,30,50,30);
	outtextxy(85,123,"  LOADING");
     settextstyle(1,0,3);
    for(j=0; j<=56; j+=8)
	{
	    outtextxy(380+j,154,".");
	    delay(300);
	}
	settextstyle(1,0,1);
	outtextxy(35,300,"  Game is developed by");
	outtextxy(35,330,"  RAFID MUSTAFIZ.");
	outtextxy(35,360,"  CE- 12014");
	outtextxy(35,390,"  DEPT. OF CSE ");
	outtextxy(335,300,"  Project Examineer.....");
	outtextxy(335,330,"  MD. Sazzad Hossain");
	outtextxy(335,360,"  Assistant Proffesser");
	outtextxy(335,390,"  dept. of CSE at MBSTU");

	settextstyle(7,0,1);
	outtextxy(150,430,"PRESS ANY KEY TO CONITINUE");
	/*for(j=0; j<=12; j+=4)
	{
	    outtextxy(350+j,123,".");
	    delay(300);
	}

	setcolor(0);
	for(j=12; j>=0; j-=4)
	{
	    outtextxy(350+j,123,".");
	}
	*/
	while( !kbhit() )
	{
		sound( octave[ random(4) ]*9 );
		delay(300);
	}
	nosound();
	getch();
	clearviewport();

	rectangle(1,1,638,478);
	settextstyle(3,0,1);
	setusercharsize(50,30,50,30);
	setbkcolor(6);
	setcolor(15);
	outtextxy(150,10,"INSTRUCTIONS");
	setbkcolor(6);
	settextstyle(1,0,1);
	setusercharsize(40,70,20,20);
	outtextxy(10,70,"1. Every shoot you can get four balloons.");
	outtextxy(10,110,"2. You can move the bow UP and DOWN with the help of arrow keys.");
	outtextxy(10,150,"3. Press enter key to shoot the arrow.");
	outtextxy(10,190,"4. You score 10 points every time you shoot the balloon.");
	outtextxy(10,230,"5. You have total 3 arrows to shoot balloons.");
	outtextxy(10,270,"6. You get bonus score 100 points to shoot all the four at a time.");
	outtextxy(10,310,"7. You should practice more if your score is bellow 100.");
	outtextxy(10,350,"8. You require to score 1000 points to be a efficient shooter.");
    //outtextxy(10,390,"9. .");
	settextstyle(7,0,1);
	outtextxy(150,430,"PRESS ANY KEY TO CONITINUE");

	getch();
	setusercharsize(1,1,1,1);
	settextstyle(0,0,0);
	setbkcolor(6);
	clearviewport();
}

