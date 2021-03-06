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
#define FPS 30
bool visible = true;
GLfloat t_y = 0.0f;
GLfloat c_y = 0.0f;
GLfloat c1_x = 0.0f;
GLfloat c2_x = 0.0f;
GLfloat ball_angle = 0.0f;
float cloud1_x_direction = -1.9f;
float cloud2_x_direction = 0.4f;
float cloud3_x_direction = -1.8f;
float ball_x_direction = -3.0f;
float ball_y_direction = -2.0f;
float s4_ball_x = -3.0f;
float s4_ball_y = -2.0f;
float s6_ball_y = -1.0f;
float ballX = -0.4;
float ballY = -0.2;
float mcX = -1.0;
float mchandX = -0.4;
float mcEyeX = -0.8;
float mcEyeBX = -0.75;
int state = 1;
float bg_angle = 0.0;
float s8_X = 0.0;
GLfloat xRotated, yRotated, zRotated;
int cx, cy, cz = 0;
int tx = 0;
int ty = 0;
float s3_ballX = -0.4;
float s3_ballY = -0.2;
float s14_ballX2 = -1.7;
float s14_ballY2 = 1.2;
float s14_G_ballX2 = -1.4;
float s14_G_ballY2 = 1.2;
float s14_B_ballX2 = -2.0;
float s14_B_ballY2 = 1.2;
GLUquadricObj* n = gluNewQuadric();

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//Scene 1
void mc_body()
{
    //head
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat head[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, head);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, 0.3, -6.0);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //eye start
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat eye[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, eye);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcEyeX, 0.28, -5.0);
    glColor3ub(255, 255, 255);
    glScaled(1.0, 0.6, 1.0);
    glutSolidSphere(0.05, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat eye2[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, eye2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcEyeBX, 0.28, -4.9);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.02, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //eye ends

    // Body start
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, 0.0, -6.0);
    glColor3ub(0, 193, 255);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body2[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, -0.45, -6.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.2, 0.2, 0.45, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //body end

    //lower body
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body3[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, -0.7, -6.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(0, 0, 220);
    gluCylinder(n, 0.17, 0.17, 0.25, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //legs
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body4[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body4);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, -1.0, -6.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(240, 184, 160);
    gluCylinder(n, 0.1, 0.1, 0.35, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //shoes
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body5[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body5);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mcX, -1.05, -6.0);
    glColor3ub(240, 0, 0);
    glScaled(1.0, 0.6, 1.0);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void mc_hand()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef((0.85 * mcX), -0.03, -5.0);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.07, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm2[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef((0.85 * mcX), -0.03, -5.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glColor3ub(240, 184, 160);
    gluCylinder(n, 0.07, 0.07, 0.4, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm3[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(mchandX, -0.03, -5.0);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.07, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void mc_court()
{
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(194, 197, 204);
    glVertex3f(-4.0, -1.5, -2.0);
    glVertex3f(-4.0, -1.5, -10.0);
    glVertex3f(6.0, -1.5, -10.0);
    glVertex3f(6.0, -1.5, -2.0);

    //court line start
    glColor3ub(200, 0, 0);
    glVertex3f(-3.5, -1.45, -2.5);
    glVertex3f(-3.5, -1.45, -9.0);
    glVertex3f(-3.4, -1.45, -9.0);
    glVertex3f(-3.4, -1.45, -2.5);

    glColor3ub(200, 0, 0);
    glVertex3f(-3.5, -1.45, -9.0);
    glVertex3f(5.5, -1.45, -9.0);
    glVertex3f(5.5, -1.45, -8.9);
    glVertex3f(-3.5, -1.45, -8.9);

    glColor3ub(200, 0, 0);
    glVertex3f(5.4, -1.45, -9.0);
    glVertex3f(5.5, -1.45, -9.0);
    glVertex3f(5.5, -1.45, -2.5);
    glVertex3f(5.4, -1.45, -2.5);
    //court line end

    //Background
    glColor3ub(0, 200, 0);
    glVertex3f(-10, -1, -11.9);
    glVertex3f(10, -1, -11.9);
    glVertex3f(10, -6, -11.9);
    glVertex3f(-10, -6, -11.9);

    glColor3ub(25, 189, 255);
    glVertex3f(-10, 10, -12);
    glVertex3f(10, 10, -12);
    glVertex3f(10, -6, -12);
    glVertex3f(-10, -6, -12);
    glEnd();
}

void mc_basketball()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(ballX, ballY, -5.0);
    glColor3ub(255, 126, 0);
    glutSolidSphere(0.12, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void mc_bBoard()
{
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(2.5f, 0.5f, -8.0f);  // Move right and into the screen

    glBegin(GL_QUADS);
    //Net Frame (Left Face Side)
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.6, 1.6, -0.5); //Left top corner
    glVertex3f(0.0, 1.4, -0.2); //Right top corner
    glVertex3f(0.0, 0.9, -0.2); //Right down corner
    glVertex3f(-0.6, 1.05, -0.4); //Left down corner

    //Pillar
    // Right face
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.2, 0.8, -0.5); //Left Top corner
    glVertex3f(1.0, 1.0, 0.5); //Right Top corner
    glVertex3f(1.0, -1.9, 0.5); //Right down corner
    glVertex3f(0.2, -2.0, 0.5); //Left down corner

    // Left face
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.1, 1.0, -0.5); //Left top corner
    glVertex3f(0.2, 0.8, 0.5); //Right top corner
    glVertex3f(0.2, -2.0, 0.5); //Right down corner
    glVertex3f(-0.1, -2.0, -0.5); //Left down corner

    //board
    //Top face
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.25, 1.85, 0.5); //Left top corner
    glVertex3f(1.25, 1.55, 0.5); //Right top corner
    glVertex3f(0.50, 1.6, -0.8); //Right down corner
    glVertex3f(-1.0, 1.85, -0.8); //Left down corner

    // Left face (x = 0.2f)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, 1.8, -0.6); //Left top corner
    glVertex3f(0.4, 1.55, -0.5); //Right top corner
    glVertex3f(0.4, 0.75, -0.5); //Right down corner
    glVertex3f(-1.0, 1.1, -0.6); //Left down corner

    // Right face 
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.45, 1.60, -0.7); //Left top corner
    glVertex3f(1.15, 1.50, 0.7); //Right top corner
    glVertex3f(1.15, 0.90, 0.7); //Right down corner
    glVertex3f(0.45, 0.75, -0.6); //Left down corner    

    glEnd();  // End of drawing color-cube

    //Basketball frame
    glBegin(GL_LINES);
    //Right line
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.45, 0.0);
    glVertex3f(-0.5, 0.6, 1.5);

    //Left line
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.15, 0.6, 0.0);
    glVertex3f(-1.25, 0.5, 2.5);

    //Bottom line
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.15, 0.60, 0.0); //Left vertex
    glVertex3f(-0.5, 0.45, 0.0); //Right vertex

    glEnd(); //End of drawing lines
}

