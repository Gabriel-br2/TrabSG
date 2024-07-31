#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

//gcc -o squares squares.c -lglut -lGL

void display(void) {
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);

    float light_position[4] = {1, 1, 1, 0};
    float light_ambient[4] = {0.2, 0.2, 0.2, 1.0};
    float light_diffuse[4] = {0.7, 0.7, 0.7, 0.7};
    float light_specular[4] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    float material_ambient[4] = {0.1, 0.1, 0.1, 1.0};
    float material_diffuse[4] = {0.2, 0.2, 0.2, 1.0};
    float material_specular[4]= {0.2, 0.2, 0.1, 1.0};
    float material_shininess[1] = {10.0};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

    glLoadIdentity ();



    glTranslatef(0, 0, -10);
    glRotatef(-35,1,0,0);

    glPushMatrix();
    glScalef(2, 5, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -2, 0);
    glScalef(4, 2, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3, -2.7, 0);
    glRotatef(-25,0,0,1);
    glScalef(3, 2, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3, -2.7, 0);
    glRotatef(25,0,0,1);
    glScalef(3, 2, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 3, 0);
    glRotatef(35,0,0,1);
    glScalef(2, 2, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, 3, 0);
    glRotatef(-35,0,0,1);
    glScalef(3, 2, 1);
    glutSolidCube(1);
    glPopMatrix();



    glFlush ();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    //glOrtho (-6.0, 6.0, -6.0, 6.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (10, 10);
    glutCreateWindow ("C3 building 3d display");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}