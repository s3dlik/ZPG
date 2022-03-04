#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
// T��da Light, kter� m� jednoduch� konstruktor, kde se nastav� pozice sv�tla a barva
class Light
{
public:
	Light(glm::vec3 position, glm::vec4 color);
	glm::vec3 position;
	glm::vec4 color;
private:
	
};

