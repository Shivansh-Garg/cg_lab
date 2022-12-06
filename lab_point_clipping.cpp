#include <GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
const float windowHeight = 700.0;
const float windowWidth = 700.0;
const float xmin = 200.0;
const float xmax = 400.0;
const float ymin = 300.0;
const float ymax = 600.0;

bool checkInsidePoint(float x,float y){
if(x>=xmin && x<=xmax && y<=ymax && y>=ymin) return true;
else false;
}

void myInit (void){
glutInitDisplayMode (GLUT_SINGLE);
glutInitWindowSize (windowWidth, windowHeight);
glutInitWindowPosition (0, 0);
glutCreateWindow ("Point Clipping");
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, windowWidth, 0.0, windowHeight,1.0,-1.0);
}

void myDisplay(void){
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xmin,ymin);
glVertex2f(xmax,ymin);
glVertex2f(xmax,ymax);
glVertex2f(xmin,ymax);
glEnd();
glFlush();
}


void plotPoint(int x,int y){
glColor3f (1.0, 1.0, 0.0);
glPointSize(3);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush ();
}

void removePoint(int x,int y){
glColor3f (0.0, 0.0, 0.0);
glPointSize(3);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush ();
}

int main(int argc, char** argv){
glutInit(&argc, argv);
myInit ();
glutDisplayFunc(myDisplay);
cout<<"Enter the point " <<endl;
int x1,y1;
cin>>x1>>y1;
plotPoint(x1,y1);
if(checkInsidePoint(x1,y1)){
    cout<<"point "<<x1<<" "<<y1<<" is inside "<<endl;
}else{
    cout<<"point "<<x1<<" "<<y1<<" is outside the clipping window "<<endl;
    removePoint(x1,y1);
}
glutMainLoop();
return 0;
}
