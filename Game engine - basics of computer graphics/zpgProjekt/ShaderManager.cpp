#include "ShaderManager.h"
ShaderManager* ShaderManager::instance = 0;

ShaderManager::ShaderManager(){}
//p�id�n� shaderu do vektoru

//Vr�cen� instance t��dy
ShaderManager* ShaderManager::getInstance()
{
	if (instance == 0) {
		instance = new ShaderManager();
	}
	return instance;
}
//Metoda, kter� vrac� pointer na phong shader
AbstractShader* ShaderManager::getPhong(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = ShaderFactory::getInstance()->phongCreate(cam);
	return tmp;
	//return ShaderFactory::getInstance()->phongCreate(cam);
}
//Metoda, kter� vrac� pointer na lambertuv shader
AbstractShader* ShaderManager::getLambert(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = ShaderFactory::getInstance()->lambertCreate(cam);

	return tmp;
}
//Metoda, kter� vrac� pointer na konstatn� shader
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
//Metoda, kter� vrac� pointer na shader, kter� zpracov�v� sky box
AbstractShader* ShaderManager::getTexSkyDom(Camera* cam)
{
	AbstractShader* tmp = nullptr;
	tmp = ShaderFactory::getInstance()->skyboxTexCreate(cam);
	return tmp;
	//return ShaderFactory::getInstance()->skyboxTexCreate(cam);

}

