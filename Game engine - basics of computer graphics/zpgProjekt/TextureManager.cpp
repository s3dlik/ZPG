#include "TextureManager.h"
#include <GL/glew.h>
TextureManager*TextureManager::instance = 0;
TextureManager::TextureManager()
{
}

TextureManager *TextureManager::getInstance()
{
	if (instance == NULL) {
		instance=  new TextureManager();
	}
	return instance;
}

void TextureManager::init_texture(std::string fileName, int id)
{
	glActiveTexture(GL_TEXTURE0 + id);

	string tex = "Textures/";
	string complet = tex + fileName;
	const char* out = complet.c_str();
	GLuint textureID = SOIL_load_OGL_texture(out, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	tex.push_back(textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void TextureManager::init_cubemap(const char* xpos, const char* xneg, const char* ypos, const char* yneg, const char* zpos, const char* zneg, int id)
{
	glActiveTexture(GL_TEXTURE0+id);

	GLuint textureID = SOIL_load_OGL_cubemap(xpos, xneg, ypos, yneg, zpos, zneg, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	tex.push_back(textureID);
	
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
}

void TextureManager::set_texture(int id)
{
	glActiveTexture(GL_TEXTURE0+id);
}
