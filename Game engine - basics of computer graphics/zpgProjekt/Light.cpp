#include "Light.h"

Light::Light(glm::vec3 position, glm::vec4 color)
{
	this->color = color;
	this->position = position;
}
