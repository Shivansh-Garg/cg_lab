#include<bits/stdc++.h>
#include<cmath>
#include<GL/glut.h>
using namespace std;

const float windowHeight = 700.0;
const float windowWidth = 700.0;

int x[4]={0,150,-150};
int y[4]={150,-100,-100};

int x1[5]={0,0,150,150};
int y2[5]={0,150,150,0};


int x3[6] = {0,0,170,130};
int y3[6] = {0,150,50,150};

void trans_triangle(double X, double Y){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++){
        glVertex2i(round(x[i] + X), round(y[i] + Y));
    }
    glEnd();
    glFlush();
}

void trans_square(double X, double Y){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 4; i++){
        glVertex2i(round(x1[i] + X), round(y2[i] + Y));
    }
    glEnd();
    glFlush();
}

void trans_fig(double X, double Y){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 4; i++){
        glVertex2i(round(x3[i] + X), round(y3[i] + Y));
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
    glOrtho(-1*windowWidth/2,windowWidth/2,-1*windowHeight/2,windowHeight/2,1.0,-1.0); // make origin at center.
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    init();
    while(true){
        cout<<"enter 1 for triangle, 2 for square, 3 for figure"<<endl;
        int n;
        cin>>n;
        if(n == 1){
        glBegin(GL_LINE_LOOP);
            glVertex2i(0,150);
            glVertex2i(150,-100);
            glVertex2i(-150,-100);
        glEnd();
        glFlush();
            cout<<"enter the translational factor X and Y"<<endl;
            double x,y;
            cin>>x>>y;
            trans_triangle(x,y);
            cout<<"Enter y to continue and n to exit"<<endl;
            char ans;
            cin>>ans;
            if(ans == 'n'){
                break;
            }
        }
        if(n == 2){
            glBegin(GL_LINE_LOOP);
                glVertex2i(0,0);
                glVertex2i(0,150);
                glVertex2i(150,150);
                glVertex2i(150,0);
            glEnd();
            glFlush();
            cout<<"enter the translational factor X and Y"<<endl;
            double x,y;
            cin>>x>>y;
            trans_square(x,y);
            cout<<"Enter y to continue and n to exit"<<endl;
            char ans;
            cin>>ans;
            if(ans == 'n'){
                break;
            }
        }
        if(n == 3){
            glBegin(GL_LINE_LOOP);
                glVertex2i(0,0);
                glVertex2i(0,150);
                //glVertex2i(50,80);
                glVertex2i(170,50);
                glVertex2i(130,150);

            glEnd();
            glFlush();
            cout<<"enter the translational factor X and Y"<<endl;
            double x,y;
            cin>>x>>y;
            trans_fig(x,y);
            cout<<"Enter y to continue and n to exit"<<endl;
            char ans;
            cin>>ans;
            if(ans == 'n'){
                break;
            }
        }

    }
    return 0;
}

