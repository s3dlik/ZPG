#pragma once
#include "AbstractShader.h"
#include "AbstractModel.h"
class TextureShader : public AbstractShader
{
public:
	TextureShader(Camera* cam, const char* vertexFile, const char* fragmentFile);
	void activateSh(glm::mat4 M, glm::vec4 color);
	void set_texture(int id);
	void activate();
	void activateFlashLight(int mod);
};

