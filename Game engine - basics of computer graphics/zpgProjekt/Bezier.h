#pragma once


#include <glm/vec3.hpp> // glm::vec3
#include <glm/mat4x4.hpp> // glm::mat4


class Bezier
{
private:
	glm::mat4 A = glm::mat4(glm::vec4(-1.0, 3.0, -3.0, 1.0),
                  glm::vec4(3.0, -6.0, 3.0, 0),
                  glm::vec4(-3.0, 3.0, 0, 0),
                  glm::vec4(1, 0, 0, 0));
    float delta = 0.001;
    float t = 0.5f;
    glm::mat4 B;
    Bezier();
    static Bezier* instance;
public:
    static Bezier* getInstance();
    glm::vec3 move(glm::mat4 B);
};

