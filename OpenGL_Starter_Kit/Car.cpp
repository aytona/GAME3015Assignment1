#include "Car.h"

Car::Car(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale) {

}

void Car::draw(float scale) {
    Cube body = Cube(glm::mat4(1.0), scale);
    body.setColor(0.0, 1.0, 0.0, 1.0);

    float wheel_offset = scale / 2.0f;
    Cylinder w1 = Cylinder(glm::translate(glm::mat4(1.0), glm::vec3(wheel_offset, wheel_offset, -wheel_offset)), scale / 3.0f);
    w1.setColor(0.0, 1.0, 0.0, 1.0);
    Cylinder w2 = Cylinder(glm::translate(glm::mat4(1.0), glm::vec3(wheel_offset, wheel_offset, wheel_offset - (scale / 3.0f))), scale / 3.0f);
    w2.setColor(0.0, 1.0, 0.0, 1.0);
    Cylinder w3 = Cylinder(glm::translate(glm::mat4(1.0), glm::vec3(wheel_offset, -wheel_offset, -wheel_offset)), scale / 3.0f);
    w3.setColor(0.0, 1.0, 0.0, 1.0);
    Cylinder w4 = Cylinder(glm::translate(glm::mat4(1.0), glm::vec3(wheel_offset, -wheel_offset, wheel_offset - (scale / 3.0f))), scale / 3.0f);
    w4.setColor(0.0, 1.0, 0.0, 1.0);

    body.addChild(&w1);
    body.addChild(&w2);
    body.addChild(&w3);
    body.addChild(&w4);

    body.render();
}