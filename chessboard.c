#include<GL/glut.h>
#include <stdlib.h>
#include<math.h>

void init(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50.0,850.0,-50.0,850.0);
}

void DDAline(GLint x0, GLint y0, GLint xEnd, GLint yEnd)
{	
	int i;
	float Steps;
	float x,y;float Xinc,Yinc;
	float dx,dy;
	dx =xEnd-x0;
	dy =yEnd-y0;
	if(dx>dy)
	Steps=abs(dx);
	else
	Steps=abs(dy);
	Xinc=dx/(float)Steps;
	Yinc=dy/(float)Steps;
	glBegin(GL_POINTS);
		glVertex2i(x0+0.5,y0+0.5);
	glEnd();
	glFlush();
	for(i=0;i<Steps;i++)
	{
	x0=x0+Xinc;
	y0=y0+Yinc;
	glBegin(GL_POINTS);
		glVertex2i(x0+0.5,y0+0.5);
	glEnd();

	}
}

void color(float p,float q,float r,float s,float t) 
{   
int i;
glColor3f(t, t, t);
for(i=1;(s+i)<q;i++)
{
DDAline(p,s+i,r,s+i);
}
}


void drawboard(void)
{
struct co
{
float x,y;
}a,b;
int i,j,c=0;
glColor3f(1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
DDAline(0.0,0.0,800.0,0.0);
DDAline(0.0,0.0,0.0,800.0);
DDAline(0.0,800.0,800.0,800.0);
DDAline(800.0,0.0,800.0,800.0);
a.x=0.0;a.y=100.0;
b.x=100.0;b.y=0.0;
for(i=0;i<8;i++)
{
	for(j=0;j<8;j++)
	{
		if(c==0){c=1;}
		else {color(b.x-99.0,a.y,b.x,b.y,c);c=0;}
		b.x+=100;
		
	}
	if(c==0)c=1;
	else c=0;
	a.y+=100.0;
	b.y+=100.0;
	b.x=100.0;
}
glFlush();
}


int main(int argc, char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(400,400);
glutInitWindowPosition(0,0);
glutCreateWindow("chessboard");
init();
glutDisplayFunc(drawboard);
glutMainLoop();
return 0;
}

