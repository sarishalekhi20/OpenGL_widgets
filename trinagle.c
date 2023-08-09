
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>
#include <GL/glu.h>
#include <math.h>
clock_t start, end;
double timeTaken;
float x0, y0_coord, x1, y1_coord, x2, y2_coord;
int fillOption;
void display() {
glClearColor(0, 0, 0, 1);
glClear(GL_COLOR_BUFFER_BIT);
if (fillOption == 1) {
glBegin(GL_TRIANGLES);
glColor3f(0, 1, 0);
glVertex2f(x0, y0_coord);
glColor3f(0, 1, 0);
glVertex2f(x1, y1_coord);
glColor3f(0, 1, 0);
glVertex2f(x2, y2_coord);
glEnd();
} else {
glBegin(GL_LINE_LOOP);
glColor3f(0, 1, 0);
glVertex2f(x0, y0_coord);
glVertex2f(x1, y1_coord);
glVertex2f(x2, y2_coord);
glEnd();
}
glutSwapBuffers();
}
void getUserInput() {
printf("Enter the x-coordinate for the first vertex: ");
scanf("%f", &x0);
printf("Enter the y-coordinate for the first vertex: ");
scanf("%f", &y0_coord);
printf("Enter the x-coordinate for the second vertex: ");
scanf("%f", &x1);
printf("Enter the y-coordinate for the second vertex: ");
scanf("%f", &y1_coord);
printf("Enter the x-coordinate for the third vertex: ");
scanf("%f", &x2);
printf("Enter the y-coordinate for the third vertex: ");
scanf("%f", &y2_coord);
printf("Enter 1 for a filled triangle or 0 for a non-filled triangle: ");
scanf("%d", &fillOption);
}
int main(int argc, char** argv) {
getUserInput(); // Get user input for vertices and fill option
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(1024, 1024);
glutInitWindowPosition(100, 100);
glutCreateWindow("GL RGB Triangle");
start = clock(); // Start measuring time
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1, 1, -1, 1);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
display();
end = clock(); // Stop measuring time
timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
printf("Time taken to form the triangle: %f seconds\n", timeTaken);
glutMainLoop();
return 0;
}
