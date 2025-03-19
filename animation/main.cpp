
#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<iostream>
#include<dos.h>
#include<bits/stdc++.h>
#include<time.h>

void triangle()
{
    glBegin(GL_TRIANGLES);//Denotes the beginning of a group of vertices that define one or more primitives.
		glColor3f(1.0,0.0,0.0);
		glVertex2f(2.0,2.0);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(2.0,0.0);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(0.0,0.0);
	glEnd();	//Terminates a list of vertices that specify a primitive initiated by glBegin.

}
int windowWidth=800,windowHeight=600;

float Txval=0,Tyval=0;int fla=-1;

void myKeyboardFunc( unsigned char key, int x, int y)
{
	switch ( key )
	{
		case 'r':
		    fla=1;
			glutPostRedisplay();
			break;
		case 'u':
			fla=0;
			glutPostRedisplay();
			break;
		case 'j':
			fla=-1;//Txval=0;Tyval=0; return to 1st position
			glutPostRedisplay();
			break;
		case 'y':
			Tyval+=0.2;
			glutPostRedisplay();
			break;
		case 'd':
			Tyval-=0.2;
			glutPostRedisplay();
			break;
		case 27:	// Escape key
			exit(1);
	}

}

void animate()
{
	if (fla == 0)
	{
		Tyval+=0.002;
		//fla=-1;
	}
	if(fla == 1)
    {Tyval-=0.002;
       // fla=-1;
    }

	glutPostRedisplay();
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-3, 4, -3, 4);// scale division increasing or decreasing
    //gluOrtho2D(0, 10, 0, 10); // just projection of an object,how much large it will be
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();


    glViewport(0, 0 ,windowWidth ,windowHeight);


/*
//different view port e show
    glViewport(0, 0 ,windowWidth ,windowHeight);
    triangle();

    glViewport(-100, 0 ,windowWidth ,windowHeight);
    triangle();

*/

//single
/*
    glTranslatef(1,-1,0);
    glRotatef(45,0,0,1);
    triangle();
  */
//double
/*
glPushMatrix();
    glTranslatef(1,-1,0);
    glRotatef(45,0,0,1);
    triangle();
glPopMatrix();


glPushMatrix();
    triangle();
glPopMatrix();

*/

//animation

glPushMatrix();
    glTranslatef(Txval,Tyval,0);
    glRotatef(45,0,0,1);
    triangle();
 glPopMatrix();

    glFlush(); // to flush the object on screen
    glutSwapBuffers();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(500,100);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Triangle Animation");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
 glEnable(GL_NORMALIZE);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
