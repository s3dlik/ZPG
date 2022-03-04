#include "LightsManager.h"
LightsManager* LightsManager::instance = 0;
LightsManager::LightsManager() {}
//Metoda na vr�cen� instance t��dy
LightsManager* LightsManager::getInstance()
{
	if (instance == 0) {
		instance = new LightsManager();
	}
	return instance;
}
//Metoda na p�id�n� sv�tla do vektoru
void LightsManager::addLight(Light* light)
{
	this->lights.push_back(light);
}
//Metoda na vr�cen� sv�tla z vektoru
Light* LightsManager::getLights(int index)
{
	return this->lights[index];
}
