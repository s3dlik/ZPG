#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>  
#include "Shader.h"
#include "Transform.h"
// Tøída model si drží informace ohlednì modelu, a spouští VAO a VBO
class Model
{
private:
	GLuint VAO;
	float points_arr[1000000];
public:
	Shader* shader;
	int indicesCnt;
	GLuint VBO;
	Model(int mode, const float points[], int size);
	Model(std::string fileName);
	void setObjects();
	int sizeArr;

};

