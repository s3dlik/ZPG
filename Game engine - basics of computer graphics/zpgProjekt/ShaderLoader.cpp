#include "ShaderLoader.h"

ShaderLoader::ShaderLoader(const char* vertexFile, const char* fragmentfile){
	this->vertexFile = vertexFile;
	this->fragmentFile = fragmentfile;
	loadShader();
}

string ShaderLoader::loadFile(const char* fname)
{
	ifstream file(fname);
	if (!file.is_open())
	{
		cout << "Unable to open file " << fname << endl;
		//exit(1);
	}
	std::stringstream fileData;
	fileData << file.rdbuf();
	file.close();
	return fileData.str();
}

void ShaderLoader::loadShader()
{
	printf("Shader::loadShader %s %s \n", vertexFile, fragmentFile);
	string vertexShaderStr = loadFile(vertexFile);
	string fragmentShaderStr = loadFile(fragmentFile);
	int vertex_len = vertexShaderStr.length();
	int fragment_len = fragmentShaderStr.length();

	if (vertexShaderStr.empty()) printf("Vertex shader (file) is empty!\n");
	if (fragmentShaderStr.empty()) printf("Fragment shader (file) is empty!\n");

	this->vert_shader = vertexShaderStr.c_str();
	this->frag_shader = fragmentShaderStr.c_str();
}

const char* ShaderLoader::returnVert()
{
	return this->vert_shader;
}

const char* ShaderLoader::returnFrag()
{
	return this->frag_shader;
}

