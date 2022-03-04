#pragma once
#include "Camera.h"
#include <GL/glew.h>
//Include GLFW  
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "windowInicialization.h"
class Controller
{
private:
	int flash = 0;
	Camera* cam;
	GLFWwindow* window;
	std::vector<int> redModels;
	windowInicialization* windowInit;
	
	//static Controller* instance;
public:
	//static Controller* getInstance();
	void inputsHandler();
	Controller(Camera* cam, GLFWwindow* window);
	Controller();
	bool firstClick = true;
	bool firstClickLeftClick = true;
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	float speed = 0.1f;
	float sensitivity = 100.0f;
	
	void init(Camera* cam, GLFWwindow* window);
	void keyCall();
	void buttonCall();
	void windowCall();
};

