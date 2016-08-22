#include<GL/glut.h>
#include<stdio.h>

float x,y,x2,y2;
void Init(void)
{glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,100.0,0.0,100.0);
}

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	glBegin(GL_POINTS);
		glVertex2i(xCoordinate,yCoordinate);
	glEnd();
	glFlush(); 
}

void lineDDA()
{	
	int v;
	float Steps;
	float Xincrement,Yincrement;
	float dx,dy;
	dx = x2 - x;
	dy = y2 - y;
	if (dx > dy)
	Steps = abs(dx);
	else
	Steps = abs(dy);
	Xincrement = dx / (float) Steps;
	Yincrement = dy / (float) Steps;
	
	setPixel(x+0.5,y+0.5);
	for(v=0; v < Steps; v++)
	{
	x = x + Xincrement;
	y = y + Yincrement;
	setPixel(x+0.5,y+0.5);
	}
}
	

void main(int argc,char **argv)
{
	scanf("%f%f",&x,&y);
	scanf("%f%f",&x2,&y2);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(400,400);
	glutCreateWindow("Line using DDA");
	glClear(GL_COLOR_BUFFER_BIT);
	Init();
	glutDisplayFunc(lineDDA);
	glutMainLoop();
}
		
