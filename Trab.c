#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// gcc -o main Trab.c -Wl,--copy-dt-needed-entries -lglut -lGL

void translac(GLfloat x, GLfloat y, GLfloat z) {
    GLfloat matriz[16];

    matriz[0] = 1.0f;  matriz[1] = 0.0f;  matriz[2] = 0.0f;  matriz[3] = 0.0f;
    matriz[4] = 0.0f;  matriz[5] = 1.0f;  matriz[6] = 0.0f;  matriz[7] = 0.0f;
    matriz[8] = 0.0f;  matriz[9] = 0.0f;  matriz[10] = 1.0f; matriz[11] = 0.0f;
    matriz[12] = x;    matriz[13] = y;    matriz[14] = z;    matriz[15] = 1.0f;

    glMultMatrixf(matriz);
}

void rotate(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    GLfloat matrix[16];

    float rad = angle * 3.14159265359 / 180.0f;
    float c = cos(rad);
    float s = sin(rad);
    float t = 1.0f - c;
    
    float tx = t * x;
    float ty = t * y;
    float tz = t * z;

    matrix[0]  = tx * x + c;     matrix[1]  = tx * y + s * z; matrix[2]  = tx * z - s * y; matrix[3]  = 0.0f; 
    matrix[4]  = ty * x - s * z; matrix[5]  = ty * y + c;     matrix[6]  = ty * z + s * x; matrix[7]  = 0.0f;
    matrix[8]  = tz * x + s * y; matrix[9]  = tz * y - s * x; matrix[10] = tz * z + c;     matrix[11] = 0.0f;
    matrix[12] = 0.0f;          matrix[13] = 0.0f;          matrix[14] = 0.0f;           matrix[15] = 1.0f;

    glMultMatrixf(matrix);
}

void scale(GLfloat sx, GLfloat sy, GLfloat sz) {
    GLfloat matrix[16];

    matrix[0] = sx;  matrix[1] = 0.0f; matrix[2] = 0.0f; matrix[3] = 0.0f;
    matrix[4] = 0.0f; matrix[5] = sy;  matrix[6] = 0.0f; matrix[7] = 0.0f;
    matrix[8] = 0.0f; matrix[9] = 0.0f; matrix[10] = sz; matrix[11] = 0.0f;
    matrix[12] = 0.0f; matrix[13] = 0.0f; matrix[14] = 0.0f; matrix[15] = 1.0f;

    glMultMatrixf(matrix);
}

void Frustum(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far){
    GLfloat matrix[16];
    
    matrix[0] = 2.0 * near / (right - left);     matrix[1] = 0;                               matrix[2] = 0;                                 matrix[3] = 0; 
    matrix[4] = 0;                               matrix[5] = 2.0 * near / (top - bottom);     matrix[6] = 0;                                 matrix[7] = 0;
    matrix[8] = (right + left) / (right - left); matrix[9] = (top + bottom) / (top - bottom); matrix[10] =-(far + near) / (far - near);      matrix[11] = -1; 
    matrix[12] = 0;                              matrix[13] = 0;                              matrix[14] = -2.0 * far * near / (far - near); matrix[15] = 0; 
    
    glMultMatrixf(matrix);
}

void Ortho(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    GLfloat matrix[16];

    matrix[0]  = 2.0 / (right - left);                 matrix[1]  = 0;                                 matrix[2]  = 0;                             matrix[3]  = 0;
    matrix[4]  = 0;                                    matrix[5]  = 2.0 / (top - bottom);              matrix[6]  = 0;                             matrix[7]  = 0;
    matrix[8]  = 0;                                    matrix[9]  = 0;                                 matrix[10] = -2.0 / (far - near);           matrix[11] = 0;
    matrix[12] = - (right + left) / (right - left);    matrix[13] = - (top + bottom) / (top - bottom); matrix[14] = - (far + near) / (far - near); matrix[15] = 1;

    glMultMatrixf(matrix);
}

