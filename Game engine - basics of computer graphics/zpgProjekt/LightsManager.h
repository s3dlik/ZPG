#pragma once
#include <vector>
#include "Light.h"
//Manager, který zpracovává objekty svìtla
class LightsManager
{
private:
	static LightsManager* instance;
	LightsManager();
	std::vector<Light*> lights;
public:
	static LightsManager* getInstance();
	void addLight(Light *light);
	Light* getLights(int index);
};

