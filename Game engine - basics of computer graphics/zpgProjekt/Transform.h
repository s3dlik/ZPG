#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include "Bezier.h"
class Transform
{
private:
	glm::mat4 Mat;
	Bezier *bezier;
public:
	Transform();


	void rotate(float x, float y, float z);
	void translate(float x, float y, float z);
	void scale(float x, float y, float z);
	void sendMatrix(GLuint shader);
	void changeColor(GLfloat val1, GLfloat val2, GLfloat val3);
	void translateBezier(glm::mat4 B);
	void translateMotion(float x, float y, float z);
	glm::mat4 returnMatrix();
	void getTrans();

};

