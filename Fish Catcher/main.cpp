#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<windows.h>
#include<iostream>


float xr=0 , yr=0, ropeX = 0, ropeY = 0;
int flag=0,ch=0,ch1=0,score=0;
float a=0,b=0,c=0,d=0,e=0,f=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,p=0,q=0,s=0.7,x=0,y=0,R=1.0,G=1.0,B=1.0;
double hx,hy,Gx,Gy,Bx,By,Rx,Ry,Yx,Yy;
GLint w=-1.0;
int color;
bool collide = false;
bool dead = false;
void create_menu(void);
void menu(int);
void playDisplay(void);
void highScoreDisplay(void);
void scoreCounter(void);
void catchGreenFish(void);
void catchRedFish(void);
void catchYellowFish(void);
void catchBlueFish(void);


void drawText(char ch[],int xpos, int ypos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos2f(xpos , ypos);
    for (int i = 0; i <= numofchar - 1; i++)
    {
     
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}

void drawTextNum(char ch[],int numtext,int xpos, int ypos)//counting the score
{
    int len;
    int k;
    k = 0;
    len = numtext - strlen (ch);
    glLoadIdentity ();
    glRasterPos2f(xpos , ypos);
    for (i = 0; i <=numtext - 1; i++)
    {
    if ( i < len )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
        k++;
    }
     
    }
}
 

void delay(int time)
{
	float i,j,k;

	for(i=0;i<time;i=i+0.001);
	for(j=0;j<time;j=j+0.001);
	for(k=0;k<time;k=k+0.001);
}

/*Moving Fish 1*/
void redFish()
{
	glColor3f(1.0,0.0,0.0);//red fish
		glBegin(GL_POLYGON);
		glVertex2f(0.7+a,0.05);
		glVertex2f(0.75+a,0.1);
		glVertex2f(0.85+a,0.05);
		glVertex2f(0.75+a,0.0);
	glEnd();

    glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(0.83+a,0.05);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(0.9+a,0.09);
		glVertex2f(0.9+a,0.01);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(0.75+a,0.095);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(0.79+a,0.125);
		glVertex2f(0.77+a,0.07);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(0.75+a,0.007);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(0.795+a,-0.035);
		glVertex2f(0.77+a,0.02);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	
	Rx= 0.73+a;
	Ry= 0.065;
	glBegin(GL_POINTS);
		glVertex2f(Rx,Ry);
	glEnd();
}  // moving fish

/*Moving Fish 2*/
void yellowFish()
{
	glColor3f(1.0,1.0,0.0);//yellow fish
	glBegin(GL_POLYGON);
		glVertex2f(-0.7-b,-0.05);
		glVertex2f(-0.75-b,-0.1);
		glVertex2f(-0.85-b,-0.05);
		glVertex2f(-0.75-b,0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(0.8,0.5,0.0); 
		glVertex2f(-0.83-b,-0.05);
		glVertex2f(-0.9-b,-0.09);
		glVertex2f(-0.9-b,-0.01);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(0.8,0.5,0.0);
		glVertex2f(-0.75-b,-0.095);
		glVertex2f(-0.79-b,-0.125);
		glVertex2f(-0.77-b,-0.07);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(0.8,0.5,0.0);
		glVertex2f(-0.75-b,-0.007);
		glVertex2f(-0.795-b,0.035);
		glVertex2f(-0.77-b,-0.02);
	glEnd();

	Yx= -0.73-b;
	Yy= -0.035;
	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
		glVertex2f(Yx,Yy);
	glEnd();
}

/*Moving Fish 3*/
void greenFish()
{ 
	glColor3f(0.8,0.498039,0.196078);//green fish
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.8+x,0.15);//body
		glVertex2f(-0.85+x,0.2);
		glVertex2f(-0.95+x,0.15);
		glVertex2f(-0.85+x,0.10);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.93+x,0.15);//wing top
		glVertex2f(-0.98+x,0.19);
		glVertex2f(-0.98+x,0.11);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.855+x,0.2);//wing bottom
		glVertex2f(-0.925+x,0.25);
		glVertex2f(-0.87+x,0.15);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.857+x,0.1);//wing back
		glVertex2f(-0.925+x,0.05);
		glVertex2f(-0.87+x,0.15);
	glEnd();


	Gx= -0.83+x;
	Gy= 0.165; 

	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
		glVertex2f(Gx,Gy);
	glEnd();
}

