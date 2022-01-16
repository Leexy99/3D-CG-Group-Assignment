#include <windows.h>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>
#define PI 3.1415927
GLfloat x = 0.0; GLfloat y = 0.0; GLfloat angle = 0.0; GLfloat angle_size = 0.1;
int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;
#define FPS 60
float sb_ballX = -3.0;
float sb_ballY = -2.0;
float nb_ballX = -3.0;
float nb_ballY = -2.0;
boolean visible = true;
GLUquadricObj* n = gluNewQuadric();

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void s_lower_body()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat nb1[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, nb1);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.0, 0.6, -6.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.8, 0.6, 1.5, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s_left_leg()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat nb2[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, nb2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.55, 0.5, -6.0);
    glScaled(1.5, 1.0, 1.0);
    glColor3ub(229, 95, 56);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s_right_leg()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat nb3[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, nb3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.55, 0.5, -6.0);
    glScaled(1.5, 1.0, 1.0);
    glColor3ub(229, 95, 56);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s_ball(float sb_ballX, float sb_ballY)
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat nb3[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, nb3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(sb_ballX, sb_ballY, -6.0f);
    glColor3ub(255, 100, 0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void k_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if (!visible)
    {
        s_lower_body();
        s_left_leg();
        s_right_leg();
    }
    s_ball(nb_ballX,nb_ballY);
    glFlush();
    glutSwapBuffers();
}

void k_reshape(GLsizei SCREEN_WIDTH, GLsizei SCREEN_HEIGHT) {
    if (SCREEN_HEIGHT == 0) SCREEN_HEIGHT = 1;
    GLfloat aspect = (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT;

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 20.0f);
}

void animation_1(int) {
    glutTimerFunc(0, animation_1, 1);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);

    if (nb_ballX>=-3.5&& nb_ballX<-1.0)
    {
        nb_ballX += 0.02;
        nb_ballY += 0.02;
    }

    glutPostRedisplay();
}

void animation_2(int) {
    glutTimerFunc(10000, animation_2, 2);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);
    visible=!visible;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("3D project");
    glutDisplayFunc(k_display);
    glutReshapeFunc(k_reshape);
    glutTimerFunc(0, animation_1, 1);
    glutTimerFunc(3000, animation_2, 2);
    initGL();
    glutMainLoop();
}
