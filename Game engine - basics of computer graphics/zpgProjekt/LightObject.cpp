#include "LightObject.h"
//Konstruktor t��dy LightObjekt, nastavuji zde pointer na model, na shader, nastavuji zde pozici sv�tla a barvu
//vyu�iji rovnou p�id�n� sv�tla do vektoru a tak� ji� nastaven� pozice, skrze zavol�n� konstruktoru ze t��dy Light
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
//Pod�d�l� virtu�ln� funkce z AbstractModel, kde aktivuj� aktu�ln� matici a p�i�ad�m si ke sv�tlu barvu. Kde n�sledn� ve funkci tuto barvu pos�l�m do fragment shaderu
//Nabinduji si VAO a vykresl�m objekty s velikost� z�skan�ch bod�

void LightObject::drawModel()
{
	shader->activateSh(this->trans->returnMatrix(), this->color);

	model->setObjects();
	glDrawArrays(GL_QUADS, 0, model->sizeArr);
}