void deadFish(float r, float g, float b)
{ 
	glColor3f(r,g,b);
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.8+0.85+xr,0.15+0.20);//body
		glVertex2f(-0.85+0.85+xr,0.2+0.20);
		glVertex2f(-0.95+0.85+xr,0.15+0.20);
		glVertex2f(-0.85+0.85+xr,0.10+0.20);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.93+0.85+xr,0.15+0.20);//wing top
		glVertex2f(-0.98+0.85+xr,0.19+0.20);
		glVertex2f(-0.98+0.85+xr,0.11+0.20);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.855+0.85+xr,0.2+0.20);//wing bottom
		glVertex2f(-0.925+0.85+xr,0.25+0.20);
		glVertex2f(-0.87+0.85+xr,0.15+0.20);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.857+0.85+xr,0.1+0.20);//wing back
		glVertex2f(-0.925+0.85+xr,0.05+0.20);
		glVertex2f(-0.87+0.85+xr,0.15+0.20);
	glEnd();


	Gx= -0.83+0.85+xr;
	Gy= 0.165+0.20; 

	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
		glVertex2f(Gx,Gy);
	glEnd();
}

/*Moving Fish 4*/
void blueFish()
{
	glColor3f(0.0,0.0,1.0);//blue fish
	glBegin(GL_POLYGON);
		glVertex2f(-0.7-e,-0.25);
		glVertex2f(-0.75-e,-0.3);
		glVertex2f(-0.775-e,-0.3);
		glVertex2f(-0.85-e,-0.25);
		glVertex2f(-0.775-e,-0.2);
		glVertex2f(-0.75-e,-0.2);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.83-e,-0.25);
		glVertex2f(-0.9-e,-0.29);
		glVertex2f(-0.9-e,-0.21);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.775-e,-0.2);
		glVertex2f(-0.79-e,-0.125);
		glVertex2f(-0.75-e,-0.2);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(-0.75-e,-0.3);
		glVertex2f(-0.795-e,-0.35);
		glVertex2f(-0.775-e,-0.3);
	glEnd();

	Bx = -0.73-e;
	By = -0.235;
	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
		glVertex2f(Bx,By);
	glEnd();
}

