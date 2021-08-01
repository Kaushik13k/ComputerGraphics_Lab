#include<math.h>
#include<gl/glut.h>
#include<stdio.h>

int x1, y11, x2, y2, dx, dy;
void display();
void init();
void brenhams(int, int, int, int);

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	printf(" enter the end points of the line");
	scanf_s("%d%d%d%d", &x1, &y11, &x2, &y2);
	glutCreateWindow("Brenhams line Drawing");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);


}
void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	brenhams(x1, y11, x2, y2);
	glFlush();
}
void plotline(int x, int y)
{
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}
void brenhams(int x1, int y1, int x2, int y2)
{
	int dx, dy, pk, xinc, yinc, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1, y = y1;
	plotline(x, y);
	if (dx > 0)
		xinc = 1;
	else
		xinc = -1;
	if (dy > 0)
		yinc = 1;
	else
		yinc = -1;
	if (abs(dx) > abs(dy))
	{
		pk = 2 * abs(dy) - abs(dx);
		for (int i = 0; i <= abs(dx) - 1; i++)
		{
			if (pk < 0)
			{
				y = y;
				pk = pk + 2 * abs(dy);
			}
			else
			{
				y = y + yinc;
				pk = pk + 2 * abs(dy) - 2 * abs(dx);
			}
			x = x + xinc;
			plotline(x, y);
		}
	}
	else {
		pk = 2 * abs(dx) - abs(dy);
		for (int i = 0; i <= abs(dy) - 1; i++)
		{
			if (pk < 0)
			{
				x = x;
				pk = pk + 2 * abs(dx);
			}
			else
			{
				x = x + xinc;
				pk = pk + 2 * abs(dx) - 2 * abs(dy);
			}
			y = y + yinc;
			plotline(x, y);
		}
	}
}