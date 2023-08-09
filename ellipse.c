
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>
#include <GL/glu.h>
#include <math.h>
clock_t start, end;
double timeTaken;
float radiusX, radiusY;
int fillOption;
void display() {
glClearColor(0.0f, 0.f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
if (fillOption == 1) {
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
float degInRad = i * 3.14159 / 180;
glVertex2f(cos(degInRad) * radiusX, sin(degInRad) * radiusY);
}
glEnd();
} else {
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 360; i++) {
float degInRad = i * 3.14159 / 180;
glVertex2f(cos(degInRad) * radiusX, sin(degInRad) * radiusY);
}
glEnd();
}
glutSwapBuffers();
glFlush();
}
int main(int argc, char** argv) {
printf("Enter the X radius of the ellipse: ");
scanf("%f", &radiusX);
printf("Enter the Y radius of the ellipse: ");
scanf("%f", &radiusY);
printf("Enter 1 for a filled ellipse or 0 for a non-filled ellipse: ");
scanf("%d", &fillOption);
start = clock();
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
glutInitWindowSize(1024, 1024);
glutInitWindowPosition(100, 100);
glutCreateWindow("Ellipse");
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
glutDisplayFunc(display);
end = clock();
timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
printf("\nTime taken to make the widget using OpenGL: %f seconds\n", timeTaken);
glutMainLoop();
return 0;
}
