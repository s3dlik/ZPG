#pragma once
#include "AbstractShader.h"
#include "LightsManager.h"
class LambertShader : public AbstractShader
{
public:
	LambertShader(Camera* camera, const char* vertexFile, const char* fragmentFile);
	void activateSh(glm::mat4 M, glm::vec4 color);
	void activate();
	void activateFlashLight(int mod);
};

