#include<bits/stdc++.h>
#include<cmath>
#include<GL/glut.h>
using namespace std;

const float windowHeight = 700.0;
const float windowWidth = 700.0;

int x3, y3;

int x[4]={50,100,75};
int y[4]={200,200,300};

double round(double d)
{
	return floor(d + 0.5);
}


void Rotate(double angle){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++){
        glVertex2i(round((x[i] * cos(angle)) - (y[i] * sin(angle))), round((x[i] * sin(angle)) + (y[i] * cos(angle))));
    }
    glEnd();
    glFlush();
}

void pivotRotation(int tx1, int ty1, double angle,int direction){

    angle = direction * angle * 3.1416 / 180;
        glColor3f(1, 1, 1);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 3; i++) {
            glVertex2i(round(x[i] * cos(angle) - y[i] * sin(angle) - tx1 * cos(angle) + ty1 * sin(angle) + tx1), round(x[i] * sin(angle) + y[i] * cos(angle) - tx1 * sin(angle) - ty1 * cos(angle) + ty1));
        }
        glEnd();
        glFlush();
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
    while(true){
        int n;
        cout<<"Enter 1 for rotation around the origin and 2 for rotation around the fixed point"<<endl;
        cin>>n;
        int angle =0;
        glBegin(GL_LINE_LOOP);
        glVertex2i(50,200);
        glVertex2i(100,200);
        glVertex2i(75,300);
        glEnd();
    glFlush();
        if(n == 1){
            cout << "Enter the angle for rotation: ";
            cin >> angle;
            angle = angle * 3.1416 / 180;
            Rotate(angle);
           char ans;
           cout<<"Enter y to continue and n to exit"<<endl;
           cin>>ans;
           if(ans == 'n'){
                break;
           }
        }
        if(n ==2){


             cout << "Enter the angle for rotation: ";
             cin >> angle;
             cout << "Enter Arbitary point- ";
             int x, y;
             cin >> x >> y;
             pivotRotation( x, y, angle,1);
             cout<<"Enter y to continue and n to exit"<<endl;
            char ans;
            cin>>ans;
            if(ans == 'n'){
                break;
            }
        }
    }
    glutMainLoop();
    return 0;
}
