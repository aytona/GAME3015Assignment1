#include "Cube.h"

Cube::Cube(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale) {

}

void Cube::draw(float scale) {
    // Front
    glBegin(GL_LINE_LOOP);
    glVertex3f(-scale / 2, -scale / 2, -scale / 2);
    glVertex3f(-scale / 2, scale / 2, -scale / 2);
    glVertex3f(scale / 2, scale / 2, -scale / 2);
    glVertex3f(scale / 2, -scale / 2, -scale / 2);
    glEnd();
    // Back
    glBegin(GL_LINE_LOOP);
    glVertex3f(-scale / 2, -scale / 2, scale / 2);
    glVertex3f(-scale / 2, scale / 2, scale / 2);
    glVertex3f(scale / 2, scale / 2, scale / 2);
    glVertex3f(scale / 2, -scale / 2, scale / 2);
    glEnd();
    // Left
    glBegin(GL_LINE_LOOP);
    glVertex3f(-scale / 2, -scale / 2, scale / 2);
    glVertex3f(-scale / 2, scale / 2, scale / 2);
    glVertex3f(-scale / 2, scale / 2, -scale / 2 );
    glVertex3f(-scale / 2, -scale / 2, -scale / 2);
    glEnd();
    // Right
    glBegin(GL_LINE_LOOP);
    glVertex3f(scale / 2, -scale / 2, -scale / 2);
    glVertex3f(scale / 2, scale / 2, -scale / 2);
    glVertex3f(scale / 2, scale / 2, scale / 2);
    glVertex3f(scale / 2, -scale / 2, scale / 2);
    glEnd();
    // Top
    glBegin(GL_LINE_LOOP);
    glVertex3f(-scale / 2, scale / 2, -scale / 2);
    glVertex3f(-scale / 2, scale / 2, scale / 2);
    glVertex3f(scale / 2, scale / 2, scale / 2);
    glVertex3f(scale / 2, scale / 2, -scale / 2);
    glEnd();
    // Bottom
    glBegin(GL_LINE_LOOP);
    glVertex3f(-scale / 2, -scale / 2, -scale / 2);
    glVertex3f(-scale / 2, -scale / 2, scale / 2);
    glVertex3f(scale / 2, -scale / 2, scale / 2);
    glVertex3f(scale / 2, - scale / 2, -scale / 2);
    glEnd();
}