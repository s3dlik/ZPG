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
#include "ShaderLoader.h"
#include "LightsManager.h"
using namespace std;
class Camera;
class Shader
{
private:
	//ShaderLoader* loader;
	Camera* m_camera;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	const char* vertex_shader;
	const char* fragment_shader;
	string loadFile(const char* fname);
	
public:
	Shader(Camera* camera, const char* vertexFile, const char *fragmentFile, std::string texture);
	Shader(Camera* camera, const char* vertexFile, const char* fragmentFile);
	void activate();
	void activate(glm::mat4 M);
	void activateSh(glm::mat4 M);
	void deleteShader();
	void compileErrors();
	void init_texture(std::string texture, int id);
	void init_skydome();
	void set_texture(int id);
	void objColorChange(glm::vec3 color);
	void shader_for_light(const char* name, glm::vec3 val);
};

