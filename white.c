#include<Gl/glut.h>

void display()
{
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("White");
    glutInitWindowSize(320,320);
    glutInitWindowPosition(50,50);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}




