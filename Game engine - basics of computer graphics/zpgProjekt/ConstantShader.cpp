#include "ConstantShader.h"

ConstantShader::ConstantShader(Camera* camera, const char* vertexFile, const char* fragmentFile) : AbstractShader(camera, vertexFile, fragmentFile)
{
}
//aktivování shaderu. Pøiøazuji zde barvu shaderu a posílám do fragmentu
void ConstantShader::activateSh(glm::mat4 M, glm::vec4 color)
{

	glm::vec4 lightColor[3];
	lightColor[0] = LightsManager::getInstance()->getLights(0)->color;
	lightColor[1] = LightsManager::getInstance()->getLights(1)->color;
	lightColor[2] = LightsManager::getInstance()->getLights(2)->color;

	glUseProgram(shaderProgram);
	m_camera->Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "cameraMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");

	glUniform3f(glGetUniformLocation(shaderProgram, "cameraPos"), m_camera->Position.x, m_camera->Position.y, m_camera->Position.z);

	glUniform4fv(glGetUniformLocation(shaderProgram, "lightColor"), 1, glm::value_ptr(color));
	
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}

void ConstantShader::activate()
{
	glUseProgram(shaderProgram);
}
