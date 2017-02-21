#include "Sphere.h"

Sphere::Sphere(glm::mat4 aTransformation, float aScale) : SceneNode(aTransformation, aScale) {

}

void Sphere::draw(float scale) {
    glutWireSphere(scale, scale * 25, scale * 25);
}