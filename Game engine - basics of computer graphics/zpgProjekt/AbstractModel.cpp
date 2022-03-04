#include "AbstractModel.h"

Transform* AbstractModel::letsTranform()
{
	return this->trans;
}
//Metoda na zmìnu barvy pøi kliknutí na objekt
void AbstractModel::sendColor(glm::vec3 color)
{
	shader->activate();
	this->modelColor = color;
	if (this->color == false) {
		
		shader->objColorChange(color);
		this->color = true;
	}
	else {
		shader->objColorChange(glm::vec3(0.0,0.0,0.0));
		this->color = false;
	}
	
}
