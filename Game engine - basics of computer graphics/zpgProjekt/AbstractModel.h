#pragma once
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
//Include GLEW

#include <GL/glew.h>
#include <GLFW/glfw3.h>  
#include <stdio.h>

#include "Transform.h"
#include "Model.h"
#include "Shader.h"
#include "LightsManager.h"
#include "AbstractShader.h"
//Abstraktn� t��da, kter� definuje, jak budou a co budou ostatn� t��dy d�dit.
class AbstractModel
{
protected:
	Model* model;
	AbstractShader* shader;
	Transform* trans;
	bool color = false;
	
public:
	glm::vec3 modelColor;
	//virtual void setModel() = 0;
	virtual void drawModel() = 0;
	Transform* letsTranform();
	//metoda na posilani barvy do shaderu. Vyu��v�m na zm�nu barvy p�i kliknut� na objekt
	void sendColor(glm::vec3 color);
};

