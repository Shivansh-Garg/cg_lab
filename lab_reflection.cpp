#include<bits/stdc++.h>
#include<cmath>
#include<GL/glut.h>
using namespace std;

const float windowHeight = 700.0;
const float windowWidth = 700.0;

int x3, y3;
char reflectionAxis;

int x[4]={50,100,75};
int y[4]={200,200,300};

double round(double d)
{
	return floor(d + 0.5);
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < 3; i++)
	{
		glVertex2i(x[i], y[i]);
	}
	glEnd();
}

void drawPolygonMirrorReflection(char reflectionAxis)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);

	if (reflectionAxis == 'x' || reflectionAxis == 'X')
	{
		for (int i = 0; i < 3; i++)
		{
			glVertex2i(round(x[i]), round(y[i] * -1));

		}
	}
	else if (reflectionAxis == 'y' || reflectionAxis == 'Y')
	{
		for (int i = 0; i < 3; i++)
		{
			glVertex2i(round(x[i] * -1), round(y[i]));
		}
	}
	glEnd();
}

void myInit(void)
{
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(windowWidth,windowHeight);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Transformation");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1*windowWidth/2,windowWidth/2,-1*windowHeight/2,windowHeight/2,1.0,-1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
    drawPolygon();
    drawPolygonMirrorReflection(reflectionAxis);
	glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter reflection axis ( x or y ): ";
    cin >> reflectionAxis;
	glutInit(&argc, argv);
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	glFlush();
	return 0;
}

