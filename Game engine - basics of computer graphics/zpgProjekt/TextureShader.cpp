#include "TextureShader.h"

TextureShader::TextureShader(Camera* cam, const char* vertexFile, const char* fragmentFile) : AbstractShader(cam, vertexFile, fragmentFile)
{
}

void TextureShader::activateSh(glm::mat4 M,glm::vec4 color)
{
	glm::vec3 lightPos[4];
	lightPos[0] = LightsManager::getInstance()->getLights(0)->position;
	lightPos[1] = LightsManager::getInstance()->getLights(1)->position;
	lightPos[2] = LightsManager::getInstance()->getLights(2)->position;

	glm::vec4 lightColor[4];
	lightColor[0] = LightsManager::getInstance()->getLights(0)->color;
	lightColor[1] = LightsManager::getInstance()->getLights(1)->color;
	lightColor[2] = LightsManager::getInstance()->getLights(2)->color;

	glUseProgram(shaderProgram);
	m_camera->Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "cameraMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");

	glUniform3f(glGetUniformLocation(shaderProgram, "cameraPos"), m_camera->Position.x, m_camera->Position.y, m_camera->Position.z);
	glUniform3fv(glGetUniformLocation(shaderProgram, "lightPosition"), 3, glm::value_ptr(lightPos[0]));
	glUniform4fv(glGetUniformLocation(shaderProgram, "lightColor"), 3, glm::value_ptr(lightColor[0]));
	glUniform3f(glGetUniformLocation(shaderProgram, "lookingDirection"), m_camera->getOrientation().x, m_camera->getOrientation().y, m_camera->getOrientation().z);
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}

void TextureShader::set_texture(int id)
{
	GLuint uniformID = glGetUniformLocation(shaderProgram, "textureUnitID");
	glUniform1i(uniformID, id);
}

void TextureShader::activate()
{
	glUseProgram(shaderProgram);
}

void TextureShader::activateFlashLight(int mod)
{
	glUniform1i(glGetUniformLocation(shaderProgram, "flash"), mod);
}