void drawRectangle(float width, float height, float length) {
    glBegin(GL_QUADS);

    // Frente
    glNormal3f(0.0f, 0.0f, 1.0f); // Normal para a face frontal
    glVertex3f(-width/2, -height/2, length/2);
    glVertex3f(width/2, -height/2, length/2);
    glVertex3f(width/2, height/2, length/2);
    glVertex3f(-width/2, height/2, length/2);

    // Traseira
    glNormal3f(0.0f, 0.0f, -1.0f); // Normal para a face traseira
    glVertex3f(-width/2, -height/2, -length/2);
    glVertex3f(width/2, -height/2, -length/2);
    glVertex3f(width/2, height/2, -length/2);
    glVertex3f(-width/2, height/2, -length/2);

    // Inferior
    glNormal3f(0.0f, -1.0f, 0.0f); // Normal para a face inferior
    glVertex3f(-width/2, -height/2, -length/2);
    glVertex3f(width/2, -height/2, -length/2);
    glVertex3f(width/2, -height/2, length/2);
    glVertex3f(-width/2, -height/2, length/2);

    // Superior
    glNormal3f(0.0f, 1.0f, 0.0f); // Normal para a face superior
    glVertex3f(-width/2, height/2, -length/2);
    glVertex3f(width/2, height/2, -length/2);
    glVertex3f(width/2, height/2, length/2);
    glVertex3f(-width/2, height/2, length/2);

    // Lateral esquerda
    glNormal3f(-1.0f, 0.0f, 0.0f); // Normal para a face lateral esquerda
    glVertex3f(-width/2, -height/2, -length/2);
    glVertex3f(-width/2, height/2, -length/2);
    glVertex3f(-width/2, height/2, length/2);
    glVertex3f(-width/2, -height/2, length/2);

    // Lateral direita
    glNormal3f(1.0f, 0.0f, 0.0f); // Normal para a face lateral direita
    glVertex3f(width/2, -height/2, -length/2);
    glVertex3f(width/2, height/2, -length/2);
    glVertex3f(width/2, height/2, length/2);
    glVertex3f(width/2, -height/2, length/2);

    glEnd();
}

void display(void) {
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);

    float light_position[4] = {0, 0, 7, 0};
    float light_ambient[4] = {0.2, 0.2, 0.2, 1.0};
    float light_diffuse[4] = {0.7, 0.7, 0.7, 0.7};
    float light_specular[4] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    float material_ambient[4] = {0.1, 0.1, 0.1, 1.0};
    float material_diffuse[4] = {0.5, 0.5, 0.5, 1.0};
    float material_specular[4]= {0.4, 0.4, 0.4, 1.0};
    float material_shininess[1] = {10.0};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

    glLoadIdentity ();

    translac(0, -1, -12);
    rotate(-12,0,1,0);
    rotate(-45,1,0,0);

    glPushMatrix();
    drawRectangle(2,5,1);
    glPopMatrix();

    glPushMatrix();
    translac(0, -2, 0);
    drawRectangle(4,2,1);
    glPopMatrix();

    glPushMatrix();
    translac(3, -2.6, 0);
    rotate(-25,0,0,1);
    drawRectangle(3.1,2,1);
    glPopMatrix();

    glPushMatrix();
    translac(-3, -2.6, 0);
    rotate(25,0,0,1);
    drawRectangle(3.1,2,1);
    glPopMatrix();

    glPushMatrix();
    translac(-3, -2.6, 0);
    rotate(25,0,0,1);
    drawRectangle(3.9,1.7,1);
    glPopMatrix();

    glPushMatrix();
    translac(3, -2.6, 0);
    rotate(-25,0,0,1);
    drawRectangle(3.9,1.7,1);
    glPopMatrix();   

    glPushMatrix();
    translac(1, 3, 0);
    rotate(35,0,0,1);
    drawRectangle(2,2,1);
    glPopMatrix();

    glPushMatrix();
    translac(-1, 3, 0);
    rotate(-35,0,0,1);
    drawRectangle(3,2,1);
    glPopMatrix();

    float ground_ambient[4] = {0.1, 0.1, 0.1, 1.0};
    float ground_diffuse[4] = {0.1, 0.9, 0.1, 1.0};
    float ground_specular[4]= {0.1, 0.9, 0.1, 1.0};
    float ground_shininess[1] = {10.0};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ground_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ground_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ground_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, ground_shininess);

    glPushMatrix();
    translac(0, 2, -1);
    scale(15, 16, 1);
    glutSolidCube(1);
    glPopMatrix();

    glFlush ();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
   
    Frustum (-1.0, 1.0, -1.0, 1.0, 1.5, 25.0);
    //Ortho (-6.0, 6.0, -6.0, 6.0, 1.5, 20.0);
   
    glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (10, 10);
    glutCreateWindow ("C3 building 3d display");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}