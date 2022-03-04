#pragma once
#include "AbstractModel.h"
#include "AbstractShader.h"
class Quad : public AbstractModel
{
public:
	Quad(Model *model, AbstractShader*shader);
	void drawModel();
};

