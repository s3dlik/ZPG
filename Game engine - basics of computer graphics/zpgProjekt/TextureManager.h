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
#include <vector>
using namespace std;
class TextureManager
{
private:
	TextureManager();
	static TextureManager* instance;
	vector<int> tex;
public:
	static TextureManager *getInstance();
	void init_texture(std::string fileName, int id);
	void init_cubemap(const char* xpos, const char *xneg, const char* ypos, const char* yneg, const char* zpos, const char *zneg, int id);
	void set_texture(int id);
};

