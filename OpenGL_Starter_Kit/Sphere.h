#pragma once

#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>

class Sphere : public SceneNode {
public:
    Sphere::Sphere(glm::mat4 transformation, float scale);
    void draw(float scale) override;
};