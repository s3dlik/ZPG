#pragma once
#include <glm/ext/vector_float3.hpp>
#include "Model.h"
#include "Shader.h"
#include "AbstractModel.h"
#include "LightsManager.h"
#include "Light.h"
#include "AbstractShader.h"
//Zde jsem využil dedìní ze tøídy AbstractModel, kde využiji metodu drawModel
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

