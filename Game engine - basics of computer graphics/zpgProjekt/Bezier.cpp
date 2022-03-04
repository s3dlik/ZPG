#include "Bezier.h"
Bezier* Bezier::instance = 0;
Bezier::Bezier()
{
}

Bezier* Bezier::getInstance()
{
	if (instance == 0) {
		instance = new Bezier();
	}
	return instance;
}

glm::vec3 Bezier::move(glm::mat4 B)
{
	glm::vec4 parameters = glm::vec4(t * t * t, t * t, t, 1.0f);
	glm::vec3 p = parameters * this->A * glm::transpose(B);
	if (t >= 1.0f || t <= 0.0f) 
		delta *= -1;
	this->t += delta;
	return p;
}
