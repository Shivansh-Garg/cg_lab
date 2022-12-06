#include<iostream>
#include <GL/glut.h>
using namespace std;

const float windowHeight = 700.0;
const float windowWidth = 700.0;

int pntX1, pntY1, r;

void plot(int x, int y)
{
    glColor3f(1.0,1.0,1.0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x+pntX1, y+pntY1);
    glEnd();
    glFlush();
}

void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float decision = 5/4 - r;
    plot(x, y);

    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }

}


void display(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,700.0,0,700.0,1.0,-1.0);
    midPointCircleAlgo();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0,0);
    cout << "Enter the coordinates of the center:\n\n" << endl;

    cout << "Enter X-coordinate:- "; cin >>pntX1;
    cout << "\nEnter Y-coordinate:- "; cin >>pntY1;
    cout << "\nEnter Enter radius:- "; cin >>r;
    glutCreateWindow("Mid-point Circle Algorithm");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
