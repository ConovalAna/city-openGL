#include "Objects.h"

//Primitive Objects
void DisplayQuad(GLfloat* color, float x1, float y1, float z1, float x2, float y2, float z2){
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4fv(color);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);
    glEnd();
    glPopMatrix();
}

void DisplayCube(GLfloat* color, float x, float y, float z, float size) {
    glPushMatrix();
    glColor4fv(color);
    glTranslatef(x, y, z);
    glutSolidCube(size);
    glPopMatrix();
}

void DisplaySphere(GLfloat* color, float x, float y, float z, float size, int details) {
    glPushMatrix();
    glColor4fv(color);
    glTranslatef(x, y, z);
    glutSolidSphere(size, details, details);
    glPopMatrix();
}

void DisplayCone(GLfloat* color, float x, float y, float z, float size, float height, int details, int xRotation) {
    glPushMatrix();
    glColor4fv(color);
    glTranslatef(x, y, z);
    glRotatef(xRotation,0,0,1);
    glutSolidCone(size, height, details, details);
    glPopMatrix();
}