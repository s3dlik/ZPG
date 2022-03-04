#pragma once
#include "Shader.h"
#include "Camera.h"
#include "ShaderFactory.h"
#include "AbstractShader.h"
// Tøída, která zpracovává shadery
class ShaderManager
{
private:
	static ShaderManager* instance;
	ShaderManager();

public:
	static ShaderManager* getInstance();
	AbstractShader* getPhong(Camera *cam);
	AbstractShader* getLambert(Camera* cam);
	AbstractShader* getConstant(Camera* cam);
	AbstractShader* getTexture(Camera* cam);
	AbstractShader* getTexSkyDom(Camera* cam);
};

