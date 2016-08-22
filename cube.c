#include<GL/glut.h>


GLfloat angle=0.0;

void display() {
glClear (GL_COLOR_BUFFER_BIT);

glLoadIdentity ();
glColor3f(1.0,0,0);
glRotatef(angle, 0.1, 0, 0);
glRotatef(angle, 0.1, 0, 0.1);
glRotatef(angle, 0.1, 0.1, 0);
//glutWireCube(0.5);
void glutWireIcosahedron ( void );
glColor3f(1.0,1.0,0);
glutSolidIcosahedron();

glFlush();
}
void spin (void) {
angle+= 0.1;
glutPostRedisplay();
}



void main(int argc,char* argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1000, 1000);
glutInitWindowPosition (200, 100);
glutCreateWindow("Hello");
glutDisplayFunc(display);
glutIdleFunc(spin);
glutMainLoop();
}
