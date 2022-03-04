#include "Triangle.h"

Triangle::Triangle(Model* model, AbstractShader* shader)
{
	this->model = model;
	this->shader = shader;
	this->trans = new Transform();

}

void Triangle::drawModel()
{
	shader->activateSh(trans->returnMatrix(), glm::vec4());
	model->setObjects();
	glDrawArrays(GL_TRIANGLES, 0, model->sizeArr);
}
