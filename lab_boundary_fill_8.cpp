#include <GL/glut.h>

const float WindowHeight = 700;
const float WindowWidth = 700;

float boundaryColor[] = {1.0,1.0,1.0};
float fillColor[] = {1.0,1.0,0.0};

void init(){
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WindowWidth,WindowHeight);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Boundary Fill");
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,WindowWidth,0,WindowHeight,1.0,-1.0);
}

void boundaryfill(int x, int y, float fillColor[3], float boundaryColor[3]){
    float currentColor[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,currentColor);
    if((currentColor[0]!=boundaryColor[0] || currentColor[1]!=boundaryColor[1] || currentColor[2]!=boundaryColor[2])
       &&(currentColor[0]!=fillColor[0] || currentColor[1]!=fillColor[1] || currentColor[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);

        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();

        boundaryfill(x-1,y,fillColor,boundaryColor);
        boundaryfill(x,y+1,fillColor,boundaryColor);
        boundaryfill(x+1,y,fillColor,boundaryColor);
        boundaryfill(x,y-1,fillColor,boundaryColor);
        boundaryfill(x-1,y-1,fillColor,boundaryColor);
        boundaryfill(x+1,y+1,fillColor,boundaryColor);
        boundaryfill(x+1,y-1,fillColor,boundaryColor);
        boundaryfill(x-1,y+1,fillColor,boundaryColor);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(350,350);
        glVertex2f(350,450);
        glVertex2f(450,450);
        glVertex2f(450,350);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
