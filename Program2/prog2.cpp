#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
float theta;
void triangle(float* a, float* b, float* c) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.9, 0.1, 0.7);
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(4);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
}
void init() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display() {
	float tri_fix[3][2] = { {-80,-60},{-20,-60},{-40,-20} };
	float tri_org[3][2] = { {40,20},{80,20},{60,60} };
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	triangle(tri_org[0], tri_org[1], tri_org[2]);
	glPushMatrix();
	glRotatef(theta, 0.0, 0.0, 1.0);
	triangle(tri_org[0], tri_org[1], tri_org[2]);
	glPopMatrix();
	char s[] = "rotation about origin";
	glRasterPos2f(-1.5, 10);
	for (int i = 0; i < strlen(s); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);
	}
	triangle(tri_fix[0], tri_fix[1], tri_fix[2]);
	glPushMatrix();
	glTranslatef(-40, -20, 0);
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(40, 20, 0);
	triangle(tri_fix[0], tri_fix[1], tri_fix[2]);
	glPopMatrix();
	char s1[] = "rotation about fixed point";
	glRasterPos2f(-80, -90);
	for (int i = 0; i < strlen(s1); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s1[i]);
	}
	glFlush();
}int main(int argc, char* argv[])
{
	printf("Enter the rotation angle:");
	scanf_s("%f", &theta);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(10, 10);
	glutCreateWindow("triangle rotation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}