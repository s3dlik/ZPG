#pragma once
#include <vector>
#include "Light.h"
//Manager, kter� zpracov�v� objekty sv�tla
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

