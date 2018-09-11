#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<stdio.h>
#define N 5


using namespace std;
void first_page()    //homepage function
{
 int poly[10],poly1[34];
 int i;
 setbkcolor(CYAN);
// This would make PlaySound return immediately, rather than waiting for the sound to finish playing

 for(i=30;i<=630&&(!kbhit());i+=15)          //car display
 {

 setcolor(RED);
 setfillstyle(SOLID_FILL,4);
 poly1[0]=300;
 poly1[1]=20;
 poly1[2]=350;
 poly1[3]=70;
 poly1[4]=400;
 poly1[5]=20;
 poly1[6]=450;
 poly1[7]=70;
 poly1[8]=500;
 poly1[9]=70;
 poly1[10]=450;
 poly1[11]=120;
 poly1[12]=500;
 poly1[13]=170;
 poly1[14]=450;
 poly1[15]=170;
 poly1[16]=400;
 poly1[17]=220;
 poly1[18]=350;
 poly1[19]=170;
 poly1[20]=300;
 poly1[21]=220;
 poly1[22]=250;
 poly1[23]=170;
 poly1[24]=200;
 poly1[25]=170;
 poly1[26]=250;
 poly1[27]=120;
 poly1[28]=200;
 poly1[29]=70;
 poly1[30]=250;
 poly1[31]=70;
 poly1[32]=poly1[0];
 poly1[33]=poly1[1];
 drawpoly(17,poly1);
 fillpoly(17,poly1);
 setcolor(YELLOW);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
 outtextxy(200,105,"KNIGHT TOUR!!");
 setcolor(RED);
 line(5,0,5,480);
 line(6,0,6,480);
 setcolor(BLUE);
 line(10,0,10,480);
 line(11,0,11,480);
 setcolor(WHITE);
 line(15,0,15,480);
 line(16,0,16,480);
 setcolor(GREEN);
 line(20,0,20,480);
 line(21,0,21,480);
 setcolor(BLUE);
 setfillstyle(SOLID_FILL,BLUE);
 rectangle(22,1,160,70);
 floodfill(23,35,BLUE);
 setcolor(BLACK);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy( 54,30,"START");
 setcolor(GREEN);
 setfillstyle(SOLID_FILL,2);
 rectangle(0,409,640,480);
 floodfill(30,410,2);
 setcolor(BLUE);
 setfillstyle(SOLID_FILL,1);
 poly[0]=i+20;    //point 1
 poly[1]=380;
 poly[2]=i+30;    //point2
 poly[3]=360;
 poly[4]=i+50;    //point 3
 poly[5]=360;
 poly[6]=i+60;    //point 4
 poly[7]=380;
 poly[8]=poly[0];
 poly[9]=poly[1];
 drawpoly(5,poly);
 fillpoly(5,poly);
 rectangle(i,380,i+90,400);
 floodfill(i+10,390,BLUE);
 setcolor(RED);
 circle(i+18,400,10);
 setfillstyle(SOLID_FILL, RED);
 floodfill(i+18,399,RED);
 circle(i+55,400,10);
 floodfill(i+55,399,RED);
 if(i==630)
 {
   setcolor(BLACK);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(30,380,"*******   KNIGHT TOUR VISUALIZATION *******");
   delay(3000);
 }
 setcolor(BLACK);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 outtextxy(70,250,"VIBHOR MITTAL (15103284) (B6)");
 outtextxy(70,280,"RAUSHAN KUMAR (15103272) (B6)");
 outtextxy(70,310,"RAJAT BANSAL (15103271) (B6)");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 delay(100);
 cleardevice();
}
}
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[],  int yMove[]);

/* A utility function to check if i,j are valid indexes
   for N*N chessboard */
bool isSafe(int x, int y, int sol[N][N])
{
    return ( x >= 0 && x < N && y >= 0 &&
             y < N && sol[x][y] == -1);
}

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

/* This function solves the Knight Tour problem using
   Backtracking.  This function mainly uses solveKTUtil()
   to solve the problem. It returns false if no complete
   tour is possible, otherwise return true and prints the
   tour.
   Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.  */