/*Plant*/
void plant()
{ 
  glColor3f(0.0,1.0,0.0);
   glLineWidth(4.0);
   glBegin(GL_LINES);
	glVertex2f(0.9,-0.8);
	glVertex2f(0.8,-0.9);
	glVertex2f(0.8,-0.8);
	glVertex2f(0.8,-0.9);
	glVertex2f(0.7,-0.8);
	glVertex2f(0.8,-0.9);
	glVertex2f(0.75,-0.8);
	glVertex2f(0.8,-0.9);
	glVertex2f(0.85,-0.8);
	glVertex2f(0.8,-0.9);
    glVertex2f(0.725,-0.8);
	glVertex2f(0.8,-0.9);
    glVertex2f(0.775,-0.8);
	glVertex2f(0.8,-0.9);
    glVertex2f(0.825,-0.8);
	glVertex2f(0.8,-0.9);
    glVertex2f(0.875,-0.8);
	glVertex2f(0.8,-0.9);
   glEnd();


   glLineWidth(4.0);
   glBegin(GL_LINES);
	glVertex2f(0.5,-0.95);
	glVertex2f(0.6,-0.85);
	glVertex2f(0.5,-0.85);
	glVertex2f(0.5,-0.95);
	glVertex2f(0.4,-0.85);
	glVertex2f(0.5,-0.95);
	glVertex2f(0.45,-0.85);
	glVertex2f(0.5,-0.95);
	glVertex2f(0.55,-0.85);
	glVertex2f(0.5,-0.95);
    glVertex2f(0.425,-0.85);
	glVertex2f(0.5,-0.95);
    glVertex2f(0.475,-0.85);
	glVertex2f(0.5,-0.95);
    glVertex2f(0.525,-0.85);
	glVertex2f(0.5,-0.95);
    glVertex2f(0.575,-0.85);
	glVertex2f(0.5,-0.95);
   glEnd();



   glLineWidth(4.0);
   glBegin(GL_LINES);
	glVertex2f(0.175,-0.9);
	glVertex2f(0.275,-0.8);
	glVertex2f(0.175,-0.8);
	glVertex2f(0.175,-0.9);
	glVertex2f(0.075,-0.8);
	glVertex2f(0.175,-0.9);
	glVertex2f(0.125,-0.8);
	glVertex2f(0.175,-0.9);
	glVertex2f(0.225,-0.8);
	glVertex2f(0.175,-0.9);
    glVertex2f(0.1,-0.8);
	glVertex2f(0.175,-0.9);
    glVertex2f(0.15,-0.8);
	glVertex2f(0.175,-0.9);
    glVertex2f(0.2,-0.8);
	glVertex2f(0.175,-0.9);
    glVertex2f(0.25,-0.8);
	glVertex2f(0.175,-0.9);
   glEnd();
	


   glLineWidth(4.0);
   glBegin(GL_LINES);
	glVertex2f(-0.175,-0.95);
	glVertex2f(-0.275,-0.85);
	glVertex2f(-0.175,-0.85);
	glVertex2f(-0.175,-0.95);
	glVertex2f(-0.075,-0.85);
	glVertex2f(-0.175,-0.95);
	glVertex2f(-0.125,-0.85);
	glVertex2f(-0.175,-0.95);
	glVertex2f(-0.225,-0.85);
	glVertex2f(-0.175,-0.95);
    glVertex2f(-0.1,-0.85);
	glVertex2f(-0.175,-0.95);
    glVertex2f(-0.15,-0.85);
 	glVertex2f(-0.175,-0.95);
    glVertex2f(-0.2,-0.85);
	glVertex2f(-0.175,-0.95);
    glVertex2f(-0.25,-0.85);
	glVertex2f(-0.175,-0.95);
   glEnd();

   glLineWidth(4.0);
   glBegin(GL_LINES);
	glVertex2f(-0.475,-0.9);
	glVertex2f(-0.575,-0.8);
	glVertex2f(-0.475,-0.9);
	glVertex2f(-0.475,-0.8);
	glVertex2f(-0.375,-0.8);
	glVertex2f(-0.475,-0.9);
	glVertex2f(-0.425,-0.8);
	glVertex2f(-0.475,-0.9);
	glVertex2f(-0.525,-0.8);
	glVertex2f(-0.475,-0.9);
    glVertex2f(-0.4,-0.8);
	glVertex2f(-0.475,-0.9);
    glVertex2f(-0.45,-0.8);
	glVertex2f(-0.475,-0.9);
    glVertex2f(-0.5,-0.8);
	glVertex2f(-0.475,-0.9);
    glVertex2f(-0.55,-0.8);
	glVertex2f(-0.475,-0.9);
   glEnd();
	


   glLineWidth(4.0);
   glBegin(GL_LINES);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.8,-0.95);
	glVertex2f(-0.8,-0.85);
	glVertex2f(-0.8,-0.95);
	glVertex2f(-0.7,-0.85);
	glVertex2f(-0.8,-0.95);
	glVertex2f(-0.75,-0.85);
	glVertex2f(-0.8,-0.95);
	glVertex2f(-0.85,-0.85);
	glVertex2f(-0.8,-0.95);
    glVertex2f(-0.725,-0.85);
	glVertex2f(-0.8,-0.95);
    glVertex2f(-0.775,-0.85);
	glVertex2f(-0.8,-0.95);
    glVertex2f(-0.825,-0.85);
	glVertex2f(-0.8,-0.95);
    glVertex2f(-0.875,-0.85);
	glVertex2f(-0.8,-0.95);
   glEnd();

}

/*Boat*/
void boat()
{
	//Boat
	glColor3f(0.65,0.50,0.39);
	glBegin(GL_QUADS);
	glVertex2f(-0.25+xr,0.5+yr); //A 
	glVertex2f(-0.15+xr,0.22+yr); //D
	glVertex2f(0.05+xr,0.22+yr);  //c
	glVertex2f(0.15+xr,0.5+yr); //B
	glEnd();

	//Fishing rod
	glColor3f(0,0,0);
	glBegin(GL_QUADS);
	glVertex2f(0.05+xr,0.5+yr); //A 
	glVertex2f(0.25+xr,0.72+yr); //D
	glVertex2f(0.25+xr,0.72+yr);  //c
	glVertex2f(0.15+xr,0.5+yr); //B
	glEnd();

	//border
	glColor3f(0.52, 0.37,  0.26);
	glBegin(GL_LINES);
	glVertex2f(-0.25+xr,0.5+yr); //A 
	glVertex2f(-0.15+xr,0.22+yr); //D
	glEnd();
	
	//border
	glColor3f(0.52, 0.37,  0.26);
	glBegin(GL_LINES);
	glVertex2f(0.15+xr,0.5+yr); //B
	glVertex2f(0.05+xr,0.22+yr);  //c
	glEnd();

	//border
	glColor3f(0.52, 0.37,  0.26);
	glBegin(GL_LINES);
	glVertex2f(0.05+xr,0.22+yr);  //c
	glVertex2f(-0.15+xr,0.22+yr); //D
	glEnd();

	//FISHING LINE
	glColor3f(0.52, 0.37,  0.26);
	glBegin(GL_LINES);
	glVertex2f(0.25+xr,0.72+yr); //top point
	glVertex2f(0.25+xr+ropeX,0.32+ropeY); //bottom point
	glEnd();

	//Hook
	hx=0.22+xr+ropeX;
	hy=0.38+yr+ropeY;
	glColor3f(0.329412, 0.329412, 0.329412);
	glBegin(GL_LINES);
	glVertex2f(hx,hy); //edge point
	glVertex2f(0.25+xr+ropeX,0.32+yr+ropeY); //connecting point
	glEnd();
}

