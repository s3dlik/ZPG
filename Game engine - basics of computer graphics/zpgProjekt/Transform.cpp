#include "Transform.h"

Transform::Transform()
{
	this->Mat = glm::mat4(1.0f);
	
}


void Transform::rotate(float x, float y, float z)
{
	this->Mat = glm::rotate(this->Mat, glm::radians(x), glm::vec3(1, 0, 0));
	this->Mat = glm::rotate(this->Mat, glm::radians(y), glm::vec3(0, 1, 0));
	this->Mat = glm::rotate(this->Mat, glm::radians(z), glm::vec3(0, 0, 1));
}

void Transform::translate(float x, float y, float z)
{
	this->Mat = glm::translate(this->Mat, glm::vec3(x, y, z));
}

void Transform::scale(float x, float y, float z)
{
	this->Mat = glm::scale(Mat, glm::vec3(x, y, z));
}

void Transform::sendMatrix(GLuint shader)
{
	int medoloc = glGetUniformLocation(shader, "modelMatrix");
	glUniformMatrix4fv(medoloc, 1, GL_FALSE, &Mat[0][0]);
}

void Transform::changeColor(GLfloat  val1, GLfloat  val2, GLfloat  val3)
{
	
}

void Transform::translateBezier(glm::mat4 B)
{
	this->Mat = glm::translate(glm::mat4(1.0), glm::vec3(Bezier::getInstance()->move(B).x, Bezier::getInstance()->move(B).y, Bezier::getInstance()->move(B).z));
}

void Transform::translateMotion(float x, float y, float z)
{
	this->Mat = glm::translate(glm::mat4(1.0),glm::vec3(x, y, z));
}

glm::mat4 Transform::returnMatrix()
{
	return this->Mat;
}

void Transform::getTrans()
{
	this->Mat = glm::mat4(1.0f);
}
