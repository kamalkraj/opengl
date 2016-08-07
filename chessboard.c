#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

void setpixel(GLint xCoordinate, GLint yCoordinate) {
  glBegin(GL_POINTS);
  glVertex2i(xCoordinate, yCoordinate);
  glEnd();
  glFlush();
}

void DDA(int X1, int Y1, int X2, int Y2) {
  int I;
  float Length;
  float X, Y, Xinc, Yinc;
  Length = abs(X2 - X1);
  if (abs(Y2 - Y1) > Length)
    Length = abs(Y2 - Y1);
  Xinc = (X2 - X1) / (Length);
  Yinc = (Y2 - Y1) / (Length);
  X = X1;
  Y = Y1;
  for (I = 0; I < Length; I++) {
    setpixel((X + 0.5), (Y + 0.5));
    X = X + Xinc;
    Y = Y + Yinc;
  }
}

void color(float e, float f, float g, float h) {
  int t;
  for (t = 0; t < 4; t++) {
    float e_n = e + 35.0;
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(e, f);
    glVertex2f(e_n, f);
    glVertex2f(g, h);
    glVertex2f(e, h);
    glEnd();
    glFlush();
    f = f + 70.0;
    h = h + 70.0;
  }
}
void drawmyboard() {
  int k;
  float p, q, r, s;
  float j, m;
  float a_n, b_n;
  p = 10.0;
  q = 45.0;
  r = 290.0;
  s = 45.0;
  j = 80.0;
  m = 45.0;
  a_n = 45.0;
  b_n = 10.0;
  DDA(10.0, 10.0, 290.0, 10.0);
  DDA(10.0, 10.0, 10.0, 290.0);
  DDA(10.0, 290.0, 290.0, 290.0);
  DDA(290.0, 290.0, 290.0, 10.0);
  for (k = 0; k < 4; k++) {
    DDA(p, q, r, s);
    DDA(q, p, s, r);
    q = q + 35;
    s = s + 35;
    color(a_n, b_n, j, m);
    color((a_n - 35.0), (b_n + 35.0), (j - 35.0), (m + 35.0));
    a_n = j + 35.0;
    j = a_n + 35.0;
  }
}

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("chessboard");
  init();
  glutDisplayFunc(drawmyboard);
  glutMainLoop();
  return 0;
}
