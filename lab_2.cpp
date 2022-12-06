#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

int x_1,x_2,y_1,y_2;

void drawPixel(int x, int y)
{
    glColor3f(1.0,1.0,1.0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenhamLine(int xa, int ya, int xb, int yb) {
    int dx = abs(xb - xa);
    int dy = abs(yb - ya);
    int x, y;
    if (dx >= dy)
    {
        int d = (2*dy) - dx;
        int ds = 2*dy;
        int dt = 2*(dy - dx);
        if (xa < xb){
            x = xa;
            y = ya;
        }
        else{
            x = xb;
            y = yb;
            xb = xa;
            yb = ya;
        }

        drawPixel(x, y);

        while (x < xb){
            if (d < 0) d += ds;
            else {
                if (y < yb) {
                    y++;
                    d+= dt;
                }
                else {
                    y--;
                    d+= dt;
                }
            }
            x++;
            drawPixel(x, y);
        }
    }
    else {
        int d = (2*dx) - dy;
        int ds = 2*dx;
        int dt = 2*(dx - dy);
        if (ya < yb) {
            x = xa;
            y = ya;
        }
        else {
            x = xb;
            y = yb;
            yb = ya;
            xb = xa;
        }

        drawPixel(x, y);

        while (y < yb){
            if (d < 0) d += ds;
            else {
                if (x>xb) {
                    x--;
                    d+= dt;
                }
                else {
                    x++;
                    d+= dt;
                }
            }
            y++;
            drawPixel(x, y);
        }
    }
}

void display(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,700.0,0,700.0,1.0,-1.0);
    bresenhamLine(x_1,y_1,x_2,y_2);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0,0);
    cout<<"Enter points x1, y1"<<endl;
    cin>>x_1>>y_1;
    cout<<"Enter points x2, y2"<<endl;
    cin>>x_2>>y_2;
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
