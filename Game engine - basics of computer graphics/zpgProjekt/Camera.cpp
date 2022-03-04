#include "Camera.h"
#include "ModelFactory.h"
#include "ShaderManager.h"
#include <glm/gtx/string_cast.hpp>
Camera::Camera(int width, int height, glm::vec3 position)
{
	this->Position = position;
	this->width = width;
	this->height = height;
}

glm::vec3 Camera::getOrientation()
{
	return this->Orientation;
}



void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, GLuint &shader, const char* uniform)
{
	//need to initialize them, otherwise they would be NULL
	//this->view = glm::mat4(1.0f);
	//glm::mat4 projection = glm::mat4(1.0f);

	this->view = glm::lookAt(Position, Position + Orientation, Up);
	// perspective
	this->projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, 0.1f, 200.0f);

	glUniformMatrix4fv(glGetUniformLocation(shader, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}

