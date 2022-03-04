#pragma once
#include "AbstractModel.h"
#include "Transform.h"
#include "Model.h"
#include "AbstractShader.h"
class Triangle: public AbstractModel
{
public:
	Triangle(Model * model, AbstractShader* shader);
	void drawModel();
};

