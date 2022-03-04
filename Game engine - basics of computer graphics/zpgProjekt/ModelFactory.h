#pragma once
#include "ModelManager.h"
#include "ModelFactory.h"
#include "Triangle.h"
#include "Quad.h"
#include "assimpObjects.h"
#include "LightObject.h"

class ModelFactory
{
private:
	static ModelFactory* instance;
	ModelFactory();
public:
	static ModelFactory *getInstance();
	AbstractModel* quadCreate(Model *model, AbstractShader* shader);
	AbstractModel* triangleCreate(Model* model, AbstractShader* shader);
	AbstractModel* objCreate(Model *model, AbstractShader*shader, int id);
	AbstractModel* lightCreate(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 color);
};

