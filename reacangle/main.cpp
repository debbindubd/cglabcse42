#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void polygon()
{
    glBegin(GL_POLYGON);//Denotes the beginning of a group of vertices that define one or more primitives.
		glColor3f(1.0, 1.0, 0.0); // RED color
		glVertex2f(1.000, 0.000);
        glVertex2f(0.992, 0.125);
        glVertex2f(0.968, 0.248);
        glVertex2f(0.929, 0.368);
        glVertex2f(0.876, 0.481);
        glVertex2f(0.809, 0.588);
        glVertex2f(0.729, 0.684);
        glVertex2f(0.637, 0.770);
        glVertex2f(0.535, 0.841);
        glVertex2f(0.425, 0.899);
        glVertex2f(0.309, 0.940);
        glVertex2f(0.189, 0.967);
        glVertex2f(0.065, 0.978);
        glVertex2f(-0.065, 0.978);
        glVertex2f(-0.189, 0.967);
        glVertex2f(-0.309, 0.940);
        glVertex2f(-0.425, 0.899);
        glVertex2f(-0.535, 0.841);
        glVertex2f(-0.637, 0.770);
        glVertex2f(-0.729, 0.684);
        glVertex2f(-0.809, 0.588);
        glVertex2f(-0.876, 0.481);
        glVertex2f(-0.929, 0.368);
        glVertex2f(-0.968, 0.248);
        glVertex2f(-0.992, 0.125);
        glVertex2f(-1.000, 0.000);
        glVertex2f(-0.992, -0.125);
        glVertex2f(-0.968, -0.248);
        glVertex2f(-0.929, -0.368);
        glVertex2f(-0.876, -0.481);
        glVertex2f(-0.809, -0.588);
        glVertex2f(-0.729, -0.684);
        glVertex2f(-0.637, -0.770);
        glVertex2f(-0.535, -0.841);
        glVertex2f(-0.425, -0.899);
        glVertex2f(-0.309, -0.940);
        glVertex2f(-0.189, -0.967);
        glVertex2f(-0.065, -0.978);
        glVertex2f(0.065, -0.978);
        glVertex2f(0.189, -0.967);
        glVertex2f(0.309, -0.940);
        glVertex2f(0.425, -0.899);
        glVertex2f(0.535, -0.841);
        glVertex2f(0.637, -0.770);
        glVertex2f(0.729, -0.684);
        glVertex2f(0.809, -0.588);
        glVertex2f(0.876, -0.481);
        glVertex2f(0.929, -0.368);
        glVertex2f(0.968, -0.248);
        glVertex2f(0.992, -0.125);

	glEnd();	//Terminates a list of vertices that specify a primitive initiated by glBegin.

}
int windowWidth=800,windowHeight=600;
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-3, 3, -3, 3);// scale division increasing or decreasing
    //gluOrtho2D(0, 10, 0, 10); // just projection of an object,how much large it will be
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glViewport(0, 0 ,windowWidth ,windowHeight);

    polygon();

    glFlush(); // to flush the object on screen
    glutSwapBuffers();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(500,100);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Circle");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
