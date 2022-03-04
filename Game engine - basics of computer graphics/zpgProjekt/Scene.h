#pragma once
#include "windowInicialization.h"
#include "Model.h"
#include "Camera.h"
#include "sphere.h"
#include "suzi_flat.h"
#include "suzi_smooth.h"
#include "plain.h"
#include "Transform.h"
#include "AbstractModel.h"
#include "ModelManager.h"
#include "ModelFactory.h"
#include "ShaderLoader.h"
#include "ShaderFactory.h"
#include "ShaderManager.h"
#include "tree.h"
#include "bushes.h"
#include "gift.h"
#include "PlainTexture.h"
#include "skybox.h"
#include "TextureManager.h"
#include "glm/gtx/string_cast.hpp"
#include "glm/ext.hpp"
#include "Controller.h"
#include "AbstractShader.h"


class Scene
{
private:/*
	static void error_callback(int error, const char* description);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	*/
	windowInicialization* windowInit;
	GLFWwindow* window;
	Camera* camera;
	Controller* controller;
	Scene();
	int _width;
	int _height;
	static Scene* instance;
public:
	static Scene* getInstance();
	void run();
};

