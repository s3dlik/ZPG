#pragma once
#include "Shader.h"
#include "Camera.h"
#include "AbstractShader.h"
#include "ConstantShader.h"
#include "TextureShader.h"
#include "PhongShader.h"
#include "LambertShader.h"
//Tøída pro vytváøení specifického typu shaderu.
class ShaderFactory
{
private:
	static ShaderFactory* instance;
	ShaderFactory();
public:
	static ShaderFactory* getInstance();
	AbstractShader* phongCreate(Camera *cam);
	AbstractShader* lambertCreate(Camera* cam);
	AbstractShader* constantCreate(Camera* cam);
	AbstractShader* textureCreate(Camera* cam);
	AbstractShader* skyboxTexCreate(Camera* cam);
};

