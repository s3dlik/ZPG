#pragma once
#include "AbstractModel.h"
#include "Transform.h"
#include "Model.h"
#include "TextureManager.h"
#include "AbstractShader.h"
class assimpObjects : public AbstractModel
{
private:
	int id;
public:
	assimpObjects(Model *model, AbstractShader *shader, int id);
	void drawModel();
};

