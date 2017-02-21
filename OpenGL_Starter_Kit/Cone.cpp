#include "Cone.h"

Cone::Cone(glm::mat4 aTransformation, float aScale) : SceneNode(aTransformation, aScale) {

}

void Cone::draw(float scale) {
    glutWireCone(scale, scale * 2, scale * 25, scale * 25);
}