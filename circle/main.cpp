#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

// Function to draw a circle
void drawCircle(float x, float y, float radius, int num_segments) {
    glBegin(GL_LINE_LOOP);  // Start drawing a loop of lines
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);  // angle
        float dx = radius * cosf(theta);  // x coordinate
        float dy = radius * sinf(theta);  // y coordinate
        glVertex2f(x + dx, y + dy);  // Specify the vertex at the circle's edge
    }
    glEnd();  // End drawing the loop
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
    glLoadIdentity();  // Reset transformations

    // Set the color to be used for the circle (RGB: 1.0 = full red)
    glColor3f(1.0, 0.0, 0.0);

    // Draw a circle at position (0, 0) with radius 0.5 and 100 segments
    drawCircle(0.0f, 0.0f, 0.5f, 100);

    glFlush();  // Render all OpenGL commands
    glutSwapBuffers();  // Swap the buffers to display the circle
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);  // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // Set display mode
    glutInitWindowSize(500, 500);  // Set window size
    glutCreateWindow("OpenGL Circle Example");  // Create a window with a title

    // Set the projection matrix to 2D orthographic view
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set the view to be in the range -1 to 1 in both x and y

    glutDisplayFunc(display);  // Register display callback function
    glutMainLoop();  // Start the GLUT event loop

    return 0;
}
