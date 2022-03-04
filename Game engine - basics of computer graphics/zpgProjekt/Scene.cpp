#include "Scene.h"
#include "ModelFactory.h"

Scene* Scene::instance = 0;


Scene* Scene::getInstance()
{
	if (instance == 0) {
		instance = new Scene();
	}
	return instance;
}
//Inicializace scény, kde si nastavím okno, vytvoøím instanci kamery a nastavím controller, který mi zpracovává jednotlivé pohyby
Scene::Scene()
{
	this->windowInit = windowInicialization::getInstance();
	this->window = windowInit->getWindow();
	this->_width = 1024;
	this->_height = 768;
	this->camera = new Camera(_width, _height, glm::vec3(-4.0f, 1.0f, 31.0f));
	this->controller = new Controller(camera, window);
}

//void Game::error_callback(int error, const char* description) { fputs(description, stderr); }
/*
void Game::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Game::window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

void Game::window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

void Game::window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void Game::cursor_callback(GLFWwindow* window, double x, double y) { printf("cursor_callback \n"); }

void Game::button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) {
		printf("button_callback [%d,%d,%d]\n", button, action, mode);
	} 

}*/
void Scene::run()
{
	float angle = 0.2f;

	TextureManager::getInstance()->init_cubemap("Textures/cubemap/posx.jpg", "Textures/cubemap/negx.jpg", "Textures/cubemap/posy.jpg", "Textures/cubemap/negy.jpg", "Textures/cubemap/posz.jpg", "Textures/cubemap/negz.jpg", 0);
	TextureManager::getInstance()->init_texture("building.png",1);
	TextureManager::getInstance()->init_texture("skydome.png", 2);
	TextureManager::getInstance()->init_texture("grass.png", 3);
	TextureManager::getInstance()->init_texture("zombie.png", 4);
	TextureManager::getInstance()->init_texture("tree.png", 5);
	TextureManager::getInstance()->init_texture("bake.png", 6);
	TextureManager::getInstance()->init_texture("cottage_diffuse.png", 7);


	ModelManager::getInstance()->createObj("Textures/skybox.obj", ShaderManager::getInstance()->getTexSkyDom(camera), 0);
	ModelManager::getInstance()->getModel(0)->letsTranform()->scale(100.0, 100.0, 100.0);

	ModelManager::getInstance()->createObj("Textures/building.obj", ShaderManager::getInstance()->getPhong(camera), 1);
	ModelManager::getInstance()->getModel(1)->letsTranform()->translate(-15.0, 0.0, 4.0);
	//ShaderManager::getInstance()->getPhong(camera);


	
	ModelManager::getInstance()->createObj("Textures/teren.obj", ShaderManager::getInstance()->getPhong(camera), 3);
	ModelManager::getInstance()->getModel(2)->letsTranform()->scale(0.75, 0.75, 0.75);

	//vytvoreni svetel, model, shader, position a barva
	ModelManager::getInstance()->createLight(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getConstant(camera), glm::vec3(0.0f, 8.0f, 15.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	ModelManager::getInstance()->createLight(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getConstant(camera), glm::vec3(20.0f, 8.0f, 15.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	ModelManager::getInstance()->createLight(sphere, sizeof(sphere) / sizeof(sphere[0]), ShaderManager::getInstance()->getConstant(camera), glm::vec3(-20.0f, 8.0f, 15.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	

	
	ModelManager::getInstance()->createObj("Textures/zombie.obj", ShaderManager::getInstance()->getPhong(camera), 4);
	ModelManager::getInstance()->getModel(6)->letsTranform()->scale(2,2,2);
	ModelManager::getInstance()->getModel(6)->letsTranform()->translate(0.0, 0.0, 10.0);

	ModelManager::getInstance()->createObj("Textures/zombie.obj", ShaderManager::getInstance()->getPhong(camera), 4);
	ModelManager::getInstance()->getModel(7)->letsTranform()->scale(2, 2, 2);
	ModelManager::getInstance()->getModel(7)->letsTranform()->translate(0.0, 0.0, 0.0);

	//ModelManager::getInstance()->getModel(7)->letsTranform()->translate(0.0, 0.0, 4.0);

	ModelManager::getInstance()->createObj("Textures/maya.obj", ShaderManager::getInstance()->getLambert(camera), 3);
	ModelManager::getInstance()->getModel(8)->letsTranform()->translate(-15.0, -0.1, 17.0);
	ModelManager::getInstance()->getModel(8)->letsTranform()->scale(3, 3, 3);

	ModelManager::getInstance()->createObj("Textures/cottage_obj.obj", ShaderManager::getInstance()->getPhong(camera), 7);
	ModelManager::getInstance()->getModel(9)->letsTranform()->translate(20.0,0.0,0.0);
	ModelManager::getInstance()->getModel(9)->letsTranform()->scale(0.6, 0.6, 0.6);

	//ploty mezi baraky
	float tmp = -16.5;
	for (unsigned int i = 10; i < 15; i++)
	{
		ModelManager::getInstance()->createObj("Textures/zed.obj", ShaderManager::getInstance()->getPhong(camera), 6);
		ModelManager::getInstance()->getModel(i)->letsTranform()->rotate(0.0, 90.0, 0.0);
		ModelManager::getInstance()->getModel(i)->letsTranform()->translate(tmp, 0.0, 3.0);
		tmp += 8.25;
	}
	float tmp1 = -16.5;
	for (unsigned int i = 15; i < 20; i++)
	{
		ModelManager::getInstance()->createObj("Textures/zed.obj", ShaderManager::getInstance()->getPhong(camera), 6);
		ModelManager::getInstance()->getModel(i)->letsTranform()->rotate(0.0, 90.0, 0.0);
		ModelManager::getInstance()->getModel(i)->letsTranform()->translate(tmp1, 0.0, 6.0);
		tmp1 += 8.25;
	}
	float tmp2 = 10.0;
	//za barakem, barak vlevo
	for (unsigned int i = 20; i < 24; i++)
	{
		ModelManager::getInstance()->createObj("Textures/zed.obj", ShaderManager::getInstance()->getPhong(camera), 6);
		//ModelManager::getInstance()->getModel(i)->letsTranform()->rotate(0.0, 0.0, 0.0);
		ModelManager::getInstance()->getModel(i)->letsTranform()->translate(tmp2, 0.0, -20.09);
		tmp2 += 8.25;
	}
	//prava zed baraku vpravo
	float tmp3 = -16.5;
	for (unsigned int i = 24; i <29; i++)
	{
		ModelManager::getInstance()->createObj("Textures/zed.obj", ShaderManager::getInstance()->getPhong(camera), 6);
		ModelManager::getInstance()->getModel(i)->letsTranform()->rotate(0.0, 90.0, 0.0);
		ModelManager::getInstance()->getModel(i)->letsTranform()->translate(tmp3, 0.0, 39.0);
		tmp3 += 8.25;
	}

	float tmp4 = -1.0;
	//za barakem, barak pravo
	for (unsigned int i = 29; i < 33; i++)
	{
		ModelManager::getInstance()->createObj("Textures/zed.obj", ShaderManager::getInstance()->getPhong(camera), 6);
		//ModelManager::getInstance()->getModel(i)->letsTranform()->rotate(0.0, 0.0, 0.0);
		ModelManager::getInstance()->getModel(i)->letsTranform()->translate(tmp4, 0.0, -20.0);
		tmp4 -= 8.25;
	}

	float tmp5 = -16.5;
	for (unsigned int i = 33; i < 38; i++)
	{
		ModelManager::getInstance()->createObj("Textures/zed.obj", ShaderManager::getInstance()->getPhong(camera), 6);
		ModelManager::getInstance()->getModel(i)->letsTranform()->rotate(0.0, 90.0, 0.0);
		ModelManager::getInstance()->getModel(i)->letsTranform()->translate(tmp5, 0.0, -30.0);
		tmp5 += 8.25;
	}
	
	//glfwSetKeyCallback(window, key_callback);
	//glfwSetWindowSizeCallback(window, window_size_callback);
	//glfwSetCursorPosCallback(window, cursor_callback);
	//glfwSetMouseButtonCallback(window, button_callback);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glEnable(GL_TEXTURE_CUBE_MAP);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	float t = 0.5f;
	float delta = 0.01;
	glm::mat4x3 B = glm::mat4x3(glm::vec3(-18, 0, 0),
		glm::vec3(-17, 0, 20),
		glm::vec3(17, 0, 20),
		glm::vec3(15, 0, 0));


	glm::mat4x3 C = glm::mat4x3(glm::vec3(12, 0, 10),
		glm::vec3(16, 5, 10),
		glm::vec3(20, 5, 10),
		glm::vec3(24, 0, 10));

	while (!glfwWindowShouldClose(window)) {
		controller->inputsHandler();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		int width_new = this->_width;
		int height_new = this->_height;
		glfwGetWindowSize(window, &width_new, &height_new);
		
		if (width_new != this->_width || height_new != this->_height) {
		
			glViewport(0,0,width_new, height_new);
			this->_width = width_new;
			this->_height = height_new;
		}
		ModelManager::getInstance()->getModel(0)->letsTranform()->translateMotion(camera->Position.x, camera->Position.y, camera->Position.z);
		glDepthMask(GL_FALSE);
		ModelManager::getInstance()->getModel(0)->drawModel();
		glDepthMask(GL_TRUE);

		
		for (int i = 1; i < ModelManager::getInstance()->modelVector.size(); i++)
		{
			
			glStencilFunc(GL_ALWAYS, i, 0xFF);
			if (ModelManager::getInstance()->getModel(i) != nullptr) {
				
				//cout << "t = " << t << " P=[ " << p[0] << ", " << p[1] << ", " << p[2] << "]" << endl;

				ModelManager::getInstance()->getModel(i)->drawModel();
				
			}
		}
		ModelManager::getInstance()->getModel(6)->letsTranform()->translateBezier(B);
		ModelManager::getInstance()->getModel(7)->letsTranform()->translateBezier(C);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);
	
	glfwTerminate();
	exit(EXIT_SUCCESS);

	
}

