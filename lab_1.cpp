#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

void ddaLine(int,int,int,int);
void plotPoints(int,int);
void plotMousePoints(int,int,int);

int x_1,x_2,y_1,y_2;

void display(void)
{
    glClearColor(0.5,0.5,0.7,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,700.0,0,700.0,1.0,-1.0);
    ddaLine(x_1,y_1,x_2,y_2);
};

void ddaLine(int x0,int y0, int xf,int yf){
    int dx=xf-x0;
    int dy=yf-y0;
    int steps;
    float Xincr,Yincr,x=x0,y=y0;

    steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

    Xincr=(float)dx/(float)steps;
    Yincr=(float)dy/(float)steps;

    if(x0!=0)
    {
        for(int i=1;i<=steps;i++)
        {
            x+=Xincr;
            y+=Yincr;
            plotPoints(round(x),round(y));
        }
    }

}

 void plotPoints(int x,int y){
    glColor3f(0.0,0.0,0.0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
 }


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0,0);
    cout<<"Enter points x1, y1"<<endl;
    cin>>x_1>>y_1;
    cout<<"Enter points x2, y2"<<endl;
    cin>>x_2>>y_2;
    glutCreateWindow("DDA Line Drawing Algorithm");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
