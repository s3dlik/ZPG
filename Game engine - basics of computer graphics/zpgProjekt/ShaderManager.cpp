#include "ShaderManager.h"
ShaderManager* ShaderManager::instance = 0;

ShaderManager::ShaderManager(){}
//pøidání shaderu do vektoru

//Vrácení instance tøídy
ShaderManager* ShaderManager::getInstance()
{
	if (instance == 0) {
		instance = new ShaderManager();
	}
	return instance;
}
//Metoda, která vrací pointer na phong shader
AbstractShader* ShaderManager::getPhong(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = ShaderFactory::getInstance()->phongCreate(cam);
	return tmp;
	//return ShaderFactory::getInstance()->phongCreate(cam);
}
//Metoda, která vrací pointer na lambertuv shader
AbstractShader* ShaderManager::getLambert(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = ShaderFactory::getInstance()->lambertCreate(cam);

	return tmp;
}
//Metoda, která vrací pointer na konstatní shader
AbstractShader* ShaderManager::getConstant(Camera* cam)
{
	AbstractShader* tmp=nullptr;
	tmp = ShaderFactory::getInstance()->constantCreate(cam);
	return tmp;
	//return ShaderFactory::getInstance()->constantCreate(cam);;
}

AbstractShader* ShaderManager::getTexture(Camera* cam)
{
	return ShaderFactory::getInstance()->textureCreate(cam);;
}
//Metoda, která vrací pointer na shader, který zpracovává sky box
AbstractShader* ShaderManager::getTexSkyDom(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = ShaderFactory::getInstance()->skyboxTexCreate(cam);
	return tmp;
	//return ShaderFactory::getInstance()->skyboxTexCreate(cam);

}

