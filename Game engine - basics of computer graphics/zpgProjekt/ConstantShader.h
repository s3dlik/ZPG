#pragma once
#include "AbstractShader.h"
#include "AbstractModel.h"
//T��da pro konstatn� shader, kter� d�d� ze t��dy AbstractShader, kde byla puu�ita virtu�ln� metoda activateSh
class ConstantShader : public AbstractShader
{
private:
public:
	ConstantShader(Camera* camera, const char* vertexFile, const char* fragmentFile);
	void activateSh(glm::mat4 M, glm::vec4 color);
	void activate();
};

