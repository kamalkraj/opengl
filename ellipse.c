#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int x,y,a,b;
void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-1000.0,1000.0,-1000.0,1000.0);
}

void display(void)
	{
	int i;
	glClear(GL_COLOR_BUFFER_BIT); 

	glColor3f(1,1,1);
	glBegin(GL_LINES);
  		glVertex2i(-1000,0);
  		glVertex2i(1000,0);
  	glEnd();
 	glBegin(GL_LINES);
  		glVertex2i(0,-1000);
  		glVertex2i(0,1000);
  	glEnd();
  	glBegin(GL_POINTS);
	for(i=0;i<1000;i++)
	{
	glVertex3f(x+(cos(3.14*i/500.0))*a,y+(sin(3.14*i/500.0))*b,0);
	}
	glEnd();
	glFlush();
	}
void main(int argc,char* argv[])
{
printf("Enter the centre:");
scanf("%d%d",&x,&y);
printf("Enter the major axis and minor axis:");
scanf("%d%d",&a,&b);
glutInit(&argc,argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (200, 100);
glutCreateWindow("Ellipse");
init();
glutDisplayFunc(display);
glutMainLoop();
}
