#include "Quad.h"

Quad::Quad(Model* model, AbstractShader* shader)
{
	this->model = model;
	this->shader = shader;
	this->trans = new Transform();
}

void Quad::drawModel()
{
	shader->activateSh(trans->returnMatrix(), glm::vec4());
	model->setObjects();
	glDrawArrays(GL_QUADS, 0, model->sizeArr);
}
