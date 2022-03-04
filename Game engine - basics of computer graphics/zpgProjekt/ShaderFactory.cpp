#include "ShaderFactory.h"
ShaderFactory* ShaderFactory::instance = 0;
ShaderFactory::ShaderFactory(){}
ShaderFactory* ShaderFactory::getInstance()
{
	if (instance == 0) {
		instance = new ShaderFactory();
	}
	return instance;
}
//Shader pro phonga
AbstractShader* ShaderFactory::phongCreate(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = new PhongShader(cam, "phong.vertex", "phong.fragment");
	return tmp;
	//return new Shader(cam, "phong.vertex", "phong.fragment");
}
//Shader pro lamberta
AbstractShader* ShaderFactory::lambertCreate(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = new LambertShader(cam, "lambert.vertex", "lambert.fragment");
	return tmp;
	//return new Shader(cam, "lambert.vertex", "lambert.fragment");
}
//Shader pro constantní
AbstractShader* ShaderFactory::constantCreate(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = new ConstantShader(cam, "constant.vertex", "constant.fragment");
	return tmp;
	//return new Shader(cam, "constant.vertex", "constant.fragment");
}
//Shader pro textury zvláštì, již nevyužíváno, ale lze použít
AbstractShader* ShaderFactory::textureCreate(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = new TextureShader(cam, "texture.vertex", "texture.fragment");
	return tmp;
	//return new Shader(cam, "texture.vertex", "texture.fragment");
}
//Shader pro na vytvoøení textury pro sky box
AbstractShader* ShaderFactory::skyboxTexCreate(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = new TextureShader(cam, "sky.vertex", "sky.fragment");
	return tmp;
	//return new Shader(cam, "sky.vertex", "sky.fragment");
}

