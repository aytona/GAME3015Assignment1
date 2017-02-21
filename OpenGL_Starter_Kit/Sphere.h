#pragma once

#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>



class Sphere : public SceneNode {
public:
    Sphere::Sphere(glm::mat4 transformation, float scale);
    Sphere::Sphere(glm::mat4 transformation, float radius, int rings, int sectors);
    void draw(float scale) override;


protected:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normals;
    std::vector<GLfloat> texcoords;
    std::vector<GLushort> indices;
};