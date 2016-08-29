#include<GL/glut.h>
#include<unistd.h>

GLfloat angle=0.0;

const GLfloat x=1;
void init()
{
	
  glClearColor(1.0,1.0,1.0,1.0);
  glEnable (GL_LIGHTING);
  glEnable (GL_LIGHT6);
  glLightfv(GL_LIGHT6,GL_POSITION,&x);
  
 }
void display() {
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity ();

glRotatef(angle, 0.1, 0, 0);
glRotatef(angle, 0.1, 0, 0.1);
glEnable (GL_DEPTH_TEST);
glShadeModel(GL_FLAT);

glColor3f(1.0,0,0);
glutSolidIcosahedron();
glColor3f(1.0,1.0,0);
glutWireIcosahedron ();
usleep(300);
glFlush();
}
void spin (void) {
angle+= 0.1;
glutPostRedisplay();
}



void main(int argc,char* argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH);
glutInitWindowSize (400, 400);
glutInitWindowPosition (200, 100);
glutCreateWindow("Hello");
glEnable (GL_DEPTH_TEST);
init();
glutDisplayFunc(display);
glutIdleFunc(spin);
glutMainLoop();
}
