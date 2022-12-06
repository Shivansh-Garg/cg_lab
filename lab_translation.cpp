#include<bits/stdc++.h>
#include<cmath>
#include<GL/glut.h>
using namespace std;

const float windowHeight = 700.0;
const float windowWidth = 700.0;

int x[4]={0,150,-150};
int y[4]={150,-100,-100};

void Trans(double X, double Y){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++){
        glVertex2i(round(x[i] + X), round(y[i] + Y));
    }
    glEnd();
    glFlush();
}

void transformation(void){
    double X,Y;
    glBegin(GL_LINE_LOOP);
        glVertex2i(0,150);
        glVertex2i(150,-100);
        glVertex2i(-150,-100);
    glEnd();
    glFlush();

        cout<<endl;
        cout<<"Translation"<< endl;
        cout << "Enter the translation factor for X and Y: ";
        cin >> X >> Y;
        Trans(X,Y);
}

void init(){
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

int main(int argc, char **argv){
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(transformation);
    glutMainLoop();
    return 0;
}