//Scene 2
void k_background(void) {
    glColor3f(0.2, 0.7, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-7.0f, 7.0f, -1.0f);
    glVertex3f(-7.0f, -0.5f, -1.0f);
    glVertex3f(7.0f, -0.5f, -1.0f);
    glVertex3f(7.0f, 7.0f, -1.0f);
    glEnd();

    glColor3f(0.3, 0.8, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(-7.0f, -0.5f, -1.0f);
    glVertex3f(-7.0f, -7.0f, -1.0f);
    glVertex3f(7.0f, -7.0f, -1.0f);
    glVertex3f(7.0f, -0.5f, -1.0f);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-1.5f, -0.5f, -1.0f);
    glVertex3f(-9.5f, -6.0f, -1.0f);
    glVertex3f(7.0f, -6.0f, -1.0f);
    glVertex3f(-0.9f, -0.5f, -1.0f);
    glEnd();
}

void k_tree(void) {
    //1
    glLoadIdentity();
    glTranslatef(-3.7, -0.2f, -6.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.1f);
    //Front
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, -0.4f, 0.4f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.4f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, -0.4f, 0.4f);
    glVertex3f(0.4f, -0.4f, -0.4f);

    // Back
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, -0.4f);

    // Left
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glEnd();

    glLoadIdentity();
    glTranslatef(-3.7f, 0.1f, -6.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    //Front
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);
    glVertex3f(0.3f, -0.3f, -0.3f);

    // Back
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, -0.3f);

    // Left
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glEnd();

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat tree1[] = { -2.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, tree1);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-3.7f, -0.5f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3f(1.0, 0.3, 0.2);
    gluCylinder(n, 0.07, 0.07, 0.5, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //2
    glLoadIdentity();
    glTranslatef(-1.5, 1.0f, -6.0f);
    glRotatef(15, 1.0, -1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.1f);
    //Front
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);
    glVertex3f(0.3f, -0.3f, -0.3f);

    // Back
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, -0.3f);

    // Left
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glEnd();

    glLoadIdentity();
    glTranslatef(-1.5f, 1.2f, -6.0f);
    glRotatef(15, 1.0, -1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    //Front
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.2f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    // Back
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);

    // Left
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glEnd();

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat tree2[] = { -2.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, tree2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-1.5f, 0.8f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3f(1.0, 0.3, 0.2);
    gluCylinder(n, 0.06, 0.06, 0.3, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //3
    glLoadIdentity();
    glTranslatef(3.65, -0.2f, -6.0f);
    glRotatef(55, 0.0, -1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.1f);
    //Front
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, -0.4f, 0.4f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.4f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, -0.4f, 0.4f);
    glVertex3f(0.4f, -0.4f, -0.4f);

    // Back
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, -0.4f);

    // Left
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glEnd();

    glLoadIdentity();
    glTranslatef(3.65f, 0.1f, -6.0f);
    glRotatef(55, 0.0, -1.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    //Front
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);
    glVertex3f(0.3f, -0.3f, -0.3f);

    // Back
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, -0.3f);

    // Left
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glEnd();

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat tree3[] = { -2.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, tree3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(3.65f, -0.5f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3f(1.0, 0.3, 0.2);
    gluCylinder(n, 0.07, 0.07, 0.5, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //4
    glLoadIdentity();
    glTranslatef(1.5f, 1.0f, -6.0f);
    glRotatef(45, 0.2, -1.0, -0.05);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.1f);
    //Front
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.3f, -0.3f, 0.3f);
    glVertex3f(0.3f, -0.3f, -0.3f);

    // Back
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, -0.3f);

    // Left
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.3f, -0.3f, -0.3f);
    glVertex3f(-0.3f, -0.3f, 0.3f);
    glEnd();

    glLoadIdentity();
    glTranslatef(1.5f, 1.2f, -6.0f);
    glRotatef(45, 0.2, -1.0, -0.05);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    //Front
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.2f);

    // Right
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    // Back
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);

    // Left
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glEnd();

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat tree4[] = { -2.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, tree4);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(1.5f, 0.8f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3f(1.0, 0.3, 0.2);
    gluCylinder(n, 0.06, 0.06, 0.3, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void k_streetlamp(void) {
    //1
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball1[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball1);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-2.5f, 0.7f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    gluCylinder(n, 0.04, 0.04, 0.9, 100, 100);

    glLoadIdentity();
    glTranslatef(-2.5f, 0.7f, -6.0f);
    glRotatef(140, 1.0, 0.9, 0.9);

    glColor3f(0.8, 0.2, 0.2);
    gluCylinder(n, 0.04, 0.04, 0.4, 100, 100);

    glLoadIdentity();
    glColor3f(1.0, 0.9, 0.4);
    glTranslatef(-2.15f, 0.62f, -6.0f);
    glutSolidSphere(0.08, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //2
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball2[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.73f, 1.4f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    gluCylinder(n, 0.03, 0.03, 0.4, 100, 100);

    glLoadIdentity();
    glTranslatef(-0.73f, 1.4f, -6.0f);
    glRotatef(70, 0.2, 1.0, 0.3);

    glColor3f(0.8, 0.2, 0.2);
    gluCylinder(n, 0.03, 0.03, 0.3, 100, 100);

    glLoadIdentity();
    glColor3f(1.0, 0.9, 0.4);
    glTranslatef(-0.5f, 1.33f, -6.0f);
    glutSolidSphere(0.06, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //3
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball3[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(2.45f, 0.7f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    gluCylinder(n, 0.04, 0.04, 0.9, 100, 100);

    glLoadIdentity();
    glTranslatef(2.45f, 0.7f, -6.0f);
    glRotatef(90, 0.0, -1.0, -0.12);

    glColor3f(0.8, 0.2, 0.2);
    gluCylinder(n, 0.04, 0.04, 0.4, 100, 100);

    glLoadIdentity();
    glColor3f(1.0, 0.9, 0.4);
    glTranslatef(2.15f, 0.62f, -6.0f);
    glutSolidSphere(0.08, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //4
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball4[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball4);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.75f, 1.4f, -6.0f);
    glRotatef(90, 1.0, 0.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    gluCylinder(n, 0.03, 0.03, 0.4, 100, 100);

    glLoadIdentity();
    glTranslatef(0.45f, 1.43f, -6.0f);
    glRotatef(110, 0.0, 1.0, 0.0);

    glColor3f(0.8, 0.2, 0.2);
    gluCylinder(n, 0.03, 0.03, 0.35, 100, 100);

    glLoadIdentity();
    glColor3f(1.0, 0.9, 0.4);
    glTranslatef(0.52f, 1.33f, -6.0f);
    glutSolidSphere(0.06, 100, 100);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void kelefei(void) {
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat head[] = { -2.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, head);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.0f, 1.6f + (-t_y), -6.0f);
    glColor3f(1.0f, 1.0f, 0.8f);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();

    //eye
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-0.07f, 1.37f + (-c_y), -5.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.07f, 1.37f + (-c_y), -5.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //mouth
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.00f, 1.30f + (-c_y), -5.0f);
    glColor3f(1.0, 0.7, 0.3);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    //Body
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.0f, 1.22f + (-t_y), -6.0f);
    //glRotatef(15, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 0.4f, 0.4f);

    glBegin(GL_QUADS);
    // Top
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);

    // Bottom
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    // Front
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);

    // Back
    glVertex3f(0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, -0.2f);

    // Left 
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);

    // Right 
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);
    glEnd();
    glPopMatrix();

    //Hand
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat lh[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lh);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.25f, 1.3f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, -0.7);
    glColor3f(1.0f, 1.0f, 0.8f);
    gluCylinder(n, 0.07, 0.07, 0.2, 100, 100);

    glLoadIdentity();
    glTranslatef(-0.35f, 1.13f + (-t_y), -6.0f);
    glutSolidSphere(0.07, 100, 100);

    glLoadIdentity();
    glTranslatef(-0.35f, 1.14f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, -0.3);
    gluCylinder(n, 0.07, 0.07, 0.2, 100, 100);

    glLoadIdentity();
    glTranslatef(-0.42f, 0.90f + (-t_y), -6.0f);
    glutSolidSphere(0.06, 100, 100);

    glLoadIdentity();
    glTranslatef(0.26f, 1.3f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, 0.3);
    gluCylinder(n, 0.07, 0.07, 0.2, 100, 100);

    glLoadIdentity();
    glTranslatef(0.32f, 1.1f + (-t_y), -6.0f);
    glutSolidSphere(0.07, 100, 100);

    glLoadIdentity();
    glTranslatef(0.33f, 1.1f + (-t_y), -6.0f);
    glRotatef(90, 1.0, 0.0, -0.3);
    gluCylinder(n, 0.07, 0.07, 0.2, 100, 100);

    glLoadIdentity();
    glTranslatef(0.26f, 0.86f + (-t_y), -6.0f);
    glutSolidSphere(0.06, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //Leg
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.1f, 0.5f + (-t_y), -6.0f);
    glRotatef(90, -1.0, 0.0, 0.0);
    glColor3f(0.5, 0.8, 1.0);

    gluCylinder(n, 0.08, 0.08, 0.5, 100, 100);

    glLoadIdentity();
    glTranslatef(0.1f, 0.5f + (-t_y), -6.0f);
    glRotatef(90, -1.0, 0.0, 0.0);
    gluCylinder(n, 0.08, 0.08, 0.5, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //pillar
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat pil[] = { -2.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, pil);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-3.8f, 1.38, -6.0f);
    glColor3f(1.0, 0.9, 0.3);
    glRotatef(90, 1.0, 0.0, 0.0);

    gluCylinder(n, 0.03, 0.03, 0.8, 100, 100);

    glLoadIdentity();
    glTranslatef(-3.65f, 1.37, -6.0f);
    glColor3f(1.0, 0.9, 0.3);
    glRotatef(90, 1.0, 0.0, 0.0);

    gluCylinder(n, 0.03, 0.03, 0.7, 100, 100);

    glLoadIdentity();
    glTranslatef(-3.0f, 1.37, -6.0f);
    glColor3f(1.0, 0.9, 0.3);
    glRotatef(90, 1.0, 0.0, 0.0);

    gluCylinder(n, 0.03, 0.03, 0.7, 100, 100);

    glLoadIdentity();
    glTranslatef(-2.85f, 1.38, -6.0f);
    glColor3f(1.0, 0.9, 0.3);
    glRotatef(90, 1.0, 0.0, 0.0);

    gluCylinder(n, 0.03, 0.03, 0.8, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //Ball
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColor3ub(255, 126, 0);
    glTranslatef(-0.26f, 0.9f + (-t_y), -6.0f);
    glutSolidSphere(0.1, 10, 10);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();

    glLoadIdentity();
    glTranslatef(1.2f, 2.0f, -6.0f);
}

void k_house() {
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-3.3f, 1.35f, -6.0f);
    glRotatef(82, -1.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCone(0.6, 0.4, 20, 20);

    glLoadIdentity();
    glTranslatef(-3.32f, 0.80f, -6.0f);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.2, 100, 100);

    glLoadIdentity();
    glTranslatef(-3.32f, 1.05f, -6.0f);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.1, 100, 100);

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.8f, 0.9f, -5.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.015, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.74f, 0.9f, -5.0f);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.015, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.765f, 0.85f, -5.0f);
    glColor3f(1.0, 0, 0);
    glutSolidSphere(0.015, 100, 100);
    glPopMatrix();
}

