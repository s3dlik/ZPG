#pragma once
#include "AbstractShader.h"
#include "AbstractModel.h"
class PhongShader : public AbstractShader
{
public:
	PhongShader(Camera* cam, const char* vertexFile, const char* fragmentFile);
	void activateSh(glm::mat4 M, glm::vec4 color);
	void activate();
	void activateFlashLight(int mod);
};

