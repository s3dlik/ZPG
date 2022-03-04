#pragma once
#include "AbstractShader.h"
#include "AbstractModel.h"
//Tøída pro konstatní shader, která dìdí ze tøídy AbstractShader, kde byla puužita virtuální metoda activateSh
class ConstantShader : public AbstractShader
{
private:
public:
	ConstantShader(Camera* camera, const char* vertexFile, const char* fragmentFile);
	void activateSh(glm::mat4 M, glm::vec4 color);
	void activate();
};

