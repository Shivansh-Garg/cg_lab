#include<bits/stdc++.h>
#include<cmath>
#include<GL/glut.h>
using namespace std;

const float windowHeight = 700.0;
const float windowWidth = 700.0;

int x3, y3;

int x[4]={50,50,75,75};
int y[4]={200,300,300,200};

int shearingX, shearingY;
char shearingAxis;

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < 4; i++)
	{
		glVertex2i(x[i], y[i]);
	}
	glEnd();
}


void drawPolygonShearing()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);

	if (shearingAxis == 'x' || shearingAxis == 'X')
	{
		glVertex2i(x[0], y[0]);

		glVertex2i(x[1] + shearingX, y[1]);
		glVertex2i(x[2] + shearingX, y[2]);

		glVertex2i(x[3], y[3]);
	}
	else if (shearingAxis == 'y' || shearingAxis == 'Y')
	{
		glVertex2i(x[0], y[0]);
		glVertex2i(x[1], y[1]);

		glVertex2i(x[2], x[2] + shearingY);
		glVertex2i(x[3], y[3] + shearingY);
	}
	glEnd();
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
    drawPolygon();
    drawPolygonShearing();
	glFlush();
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

int main(int argc, char** argv)
{
    cout << "Enter shearing axis ( x or y ): ";
    cin >> shearingAxis;
    if (shearingAxis == 'x' || shearingAxis == 'X')
    {
        cout << "Enter the shearing factor for X: "; cin >> shearingX;
    }
    else
    {
        cout << "Enter the shearing factor for Y: "; cin >> shearingY;
    }
	glutInit(&argc, argv);
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	glFlush();
	return 0;
}

