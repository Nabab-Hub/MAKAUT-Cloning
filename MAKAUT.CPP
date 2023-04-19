#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
#define N 5 //no of students
int stulog();
typedef struct
{
   char name[20];
   int user;
   int pass;
}stu_login;
typedef struct
{
   int Cca1,Cca2,Cca3,Cca4;
   int Dca1,Dca2,Dca3,Dca4;
   int Sca1,Sca2,Sca3,Sca4;
   int Pca1,Pca2,Pca3,Pca4;
   int Cpca1,Cpca2;
   int Dpca1,Dpca2;
}stu_dat;
stu_login s[N];
stu_dat st[N];
int studentNo;
int main()
{
    int gd=0,gm;
    int frontx=80,fronty=100,stux=80,stuy=100;
    main:
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    mainMenu:
    cleardevice();
    setbkcolor(WHITE);
    setcolor(8);
    while(1)
    {
      rectangle(50,50,590,440);
      setfillstyle(1,7);
      rectangle(80,100,290,150); floodfill(100,130,8);
      setfillstyle(1,14);
      rectangle(350,100,560,150); floodfill(370,130,8);
      setfillstyle(1,LIGHTRED);
      rectangle(80,180,290,230); floodfill(100,200,8);
      rectangle(350,180,560,230);
      setfillstyle(1,CYAN);
      rectangle(80,260,290,310); floodfill(100,290,8);
      rectangle(350,260,560,310);
      setfillstyle(1,2);
      bar3d(frontx,fronty,frontx+210,fronty+50,3,1);
      settextstyle(0,0,1);
      outtextxy(85,110,"STUDENT");
      outtextxy(85,190,"TEACHER/EVALUATOR");
      outtextxy(85,270,"RESULT");
      outtextxy(355,110,"ADMINISTRATOR LOGIN");
      outtextxy(355,190,"COLLEGE-CENTER LOGIN");
      outtextxy(355,270,"HelpDesk");
      outtextxy(150,400,"U = Up , D = Down , O = Ok & E = exit");
      settextstyle(2,0,0);
      outtextxy(85,130,"Click here to Login Portal");
      outtextxy(85,210,"To login click here...");
      outtextxy(85,290,"Click here to se Result Details...");
      outtextxy(355,130,"To login click here...");
      outtextxy(355,210,"To login click here...");
      outtextxy(355,290,"Click Here...");

	switch(getch())
	{
	    case 'D': fronty+=80;break;
	    case 'U': fronty-=80;break;
	    case 'O': if(frontx==80&&fronty==100)goto studentLogin;
		      else if(frontx==350&&fronty==100) goto adminLogin;
		      else if(frontx==80&&fronty==180) goto teacherEva;
		      else break;
	    case 'E': goto bye;
	    default : break;
	}
	delay(100);
	cleardevice();
	if(fronty>260&&frontx==80){frontx=350;fronty=100;}
	if(fronty>260&&frontx==350){frontx=80;fronty=100;}
	if(fronty<100&&frontx==350){frontx=80;fronty=260;}
	if(fronty<100&&frontx==80){frontx=350;fronty=260;}
    }

    studentLogin:
    if(frontx==80&&fronty==100)
    {
       int true=0;
       true=stulog();
       if(true)
       {
	 FILE *fp;
	 fp=fopen("stmarks.dat","rb");
	 fread(&st,sizeof(stu_dat),N,fp);
	 fclose(fp);
	 while(1)
	 {
	   cleardevice();
	   outtextxy(250,20,"WELCOME");
	   outtextxy(320,20,s[studentNo].name);
	   rectangle(50,50,590,440);
	   setfillstyle(9,CYAN);
	   rectangle(80,100,130,150);   floodfill(100,130,8);
	   rectangle(165,100,215,150);  floodfill(180,130,8);
	   rectangle(250,100,300,150);  floodfill(270,130,8);
	   rectangle(335,100,385,150);  floodfill(355,130,8);
	   rectangle(420,100,470,150);  floodfill(440,130,8);
	   rectangle(505,100,555,150);  floodfill(520,130,8);

	   rectangle(80,200,130,250);   floodfill(100,220,8);
	   rectangle(165,200,215,250);  floodfill(180,220,8);
	   rectangle(250,200,300,250);  floodfill(270,220,8);
	   rectangle(335,200,385,250);  floodfill(355,220,8);
	   rectangle(420,200,470,250);  floodfill(440,220,8);
	   rectangle(505,200,555,250);  floodfill(520,220,8);

	   rectangle(80,300,130,350);   floodfill(100,320,8);
	   rectangle(165,300,215,350);  floodfill(180,320,8);
	   rectangle(250,300,300,350);  floodfill(270,320,8);
	   rectangle(335,300,385,350);  floodfill(355,320,8);
	   rectangle(420,300,470,350);  floodfill(440,320,8);
	   rectangle(505,300,555,350);  floodfill(520,320,8);

	   outtextxy(80,155,"Regular");outtextxy(70,165,"Enrollment");outtextxy(90,175,"Form");
	   outtextxy(162,155,"Backlog");outtextxy(155,165,"Enrollment");outtextxy(175,175,"Form");
	   outtextxy(267,155,"CA");outtextxy(255,165,"Marks");
	   outtextxy(348,155,"PCA");outtextxy(340,165,"Marks");
	   outtextxy(430,155,"Exam");outtextxy(430,165,"Form");
	   outtextxy(503,155,"Backlog");outtextxy(514,165,"Form");
	   outtextxy(95,255,"Mar"); outtextxy(172,255,"Moocs");
	   outtextxy(253,255,"Mentor");
	   outtextxy(335,255,"Student");outtextxy(334,265,"Backlog");outtextxy(338,275,"Papers");
	   outtextxy(427,255,"Admit");outtextxy(430,265,"Card");
	   outtextxy(504,255,"Special");outtextxy(480,265,"Supplementary");outtextxy(513,275,"Form");
	   outtextxy(83,355,"Result"); outtextxy(166,355,"Review");outtextxy(167,365,"Result");
	   outtextxy(249,355,"Special");outtextxy(225,365,"Supplementary");outtextxy(252,375,"Result");
	   outtextxy(337,355,"Email/"); outtextxy(337,365,"Mobile");outtextxy(337,375,"Update");
	   outtextxy(430,355,"From");outtextxy(418,365,"Preview");
	   outtextxy(515,355,"Make");outtextxy(506,365,"Payment");
	   setcolor(4);
	   outtextxy(140,420,"U = Up , D = Down , O = Ok & E = Main menu");
	   setcolor(8);

	   setfillstyle(1,2);
	   bar3d(stux,stuy,stux+50,stuy+50,3,1);
	   switch(getch())
	    {
	       case 'U': stuy-=100; break;
	       case 'D': stuy+=100; break;
	       case 'O': if(stux==250&&stuy==100) goto camarks;
			 else if(stux==335&&stuy==100) goto pcamarks;
			 else break;
	       case 'E': goto mainMenu;
	       default : break;
	    }
	    if(stuy>300){stux+=85;stuy=100;}
	    if(stuy<300&&stux>505){stux=80;stuy=100;}
	    if(stuy<100){stux-=85;stuy=300;}
	    if(stuy>100&&stux<80){stux=505;stuy=300;}
	 }
       }
       else {cleardevice();goto mainMenu;}
    }

    adminLogin:
    if(frontx==350&&fronty==100)
    {
       int i;
       FILE *fp;
       cleardevice();
       closegraph();
       stu_login  s[N];
       again:
       clrscr();
       printf("Can you set students user Id and Password : Y/N");
       switch(getch())
       {
       case 'Y':
       for(i=0;i<N;i++)
       {
	  printf("Enter name of %d student : ",i+1);
	  gets(s[i].name);
	  printf("Create User id of %d student : ",i+1);
	  scanf("%d",&s[i].user);
	  printf("Create Password of %d student : ",i+1);
	  scanf("%d",&s[i].pass);
	  fflush(stdin);
       }

       fp=fopen("student.dat","wb");

       fwrite(&s,sizeof(stu_login),N,fp);
       fclose(fp);
       printf("\nenter any key...");
       getch();
       goto main;

       case 'N':goto main;
       default : goto again;
       }
    }

    teacherEva:
    if(frontx==80&&fronty==180)
    {
       cleardevice();
       closegraph();
       int i;
       FILE *fp;
       stu_dat st[N];
       AgaiN:
       clrscr();
       printf("Can you set Marks of students : Y/N");
       switch(getch())
       {
	  case 'Y':
		    fp=fopen("student.dat","rb");
		    fread(&s,sizeof(stu_login),N,fp);
		    fclose(fp);
		    for(i=0;i<N;i++)
		    {
		       printf("\nEnter Marks of : %s \n",s[i].name);
		       printf("Enter Marks of CA1 CA2 CA3 & CA4 for C programming : ");
		       scanf("%d%d%d%d",&st[i].Cca1,&st[i].Cca2,&st[i].Cca3,&st[i].Cca4);
		       printf("Enter Marks of CA1 CA2 CA3 & CA4 for Digital Electronics : ");
		       scanf("%d%d%d%d",&st[i].Dca1,&st[i].Dca2,&st[i].Dca3,&st[i].Dca4);
		       printf("Enter Marks of CA1 CA2 CA3 & CA4 for Soft Skills : ");
		       scanf("%d%d%d%d",&st[i].Sca1,&st[i].Sca2,&st[i].Sca3,&st[i].Sca4);
		       printf("Enter Marks of CA1 CA2 CA3 & CA4 for Professional Communicatoin : ");
		       scanf("%d%d%d%d",&st[i].Pca1,&st[i].Pca2,&st[i].Pca3,&st[i].Pca4);
		       printf("\n");
		       printf("Enter Marks of PCA1 & PCA2 for C programming : ");
		       scanf("%d%d",&st[i].Cpca1,&st[i].Cpca2);
		       printf("Enter Marks of PCA1 & PCA2 for Digital Electronics : ");
		       scanf("%d%d",&st[i].Dpca1,&st[i].Dpca2);
		    }

		    fp=fopen("stmarks.dat","wb");
		    fwrite(&st,sizeof(stu_dat),N,fp);
		    fclose(fp);

		    printf("\nenter any key...");
		    getch();
		    goto main;
	  case 'N': goto main;
	  default : goto AgaiN;
       }
    }

    //login options.....
    camarks:
    if(stux==250&&stuy==100)
    {
      cleardevice();
      while(1)
      {
	char itos[5];
	outtextxy(250,20,"WELCOME");
	outtextxy(320,20,s[studentNo].name);
	rectangle(50,50,590,440);
	rectangle(55,55,585,425);
	rectangle(55,55,585,75);setfillstyle(1,CYAN);floodfill(200,65,8);
	setcolor(15);
	outtextxy(60,60,"CA Marks's Details"); setcolor(8);
	rectangle(55,75,585,95);
	outtextxy(250,85,"FIRST SEMESTER");
	rectangle(55,95,585,155);rectangle(55,155,585,215);
	rectangle(55,215,585,275);rectangle(55,275,585,335);
	rectangle(55,335,585,395);
	line(130,95,130,395); line(270,95,270,395);
	line(320,95,320,395); line(370,95,370,395);
	line(420,95,420,395); line(470,95,470,395);

	outtextxy(75,100,"Paper");outtextxy(77,110,"Code");outtextxy(65,120,"(Unique");outtextxy(75,130,"Code)");
	outtextxy(160,120,"Paper Name"); outtextxy(285,120,"CA1");
	outtextxy(335,120,"CA2");outtextxy(384,120,"CA3");outtextxy(435,120,"CA4");
	outtextxy(485,115,"Responsible");outtextxy(497,125,"Teacher");

	outtextxy(66,180,"BCAC101");
	outtextxy(141,175,"Programming For");outtextxy(140,187,"Problem Solving");
	sprintf(itos,"%d",st[studentNo].Cca1);outtextxy(287,180,itos);
	sprintf(itos,"%d",st[studentNo].Cca2);outtextxy(337,180,itos);
	sprintf(itos,"%d",st[studentNo].Cca3);outtextxy(387,180,itos);
	sprintf(itos,"%d",st[studentNo].Cca4);outtextxy(437,180,itos);
	outtextxy(505,175,"Sayon");outtextxy(505,190,"Ghosh");

	outtextxy(66,240,"BCAC102");
	outtextxy(170,235,"Digital");outtextxy(155,248,"Electronics");
	sprintf(itos,"%d",st[studentNo].Dca1);outtextxy(287,240,itos);
	sprintf(itos,"%d",st[studentNo].Dca2);outtextxy(337,240,itos);
	sprintf(itos,"%d",st[studentNo].Dca3);outtextxy(387,240,itos);
	sprintf(itos,"%d",st[studentNo].Dca4);outtextxy(437,240,itos);
	outtextxy(505,235,"Sayon");outtextxy(505,250,"Ghosh");

	outtextxy(66,300,"BCAA101");
	outtextxy(155,300,"Soft Skills");
	sprintf(itos,"%d",st[studentNo].Sca1);outtextxy(287,300,itos);
	sprintf(itos,"%d",st[studentNo].Sca2);outtextxy(337,300,itos);
	sprintf(itos,"%d",st[studentNo].Sca3);outtextxy(387,300,itos);
	sprintf(itos,"%d",st[studentNo].Sca4);outtextxy(437,300,itos);
	outtextxy(505,295,"Sayon");outtextxy(505,310,"Ghosh");

	outtextxy(66,360,"GE1B-19");
	outtextxy(155,355,"Professional");outtextxy(152,370,"Communication");
	sprintf(itos,"%d",st[studentNo].Pca1);outtextxy(287,360,itos);
	sprintf(itos,"%d",st[studentNo].Pca2);outtextxy(337,360,itos);
	sprintf(itos,"%d",st[studentNo].Pca3);outtextxy(387,360,itos);
	sprintf(itos,"%d",st[studentNo].Pca4);outtextxy(437,360,itos);
	outtextxy(505,355,"Sayon");outtextxy(505,370,"Ghosh");
	setcolor(4);
	outtextxy(200,410,"PRESS E TO GO BACK LOGIN PAGE"); setcolor(8);
	 switch(getch())
	 {
	    case 'E': goto studentLogin;
	    default : break;
	 }
      }
    }

    pcamarks:
    if(stux==335&&stuy==100)
    {
      cleardevice();
      while(1)
      {
	char itos[5];
	outtextxy(250,20,"WELCOME");
	outtextxy(320,20,s[studentNo].name);
	rectangle(50,50,590,285);
	rectangle(55,55,585,270);
	rectangle(55,55,585,75);setfillstyle(1,CYAN);floodfill(200,65,8);
	rectangle(55,75,585,100);rectangle(55,100,585,150);
	rectangle(55,150,585,200);rectangle(55,200,585,250);
	line(150,100,150,250);line(300,100,300,250);
	line(360,100,360,250);line(420,100,420,250);
	setcolor(15);
	outtextxy(65,62,"Practical Assessment Marks"); setcolor(8);
	outtextxy(250,85,"FIRST SEMESTER");
	outtextxy(65,109,"Paper Code"); outtextxy(74,120,"(Unique");outtextxy(80,130,"Code)");
	outtextxy(185,120,"Paper Name");outtextxy(318,120,"PA1");outtextxy(378,120,"PA2");
	outtextxy(427,120,"Responsible Teacher");

	outtextxy(70,170,"BCAC191");outtextxy(167,165,"Programming For");outtextxy(166,180,"Problem Solving");
	sprintf(itos,"%d",st[studentNo].Cpca1);outtextxy(320,170,itos);
	sprintf(itos,"%d",st[studentNo].Cpca2);outtextxy(380,170,itos);
	outtextxy(460,170,"Sayon Ghosh");

	outtextxy(70,220,"BCAC192");outtextxy(200,215,"Digital");outtextxy(185,230,"Electronics");
	sprintf(itos,"%d",st[studentNo].Dpca1);outtextxy(320,220,itos);
	sprintf(itos,"%d",st[studentNo].Dpca2);outtextxy(380,220,itos);
	outtextxy(460,220,"Sayon Ghosh");
	setcolor(4);
	outtextxy(200,257,"PRESS E TO GO BACK LOGIN PAGE"); setcolor(8);
	switch(getch())
	{
	   case 'E': goto studentLogin;
	   default : break;
	}

      }
    }
    bye:
    getch();
    closegraph();
    return 0;
}
int stulog()
{
    char user[10]="\0",pass[10]="\0",star[10]="\0",temch,i=0;
    FILE *fp;
    cleardevice();
   for(i=0;i<8;i++)
   {
    rectangle(140,130,500,350);
    setfillstyle(1,CYAN);
    rectangle(140,130,500,160); floodfill(250,145,8);
    setfillstyle(1,4);
    rectangle(140,320,500,350); floodfill(250,330,8);
    outtextxy(145,140,"Student Login Portal");
    outtextxy(145,180,"User Name*");
    rectangle(145,200,495,220);
    outtextxy(145,240,"Password*");
    rectangle(145,260,495,280);
    settextstyle(2,0,0);
    setcolor(14);
    outtextxy(145,330,"Don't enter any space            For pressing enter press O");
    setcolor(8);
    settextstyle(0,0,1);
     outtextxy(150,207,user);
     temch=getch();
     if(temch>='0'&&temch<='9')
     user[i]=temch;
     else i--;
     delay(200);
     cleardevice();
   } user[i]='\0';
   for(i=0;i<8;i++)
   {
    rectangle(140,130,500,350);
    setfillstyle(1,CYAN);
    rectangle(140,130,500,160); floodfill(250,145,8);
    setfillstyle(1,4);
    rectangle(140,320,500,350); floodfill(250,330,8);
    outtextxy(145,140,"Student Login Portal");
    outtextxy(145,180,"User Name*");
    rectangle(145,200,495,220);
    outtextxy(145,240,"Password*");
    rectangle(145,260,495,280);
    settextstyle(2,0,0);
    setcolor(14);
    outtextxy(145,330,"Don't enter any space            For pressing enter press O");
    setcolor(8);
    settextstyle(0,0,1);
     outtextxy(150,207,user);
     outtextxy(150,267,star);
     temch=getch();
     if(temch>='0'&&temch<='9')
     {
     pass[i]=temch;
     star[i]='*';
     }
     else i--;
     delay(200);
     cleardevice();
   } pass[i]='\0';

   fp=fopen("student.dat","rb");
   fread(&s,sizeof(stu_login),N,fp);
   fclose(fp);
   for(i=0;i<N;i++)
   {
      rectangle(140,130,500,350);
      setfillstyle(1,CYAN);
      rectangle(140,130,500,160); floodfill(250,145,8);
      setfillstyle(1,4);
      rectangle(140,320,500,350); floodfill(250,330,8);
      outtextxy(145,140,"Student Login Portal");
      outtextxy(145,180,"User Name*");
      rectangle(145,200,495,220);
      outtextxy(145,240,"Password*");
      rectangle(145,260,495,280);
      settextstyle(2,0,0);
      setcolor(14);
      outtextxy(145,330,"Don't enter any space            For pressing enter press O");
      setcolor(8);
      settextstyle(0,0,1);
      outtextxy(150,207,user);
      outtextxy(150,267,star);
     if(atoi(user)==s[i].user&&atoi(pass)==s[i].pass)
      {
	setcolor(2);
	outtextxy(250,300,"LOGIN SUCCESSFULL");
	setcolor(8);
	studentNo=i;
	delay(500);
	return 1;
      }
   }
   if(N>=i)
   {
	setcolor(4);
	outtextxy(225,300,"INVALID ID OR PASSWORD");
	setcolor(8);
	delay(500);
	return 0;
   }
}