void k_cloud() {
    //cloud 1
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat ball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, ball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-2.0f + c1_x, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-1.8f + c1_x, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-2.2f + c1_x, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);
    glPopMatrix();

    //cloud 2
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(3.0f + c2_x, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(2.8f + c2_x, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(3.2f + c2_x, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPopMatrix();
}

//Scene 3
void s3_basketball()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s3_ballX, s3_ballY, -5.0);
    glColor3ub(255, 126, 0);
    glutSolidSphere(0.12, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 4
void s4_basketball(float ball_x_direction, float ball_y_direction)
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(ball_x_direction, ball_y_direction, -6.0f);
    glColor3ub(255, 126, 0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s4_blueSky()
{
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(25, 189, 255);
    glVertex3f(-10, 10, -12);
    glVertex3f(10, 10, -12);
    glVertex3f(10, -10, -12);
    glVertex3f(-10, -10, -12);
    glEnd();
}

void s4_combinedCloud()
{
    //Center sphere
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(cloud1_x_direction, 1.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.2, 100, 100);

    //Right Sphere
    glLoadIdentity();
    glTranslatef(cloud1_x_direction + 0.2f, 1.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);

    //Left Sphere
    glLoadIdentity();
    glTranslatef(cloud1_x_direction - 0.2f, 1.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);

    //Center sphere
    glLoadIdentity();
    glTranslatef(cloud2_x_direction, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.2, 100, 100);

    //Right Sphere
    glLoadIdentity();
    glTranslatef(cloud2_x_direction - 0.2f, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);

    //Left Sphere
    glLoadIdentity();
    glTranslatef(cloud2_x_direction + 0.2f, 2.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);

    //Center sphere
    glLoadIdentity();
    glTranslatef(cloud3_x_direction, 0.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.2, 100, 100);

    //Right Sphere
    glLoadIdentity();
    glTranslatef(cloud3_x_direction - 0.2f, 0.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);

    //Left Sphere
    glLoadIdentity();
    glTranslatef(cloud3_x_direction + 0.2f, 0.0f, -6.0f);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 5
void s5_head() {
    glLoadIdentity();
    glTranslatef(0.0, 1.6, -6.0);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.3, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//body
void s5_upper_body() {
    glLoadIdentity();
    glTranslatef(0.0, 0.85, -6.0);
    glRotatef(15, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    glScalef(3.0, 2.3, 1.5);

    glBegin(GL_QUADS);
    //Top
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);

    //Bottom
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    //Front
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);

    //Back
    glVertex3f(0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, -0.2f);

    //Left
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, -0.2f);
    glVertex3f(-0.2f, -0.2f, 0.2f);

    //Right
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, 0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    glEnd();

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //depth buffer
    //glEnable(GL_DEPTH_TEST);

}

//Right_Hand
void s5_right_hand() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.55, 1.1, -6.0);
    glRotatef(60.0, 1.0, 1.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.25, 0.25, 0.75, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//forearms_right
void s5_right_forearm() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(1.1, 0.55, -5.5);
    glRotatef(60.0, 1.0, 1.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.22, 0.22, 0.75, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//palm_right
void s5_right_palm() {
    glLoadIdentity();
    glTranslatef(1.65, 0.05, -5.2);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.21, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Left_Hand
void s5_left_hand() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.55, 1.1, -6.0);
    glRotatef(-60, 0.0, 1.0, -0.5);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.25, 0.25, 0.75, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//forearms_left
void s5_left_forearm() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-1.2, 0.90, -5.5);
    glRotatef(-60, 0.0, 1.0, -0.5);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.22, 0.22, 0.70, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//palm_left
void s5_left_palm() {
    glLoadIdentity();
    glTranslatef(-1.85, 0.77, -5.2);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.21, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Lower body
void s5_lower_body() {
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat hand[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, hand);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(0.0, -1.2, -6.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.8, 0.6, 1.5, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Left_leg
void s5_left_leg() {
    glLoadIdentity();
    glTranslatef(-0.55, -1.5, -6.0);
    glScaled(1.5, 1.0, 1.0);
    glColor3ub(229, 95, 56);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat leg[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, leg);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Right_leg
void s5_right_leg() {
    glLoadIdentity();
    glTranslatef(0.55, -1.5, -6.0);
    glScaled(1.5, 1.0, 1.0);
    glColor3ub(229, 95, 56);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat leg[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, leg);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Joint
void s5_joint1() {
    glLoadIdentity();
    glTranslatef(1.05, 0.57, -5.6);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.19, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s5_joint2() {
    glLoadIdentity();
    glTranslatef(-1.2, 0.95, -5.6);
    glColor3ub(255, 75, 28);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(0.19, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 6
void s6_lower_body()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glTranslatef(0.0, 0.6, -6.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.8, 0.6, 1.5, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s6_left_leg()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.55, 0.5, -6.0);
    glScaled(1.5, 1.0, 1.0);
    glColor3ub(229, 95, 56);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s6_right_leg()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glTranslatef(0.55, 0.5, -6.0);
    glScaled(1.5, 1.0, 1.0);
    glColor3ub(229, 95, 56);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s6_ball1()
{
    //Center Ball (Gold ball)
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glTranslatef(0.0, s6_ball_y, -6.0f);
    glColor3ub(255, 220, 0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s6_ball2()
{
    //Left Ball (Blue ball)
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glTranslatef(-1.0, s6_ball_y, -6.0f);
    glColor3ub(40, 25, 255);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s6_ball3()
{
    //Right Ball (Original ball)
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 1.0, 1.0, -2.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glTranslatef(1.0, s6_ball_y, -6.0f);
    glColor3ub(255, 100, 0);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 7
void blue_ball() {
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
    glRotatef(bg_angle, 0.0, 0.0, 1.0);
    glColor3ub(40, 25, 255);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(2.0, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 8
void s8_body()
{
    //head
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat head[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, head);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s8_X, 0.3, -4.0);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //eye start
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat eye[] = { 1.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, eye);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.06, 0.28, -3.3);
    glColor3ub(255, 255, 255);
    glScaled(1.0, 0.6, 1.0);
    glutSolidSphere(0.05, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat eye2[] = { 1.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, eye2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.07, 0.28, -3.2);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.02, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //eye ends

    // Body start
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s8_X, 0.0, -4.0);
    glColor3ub(0, 193, 255);
    glutSolidSphere(0.2, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body2[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s8_X, -0.45, -4.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(0, 193, 255);
    gluCylinder(n, 0.2, 0.2, 0.45, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    //body end

    //lower body
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body3[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s8_X, -0.7, -4.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(0, 0, 220);
    gluCylinder(n, 0.17, 0.17, 0.25, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);


    //legs
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body4[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body4);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s8_X, -1.0, -4.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3ub(240, 184, 160);
    gluCylinder(n, 0.1, 0.1, 0.35, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);


    //shoes
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat body5[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, body5);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s8_X, -1.05, -4.0);
    glColor3ub(240, 0, 0);
    glScaled(1.0, 0.6, 1.0);
    glutSolidSphere(0.15, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s8_hand()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.02, -0.03, -3.3);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.07, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm2[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.02, -0.03, -3.3);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glColor3ub(240, 184, 160);
    gluCylinder(n, 0.07, 0.07, 0.4, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat arm3[] = { 2.0, 1.0, -1.0, -2.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, arm3);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(-0.02, -0.49, -3.3);
    glColor3ub(240, 184, 160);
    glutSolidSphere(0.07, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s8_court()
{
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(194, 197, 204);
    glVertex3f(-6.0, -1.5, -2.0);
    glVertex3f(-6.0, -1.0, -10.0);
    glVertex3f(8.0, -1.0, -10.0);
    glVertex3f(8.0, -1.5, -2.0);

    glColor3ub(200, 0, 0);
    glVertex3f(-5, -1.49, -2.5);
    glVertex3f(-5, -0.99, -8.5);
    glVertex3f(-4.8, -0.99, -8.5);
    glVertex3f(-4.8, -1.49, -2.5);

    glColor3ub(200, 0, 0);
    glVertex3f(-5, -0.99, -8.5);
    glVertex3f(-5, -0.99, -8.7);
    glVertex3f(8, -0.99, -8.7);
    glVertex3f(8, -0.99, -8.5);

    glEnd();
}

void s8_background()
{
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(25, 189, 255);
    glVertex3f(-10, 10, -12);
    glVertex3f(10, 10, -12);
    glVertex3f(10, -10, -12);
    glVertex3f(-10, -10, -12);

    glColor3ub(0, 200, 0);
    glVertex3f(-10, -1, -11.9);
    glVertex3f(10, -1, -11.9);
    glVertex3f(10, -6, -11.9);
    glVertex3f(-10, -6, -11.9);
    glEnd();
}

void no() {
    glLoadIdentity();
    glTranslatef(-1.5f, 0.5f, -7.0f);  // Move right and into the screen
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    //draw X

    glBegin(GL_POLYGON);                // Begin drawing the color cube with 6 quads
       // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(cx - 0.10f, cy, cz + 0.15f);
    glVertex3f(cx - 0.30f, cy + 0.20f, cz + 0.15f);
    glVertex3f(cx - 0.20f, cy + 0.30f, cz + 0.15f);
    glVertex3f(cx, cy + 0.10f, cz + 0.15f);
    glVertex3f(cx + 0.20f, cy + 0.30f, cz + 0.15f);
    glVertex3f(cx + 0.30f, cy + 0.20f, cz + 0.15f);
    glVertex3f(cx + 0.10f, cy + 0.0f, cz + 0.15f);
    glVertex3f(cx + 0.30f, cy - 0.20f, cz + 0.15f);
    glVertex3f(cx + 0.20f, cy - 0.30f, cz + 0.15f);
    glVertex3f(cx + 0.0f, cy - 0.10f, cz + 0.15f);
    glVertex3f(cx - 0.20f, cy - 0.30f, cz + 0.15f);
    glVertex3f(cx - 0.30f, cy - 0.20f, cz + 0.15f);
    glVertex3f(cx - 0.10f, cy - 0.0f, cz + 0.15f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(cx - 0.10f, cy, cz + 0.10f);
    glVertex3f(cx - 0.30f, cy + 0.20f, cz + 0.10f);
    glVertex3f(cx - 0.20f, cy + 0.30f, cz + 0.10f);
    glVertex3f(cx, cy + 0.10f, cz + 0.10f);
    glVertex3f(cx + 0.20f, cy + 0.30f, cz + 0.10f);
    glVertex3f(cx + 0.30f, cy + 0.20f, cz + 0.10f);
    glVertex3f(cx + 0.10f, cy, cz + 0.10f);
    glVertex3f(cx + 0.30f, cy - 0.20f, cz + 0.10f);
    glVertex3f(cx + 0.20f, cy - 0.30f, cz + 0.10f);
    glVertex3f(cx, cy - 0.10f, cz + 0.10f);
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
    glVertex3f(cx, cy + 0.10f, cz + 0.10f);
    glVertex3f(cx, cy + 0.10f, cz + 0.15f);
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
}

//Scene 9
void gold_ball() {
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
    glRotatef(bg_angle, 0.0, 0.0, 1.0);
    glColor3ub(255, 220, 0);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(2.0, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 11
void ori_ball() {
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
    glRotatef(bg_angle, 0.0, 0.0, 1.0);
    glColor3ub(255, 100, 0);
    //lights
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.2, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glutSolidSphere(2.0, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 12
void yes() {
    glLoadIdentity();
    glTranslatef(-1.5f, 0.5f, -7.0f);  // Move right and into the screen
    glRotatef(yRotated, 0.0, 1.0, 0.0);

    //draw tick
    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f);     // green
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.15f);
    glVertex3f(tx - 0.20, ty, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.15f);

    glColor3f(0.0f, 1.0f, 0.0f);     // green
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.05f);
    glVertex3f(tx, ty - 0.10f, 0.05f);
    glVertex3f(tx - 0.20, ty, 0.05f);
    glVertex3f(tx, ty - 0.25f, 0.05f);

    //topcover
    glColor3f(0.0f, 0.50f, 0.0f); //dark green
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.05f);
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.05f);

    glColor3f(0.0f, 0.50f, 0.0f); //dark green
    glVertex3f(tx - 0.20, ty, 0.05f);
    glVertex3f(tx - 0.20, ty, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.15f);
    glVertex3f(tx, ty - 0.10f, 0.05f);

    //bottom cover
    glColor3f(0.0f, 0.50f, 0.0f); //dark green
    glVertex3f(tx - 0.20, ty, 0.05f);
    glVertex3f(tx - 0.20, ty, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.05f);

    glColor3f(0.0f, 0.50f, 0.0f); //dark green
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.05f);
    glVertex3f(tx + 0.40f, ty + 0.30f, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.15f);
    glVertex3f(tx, ty - 0.25f, 0.05f);

    glEnd();  // End of drawing 
}

//Scene 13
void love1() {
    glLoadIdentity();
    glTranslatef(2.5, -1.0, -6.0);
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.0, 1.0, 0.5, 0.2 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glColor3f(1, 0, 0);
    glutSolidSphere(0.3, 100, 100);

    glLoadIdentity();
    glTranslatef(2.95, -1.0, -6.0);
    glutSolidSphere(0.3, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat love1[] = { 0.2, 0.2, 0.2, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, love1);
    glEnable(GL_LIGHT0);
    glTranslatef(2.76, -1.22, -6.0);
    glRotatef(70, 1.0, 0.0, 0.0);
    glutSolidCone(0.42, 0.3, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void love2() {
    glLoadIdentity();
    glTranslatef(-2.5, -1.0, -6.0);
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat dir[] = { 0.0, 1.0, 0.5, 0.2 };
    glLightfv(GL_LIGHT0, GL_POSITION, dir);
    glEnable(GL_LIGHT0);
    glColor3f(1, 0, 0);
    glutSolidSphere(0.3, 100, 100);

    glLoadIdentity();
    glTranslatef(-2.95, -1.0, -6.0);
    glutSolidSphere(0.3, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL); //cheat
    glEnable(GL_LIGHTING); //turn on lighting
    GLfloat love2[] = { 0.2, 0.2, 0.2, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, love2);
    glEnable(GL_LIGHT0);
    glTranslatef(-2.75, -1.22, -6.0);
    glRotatef(80, 1.0, 0.0, 0.0);
    glutSolidCone(0.42, 0.3, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 14
void s14_basketball()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { -1.0, 2.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s14_ballX2, s14_ballY2, -3.3);
    glColor3ub(255, 126, 0);
    glutSolidSphere(0.12, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s14_gold_basketball()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { -1.0, 2.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s14_G_ballX2, s14_G_ballY2, -3.3);
    glColor3ub(255, 220, 0);
    glutSolidSphere(0.12, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void s14_blue_basketball()
{
    glLoadIdentity();
    glEnable(GL_COLOR_MATERIAL);
    GLfloat basketball[] = { -1.0, 2.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, basketball);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glTranslatef(s14_B_ballX2, s14_B_ballY2, -3.3);
    glColor3ub(40, 25, 255);
    glutSolidSphere(0.12, 100, 100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

//Scene 15
void theEnd()
{
    //Alphabet T
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.7, 0.3, -1.0);
    glVertex3f(-0.5, 0.3, -1.0);
    glVertex3f(-0.5, 0.2, -1.0);
    glVertex3f(-0.7, 0.2, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.62, 0.3, -1.0);
    glVertex3f(-0.58, 0.3, -1.0);
    glVertex3f(-0.58, -0.3, -1.0);
    glVertex3f(-0.62, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.62, -0.3, -1.0);
    glVertex3f(-0.62, 0.2, -1.0);
    glVertex3f(-0.66, 0.2, -1.0);
    glVertex3f(-0.66, -0.2, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.7, 0.2, -1.0);
    glVertex3f(-0.7, 0.3, -1.0);
    glVertex3f(-0.73, 0.35, -1.0);
    glVertex3f(-0.73, 0.25, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.73, 0.35, -1.0);
    glVertex3f(-0.55, 0.35, -1.0);
    glVertex3f(-0.5, 0.3, -1.0);
    glVertex3f(-0.7, 0.3, -1.0);
    glEnd();

    //Alphabet H
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.45, 0.3, -1.0);
    glVertex3f(-0.4, 0.3, -1.0);
    glVertex3f(-0.4, -0.3, -1.0);
    glVertex3f(-0.45, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.45, 0.0, -1.0);
    glVertex3f(-0.3, 0.0, -1.0);
    glVertex3f(-0.3, -0.1, -1.0);
    glVertex3f(-0.45, -0.1, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.35, 0.3, -1.0);
    glVertex3f(-0.3, 0.3, -1.0);
    glVertex3f(-0.3, -0.3, -1.0);
    glVertex3f(-0.35, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.48, 0.35, -1.0);
    glVertex3f(-0.45, 0.3, -1.0);
    glVertex3f(-0.4, 0.3, -1.0);
    glVertex3f(-0.43, 0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.48, 0.35, -1.0);
    glVertex3f(-0.48, -0.23, -1.0);
    glVertex3f(-0.45, -0.3, -1.0);
    glVertex3f(-0.45, 0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.38, 0.35, -1.0);
    glVertex3f(-0.35, 0.3, -1.0);
    glVertex3f(-0.3, 0.3, -1.0);
    glVertex3f(-0.33, 0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.35, 0.3, -1.0);
    glVertex3f(-0.35, 0.0, -1.0);
    glVertex3f(-0.38, 0.03, -1.0);
    glVertex3f(-0.38, 0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.4, 0.0, -1.0);
    glVertex3f(-0.35, 0.0, -1.0);
    glVertex3f(-0.38, 0.03, -1.0);
    glVertex3f(-0.4, 0.03, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.38, -0.1, -1.0);
    glVertex3f(-0.35, -0.1, -1.0);
    glVertex3f(-0.35, -0.3, -1.0);
    glVertex3f(-0.38, -0.25, -1.0);
    glEnd();


    //Alphabet E
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.25, 0.3, -1.0);
    glVertex3f(-0.2, 0.3, -1.0);
    glVertex3f(-0.2, -0.3, -1.0);
    glVertex3f(-0.25, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.2, 0.3, -1.0);
    glVertex3f(-0.1, 0.3, -1.0);
    glVertex3f(-0.1, 0.2, -1.0);
    glVertex3f(-0.2, 0.2, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.2, 0.05, -1.0);
    glVertex3f(-0.1, 0.05, -1.0);
    glVertex3f(-0.1, -0.05, -1.0);
    glVertex3f(-0.2, -0.05, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.2, -0.2, -1.0);
    glVertex3f(-0.1, -0.2, -1.0);
    glVertex3f(-0.1, -0.3, -1.0);
    glVertex3f(-0.2, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.28, 0.35, -1.0);
    glVertex3f(-0.25, 0.3, -1.0);
    glVertex3f(-0.25, -0.3, -1.0);
    glVertex3f(-0.28, -0.25, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.48, 0.35, -1.0);
    glVertex3f(-0.45, 0.3, -1.0);
    glVertex3f(-0.4, 0.3, -1.0);
    glVertex3f(-0.43, 0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.28, 0.35, -1.0);
    glVertex3f(-0.25, 0.3, -1.0);
    glVertex3f(-0.1, 0.3, -1.0);
    glVertex3f(-0.13, 0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.2, 0.08, -1.0);
    glVertex3f(-0.2, 0.05, -1.0);
    glVertex3f(-0.1, 0.05, -1.0);
    glVertex3f(-0.13, 0.08, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.2, -0.17, -1.0);
    glVertex3f(-0.2, -0.2, -1.0);
    glVertex3f(-0.1, -0.2, -1.0);
    glVertex3f(-0.13, -0.17, -1.0);
    glEnd();

    //Alphabet E
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.05, 0.3, -1.0);
    glVertex3f(0.1, 0.3, -1.0);
    glVertex3f(0.1, -0.3, -1.0);
    glVertex3f(0.05, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.05, 0.3, -1.0);
    glVertex3f(0.2, 0.3, -1.0);
    glVertex3f(0.2, 0.2, -1.0);
    glVertex3f(0.05, 0.2, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.05, 0.05, -1.0);
    glVertex3f(0.2, 0.05, -1.0);
    glVertex3f(0.2, -0.05, -1.0);
    glVertex3f(0.05, -0.05, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.05, -0.2, -1.0);
    glVertex3f(0.2, -0.2, -1.0);
    glVertex3f(0.2, -0.3, -1.0);
    glVertex3f(0.05, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.02, 0.35, -1.0);
    glVertex3f(0.05, 0.3, -1.0);
    glVertex3f(0.05, -0.3, -1.0);
    glVertex3f(0.02, -0.25, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.02, 0.35, -1.0);
    glVertex3f(0.05, 0.3, -1.0);
    glVertex3f(0.2, 0.3, -1.0);
    glVertex3f(0.17, 0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.1, 0.08, -1.0);
    glVertex3f(0.1, 0.05, -1.0);
    glVertex3f(0.2, 0.05, -1.0);
    glVertex3f(0.17, 0.08, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.1, -0.17, -1.0);
    glVertex3f(0.1, -0.2, -1.0);
    glVertex3f(0.2, -0.2, -1.0);
    glVertex3f(0.17, -0.17, -1.0);
    glEnd();

    //Alphabet N
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.25, 0.3, -1.0);
    glVertex3f(0.3, 0.3, -1.0);
    glVertex3f(0.3, -0.3, -1.0);
    glVertex3f(0.25, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.35, 0.3, -1.0);
    glVertex3f(0.4, 0.3, -1.0);
    glVertex3f(0.4, -0.3, -1.0);
    glVertex3f(0.35, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.23, 0.35, -1.0);
    glVertex3f(0.25, 0.3, -1.0);
    glVertex3f(0.25, -0.3, -1.0);
    glVertex3f(0.23, -0.25, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.33, 0.35, -1.0);
    glVertex3f(0.35, 0.3, -1.0);
    glVertex3f(0.35, -0.3, -1.0);
    glVertex3f(0.33, -0.25, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.23, 0.35, -1.0);
    glVertex3f(0.25, 0.3, -1.0);
    glVertex3f(0.3, 0.3, -1.0);
    glVertex3f(0.27, 0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.33, 0.35, -1.0);
    glVertex3f(0.35, 0.3, -1.0);
    glVertex3f(0.4, 0.3, -1.0);
    glVertex3f(0.37, 0.35, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.25, 0.3, -1.0);
    glVertex3f(0.4, -0.2, -1.0);
    glVertex3f(0.4, -0.3, -1.0);
    glVertex3f(0.25, 0.2, -1.0);
    glEnd();

    //Alphabet D
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.45, 0.3, -1.0);
    glVertex3f(0.55, 0.3, -1.0);
    glVertex3f(0.65, 0.025, -1.0);
    glVertex3f(0.65, -0.025, -1.0);
    glVertex3f(0.55, -0.3, -1.0);
    glVertex3f(0.45, -0.3, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.2, -1.0);
    glVertex3f(0.55, 0.2, -1.0);
    glVertex3f(0.6, 0.025, -1.0);
    glVertex3f(0.6, -0.025, -1.0);
    glVertex3f(0.55, -0.2, -1.0);
    glVertex3f(0.5, -0.2, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.42, 0.35, -1.0);
    glVertex3f(0.45, 0.3, -1.0);
    glVertex3f(0.45, -0.3, -1.0);
    glVertex3f(0.42, -0.25, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.42, 0.35, -1.0);
    glVertex3f(0.45, 0.3, -1.0);
    glVertex3f(0.55, 0.3, -1.0);
    glVertex3f(0.52, 0.35, -1.0);
    glEnd();
}

//Display
void s1_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    mc_body();
    mc_hand();
    mc_basketball();
    mc_bBoard();
    mc_court();
    glFlush();
    glutSwapBuffers();
}

void s2_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    k_tree();
    k_streetlamp();
    kelefei();
    k_house();
    k_background();
    k_cloud();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void s3_display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    
    s3_basketball();
    mc_bBoard();
    mc_court();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void s4_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    s4_basketball(s4_ball_x, s4_ball_y);
    s4_blueSky();
    s4_combinedCloud();
    glFlush();
    glutSwapBuffers();
}

void s5_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    s5_head();
    s5_upper_body();
    s5_right_hand();
    s5_left_hand();
    s5_lower_body();
    s5_left_leg();
    s5_right_leg();
    glFlush();
    s5_joint1();
    s5_joint2();
    s5_left_forearm();
    s5_right_forearm();
    s5_left_palm();
    s5_right_palm();
    glutSwapBuffers();
}

void s6_display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    s6_ball1();
    s6_ball2();
    s6_ball3();
    s6_lower_body();
    s6_left_leg();
    s6_right_leg();
    glPopMatrix();
    gluLookAt(7.0, 7.0, 7.0, 0.0, 0.0, 0.0, 5.0, 1.0, 1.0);
    glFlush();
    glutSwapBuffers();
}

void s7_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    blue_ball();
    glFlush();
    glutSwapBuffers();
}

void s8_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    s8_body();
    s8_hand();
    no();
    s8_court();
    s8_background();
    glFlush();
    glutSwapBuffers();
}

void s9_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gold_ball();
    glFlush();
    glutSwapBuffers();
}

void s10_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    s8_body();
    s8_hand();
    no();
    s8_court();
    s8_background();
    glFlush();
    glutSwapBuffers();
}

void s11_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    ori_ball();
    glFlush();
    glutSwapBuffers();
}

void s12_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    s8_body();
    s8_hand();
    yes();
    s8_court();
    s8_background();
    glFlush();
    glutSwapBuffers();
}

void s13_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    s5_head();
    s5_upper_body();
    s5_right_hand();
    s5_left_hand();
    s5_lower_body();
    s5_left_leg();
    s5_right_leg();
    glFlush();
    s5_joint1();
    s5_joint2();
    s5_left_forearm();
    s5_right_forearm();
    s5_left_palm();
    s5_right_palm();
    if (visible) {
        love1();
        love2();
    }
    glutSwapBuffers();
}

void s14_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    s8_body();
    s8_hand();
    s14_basketball();
    s14_gold_basketball();
    s14_blue_basketball();
    s8_court();
    s8_background();
    glFlush();
    glutSwapBuffers();
}

void s15_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    theEnd();
    glFlush();
    glutSwapBuffers();
}

//Animation
void s1_animation(int)
{
    glutTimerFunc(0, s1_animation, 1);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);

    switch (state)
    {
    case 1:
        if (ballY > -0.8)
            ballY -= 0.03;
        else
            state = -1;
        break;
    case -1:
        if (ballY < -0.2)
            ballY += 0.03;
        else
            state = 1;
        break;
    }

    if (ballX < 1.5)
        ballX += 0.0085;
    if (mcX < 1.3)
        mcX += 0.01;
    if (mchandX < 1.58)
        mchandX += 0.0086;
    if (mcEyeX < 1.14)
        mcEyeX += 0.0084;
    if (mcEyeBX < 1.14)
        mcEyeBX += 0.0082;

    glutPostRedisplay();
}

void s2_animation(int) {
    glutTimerFunc(0, s2_animation, 2);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);
    t_y += 0.02;
    c_y += 0.017;

    c1_x += 0.02;
    c2_x += 0.02;

    if (c2_x > 2.0)
    {
        c2_x = -7.0;
    }

    glutPostRedisplay();
}

void s3_animation(int)
{
    glutTimerFunc(0, s3_animation, 3);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);

    if (s3_ballY < 1.0)
    {
        s3_ballX += 0.10;
        s3_ballY += 0.05;
    }
    if (s3_ballY >= 1.0)
    {
        s3_ballX -= 0.10;
        s3_ballY += 0.05;
    }

    glutPostRedisplay();
}

void s4_animation(int)
{
    glutTimerFunc(0, s4_animation, 4);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);

    //Cloud Animation
    cloud1_x_direction += 0.01;
    cloud2_x_direction += 0.02;
    cloud3_x_direction += 0.02;
    if (cloud2_x_direction > 3.0 && cloud1_x_direction > 3.0 && cloud3_x_direction > 3.0)
    {
        cloud2_x_direction = -4.0;
        cloud1_x_direction = -5.4;
        cloud3_x_direction = -3.0;
    }

    //Basketball Animation
    if (s4_ball_x >= -3.0 && s4_ball_x < -1.3)
    {
        s4_ball_x += 0.03;
        s4_ball_y += 0.05;
    }
    //After hit the first cloud, fall down
    else if (s4_ball_y > 0.2 && s4_ball_x < -0.3)
    {
        s4_ball_x += 0.06;
        s4_ball_y -= 0.04;
    }
    //Bounce back
    else if (s4_ball_y > 0.0 && s4_ball_x >= -0.3)
    {
        s4_ball_x += 0.05;
        s4_ball_y += 0.05;
    }

    glutPostRedisplay();
}

void s6_animation(int) {
    glutTimerFunc(0, s6_animation, 6);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);

    //Basketball Animation
    switch (state)
    {
    case 1:
        if (s6_ball_y < 0.2)
        {
            s6_ball_y += 0.1;
        }
        else
        {
            state = -1;
        }
        break;
    case -1:
        if (s6_ball_y > -1.0)
        {
            s6_ball_y -= 0.1;
        }
        else
        {
            state = 1;
        }
        break;
    }

    glutPostRedisplay();
}

void s7_s9_s11_animation(int) {
    glutTimerFunc(0, s7_s9_s11_animation, 7);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);
    bg_angle += 2;
    glutPostRedisplay();
}

void s8_s10_s12_animation(int) {
    glutTimerFunc(0, s8_s10_s12_animation, 8);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);
    yRotated += 2.2;
    glutPostRedisplay();
}

void s13_animation(int) {
    glutTimerFunc(500, s13_animation, 13);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);
    visible = !visible;
    glutPostRedisplay();
}

void s14_animation(int) {
    glutTimerFunc(1, s14_animation, 14);
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS);
    if (s14_ballX2 < -0.8)
    {
        s14_ballX2 += 0.011;
        s14_ballY2 -= 0.022;
    }

    if (s14_G_ballX2 < -0.5)
    {
        s14_G_ballX2 += 0.011;
        s14_G_ballY2 -= 0.022;
    }

    if (s14_B_ballX2 < -1.1)
    {
        s14_B_ballX2 += 0.011;
        s14_B_ballY2 -= 0.022;
    }

    glutPostRedisplay();
}

void HEX_reshape(GLsizei SCREEN_WIDTH, GLsizei SCREEN_HEIGHT) {
    if (SCREEN_HEIGHT == 0) SCREEN_HEIGHT = 1;
    GLfloat aspect = (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT;

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 20.0f);
}

void switchDisplay(int value) {
    if (value == 2)
    {
        glutDisplayFunc(s2_display);
        glutTimerFunc(0, s2_animation, 2);
        glutTimerFunc(15000, switchDisplay, 3);
    }
    
    else if (value == 3)
    {
        glutDisplayFunc(s3_display);
        glutTimerFunc(0, s3_animation, 3);
        glutTimerFunc(5000, switchDisplay, 4);
    }
    
    else if (value == 4)
    {
        glutDisplayFunc(s4_display);
        glutTimerFunc(0, s4_animation, 4);
        glutTimerFunc(22000, switchDisplay, 5);
    }
    
    else if (value == 5)
    {
        glutDisplayFunc(s5_display);
        glutTimerFunc(3000, switchDisplay, 6);
    }
    
    else if (value == 6)
    {
        glutDisplayFunc(s6_display);
        glutTimerFunc(0, s6_animation, 6);
        glutTimerFunc(3000, switchDisplay, 7);
    }
    else if (value == 7)
    {
        glutDisplayFunc(s7_display);
        glutTimerFunc(0, s7_s9_s11_animation, 7);
        glutTimerFunc(3000, switchDisplay, 8);
    }
    else if (value == 8)
    {
        glutDisplayFunc(s8_display);
        glutTimerFunc(0, s8_s10_s12_animation, 8);
        glutTimerFunc(3000, switchDisplay, 9);
    }
    else if (value == 9)
    {
        glutDisplayFunc(s9_display);
        glutTimerFunc(0, s7_s9_s11_animation, 7);
        glutTimerFunc(3000, switchDisplay, 10);
    }
    else if (value == 10)
    {
        glutDisplayFunc(s10_display);
        glutTimerFunc(0, s8_s10_s12_animation, 8);
        glutTimerFunc(3000, switchDisplay, 11);
    }
    else if (value == 11)
    {
        glutDisplayFunc(s11_display);
        glutTimerFunc(0, s7_s9_s11_animation, 7);
        glutTimerFunc(3000, switchDisplay, 12);
    }
    else if (value == 12)
    {
        glutDisplayFunc(s12_display);
        glutTimerFunc(0, s8_s10_s12_animation, 8);
        glutTimerFunc(3000, switchDisplay, 13);
    }
    else if (value == 13)
    {
        glutDisplayFunc(s13_display);
        glutTimerFunc(500, s13_animation, 13);
        glutTimerFunc(3000, switchDisplay, 14);
    }
    else if (value == 14)
    {
        glutDisplayFunc(s14_display);
        glutTimerFunc(0, s14_animation, 14);
        glutTimerFunc(23000, switchDisplay, 15);
    }
    else if (value == 15)
    {
        glutDisplayFunc(s15_display);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Cloud God & The Basketball");
    glutDisplayFunc(s1_display);
    glutReshapeFunc(HEX_reshape);
    glutTimerFunc(0,s1_animation,1);
    glutTimerFunc(8500,switchDisplay,2);
    initGL();
    glutMainLoop();
}
