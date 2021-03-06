#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
GLfloat xRotated, yRotated, zRotated;
 /* Global variables */
char title[] = "Board";
int cx,cy,cz = 0;
/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(-1.5f, 0.0f, -7.0f);  // Move right and into the screen
    glRotatef(yRotated, 0.0, 1.0, 0.0);
        //draw X
    
    glBegin(GL_POLYGON);                // Begin drawing the color cube with 6 quads
       // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(cx-0.10f, cy, cz+0.15f);
    glVertex3f(cx-0.30f, cy+0.20f, cz + 0.15f);
    glVertex3f(cx-0.20f, cy+0.30f, cz + 0.15f);
    glVertex3f(cx, cy+0.10f,cz + 0.15f);
    glVertex3f(cx+0.20f, cy+0.30f, cz + 0.15f);
    glVertex3f(cx+0.30f, cy+0.20f, cz + 0.15f);
    glVertex3f(cx+0.10f, cy+0.0f, cz + 0.15f);
    glVertex3f(cx+0.30f, cy-0.20f, cz + 0.15f);
    glVertex3f(cx+0.20f, cy-0.30f, cz + 0.15f);
    glVertex3f(cx+0.0f, cy-0.10f, cz + 0.15f);
    glVertex3f(cx-0.20f, cy-0.30f, cz + 0.15f);
    glVertex3f(cx-0.30f, cy-0.20f, cz + 0.15f);
    glVertex3f(cx-0.10f, cy-0.0f, cz + 0.15f);
    glEnd();
    

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(cx - 0.10f, cy, cz + 0.10f);
    glVertex3f(cx - 0.30f, cy + 0.20f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy + 0.30f, cz + 0.10f);
    glVertex3f(cx, cy + 0.10f, cz + 0.10f);
    glVertex3f(cx + 0.20f, cy + 0.30f, cz + 0.10f);
    glVertex3f(cx + 0.30f, cy + 0.20f, cz + 0.10f);
    glVertex3f(cx + 0.10f, cy , cz + 0.10f);
    glVertex3f(cx + 0.30f, cy - 0.20f, cz + 0.10f);
    glVertex3f(cx + 0.20f, cy - 0.30f, cz + 0.10f);
    glVertex3f(cx , cy - 0.10f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy - 0.30f, cz + 0.10f);
    glVertex3f(cx - 0.30f, cy - 0.20f, cz + 0.10f);
    glVertex3f(cx - 0.10f, cy - 0.0f, cz + 0.10f);
    glEnd();  // End of drawing

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);     // darkRed

    glVertex3f(cx + 0.30f, cy + 0.20f, cz + 0.10f);
    glVertex3f(cx + 0.20f, cy + 0.30f, cz + 0.10f);
    glVertex3f(cx + 0.20f, cy + 0.30f, cz + 0.15f);
    glVertex3f(cx + 0.30f, cy + 0.20f, cz + 0.15f);

    glVertex3f(cx - 0.30f, cy + 0.20f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy + 0.30f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy + 0.30f, cz + 0.15f);
    glVertex3f(cx - 0.30f, cy + 0.20f, cz + 0.15f);

    glVertex3f(cx + 0.20f, cy + 0.30f, cz + 0.10f);
    glVertex3f(cx , cy + 0.10f, cz + 0.10f);
    glVertex3f(cx , cy + 0.10f, cz + 0.15f);
    glVertex3f(cx + 0.20f, cy + 0.30f, cz + 0.15f);

    glVertex3f(cx, cy + 0.10f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy + 0.30f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy + 0.30f, cz + 0.15f);
    glVertex3f(cx, cy + 0.10f, cz + 0.15f);
  
    glVertex3f(cx - 0.30f, cy + 0.20f, cz + 0.10f);
    glVertex3f(cx - 0.10f, cy, cz + 0.10f);
    glVertex3f(cx - 0.10f, cy, cz + 0.15f);
    glVertex3f(cx - 0.30f, cy + 0.20f, cz + 0.15f);

    glVertex3f(cx + 0.30f, cy + 0.20f, cz + 0.10f);
    glVertex3f(cx + 0.10f, cy, cz + 0.10f);
    glVertex3f(cx + 0.10f, cy, cz + 0.15f);
    glVertex3f(cx + 0.30f, cy + 0.20f, cz + 0.15f);
    //--------------------------------REFLECTION-----------------//
    glVertex3f(cx - 0.30f, cy - 0.20f, cz + 0.10f);
    glVertex3f(cx - 0.10f, cy, cz + 0.10f);
    glVertex3f(cx - 0.10f, cy, cz + 0.15f);
    glVertex3f(cx - 0.30f, cy - 0.20f, cz + 0.15f);

    glVertex3f(cx + 0.30f, cy - 0.20f, cz + 0.10f);
    glVertex3f(cx + 0.10f, cy, cz + 0.10f);
    glVertex3f(cx + 0.10f, cy, cz + 0.15f);
    glVertex3f(cx + 0.30f, cy - 0.20f, cz + 0.15f);

    glVertex3f(cx + 0.30f, cy - 0.20f, cz + 0.10f);
    glVertex3f(cx + 0.20f, cy - 0.30f, cz + 0.10f);
    glVertex3f(cx + 0.20f, cy - 0.30f, cz + 0.15f);
    glVertex3f(cx + 0.30f, cy - 0.20f, cz + 0.15f);

    glVertex3f(cx - 0.30f, cy - 0.20f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy - 0.30f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy - 0.30f, cz + 0.15f);
    glVertex3f(cx - 0.30f, cy - 0.20f, cz + 0.15f);

    glVertex3f(cx + 0.20f, cy - 0.30f, cz + 0.10f);
    glVertex3f(cx, cy - 0.10f, cz + 0.10f);
    glVertex3f(cx, cy - 0.10f, cz + 0.15f);
    glVertex3f(cx + 0.20f, cy - 0.30f, cz + 0.15f);

    glVertex3f(cx, cy - 0.10f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy - 0.30f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy - 0.30f, cz + 0.15f);
    glVertex3f(cx, cy - 0.10f, cz + 0.15f);



    glEnd();








    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
void idleFunc(void)
{

    yRotated += 0.05;

    display();
}
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    xRotated = yRotated = zRotated = 0.0;
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(1080, 720);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    glutIdleFunc(idleFunc);
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
   
    return 0;
}
