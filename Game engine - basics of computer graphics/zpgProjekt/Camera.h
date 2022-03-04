#pragma once
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
#include "AbstractShader.h"
//Tøída Camera je využíváaná na pohyb kamery
//Využita dopøedná deklarace na AbstractShader, stejné využití dopøedné deklarace ve tøídì AbstractShader, kvùli nutnosti používání kamery
class AbstractShader;
class Camera
{
private:
	std::vector<int> redModels;
public:
	AbstractShader* shader;
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

	// Prevents the camera from jumping around when first clicking left click
	bool firstClick = true;
	bool firstClickLeftClick = true;
	bool isNotRed = true;
	
	// Stores the width and height of the window
	int width;
	int height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = 0.1f;
	float sensitivity = 100.0f;

	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);

	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);
	Camera() {}
	glm::vec3 getOrientation();
	// Updates and exports the camera matrix to the Vertex Shader
	void Matrix(float FOVdeg, float nearPlane, float farPlane, GLuint& shader, const char* uniform);
	// Handles camera inputs
};

