#include<GL/glut.h>
#include<stdio.h>

int x1,y1,x2,y2;
void Init(void)
{glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

void display(void)
{
	int dx,dy,p,xinc,yinc,x,y;
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	if(dx>0)xinc=1;
	else xinc=-1;
	if(dy>0)yinc=1;
	else yinc=-1;
	dx=abs(dx);
	dy=abs(dy);
	if(x1==x2)
	{
	while(y!=y2)
	{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glFlush();
	y+=yinc;
	}
	}
	else
	{while(x!=x2)
	{
		if(p<0.0)
		{
		x+=xinc;
		p+=dy;
		}
		else
		{
		x+=xinc;
		y+=yinc;
		p+=2*dy-2*dx;
		}
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glFlush();
	}}
}	
int main(int argc,char **argv)
{
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Line using Bresenham");
	glClear(GL_COLOR_BUFFER_BIT);
	Init();
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
