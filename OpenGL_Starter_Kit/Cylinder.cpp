#include "Cylinder.h"

Cylinder::Cylinder(glm::mat4 aTransformation, float aScale) : SceneNode(aTransformation, aScale) {

}

void Cylinder::draw(float scale) {
    GLUquadric *quad;
    quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_LINE);
    gluCylinder(quad, scale / 2, scale / 2, scale, 18, 18);
}