#include<GL/glut.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0,0,1,0);
glColor3f(1, 0,0);
glBegin(GL_POLYGON);
	
	glVertex3f(0,0.4,0.6);
	glVertex3f(x/1000,y/1000,0);
	glVertex3f(0.7,0,0);
glEnd();
glFlush();

}
void main(int argc, char* argv[])
{

glutInit(&argc,argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (200, 100);
glutCreateWindow("Hello");
glutKeyboardFunc(display);
glutMainLoop();
}

