#include "LightsManager.h"
LightsManager* LightsManager::instance = 0;
LightsManager::LightsManager() {}
//Metoda na vrácení instance tøídy
LightsManager* LightsManager::getInstance()
{
	if (instance == 0) {
		instance = new LightsManager();
	}
	return instance;
}
//Metoda na pøidání svìtla do vektoru
void LightsManager::addLight(Light* light)
{
	this->lights.push_back(light);
}
//Metoda na vrácení svìtla z vektoru
Light* LightsManager::getLights(int index)
{
	return this->lights[index];
}
