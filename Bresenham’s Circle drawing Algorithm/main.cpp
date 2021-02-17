#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

int pntx1, pnty1, r;
void plot(int x,  int  y)
{

     glBegin(GL_POINTS);
    glVertex2i(x+pntx1,  y+pnty1);
    glEnd();
}

void  myInit(void){
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0f,0.0f,0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0,0.0, 480.0);

}

void  midPointCircle(){
int   x = 0;
int  y =r;
float  decisions = 5/4-r;
plot(x,y);
while(y>x){
    if(decisions<0){
        x++;
        decisions+=2*x+1;
    }
    else{
        y--;
        x++;
        decisions+=2*(x-y)+1;

    }
    plot(x,y);
    plot(x,-y);
    plot(-x,y);
    plot(-x,-y);
    plot(y,x);
        plot(-y,x);
    plot(y,-x);
    plot(-y,-x);


}
}

void  myDisplay(void){

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.0);
glPointSize(1.0);
midPointCircle();
glFlush();
}


int main(int argc,  char** argv){
    printf("Enter  the  coordinate  of  the  center.\n\n");
    printf("xcoordinate");
    scanf("%i",&pntx1);
       printf("ycoordinate");
    scanf("%i",&pnty1);
    printf("Radius");
    scanf("%i",&r);


    glutInit(&argc,  argv);
    glutInitDisplayMode(GLUT_SINGLE |  GLUT_RED);
    glutInitWindowSize(640,  460);
glutInitWindowPosition(100,150);
glutCreateWindow("Bresenham’s Circle drawing Algorithm");
glutDisplayFunc(myDisplay);
    myInit();
    	glutMainLoop();



}










