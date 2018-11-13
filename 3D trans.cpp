#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<math.h>
int ymax,xmax,ymid,xmid;
void translation(int tx,intty,inttz=0)
{
		bar3d(xmid+50+tx, ymid-50+ty, xmid+150+tx, ymid-150+ty, 10+tz,1);
}
void scaling(double s)
{
    bar3d((xmid+50)*s, (ymid-50)*s, (xmid+150)*s, (ymid-150)*s, 10*s,1);
}
void rotation(int angle)
{
	float ang=(3.14*angle)/180;
	int x1,x2,x3,y1,y2,y3,x11,x22,x33,y11,y22,y33;
	x1=xmid+50;
	x2=xmid+150;
	y1=ymid-50;
	y2=ymid-150;

	x11=x1*cos(ang)-y1*sin(ang);
	y11=x1*sin(ang)+y1*cos(ang);
	x22=x2*cos(ang)-y2*sin(ang);
	y22=x2*sin(ang)+y2*cos(ang);
	
	bar3d(x11,y22,x22,y11,10,1);
}
int main()
{
	clrscr();
	int gm=0,gd=DETECT;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	int tx,ty, choice=0,angle;
	double s;
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=(0+xmax)/2;
	ymid=(0+ymax)/2;
	while(1)
	{
		cout<<"1: for Translation"<<endl;
		cout<<"2: for Rotation"<<endl;
		cout<<"3: for Scaling"<<endl;
		cout<<"4: for Exit"<<endl;
		cin>>choice;
		line(0,ymid,xmax,ymid);
		line(xmid,0,xmid,ymax);

		bar3d(xmid+50, ymid-50, xmid+150, ymid-150, 10,1);
		if(choice==1)
		{
			cout<<"enter factors:";
			cin>>tx>>ty;
			translation(tx,ty);
		}
		else if(choice==2)
		{
			cout<<"enter";
			cin>>angle;
			rotation(angle);
		}
		else if(choice==3)
		{
			cout<<"enter Factors:";
			cin>>s;
			scaling(s);
		}
		else if(choice==4)
		exit(0);
		else
		cout<<"Wrong Choice";
		getch();
		cleardevice();
	}
}
