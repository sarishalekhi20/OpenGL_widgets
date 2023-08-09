#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>
#include <GL/glu.h>
#include <math.h>
clock_t start, end;
double timeTaken;
float radius;
int fillOption;
void display() {
glClearColor(0.0f, 0.f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
if (fillOption == 1) {
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
float degInRad = i * 3.14159 / 180;
glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
}
glEnd();
} else {
glColor3f(0.0, 1.0, 0.0);
glBegin(GL_LINE_LOOP);
for (int i = 0; i < 360; i++) {
float degInRad = i * 3.14159 / 180;
glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
}
glEnd();
}
glutSwapBuffers();
glFlush();
}
int main(int argc, char** argv) {
printf("Enter the radius of the circle: ");
scanf("%f", &radius);
printf("Enter 1 for a filled circle or 0 for a non-filled circle: ");
scanf("%d", &fillOption);
start = clock();
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
glutInitWindowSize(1024, 1024);
glutInitWindowPosition(100, 100);
glutCreateWindow("Circle");
glMatrixMode(GL_PROJECTION); // Set the matrix mode to projection
glLoadIdentity(); // Load the identity matrix
gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the orthographic view
glutDisplayFunc(display);
end = clock();
timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
printf("\nTime taken to make the widget using OpenGL: %f seconds\n", timeTaken);
glutMainLoop();
return 0;
}
