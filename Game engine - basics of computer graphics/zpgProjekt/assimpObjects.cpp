#include "assimpObjects.h"

assimpObjects::assimpObjects(Model* model, AbstractShader* shader, int id)
{
	this->model = model;
	this->shader = shader;
	this->trans = new Transform();
	this->id = id;
}

void assimpObjects::drawModel()
{
	shader->activateSh(trans->returnMatrix(), glm::vec4());
	model->setObjects();

	shader->set_texture(this->id);
	TextureManager::getInstance()->set_texture(this->id);
	glDrawElements(GL_TRIANGLES, model->indicesCnt, GL_UNSIGNED_INT, NULL);
}