void catcherfg()
{
	catchBlueFish();
	catchRedFish();
	catchYellowFish();
	catchGreenFish();
}

void catchBlueFish()
{
	if((Bx <= hx + 0.25 && By <= hy + 0.15 ) && (Bx >= hx - 0.25 && By >= hy - 0.15))
	{
		collide = true;
		color = 1;
		scoreCounter();
		e=1.95;
		glutPostRedisplay();
	}
	else
	{
		collide = false;
	}	
}

void catchRedFish()
{
	if((Rx <= hx + 0.25 && Ry <= hy + 0.15 ) && (Rx >= hx - 0.25 && Ry >= hy - 0.15))
	{
		collide = true;
		color = 2;
		scoreCounter();
		a=1.95;
		glutPostRedisplay();
	}
	else
	{
		collide = false;
	}	
}

void catchYellowFish()
{
	if((Yx <= hx + 0.25 && Yy <= hy + 0.15 ) && (Yx >= hx - 0.25 && Yy >= hy - 0.15))
	{
		collide = true;
		color = 3;
		scoreCounter();
		b=1.95;
		glutPostRedisplay();
	}
	else
	{
		collide = false;
	}	
}

void catchGreenFish()
{
	if((Gx <= hx + 0.25 && Gy <= hy + 0.15 ) && (Gx >= hx - 0.25 && Gy >= hy - 0.15))
	{
		collide = true;
		color = 4;
		scoreCounter();
		x=1.95;
		glutPostRedisplay();
	}
	else
	{
		collide = false;
	}	
}

void scoreCounter()
{
		if (collide == true)
	{
		score++;
		printf("Score: %d \n",score);
		dead = true;
		
	}
}

void sky()
{
	glColor3f(0.22,0.69, 0.87);
	glBegin(GL_QUADS);
	glVertex2f(-1.0,1.0); //A 
	glVertex2f(-1.0,0.25); //D
	glVertex2f(1.0,0.25);  //c
	glVertex2f(1.0,1.0); //B
	glEnd();
}

void update(int value)
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	
	w-=50;
	if(w<=-80)
		w=-1.0;
			
		glutPostRedisplay();
	
		glutTimerFunc(200,update,0);
}


