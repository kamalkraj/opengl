#include<GL/glut.h>
#include<stdio.h>
float x,y,x2,y2;
void Init(void)
{glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

void DDAline(float a,float b)
{
glBegin(GL_POINTS);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(a,b,0.0);
glEnd();
glFlush();
}
void display(void)
{
	int i,s;
	
	float dx,dy,step,xinc,yinc;

	dx=x2-x;
	dy=y2-y;
	if(abs(dx)>abs(dy))
	step=abs(dx);
	else
	step=abs(dy);

	xinc=dx/step;
	yinc=dy/step;


	for(i=0;i<=step;i++)
	{
		DDAline(x,y);
		
		x=x+xinc;
		y=y+yinc;
		
	
	}
		

glFlush();
	
	
}	

int main(int argc,char **argv)
{
	scanf("%f%f",&x,&y);
	scanf("%f%f",&x2,&y2);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Line using DDA");
	glClear(GL_COLOR_BUFFER_BIT);
	Init();
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
		
