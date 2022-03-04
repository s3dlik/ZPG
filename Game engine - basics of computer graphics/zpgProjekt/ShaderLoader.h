#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>  


#include <string.h> 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
class ShaderLoader
{
public:
	ShaderLoader(const char* vertexFile, const char* fragmentfile);
	string loadFile(const char* fname);
	void loadShader();
	const char* vert_shader;
	const char* frag_shader;

	const char* vertexFile;
	const char* fragmentFile;

	const char* returnVert();
	const char* returnFrag();
};