bool solveKT()
{
    int sol[N][N];

    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    // Since the Knight is initially at the first block
    sol[0][0]  = 0;

    /* Start from 0,0 and explore all tours using
       solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false)
    {
        printf("Solution does not exist");
        return false;
    }
    else
        printSolution(sol);

    return true;
}

/* A recursive utility function to solve Knight Tour
   problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N])
{
   int k, next_x, next_y;
   if (movei == N*N)
       return true;

   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (isSafe(next_x, next_y, sol))
       {
         sol[next_x][next_y] = movei;
         if (solveKTUtil(next_x, next_y, movei+1, sol,
                         xMove, yMove) == true)
             return true;
         else
             sol[next_x][next_y] = -1;// backtracking
       }
   }

   return false;
}


int main()
{
    char chh;
    printf("#######   KNIGHT TOUR USING BACKTRACKING   ");
    printf("\n");
    printf("\n********************   KNIGHT TOUR VISUALIZATION   *****************************");
    printf("\n");
    printf("\nPROJECT MADE BY----------->");
    printf("\n 1->VIBHOR MITTAL (15103284)  (B6)");
    printf("\n 2->RAUSHAN KUMAR (15103272)  (B6)");
    printf("\n 3->RAJAT BANSAL  (15103271)  (B6)");
    printf("\n");
    printf("\n THE KNIGHT TOUR PROBLEM ON A 5*5 CHESS BOARD");
    printf("\n");
    printf("\n KNIGHT WILL VISIT EACH SQUARE WITHOUT VISITING THE PREVIOUS ONE");
    printf("\n");
    printf("\n");
    solveKT();
    printf("\n DO YOU WANT TO SEE ITS VISUALIZATION");
    printf("\n");
    printf("\n THEN ENTER Y TO SEE IT");
    printf("\n");
    scanf(" %c",&chh);
    printf("\n visualization has started");
    delay(1000);
    if(chh=='y'||'Y')
    {
    int gd=DETECT,gm,j=10;
    initgraph(&gd,&gm,"");
    int array[10],i=50;
    int show=1;
    int count,k=80,l=55;
    int ear[8],ear1[8];
    int mouth[8];
    int textx,texty;
    first_page();
    setbkcolor(BLACK);
    setbkcolor(BLACK);
    setcolor(YELLOW);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(50,280,"THIS VISUALIZATION WILL RUN 3 TIMES ONLY. THANKS!");
    delay(3000);
    cleardevice();
    for(count=1;count<=25;count++)
    {
    setcolor(GREEN);
    i=50;j=10;
    while(i<500)
    {
        setcolor(WHITE);
        array[0]=i;
        array[1]=j;
        array[2]=i+90;
        array[3]=j;
        array[4]=i+90;
        array[5]=j+90;
        array[6]=i;
        array[7]=j+90;
        array[8]=array[0];
        array[9]=array[1];
        drawpoly(5,array);
        if(i==140)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        else if(i==320)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        i=i+90;

    }
    i=50;
    j=100;
    while(i<500)
    {
        array[0]=i;
        array[1]=j;
        array[2]=i+90;
        array[3]=j;
        array[4]=i+90;
        array[5]=j+90;
        array[6]=i;
        array[7]=j+90;
        array[8]=array[0];
        array[9]=array[1];
        drawpoly(5,array);
        if(i==50)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        if(i==230)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        if(i==410)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }

        i=i+90;

    }
    i=50;
    j=190;
    while(i<500)
    {
        array[0]=i;
        array[1]=j;
        array[2]=i+90;
        array[3]=j;
        array[4]=i+90;
        array[5]=j+90;
        array[6]=i;
        array[7]=j+90;
        array[8]=array[0];
        array[9]=array[1];
        drawpoly(5,array);
        if(i==140)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        if(i==320)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }

        i=i+90;

    }
    i=50;
    j=280;
    while(i<500)
    {
        array[0]=i;
        array[1]=j;
        array[2]=i+90;
        array[3]=j;
        array[4]=i+90;
        array[5]=j+90;
        array[6]=i;
        array[7]=j+90;
        array[8]=array[0];
        array[9]=array[1];
        drawpoly(5,array);
        if(i==50)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        if(i==230)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        if(i==410)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        i=i+90;

    }
    i=50;
    j=370;
    while(i<500)
    {
        array[0]=i;
        array[1]=j;
        array[2]=i+90;
        array[3]=j;
        array[4]=i+90;
        array[5]=j+90;
        array[6]=i;
        array[7]=j+90;
        array[8]=array[0];
        array[9]=array[1];
        drawpoly(5,array);
        if(i==140)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        if(i==320)
        {
            setcolor(WHITE);
            fillpoly(5,array);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(i+18,j+2,WHITE);
        }
        i=i+90;

    }
    if(count==1)
    {
     setcolor(GREEN);
     circle(95,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(96,56,GREEN);
     line(100,55,185,55);
     line(185,55,185,230);
     circle(185,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,236,GREEN);
     setcolor(BLUE);
     line(50+40,10+20,50+15,10+40);
     line(50+40,10+40,50+15,10+40);
     ellipse(50+40,10+80,0,100,20,60);
     ellipse(50+40,10+60,90,-70,5,20);
     ellipse(50+49,10+75,0,180,12,12);
     ellipse(50+49,10+75,180,360,12,12);
     ear[0]=50+25;
     ear[1]=10+33;
     ear[2]=50+30;
     ear[3]=10+27;
     ear[4]=50+20;
     ear[5]=10+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=50+30;
     ear1[1]=10+27;
     ear1[2]=50+40;
     ear1[3]=10+21;
     ear1[4]=50+25;
     ear1[5]=10+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(50+40,10+30,5);
    }
    if(count==2)
    {
     setcolor(GREEN);
     circle(185,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,236,GREEN);
     line(185,240,185,415);
     line(185,415,270,415);
     circle(275,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,416,GREEN);
     setcolor(BLUE);
     line(180,210,155,230);
     line(180,230,155,230);
     ellipse(180,270,0,100,20,60);
     ellipse(180,250,90,-70,5,20);
     ellipse(189,265,0,180,12,12);
     ellipse(189,265,180,360,12,12);
     ear[0]=165;
     ear[1]=223;
     ear[2]=170;
     ear[3]=217;
     ear[4]=160;
     ear[5]=200;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=170;
     ear1[1]=217;
     ear1[2]=180;
     ear1[3]=211;
     ear1[4]=165;
     ear1[5]=193;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(180,220,5);
    }
    else if(count==3)
    {
     setcolor(GREEN);
     circle(275,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,416,GREEN);
     line(280,415,450,415);
     line(450,415,450,330);
     circle(450,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(450,326,GREEN);
     setcolor(BLUE);
     line(230+40,370+20,230+15,370+40);
     line(230+40,370+40,230+15,370+40);
     ellipse(230+40,370+80,0,100,20,60);
     ellipse(230+40,370+60,90,-70,5,20);
     ellipse(230+49,370+75,0,180,12,12);
     ellipse(230+49,370+75,180,360,12,12);
     ear[0]=230+25;
     ear[1]=370+33;
     ear[2]=230+30;
     ear[3]=370+27;
     ear[4]=230+20;
     ear[5]=370+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=230+30;
     ear1[1]=370+27;
     ear1[2]=230+40;
     ear1[3]=370+21;
     ear1[4]=230+25;
     ear1[5]=370+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(230+40,370+30,5);
    }
    else if(count==4)
    {
     setcolor(GREEN);
     circle(455,335,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(455,336,GREEN);
     line(455,330,455,145);
     line(455,145,370,145);
     circle(365,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,146,GREEN);
     setcolor(BLUE);
     line(410+40,280+20,410+15,280+40);
     line(410+40,280+40,410+15,280+40);
     ellipse(410+40,280+80,0,100,20,60);
     ellipse(410+40,280+60,90,-70,5,20);
     ellipse(410+49,280+75,0,180,12,12);
     ellipse(410+49,280+75,180,360,12,12);
     ear[0]=410+25;
     ear[1]=280+33;
     ear[2]=410+30;
     ear[3]=280+27;
     ear[4]=410+20;
     ear[5]=280+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=410+30;
     ear1[1]=280+27;
     ear1[2]=410+40;
     ear1[3]=280+21;
     ear1[4]=410+25;
     ear1[5]=280+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(410+40,280+30,5);
    }
    else if(count==5)
    {
     setcolor(GREEN);
     circle(365,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,145,GREEN);
     line(360,145,185,145);
     line(185,145,185,60);
     circle(185,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,56,GREEN);
     setcolor(BLUE);
     line(320+40,100+20,320+15,100+40);
     line(320+40,100+40,320+15,100+40);
     ellipse(320+40,100+80,0,100,20,60);
     ellipse(320+40,100+60,90,-70,5,20);
     ellipse(320+49,100+75,0,180,12,12);
     ellipse(320+49,100+75,180,360,12,12);
     ear[0]=320+25;
     ear[1]=100+33;
     ear[2]=320+30;
     ear[3]=100+27;
     ear[4]=320+20;
     ear[5]=100+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=320+30;
     ear1[1]=100+27;
     ear1[2]=320+40;
     ear1[3]=100+21;
     ear1[4]=320+25;
     ear1[5]=100+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(320+40,100+30,5);
    }
    else if(count==6)
    {
     setcolor(GREEN);
     circle(185,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,56,GREEN);
     line(185,60,185,235);
     line(185,235,270,235);
     circle(275,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,236,GREEN);
     setcolor(BLUE);
     line(140+40,10+20,140+15,10+40);
     line(140+40,10+40,140+15,10+40);
     ellipse(140+40,10+80,0,100,20,60);
     ellipse(140+40,10+60,90,-70,5,20);
     ellipse(140+49,10+75,0,180,12,12);
     ellipse(140+49,10+75,180,360,12,12);
     ear[0]=140+25;
     ear[1]=10+33;
     ear[2]=140+30;
     ear[3]=10+27;
     ear[4]=140+20;
     ear[5]=10+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=140+30;
     ear1[1]=10+27;
     ear1[2]=140+40;
     ear1[3]=10+21;
     ear1[4]=140+25;
     ear1[5]=10+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(140+40,10+30,5);
    }
    else if(count==7)
    {
     setcolor(GREEN);
     circle(275,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,236,GREEN);
     line(270,235,100,235);
     line(100,235,100,320);
     circle(100,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(100,326,GREEN);
     setcolor(BLUE);
     line(230+40,190+20,230+15,190+40);
     line(230+40,190+40,230+15,190+40);
     ellipse(230+40,190+80,0,100,20,60);
     ellipse(230+40,190+60,90,-70,5,20);
     ellipse(230+49,190+75,0,180,12,12);
     ellipse(230+49,190+75,180,360,12,12);
     ear[0]=230+25;
     ear[1]=190+33;
     ear[2]=230+30;
     ear[3]=190+27;
     ear[4]=230+20;
     ear[5]=190+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=230+30;
     ear1[1]=190+27;
     ear1[2]=230+40;
     ear1[3]=190+21;
     ear1[4]=230+25;
     ear1[5]=190+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(230+40,190+30,5);
    }
    else if(count==8)
    {
     setcolor(GREEN);
     circle(100,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(100,326,GREEN);
     line(100,320,100,145);
     line(100,145,180,145);
     circle(185,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,146,GREEN);
        setcolor(BLUE);
     line(50+40,280+20,50+15,280+40);
     line(50+40,280+40,50+15,280+40);
     ellipse(50+40,280+80,0,100,20,60);
     ellipse(50+40,280+60,90,-70,5,20);
     ellipse(50+49,280+75,0,180,12,12);
     ellipse(50+49,280+75,180,360,12,12);
     ear[0]=50+25;
     ear[1]=280+33;
     ear[2]=50+30;
     ear[3]=280+27;
     ear[4]=50+20;
     ear[5]=280+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=50+30;
     ear1[1]=280+27;
     ear1[2]=50+40;
     ear1[3]=280+21;
     ear1[4]=50+25;
     ear1[5]=280+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(50+40,280+30,5);
    }
    else if(count==9)
    {
     setcolor(GREEN);
     circle(185,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,146,GREEN);
     line(190,145,360,145);
     line(360,145,360,60);
     circle(365,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,56,GREEN);
       setcolor(BLUE);
     line(140+40,100+20,140+15,100+40);
     line(140+40,100+40,140+15,100+40);
     ellipse(140+40,100+80,0,100,20,60);
     ellipse(140+40,100+60,90,-70,5,20);
     ellipse(140+49,100+75,0,180,12,12);
     ellipse(140+49,100+75,180,360,12,12);
     ear[0]=140+25;
     ear[1]=100+33;
     ear[2]=140+30;
     ear[3]=100+27;
     ear[4]=140+20;
     ear[5]=100+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=140+30;
     ear1[1]=100+27;
     ear1[2]=140+40;
     ear1[3]=100+21;
     ear1[4]=140+25;
     ear1[5]=100+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(140+40,100+30,5);
    }
    else if(count==10)
    {
     setcolor(GREEN);
     circle(365,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,56,GREEN);
     line(360,60,360,235);
     line(360,235,450,235);
     circle(455,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,56,GREEN);
        setcolor(BLUE);
     line(320+40,10+20,320+15,10+40);
     line(320+40,10+40,320+15,10+40);
     ellipse(320+40,10+80,0,100,20,60);
     ellipse(320+40,10+60,90,-70,5,20);
     ellipse(320+49,10+75,0,180,12,12);
     ellipse(320+49,10+75,180,360,12,12);
     ear[0]=320+25;
     ear[1]=10+33;
     ear[2]=320+30;
     ear[3]=10+27;
     ear[4]=320+20;
     ear[5]=10+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=320+30;
     ear1[1]=10+27;
     ear1[2]=320+40;
     ear1[3]=10+21;
     ear1[4]=320+25;
     ear1[5]=10+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(320+40,10+30,5);
    }
    else if(count==11)
    {
     setcolor(GREEN);
     circle(455,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(455,236,GREEN);
     line(455,235,360,235);
     line(360,235,360,410);
     circle(365,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,416,GREEN);
        setcolor(BLUE);
     line(410+40,190+20,410+15,190+40);
     line(410+40,190+40,410+15,190+40);
     ellipse(410+40,190+80,0,100,20,60);
     ellipse(410+40,190+60,90,-70,5,20);
     ellipse(410+49,190+75,0,180,12,12);
     ellipse(410+49,190+75,180,360,12,12);
     ear[0]=410+25;
     ear[1]=190+33;
     ear[2]=410+30;
     ear[3]=190+27;
     ear[4]=410+20;
     ear[5]=190+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=410+30;
     ear1[1]=190+27;
     ear1[2]=410+40;
     ear1[3]=190+21;
     ear1[4]=410+25;
     ear1[5]=190+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(410+40,190+30,5);
    }
    else if(count==12)
    {
     setcolor(GREEN);
     circle(365,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,416,GREEN);
     line(365,415,185,415);
     line(185,415,185,330);
     circle(185,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,326,GREEN);
      setcolor(BLUE);
     line(320+40,370+20,320+15,370+40);
     line(320+40,370+40,320+15,370+40);
     ellipse(320+40,370+80,0,100,20,60);
     ellipse(320+40,370+60,90,-70,5,20);
     ellipse(320+49,370+75,0,180,12,12);
     ellipse(320+49,370+75,180,360,12,12);
     ear[0]=320+25;
     ear[1]=370+33;
     ear[2]=320+30;
     ear[3]=370+27;
     ear[4]=320+20;
     ear[5]=370+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=320+30;
     ear1[1]=370+27;
     ear1[2]=320+40;
     ear1[3]=370+21;
     ear1[4]=320+25;
     ear1[5]=370+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(320+40,370+30,5);
    }
    else if(count==13)
    {
     setcolor(GREEN);
     circle(185,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,326,GREEN);
     line(180,325,95,325);
     line(95,325,95,150);
     circle(95,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(95,146,GREEN);
        setcolor(BLUE);
     line(140+40,280+20,140+15,280+40);
     line(140+40,280+40,140+15,280+40);
     ellipse(140+40,280+80,0,100,20,60);
     ellipse(140+40,280+60,90,-70,5,20);
     ellipse(140+49,280+75,0,180,12,12);
     ellipse(140+49,280+75,180,360,12,12);
     ear[0]=140+25;
     ear[1]=280+33;
     ear[2]=140+30;
     ear[3]=280+27;
     ear[4]=140+20;
     ear[5]=280+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=140+30;
     ear1[1]=280+27;
     ear1[2]=140+40;
     ear1[3]=280+21;
     ear1[4]=140+25;
     ear1[5]=280+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(140+40,280+30,5);
    }
    else if(count==14)
    {
     setcolor(GREEN);
     circle(95,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(95,146,GREEN);
     line(95,140,95,55);
     line(95,55,270,55);
     circle(275,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,56,GREEN);
        setcolor(BLUE);
     line(50+40,100+20,50+15,100+40);
     line(50+40,100+40,50+15,100+40);
     ellipse(50+40,100+80,0,100,20,60);
     ellipse(50+40,100+60,90,-70,5,20);
     ellipse(50+49,100+75,0,180,12,12);
     ellipse(50+49,100+75,180,360,12,12);
     ear[0]=50+25;
     ear[1]=100+33;
     ear[2]=50+30;
     ear[3]=100+27;
     ear[4]=50+20;
     ear[5]=100+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=50+30;
     ear1[1]=100+27;
     ear1[2]=50+40;
     ear1[3]=100+21;
     ear1[4]=50+25;
     ear1[5]=100+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(50+40,100+30,5);
    }
    else if(count==15)
    {
     setcolor(GREEN);
     circle(275,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,56,GREEN);
     line(275,60,275,145);
     line(275,145,450,145);
     circle(455,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(455,146,GREEN);
        setcolor(BLUE);
     line(230+40,10+20,230+15,10+40);
     line(230+40,10+40,230+15,10+40);
     ellipse(230+40,10+80,0,100,20,60);
     ellipse(230+40,10+60,90,-70,5,20);
     ellipse(230+49,10+75,0,180,12,12);
     ellipse(230+49,10+75,180,360,12,12);
     ear[0]=230+25;
     ear[1]=10+33;
     ear[2]=230+30;
     ear[3]=10+27;
     ear[4]=230+20;
     ear[5]=10+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=230+30;
     ear1[1]=10+27;
     ear1[2]=230+40;
     ear1[3]=10+21;
     ear1[4]=230+25;
     ear1[5]=10+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(230+40,10+30,5);
    }
    else if(count==16)
    {
     setcolor(GREEN);
     circle(455,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(455,146,GREEN);
     line(450,145,365,145);
     line(365,145,365,320);
     circle(365,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,326,GREEN);
        setcolor(BLUE);
     line(410+40,100+20,410+15,100+40);
     line(410+40,100+40,410+15,100+40);
     ellipse(410+40,100+80,0,100,20,60);
     ellipse(410+40,100+60,90,-70,5,20);
     ellipse(410+49,100+75,0,180,12,12);
     ellipse(410+49,100+75,180,360,12,12);
     ear[0]=410+25;
     ear[1]=100+33;
     ear[2]=410+30;
     ear[3]=100+27;
     ear[4]=410+20;
     ear[5]=100+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=410+30;
     ear1[1]=100+27;
     ear1[2]=410+40;
     ear1[3]=100+21;
     ear1[4]=410+25;
     ear1[5]=100+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(410+40,100+30,5);
    }
    else if(count==17)
    {
     setcolor(GREEN);
     circle(365,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,326,GREEN);
     line(360,325,185,325);
     line(185,325,185,410);
     circle(185,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,416,GREEN);
        setcolor(BLUE);
     line(320+40,280+20,320+15,280+40);
     line(320+40,280+40,320+15,280+40);
     ellipse(320+40,280+80,0,100,20,60);
     ellipse(320+40,280+60,90,-70,5,20);
     ellipse(320+49,280+75,0,180,12,12);
     ellipse(320+49,280+75,180,360,12,12);
     ear[0]=320+25;
     ear[1]=280+33;
     ear[2]=320+30;
     ear[3]=280+27;
     ear[4]=320+20;
     ear[5]=280+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=320+30;
     ear1[1]=280+27;
     ear1[2]=320+40;
     ear1[3]=280+21;
     ear1[4]=320+25;
     ear1[5]=280+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(320+40,280+30,5);
    }
    else if(count==18)
    {
     setcolor(GREEN);
     circle(185,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(185,416,GREEN);
     line(180,415,95,415);
     line(95,415,95,240);
     circle(95,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(95,236,GREEN);
        setcolor(BLUE);
     line(140+40,370+20,140+15,370+40);
     line(140+40,370+40,140+15,370+40);
     ellipse(140+40,370+80,0,100,20,60);
     ellipse(140+40,370+60,90,-70,5,20);
     ellipse(140+49,370+75,0,180,12,12);
     ellipse(140+49,370+75,180,360,12,12);
     ear[0]=140+25;
     ear[1]=370+33;
     ear[2]=140+30;
     ear[3]=370+27;
     ear[4]=140+20;
     ear[5]=370+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=140+30;
     ear1[1]=370+27;
     ear1[2]=140+40;
     ear1[3]=370+21;
     ear1[4]=140+25;
     ear1[5]=370+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(140+40,370+30,5);
    }
    else if(count==19)
    {
     setcolor(GREEN);
     circle(95,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(95,236,GREEN);
     line(100,235,275,235);
     line(275,235,275,150);
     circle(275,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,146,GREEN);
        setcolor(BLUE);
     line(50+40,190+20,50+15,190+40);
     line(50+40,190+40,50+15,190+40);
     ellipse(50+40,190+80,0,100,20,60);
     ellipse(50+40,190+60,90,-70,5,20);
     ellipse(50+49,190+75,0,180,12,12);
     ellipse(50+49,190+75,180,360,12,12);
     ear[0]=50+25;
     ear[1]=190+33;
     ear[2]=50+30;
     ear[3]=190+27;
     ear[4]=50+20;
     ear[5]=190+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=50+30;
     ear1[1]=190+27;
     ear1[2]=50+40;
     ear1[3]=190+21;
     ear1[4]=50+25;
     ear1[5]=190+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(50+40,190+30,5);
    }
    else if(count==20)
    {
     setcolor(GREEN);
     circle(275,145,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,146,GREEN);
     line(275,140,275,55);
     line(275,55,450,55);
     circle(455,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(455,56,GREEN);
        setcolor(BLUE);
     line(230+40,100+20,230+15,100+40);
     line(230+40,100+40,230+15,100+40);
     ellipse(230+40,100+80,0,100,20,60);
     ellipse(230+40,100+60,90,-70,5,20);
     ellipse(230+49,100+75,0,180,12,12);
     ellipse(230+49,100+75,180,360,12,12);
     ear[0]=230+25;
     ear[1]=100+33;
     ear[2]=230+30;
     ear[3]=100+27;
     ear[4]=230+20;
     ear[5]=100+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=230+30;
     ear1[1]=100+27;
     ear1[2]=230+40;
     ear1[3]=100+21;
     ear1[4]=230+25;
     ear1[5]=100+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(230+40,100+30,5);
    }
    else if(count==21)
    {
     setcolor(GREEN);
     circle(455,55,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(455,56,GREEN);
     line(455,60,455,235);
     line(455,235,370,235);
     circle(365,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,236,GREEN);
        setcolor(BLUE);
     line(410+40,10+20,410+15,10+40);
     line(410+40,10+40,410+15,10+40);
     ellipse(410+40,10+80,0,100,20,60);
     ellipse(410+40,10+60,90,-70,5,20);
     ellipse(410+49,10+75,0,180,12,12);
     ellipse(410+49,10+75,180,360,12,12);
     ear[0]=410+25;
     ear[1]=10+33;
     ear[2]=410+30;
     ear[3]=10+27;
     ear[4]=410+20;
     ear[5]=10+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=410+30;
     ear1[1]=10+27;
     ear1[2]=410+40;
     ear1[3]=10+21;
     ear1[4]=410+25;
     ear1[5]=10+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(410+40,10+30,5);
    }
    else if(count==22)
    {
     setcolor(GREEN);
     circle(365,235,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(365,236,GREEN);
     line(365,240,365,415);
     line(365,415,450,415);
     circle(455,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(455,416,GREEN);
        setcolor(BLUE);
     line(320+40,190+20,320+15,190+40);
     line(320+40,190+40,320+15,190+40);
     ellipse(320+40,190+80,0,100,20,60);
     ellipse(320+40,190+60,90,-70,5,20);
     ellipse(320+49,190+75,0,180,12,12);
     ellipse(320+49,190+75,180,360,12,12);
     ear[0]=320+25;
     ear[1]=190+33;
     ear[2]=320+30;
     ear[3]=190+27;
     ear[4]=320+20;
     ear[5]=190+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=320+30;
     ear1[1]=190+27;
     ear1[2]=320+40;
     ear1[3]=190+21;
     ear1[4]=320+25;
     ear1[5]=190+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(320+40,190+30,5);
    }
    else if(count==23)
    {
     setcolor(GREEN);
     circle(455,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(455,416,GREEN);
     line(450,415,275,415);
     line(275,415,275,330);
     circle(275,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,326,GREEN);
        setcolor(BLUE);
     line(410+40,370+20,410+15,370+40);
     line(410+40,370+40,410+15,370+40);
     ellipse(410+40,370+80,0,100,20,60);
     ellipse(410+40,370+60,90,-70,5,20);
     ellipse(410+49,370+75,0,180,12,12);
     ellipse(410+49,370+75,180,360,12,12);
     ear[0]=410+25;
     ear[1]=370+33;
     ear[2]=410+30;
     ear[3]=370+27;
     ear[4]=410+20;
     ear[5]=370+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=410+30;
     ear1[1]=370+27;
     ear1[2]=410+40;
     ear1[3]=370+21;
     ear1[4]=410+25;
     ear1[5]=370+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(410+40,370+30,5);
    }
    else if(count==24)
    {
     setcolor(GREEN);
     circle(275,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,326,GREEN);
     line(270,325,95,325);
     line(95,325,95,410);
     circle(95,415,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(95,416,GREEN);
     setcolor(GREEN);
     circle(275,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,326,GREEN);
     line(450,415,275,415);
     line(275,415,275,330);
     circle(275,325,5);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(275,326,GREEN);
        setcolor(BLUE);
     line(230+40,280+20,230+15,280+40);
     line(230+40,280+40,230+15,280+40);
     ellipse(230+40,280+80,0,100,20,60);
     ellipse(230+40,280+60,90,-70,5,20);
     ellipse(230+49,280+75,0,180,12,12);
     ellipse(230+49,280+75,180,360,12,12);
     ear[0]=230+25;
     ear[1]=280+33;
     ear[2]=230+30;
     ear[3]=280+27;
     ear[4]=230+20;
     ear[5]=280+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=230+30;
     ear1[1]=280+27;
     ear1[2]=230+40;
     ear1[3]=280+21;
     ear1[4]=230+25;
     ear1[5]=280+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(230+40,280+30,5);
    }
    else if(count==25)
    {
        setcolor(BLUE);
     line(50+40,370+20,50+15,370+40);
     line(50+40,370+40,50+15,370+40);
     ellipse(50+40,370+80,0,100,20,60);
     ellipse(50+40,370+60,90,-70,5,20);
     ellipse(50+49,370+75,0,180,12,12);
     ellipse(50+49,370+75,180,360,12,12);
     ear[0]=50+25;
     ear[1]=370+33;
     ear[2]=50+30;
     ear[3]=370+27;
     ear[4]=50+20;
     ear[5]=370+10;
     ear[6]=ear[0];
     ear[7]=ear[1];
     drawpoly(4,ear);
     ear1[0]=50+30;
     ear1[1]=370+27;
     ear1[2]=50+40;
     ear1[3]=370+21;
     ear1[4]=50+25;
     ear1[5]=370+3;
     ear1[6]=ear1[0];
     ear1[7]=ear1[1];
     drawpoly(4,ear1);
     circle(50+40,370+30,5);
    }
    if(count>1)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(95,55,"0");
    }
    if(count>2)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(185,235,"1");
    }
    if(count>3)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(275,415,"2");
    }
    if(count>4)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(455,325,"3");
    }
    if(count>5)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(365,145,"4");
    }
    if(count>6)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(185,55,"5");
    }
    if(count>7)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(275,235,"6");
    }
    if(count>8)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(95,325,"7");
    }
    if(count>9)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(185,145,"8");
    }
    if(count>10)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(355,55,"9");
    }
    if(count>11)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(440,230,"10");
    }
    if(count>12)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(350,410,"11");
    }
    if(count>13)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(170,320,"12");
    }
    if(count>14)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(80,140,"13");
    }
    if(count>15)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(260,50,"14");
    }
    if(count>16)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(440,140,"15");
    }
    if(count>17)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(350,320,"16");
    }
    if(count>18)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(170,410,"17");
    }
    if(count>19)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(80,230,"18");
    }
    if(count>20)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(260,140,"19");
    }
    if(count>21)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(440,50,"20");
    }
    if(count>22)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(350,230,"21");
    }
    if(count>23)
    {
        setcolor(RED);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(440,410,"22");
    }
    if(count>24)
    {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,5);
        outtextxy(260,320,"23");
    }
    delay(3000);
    if(count<25){
            cleardevice();
    }
    if(count==25&&show<3)
    {
        delay(2000);
        cleardevice();
        setcolor(YELLOW);
        settextstyle(10,HORIZ_DIR,1);
        outtextxy(50,280,"THIS VISUALIZATION WILL RUN 3 TIMES ONLY. THANKS!");
        delay(3000);
        cleardevice();
        if(show==1)
        {
        setcolor(GREEN);
        settextstyle(10,HORIZ_DIR,1);
        outtextxy(50,280,"RUNNING 2ND TIME :)");
        delay(5000);
        }
        cleardevice();
        if(show==2)
        {
            setcolor(GREEN);
            settextstyle(10,HORIZ_DIR,1);
            outtextxy(50,280,"RUNNING 3RD TIME :)");
            delay(5000);
        }
        cleardevice();
        show=show+1;
        count=0;
        if(show>3)
        {
            getch();
            closegraph();
        }
    }
    }
    }
    printf("\n");
    printf("\n####### THANKS FOR SEEING THE VISUALIZATION #######");
    printf("\n");
    printf("\n******************** THE VISUALTIZATION IS OVER THANKS! :)*****************");
}