/* DRAW WATER */
/*
void water()
{

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(1000,0);
		glVertex2f(1000,100);
		glVertex2f(0,100);
	glEnd();
}
*/
/*To draw water*/
void water()
{	
		glPushMatrix();
		//glPushMatrix();
		glTranslated(w,-1.0,0.0);
		glColor3f(0.1,0.5,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glVertex2f(0.10,0.96); 
		glVertex2f(0.25,0.98);		
		glVertex2f(0.39,0.94);
		glVertex2f(0.50,0.92);
		glVertex2f(0.70,0.98);
		glVertex2f(0.85,0.95);
		glVertex2f(0.95,0.96);
		glVertex2f(1.10,0.99);
		glVertex2f(1.28,0.97);
		glVertex2f(1.39,0.95);
		glVertex2f(1.45,0.97);
		glVertex2f(1.55,0.99);
		glVertex2f(1.72,0.95);
		glVertex2f(1.95,0.96);
		glVertex2f(2.12,0.95);
		glVertex2f(2.54,0.92);
		glVertex2f(2.84,0.96);
		glVertex2f(3.44,0.98);
		glVertex2f(3.60,0.93);
		glVertex2f(3.90,0.94);
		glVertex2f(4.10,0.99);
		glVertex2f(4.50,0.94);
		glVertex2f(4.85,1.00);
		glVertex2f(5.02,0.92);
		glVertex2f(5.52,0.92);
		glVertex2f(5.92,0.96);
		glVertex2f(6.30,1.05);
		glVertex2f(6.80,0.93);
		glVertex2f(7.20,0.97);
		glVertex2f(7.50,0.93);
		glVertex2f(8.00,0.95);
		glVertex2f(8.50,0.97);
		glVertex2f(8.80,1.08);
		glVertex2f(9.00,0.96);
		glVertex2f(9.20,0.93);
		glVertex2f(9.50,0.99);
		glVertex2f(9.80,0.92);
		glVertex2f(10.00,0.99);
		glVertex2f(10.00,0);
		glVertex2f(16.00,0.10);
		glVertex2f(30.00,2.80);
		glEnd();
		glPopMatrix();
}


void myKey(unsigned char key, int x, int y)
{
		if (key == 'z' || key == 'Z')
		{
			ropeX-= 0.05;
			glutPostRedisplay();
			
		}
			
		if (key == 'x' || key == 'X')
		{
			ropeX += 0.05;
			glutPostRedisplay();
		}
		if(key =='g')
		{
			catcherfg();
			glutPostRedisplay();
		}
		else
		{
			//Handle Exception
		}
}

void SpecialKey(int key, int x, int y)
{
		if (key == GLUT_KEY_UP)
		{
			ropeY+= 0.05;
			glutPostRedisplay();
		}
			
		else if (key == GLUT_KEY_DOWN)
		{
			ropeY-= 0.05;
			glutPostRedisplay();
		}  

		else if (key == GLUT_KEY_LEFT)
		{
			xr -= 0.05;
			//ropeX-= 1.05;
			glutPostRedisplay();
		}
	

		else if (key == GLUT_KEY_RIGHT)
		{
			//ropeX += 1.05;
			xr += 0.05;
			glutPostRedisplay();
		}

		else
		{
			//Handle Exception
		}
}

/*Init*/

void myinit()
{
	glClearColor(0,0,0.5,0.0);
	glColor3f(1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
gluOrtho2D(0.0,999.0,0.0,799.0);
}

/*Menu*/
void create_menu(void)
   {
     glutCreateMenu(menu);
     glutAttachMenu(GLUT_LEFT_BUTTON);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
     glutAddMenuEntry("Play", 1);
     //glutAddMenuEntry("High Score", 2);
     glutAddMenuEntry("Exit", 3);     
    }

void menu(int val)
   {
     switch (val) {
     case 1:
			glutDisplayFunc(playDisplay);;
			break;
     case 2:
		    //glutDisplayFunc(highScoreDisplay);
			break;

	 case 3: exit(0);     
   }
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glColor3f(1.0,0.0,0.0);
 glPointSize(2.0);
 //water(); 
 plant();
 sky();
 
 boat();
 boat2();
 
    glColor3f(1,1,1);
    drawText("WELCOME\nPLAYER\nPress Play to Continue", 0.25, 0.55);
    
 glutPostRedisplay();
 glFlush();
 glutSwapBuffers();
 
}

void playDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	
	glColor3f(1,1,1);
	
	//drawTextNum("Score: ",10,0.5,0.5);
	
	plant();
	sky();

	if(a>=-1.99)   
		a=a-0.0005;
	else
		a=0;

	if(x>=-1.99)   
		x=x+0.001;
	else
		x=0;

	if(b>=-1.99)
		b=b-0.0004;
	else
 		b=0;

	if(c>=-1.99)
		c=c-0.0003;
	else
 		c=0;

	if(d>=-1.99)
		d=d+0.0007;
	else
 		d=0;

	if(e>=-1.99)
		e=e-0.0005;
	else
 		e=0;

	if(f>=-1.99)
		f=f-0.0002;
	else
 		f=0;

	redFish();
	yellowFish();
	greenFish();
	blueFish();
	redFish();
 
	boat();

	if (dead == true && color == 1)
	{
		deadFish(0.0,0.0,1.0);
	}
	else if (dead == true && color == 2)
	{
		deadFish(1.0,0.0,0.0);
	}
	else if (dead == true && color == 3)
	{
		deadFish(1.0,1.0,0.0);
	}
	else if (dead == true && color == 4)
	{
		deadFish(0.0,1.0,0.0);
	}
	glutPostRedisplay();
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1280,600);
	glutCreateWindow("fish catcher");
	myinit();
	create_menu();
	glutDisplayFunc(display);
	glutKeyboardFunc(myKey);
	glutSpecialFunc(SpecialKey);
	glutTimerFunc(100,update,0);
	glutMainLoop();
}

