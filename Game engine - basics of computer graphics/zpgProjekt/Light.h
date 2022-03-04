#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
// Tøída Light, která má jednoduchý konstruktor, kde se nastaví pozice svìtla a barva
class Light
{
public:
	Light(glm::vec3 position, glm::vec4 color);
	glm::vec3 position;
	glm::vec4 color;
private:
	
};

