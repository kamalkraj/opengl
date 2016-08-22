#include <GL/glut.h>

void init( void )
{
glClearColor( 0.0, 0.0, 0.0, 1.0 );
glClearDepth( 1.0 );
glEnable( GL_LIGHT0 );
glEnable( GL_LIGHTING );
glEnable( GL_DEPTH_TEST );
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	int i;
	//draw two points
	glBegin(GL_POINTS);
	for(i = 0; i < 10; i++)
	{
		glVertex2i(10+5*i,110);
	}
	glEnd();

	//draw a line
	glBegin(GL_LINES);
		glVertex2i(10,10);
		glVertex2i(100,100);
	glEnd();

	glFlush();
}

void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutMainLoop();
}
