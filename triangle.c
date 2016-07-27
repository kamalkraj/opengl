#include<Gl/glut.h>

GLint w=500,h=500;
void display()
{
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);         
      glColor3f(0.0f, 1.0f, 0.0f); 
      glVertex2f(-0.5f, -0.5f);    
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
   glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInitWindowSize(w,h);
    glutInit(&argc,argv);
    glutCreateWindow("White");
    glutInitWindowPosition(500,2000);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}




