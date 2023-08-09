#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>
#include <GL/glu.h>
#include <math.h>


clock_t start, end;
double timeTaken;
int x1, y1_coord, x0, y0_coord;
void display() {
glBegin(GL_LINES);
glClearColor(0.0f, 0.f, 0.0f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0f, 1.0f, 0.0f);
// Draw the rectangle
glVertex2f(x1, y1_coord);
glVertex2f(x0, y1_coord);
glVertex2f(x0, y1_coord);
glVertex2f(x0, y0_coord);
glVertex2f(x0, y0_coord);
glVertex2f(x1, y0_coord);
glVertex2f(x1, y0_coord);
glVertex2f(x1, y1_coord);
glEnd();
glutSwapBuffers();
glFlush();
}
int main(int argc, char** argv) {
printf("Enter the coordinates of the first endpoint (x0 y0): ");
scanf("%d %d", &x0, &y0_coord);
printf("Enter the coordinates of the second endpoint (x1 y1): ");
scanf("%d %d", &x1, &y1_coord);
start = clock();
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB);
glutInitWindowSize(1024, 1024);
glutInitWindowPosition(100, 100);
glutCreateWindow("GL rectangle");
glutDisplayFunc(display);
end = clock();
timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
printf("\nTime taken to make the widget using OpenGL: %f seconds\n", timeTaken);
glutMainLoop();
return 0;
}
