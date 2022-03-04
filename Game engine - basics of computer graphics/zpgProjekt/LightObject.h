#pragma once
#include <glm/ext/vector_float3.hpp>
#include "Model.h"
#include "Shader.h"
#include "AbstractModel.h"
#include "LightsManager.h"
#include "Light.h"
#include "AbstractShader.h"
//Zde jsem vyu�il ded�n� ze t��dy AbstractModel, kde vyu�iji metodu drawModel
class LightObject : public AbstractModel
{
public:
	LightObject(Model *model, AbstractShader *shader, glm::vec3 position, glm::vec4 color);
	void drawModel();
private:
	Light* light;
	glm::vec3 position;
	glm::vec4 color;
};

