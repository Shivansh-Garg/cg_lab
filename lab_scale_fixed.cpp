#include<bits/stdc++.h>
#include<cmath>
#include<GL/glut.h>
using namespace std;

const float windowHeight = 700.0;
const float windowWidth = 700.0;

int a,b;
int sx, sy;
int x[4]={50,100,75};
int y[4]={200,200,300};
int resx[3];
int resy[3];

double round(double d)
{
	return floor(d + 0.5);
}

void matrix_mult(int mat1[3][3], int mat2[3][3],int result[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                result[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}
void Scale(int a, int b){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    int matrix2[3][3] = {{50,100,75},
                        {200,200,300},
                        {1,1,1}};

    int matrix1[3][3] = {{sx,0,a-a*sx},
                        {0,sy,b-b*sy},
                        {0,0,1}};


    int result[3][3] = {{0,0,0},
                        {0,0,0},
                        {0,0,0}};
    matrix_mult(matrix1,matrix2,result);
    resx[0] = result[0][0];
    resx[1] = result[0][1];
    resx[2] = result[0][2];
    resy[0] = result[1][0];
    resy[1] = result[1][1];
    resy[2] = result[1][2];
    for (int i = 0; i < 3; i++)
    {
        glVertex2i(round(resx[i]), round(resy[i]));

    }
	glEnd();
    glFlush();

}
void drawPolygon()
{
	glBegin(GL_LINE_LOOP);
        glVertex2i(50,200);
        glVertex2i(100,200);
        glVertex2i(75,300);
	glEnd();
	glFlush();

        cout<<endl;
        cout<<"Scaling"<< endl;
        cout << "Enter the scaling factor for X and Y: ";
        cin >> sx >> sy;
        cout << "Enter Arbitary point- ";
        cin >> a >> b;
        Scale(a,b);
}


void init(){
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(windowWidth,windowHeight);
    glutInitWindowPosition(0,0);
    glutCreateWindow("scaling");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1*windowWidth/2,windowWidth/2,-1*windowHeight/2,windowHeight/2,1.0,-1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(drawPolygon);
    glutMainLoop();;
    return 0;
}

