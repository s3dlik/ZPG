#include "LightObject.h"
//Konstruktor tøídy LightObjekt, nastavuji zde pointer na model, na shader, nastavuji zde pozici svìtla a barvu
//využiji rovnou pøidání svìtla do vektoru a také již nastavení pozice, skrze zavolání konstruktoru ze tøídy Light
LightObject::LightObject(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 color)
{
	this->model = model;
	this->shader = shader;
	this->position = position;
	this->trans = new Transform();
	this->color = color;
	this->light = new Light(position, color);
	this->trans->translate(position.x, position.y, position.z);
	LightsManager::getInstance()->addLight(this->light);
}
//Podìdìlá virtuální funkce z AbstractModel, kde aktivují aktuální matici a pøiøadím si ke svìtlu barvu. Kde následnì ve funkci tuto barvu posílám do fragment shaderu
//Nabinduji si VAO a vykreslím objekty s velikostí získaných bodù

void LightObject::drawModel()
{
	shader->activateSh(this->trans->returnMatrix(), this->color);

	model->setObjects();
	glDrawArrays(GL_QUADS, 0, model->sizeArr);
}
