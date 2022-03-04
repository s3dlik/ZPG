#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>  
#include <SOIL.h>
#include <assimp/Importer.hpp>// C++ importerinterface
#include <assimp/scene.h>// aiSceneoutputdata structure
#include <assimp/postprocess.h>// Post processingflags
#include <string.h> 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Camera.h"
using namespace std;
//Využita dopøedná deklarace tøídy Camera
//Udržuji zde informace ohlednì vertex shaderu, fragment shaderu, o jednotlivých ID shaderprogramu
class Camera;
class AbstractShader
{
protected:
	Camera* m_camera;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	const char* vertexFile;
	const char* fragmentFile;
	const char* vertex_shader;
	const char* fragment_shader;
	string loadFile(const char* fname);
public:
	virtual void activateSh(glm::mat4 M, glm::vec4 color) = 0;
	AbstractShader(Camera* camera, const char* vertexFile, const char* fragmentFile);
	void compileErrors();
	void set_texture(int id);
	void objColorChange(glm::vec3 color);
	virtual void activate() = 0;
	void activateFlashLight(int mod);
};

