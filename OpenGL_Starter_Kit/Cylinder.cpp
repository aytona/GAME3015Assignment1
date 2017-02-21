#include "Cylinder.h"

Cylinder::Cylinder(glm::mat4 aTransformation, float aScale) : SceneNode(aTransformation, aScale) {

}

void Cylinder::draw(float scale) {
    float slices = scale * 180;
    float radius = 0;
    if (radius > 0) {
        radius = 360 / slices * (M_PI / 180);
    }
    for (int i = 0; i < slices; i++) {
        float angle = i * radius;
        glBegin(GL_LINE_LOOP);
        glVertex3f(0, scale / 2, 0);
        glVertex3f(cos(i) * scale / 2, scale / 2, sin(i) * scale / 2);
        glVertex3f(cos(i + angle) * scale / 2, scale / 2, sin(i + angle) * scale / 2);
        glVertex3f(cos(i + angle) * scale / 2, -scale / 2, sin(i + angle) * scale / 2);
        glVertex3f(cos(i) * scale / 2, -scale / 2, sin(i) * scale / 2);
        glVertex3f(0, -scale / 2, 0);
        glEnd();
    }
}