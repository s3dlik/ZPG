#pragma once
#include "AbstractShader.h"
class CubemapTexture : public AbstractShader
{public:
	CubemapTexture(Camera* camera, const char* vertexFile, const char* fragmentFile);
	void activateSh(glm::mat4 M);
};

