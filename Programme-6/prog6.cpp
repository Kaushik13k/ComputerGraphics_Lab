#include<Windows.h>
#include <stdio.h>
#include <GL/glut.h>
void displaySolid(void)
{
	glClearColor(0.5, 0.5, 0.1, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat mat_ambient[] = { 0.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_diffuse[] = { 1.0f, 0.5f, 1.0f, 1.0f };
	GLfloat mat_specular[] = { 0.5f, 0.5f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 25.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	GLfloat lightintensity[] = { 1.0f, 0.7f, 0.7f, 1.0f };
	GLfloat light_position[] = { 25.0f, 50.0f, 50.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensity);
	//TEAPOT
	glPushMatrix();
	glTranslated(0, 30, 0);
	glRotatef(35, 1, 0.5, 0);
	glutSolidTeapot(10);
	glPopMatrix();
	GLfloat mat_ambient1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_diffuse1[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	GLfloat mat_specular1[] = { 1.0f, 1.0f, 0.5f, 1.0f };
	GLfloat mat_shininess1[] = { 25.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess1);
	GLfloat lightintensity1[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat light_position1[] = { 25.0f, 50.0f, 50.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensity1);
	//topsurface
	glPushMatrix();
	glTranslated(0, 20, 0);
	glRotatef(-80, 1, 0.5, 0.8);
	glScalef(1.5, 1.5, 0.1);
	glutSolidCube(50);
	glPopMatrix();
	//1st leg
	glPushMatrix();
	glTranslated(-45, -10, -5);
	glRotatef(45, 0, 1, 0);
	glScalef(0.4, 5.5, 0.4);
	glutSolidCube(10);
	glPopMatrix();
	//2nd leg
	glPushMatrix();
	glTranslated(-10, -25, 5);
	glRotatef(45, 0, 1, 0);
	glScalef(0.4, 4.5, 0.4);
	glutSolidCube(10);
	glPopMatrix();
	//third leg
	glPushMatrix();
	glTranslated(45, -5, -10);
	glRotatef(45, 0, 1, 0);
	glScalef(0.4, 5.5, 0.4);
	glutSolidCube(10);
	glPopMatrix();
	glPushMatrix();
	//4th leg
	glTranslated(10, 5, -35);
	glRotatef(45, 0, 1, 0);
	glScalef(0.4, 6, 0.4);
	glutSolidCube(10);
	glPopMatrix();
	glFlush();
}
int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("______________");
	glutDisplayFunc(displaySolid);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutMainLoop();
}