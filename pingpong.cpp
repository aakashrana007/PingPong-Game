// #include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

//Structure of ball
struct ball{
 int x ;
 int y ;
 int radius;
 int speedx;
 int speedy;
}ball;
struct square{
	int x;
	int y;
 	int l;
 	int w;
 	int s;
 }sq;
//Structure of Bat(b1,b2)
struct bat{
 int x;
 int y;
 int l;
 int w;
 int s;
}b1,b2;

struct score{
 int s;
}s1,s2;

int m=0,d,p;
char buff[3][100];
char t[15];
char n[25];
char a[50];
char c,cup,cdn,name1[15],name2[15]="Bot",str[3];
int i=0;

void initialize()
{

 replay:

 cleardevice();

 ball.x=getmaxx()/2;
 ball.y=getmaxy()/2;
 ball.radius= 5;
 ball.speedx = 5;
 ball.speedy = 8;
 
 sq.x=getmaxx()/2-80;
 sq.y=getmaxy()/2-12;
 sq.l=10;
 sq.w=10;
 sq.s=24;

 b1.x=20;
 b1.y=getmaxy()/2-20;;
 b1.l=40;
 b1.w=6;
 b1.s=40;
 

 b2.x=620;
 b2.y=getmaxy()/2-20;
 b2.l=40;
 b2.w=6;
 b2.s=40;
 
 
 

 s1.s=0;//score ini
 s2.s=0;

 setbkcolor(BLACK);//just basic front home page

 settextstyle(0,0,3);
 sprintf(a,"WELCOME TO PONG GAME");
 outtextxy(90,(getmaxy()/2),a);
 delay(1000);
 

while(1)
{
	cleardevice();
	settextstyle(0,0,1);
	outtextxy(30,getmaxy()-30,"MOVE(w/s)");
	outtextxy(getmaxx()-100,getmaxy()-30,"SELECT(o)");
	outtextxy(getmaxx()/2-40,getmaxy()/2-10,"One Player");	
	outtextxy(getmaxx()/2-40,getmaxy()/2+15,"Two Players");
	bar(sq.x,sq.y,sq.x+sq.w,sq.y+sq.l);
    c=getch();
	if(c=='w'||c=='s'||c=='W'||c=='S')
 	{
  		if(sq.y==getmaxy()/2-12)
  			sq.y=sq.y+sq.s;
  	 	else if(sq.y==getmaxy()/2+12)
			sq.y=sq.y-sq.s;
  	}
	if (c=='o'||c=='O')
	{
		cleardevice();
		if(sq.y==getmaxy()/2-12)
		{
			p=1;
			outtextxy(150,getmaxy()/2-50,"Enter Player 1 name:");
			for(i=0;i<15;i++)
			{
				name1[i]=getch();
				name1[i]=toupper(name1[i]);
				if(name1[i]<91&&name1[i]>64||name1[i]<58&&name1[i]>47)
					{
					sprintf(str,"%c",name1[i]);
					outtextxy(400+i*9,getmaxy()/2-50,str);
					continue;
					}
				break;
			}
			name1[i]='\0';
			
			while(1)
			{
				cleardevice();
				outtextxy(30,getmaxy()-30,"MOVE(w/s)");
				outtextxy(getmaxx()-100,getmaxy()-30,"SELECT(o)");
				outtextxy(getmaxx()/2-50,getmaxy()/2-40,"Choose Difficulty Level:");
				outtextxy(getmaxx()/2-50,getmaxy()/2-10,"Easy");
				outtextxy(getmaxx()/2-50,getmaxy()/2+15,"Hard");
				bar(sq.x,sq.y,sq.x+sq.w,sq.y+sq.l);
				c=getch();
				if(c=='w'||c=='s')
  				{
  					if(sq.y==getmaxy()/2-12)
  						sq.y=sq.y+sq.s;
   					else if(sq.y==getmaxy()/2+12)
						sq.y=sq.y-sq.s;
				}
				if (c=='o')
				{
					if(sq.y==getmaxy()/2-12)
						d=0;
					else if(sq.y==getmaxy()/2+12)
						d=1;
						break;
				}	
			}	
		}
		else if(sq.y==getmaxy()/2+12)
		{
			p=2;
			outtextxy(getmaxx()/2-70,getmaxy()/2-50,"Enter Player 1 name:");
			for(i=0;i<15;i++)
			{
				name1[i]=getch();
				name1[i]=toupper(name1[i]);
				if(name1[i]<91&&name1[i]>64||name1[i]<58&&name1[i]>47)
				{
					sprintf(str,"%c",name1[i]);
					outtextxy(450+i*9,getmaxy()/2-50,str);
					continue;
				}	
				break;
			}
			name1[i]='\0';
			outtextxy(getmaxx()/2-70,getmaxy()/2,"Enter Player 2 name:");
			for(i=0;i<15;i++)
			{
				name2[i]=getch();
				name2[i]=toupper(name2[i]);
				if(name2[i]<91&&name2[i]>64||name2[i]<58&&name2[i]>47)
					{
					sprintf(str,"%c",name2[i]);
					outtextxy(450+i*9,getmaxy()/2,str);
					continue;
					}
				break;
			}
			name2[i]='\0';
		}
		while(1)
		{
			cleardevice();
			outtextxy(30,getmaxy()-30,"MOVE(w/s)");
			outtextxy(getmaxx()-100,getmaxy()-30,"SELECT(o)");
			outtextxy(getmaxx()/2-50,getmaxy()/2-40,"Select Score to Win:");
			outtextxy(getmaxx()/2-50,getmaxy()/2-10,"5");
			outtextxy(getmaxx()/2-50,getmaxy()/2+15,"10");
			bar(sq.x,sq.y,sq.x+sq.w,sq.y+sq.l);
    		c=getch();
  			if(c=='w'||c=='s')
 			{
  				if(sq.y==getmaxy()/2-12)
  					sq.y=sq.y+sq.s;
  	 			else if(sq.y==getmaxy()/2+12)
					sq.y=sq.y-sq.s;
  			}
 			if (c=='o')
			{
				if(sq.y==getmaxy()/2-12)
					m=5;
				else if(sq.y==getmaxy()/2+12)
					m=10;
					break;		
			}
		}
			while(1)
			{
 				cleardevice();
 				settextstyle(0,HORIZ_DIR,1);//to SHOW score below
 				sprintf(t,"%s-%d",name1,s1.s);
 				outtextxy(10,470,t);
 				sprintf(t,"%s-%d",name2,s2.s);
 				outtextxy(560,470,t);
				rectangle(0,0,getmaxx(),getmaxy());//playfield
 				if(ball.x<b1.x)
				{//ball le bat lai choyena bhane score + hunxa .. left side ma 
					ball.x=getmaxx()/2;//yo chai ball lai feri reset garera center ma laney
	 				ball.y=getmaxy()/2;
	 				s2.s=s2.s+1;
					sound(1000);
					delay(75);
					nosound();
				}
				if(ball.x>b2.x+b2.w)
				{//same mathi jastai but right side ma
					 ball.x=getmaxx()/2;
					 ball.y=getmaxy()/2;
					 s1.s=s1.s+1;
					 sound(1000);
					 delay(75);
					 nosound();
				}
 				if(ball.y<=5 || ball.y>=getmaxy()-5)
     					ball.speedy = ball.speedy * -1;//y direction ma gayera bounce garauna lai thyakkai opposite direction ghumna lai -ve
 				if(d==0)
 				{
 					ball.x = ball.x + ball.speedx;
				 	ball.y = ball.y + ball.speedy;
				 }
 				 if(d==1)
 				{
 					ball.x = ball.x + 2*ball.speedx;
				 	ball.y = ball.y + 2*ball.speedy;
				 }
				 setcolor(WHITE);
				 setfillstyle(SOLID_FILL, WHITE);
				 circle(ball.x,ball.y,ball.radius);//ball banako
				 floodfill(ball.x,ball.y,WHITE);
				
				 bar(b1.x,b1.y,b1.x+b1.w,b1.y+b1.l);//bat1
				 bar(b2.x,b2.y,b2.x+b2.w,b2.y+b2.l);//bat2
				
				
				 if(b1.y+b1.l>ball.y){
				 if(b1.x+b1.w+5>ball.x){
				 if(b1.y<ball.y){
				  ball.speedx = ball.speedx * -1;
				  
				  sound(200);
				  delay(50);
				  nosound();
				 }
				 }
				 }
				
				 if(b2.x-5<ball.x){
				 if(b2.y<ball.y){
				 if(b2.y+b2.l>ball.y){
				 ball.speedx=ball.speedx * -1;
				 
				 sound(200);
				 delay(50);
				 nosound();
				 }
				 }
				 }
				
						
				if(p==1)
					{
						b2.y=ball.y;
						if(kbhit())
						{
							c=getch();
				    		if(c=='w')
							{
								b1.y=b1.y-b1.s;
							}
							if(c=='s')
							{
								b1.y=b1.y+b1.s;
							}
						}
					}
				else if (p==2)
				{
				if(kbhit())
					{
						c=getch();
						if(c=='w')
						{
						b1.y=b1.y-b1.s;
						}
						if(c=='s')
						{
						b1.y=b1.y+b1.s;
						}
						if(c=='i')
						{
								b2.y=b2.y-b2.s;
						}
						if(c=='k')
						{
								b2.y=b2.y+b2.s;
						}		
					}
				}
				delay(50);
				
				 if(s1.s==m || s2.s==m)
				 {
				  	FILE *o;
				  	o=fopen("leader.txt","a");
				  	fprintf(o,"\n%s-%d \t %s-%d",name1,s1.s,name2,s2.s);
				  	fclose(o);
					o=fopen("Q.txt","r");
  						fseek(o,-43,2);
  						i=0;
  						while(!feof(o))
						{
							fgets(buff[i],10,o);
 			 			i++;
 			 			}
 			 			fclose(o);
				cleardevice();
				  
				settextstyle(0,0,2);
				outtextxy(200,100,"GAME OVER");
				settextstyle(0,0,2);
				settextstyle(0,0,1);
				outtextxy(40,getmaxy()-20,"PLAY AGAIN(p)");
				outtextxy(250,getmaxy()-20,"SCOREBOARD(h)");
				outtextxy(500,getmaxy()-20,"QUIT(q)");
				
				
				if(kbhit)
				{
				  	c=getch();
				  	if(c=='h'||'H')
					{
						FILE *fp;
						char c;
						outtextxy(100,500,"Scoreboard");
						cleardevice();
						
						fp=fopen("leader.txt","r");
						settextstyle(0,0,1);
						c= fgetc(fp);
						while(c!=EOF)
						{
							printf("%c",c);
							c=fgetc(fp);
						}
					
						delay(10000);
					}
				  	if(c=='p'||'P')
				  	{
					  
					  goto replay;
					}
					
				  	if(c=='q'||'Q')
				  	{ 
					  exit(0); 
					}
				}
				}
			}
				
			
			
		
	
	}
}
						
}
					



int main(){
   int gd = DETECT,gm;
   initgraph(&gd, &gm, "C:/TURBOC3/bgi");
   initialize ();
   getch();
   closegraph();
   return 0;
}