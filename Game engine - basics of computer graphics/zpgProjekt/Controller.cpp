#include "Controller.h"
#include "ModelFactory.h"
#include "ShaderManager.h"
#include <glm/gtx/string_cast.hpp>
//Controller* Controller::instance = 0;

Controller::Controller()
{
	this->windowInit = windowInicialization::getInstance();
	this->window = windowInit->getWindow();
}

void Controller::inputsHandler()
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		cam->Position += cam->speed * cam->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cam->Position += cam->speed * -glm::normalize(glm::cross(cam->Orientation, cam->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		cam->Position += cam->speed * -cam->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cam->Position += cam->speed * glm::normalize(glm::cross(cam->Orientation, cam->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{/*
		printf("F pressed 1\n");
		if (firstClickLeftClick) {
			firstClickLeftClick = false;
			printf("F pressed 2 \n");
			if (flash == 0) {
				ShaderManager::getInstance()->activateFlashLight(1);
				flash = 1;
				printf("flashlight ON\n");
			}
			else {
				ShaderManager::getInstance()->activateFlashLight(0);
				flash = 0;
				printf("flashlight OFF\n");
			}
		}
		*/
	}

	else if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
	{

		if (firstClickLeftClick) {
			firstClickLeftClick = false;


			double mousePosX;
			double mousePosY;
			glfwGetCursorPos(window, &mousePosX, &mousePosY);


			GLbyte color[4];
			GLfloat depth;
			GLuint index;

			int newy = cam->height - mousePosY;

			glReadPixels(mousePosX, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
			glReadPixels(mousePosX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
			glReadPixels(mousePosX, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
			printf("Clicked on pixel %f, %f, color %02hhx%02hhx%02hhx%02hhx, depth%f, stencil index % u\n", mousePosX, mousePosY, color[0], color[1], color[2], color[3], depth, index);

			if (index > 5) {
				if (ModelManager::getInstance()->getModel(index)->modelColor != glm::vec3(1.0, 0.0, 0.0)) {
					//std::cout << glm::to_string(ModelManager::getInstance()->getModel(index)->modelColor) << std::endl;
					if (dynamic_cast<AbstractModel*>(ModelManager::getInstance()->getModel(index))) {

						ModelManager::getInstance()->getModel(index)->sendColor(glm::vec3(1.0, 0.0, 0.0));
						redModels.push_back(index);
					}
				}
				else if (ModelManager::getInstance()->getModel(index)->modelColor == glm::vec3(1.0, 0.0, 0.0)) {
					ModelManager::getInstance()->getModel(index)->sendColor(glm::vec3(0.0, 0.0, 0.0));

					redModels.erase(std::remove(redModels.begin(), redModels.end(), index), redModels.end());
				}
			}
			else if (index == 2) {
				glm::vec3 screenX = glm::vec3(mousePosX, newy, depth);
				glm::vec4 viewPort = glm::vec4(0, 0, cam->width, cam->height);
				glm::vec3 pos = glm::unProject(screenX, cam->view, cam->projection, viewPort);
				//printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
				for (unsigned int i = 0; i < redModels.size(); i++)
				{
					ModelManager::getInstance()->getModel(redModels.at(i))->letsTranform()->translateMotion(pos.x, pos.y, pos.z);
				}
				
			}
		}
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);


		if (firstClick)
		{
			glfwSetCursorPos(window, (cam->width / 2), (cam->height / 2));
			firstClick = false;
		}

		double mousePosX;
		double mousePosY;
		glfwGetCursorPos(this->window, &mousePosX, &mousePosY);
		float rotationX = sensitivity * (float)(mousePosY - (cam->height / 2)) / cam->height;
		float rotationY = sensitivity * (float)(mousePosX - (cam->width / 2)) / cam->width;

		glm::vec3 newOrientation = glm::rotate(cam->Orientation, glm::radians(-rotationX), glm::normalize(glm::cross(cam->Orientation, cam->Up)));


		if (abs(glm::angle(newOrientation, cam->Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			cam->Orientation = newOrientation;
		}
		cam->Orientation = glm::rotate(cam->Orientation, glm::radians(-rotationY), cam->Up);


		glfwSetCursorPos(this->window, (cam->width / 2), (cam->height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
			//firstClickLeftClick = true;
			if (firstClickLeftClick) {
				firstClickLeftClick = false;


				double mousePosX;
				double mousePosY;
				glfwGetCursorPos(window, &mousePosX, &mousePosY);


				GLbyte color[4];
				GLfloat depth;
				GLuint index;
				int newy = cam->height - mousePosY;

				glReadPixels(mousePosX, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
				glReadPixels(mousePosX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
				glReadPixels(mousePosX, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
				//printf("index: %d", index);
				printf("Clicked on pixel %f, %f, color %02hhx%02hhx%02hhx%02hhx, depth%f, stencil index % u\n", mousePosX, mousePosY, color[0], color[1], color[2], color[3], depth, index);

				if (dynamic_cast<AbstractModel*>(ModelManager::getInstance()->getModel(index)) && index > 5)
				{
					ModelManager::getInstance()->removeModel(index);
					printf("%d\n", index);
					//ModelManager::getInstance()->getModel(index)->sendColor(glm::vec3(1.0,0.0,0.0));

				}
				else {
					glm::vec3 screenX = glm::vec3(mousePosX, newy, depth);
					glm::vec4 viewPort = glm::vec4(0, 0, cam->width, cam->height);
					glm::vec3 pos = glm::unProject(screenX, cam->view, cam->projection, viewPort);
					printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
					ModelManager::getInstance()->createObj("Textures/tree.obj", ShaderManager::getInstance()->getPhong(cam), 5);
					ModelManager::getInstance()->getModel(ModelManager::getInstance()->returnLastId())->letsTranform()->translate(pos.x, pos.y, pos.z);
					//ModelManager::getInstance()->getModel(ModelManager::getInstance()->returnLastId())->letsTranform()->scale(0.2, 0.2, 0.2);
				}

				/*if (index == 2) {
					glm::vec3 screenX = glm::vec3(mousePosX, newy, depth);
					glm::vec4 viewPort = glm::vec4(0, 0, width, height);
					glm::vec3 pos = glm::unProject(screenX, this->view, this->projection, viewPort);
					printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
					ModelManager::getInstance()->createObj("Textures/tree.obj", ShaderManager::getInstance()->getTexture(this), 5);
					ModelManager::getInstance()->getModel(ModelManager::getInstance()->returnLastId())->letsTranform()->translate(pos.x, pos.y, pos.z);
					ModelManager::getInstance()->getModel(ModelManager::getInstance()->returnLastId())->letsTranform()->scale(0.2,0.2,0.2);

				}*/
			}
		}
		else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
			this->firstClickLeftClick = true;
			this->firstClick = true;
		}
	}
}
Controller::Controller(Camera* cam, GLFWwindow* window)
{
	this->cam = cam;
	this->window = window;
}
/*
Controller* Controller::getInstance()
{
	if (instance == 0) {
		instance = new Controller();
	}
	return instance;
}
*/

void Controller::init(Camera* cam, GLFWwindow* window)
{
	this->cam = cam;
	this->window = window;
}

void Controller::keyCall()
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		cam->Position += cam->speed * cam->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cam->Position += cam->speed * -glm::normalize(glm::cross(cam->Orientation, cam->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		cam->Position += cam->speed * -cam->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cam->Position += cam->speed * glm::normalize(glm::cross(cam->Orientation, cam->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{

		if (firstClickLeftClick) {
			firstClickLeftClick = false;


			double mousePosX;
			double mousePosY;
			glfwGetCursorPos(window, &mousePosX, &mousePosY);


			GLbyte color[4];
			GLfloat depth;
			GLuint index;

			int newy = cam->height - mousePosY;

			glReadPixels(mousePosX, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
			glReadPixels(mousePosX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
			glReadPixels(mousePosX, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
			printf("Clicked on pixel %f, %f, color %02hhx%02hhx%02hhx%02hhx, depth%f, stencil index % u\n", mousePosX, mousePosY, color[0], color[1], color[2], color[3], depth, index);


		}
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
	{

		if (firstClickLeftClick) {
			firstClickLeftClick = false;


			double mousePosX;
			double mousePosY;
			glfwGetCursorPos(window, &mousePosX, &mousePosY);


			GLbyte color[4];
			GLfloat depth;
			GLuint index;

			int newy = cam->height - mousePosY;

			glReadPixels(mousePosX, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
			glReadPixels(mousePosX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
			glReadPixels(mousePosX, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
			printf("Clicked on pixel %f, %f, color %02hhx%02hhx%02hhx%02hhx, depth%f, stencil index % u\n", mousePosX, mousePosY, color[0], color[1], color[2], color[3], depth, index);

			if (index > 5) {
				if (ModelManager::getInstance()->getModel(index)->modelColor != glm::vec3(1.0, 0.0, 0.0)) {
					//std::cout << glm::to_string(ModelManager::getInstance()->getModel(index)->modelColor) << std::endl;
					if (dynamic_cast<AbstractModel*>(ModelManager::getInstance()->getModel(index))) {

						ModelManager::getInstance()->getModel(index)->sendColor(glm::vec3(1.0, 0.0, 0.0));
						redModels.push_back(index);
					}
				}
				else if (ModelManager::getInstance()->getModel(index)->modelColor == glm::vec3(1.0, 0.0, 0.0)) {
					ModelManager::getInstance()->getModel(index)->sendColor(glm::vec3(0.0, 0.0, 0.0));

					redModels.erase(std::remove(redModels.begin(), redModels.end(), index), redModels.end());
					ModelManager::getInstance()->getModel(index)->letsTranform()->scale(0.2, 0.2, 0.2);
				}
			}
			else if (index == 2) {
				glm::vec3 screenX = glm::vec3(mousePosX, newy, depth);
				glm::vec4 viewPort = glm::vec4(0, 0, cam->width, cam->height);
				glm::vec3 pos = glm::unProject(screenX, cam->view, cam->projection, viewPort);
				//printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
				for (unsigned int i = 0; i < redModels.size(); i++)
				{
					ModelManager::getInstance()->getModel(redModels.at(i))->letsTranform()->translateMotion(pos.x, pos.y, pos.z);
					ModelManager::getInstance()->getModel(index)->letsTranform()->scale(0.2, 0.2, 0.2);
				}
			}
		}
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		this->firstClickLeftClick = true;
		this->firstClick = true;
	}
}

void Controller::buttonCall()
{
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);


		if (firstClick)
		{
			glfwSetCursorPos(window, (cam->width / 2), (cam->height / 2));
			firstClick = false;
		}

		double mousePosX;
		double mousePosY;
		glfwGetCursorPos(this->window, &mousePosX, &mousePosY);
		float rotationX = sensitivity * (float)(mousePosY - (cam->height / 2)) / cam->height;
		float rotationY = sensitivity * (float)(mousePosX - (cam->width / 2)) / cam->width;

		glm::vec3 newOrientation = glm::rotate(cam->Orientation, glm::radians(-rotationX), glm::normalize(glm::cross(cam->Orientation, cam->Up)));


		if (abs(glm::angle(newOrientation, cam->Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			cam->Orientation = newOrientation;
		}
		cam->Orientation = glm::rotate(cam->Orientation, glm::radians(-rotationY), cam->Up);


		glfwSetCursorPos(this->window, (cam->width / 2), (cam->height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
			//firstClickLeftClick = true;
			if (firstClickLeftClick) {
				firstClickLeftClick = false;


				double mousePosX;
				double mousePosY;
				glfwGetCursorPos(window, &mousePosX, &mousePosY);


				GLbyte color[4];
				GLfloat depth;
				GLuint index;
				int newy = cam->height - mousePosY;

				glReadPixels(mousePosX, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
				glReadPixels(mousePosX, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
				glReadPixels(mousePosX, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
				//printf("index: %d", index);
				printf("Clicked on pixel %f, %f, color %02hhx%02hhx%02hhx%02hhx, depth%f, stencil index % u\n", mousePosX, mousePosY, color[0], color[1], color[2], color[3], depth, index);

				if (dynamic_cast<AbstractModel*>(ModelManager::getInstance()->getModel(index)) && index > 5)
				{
					ModelManager::getInstance()->removeModel(index);
					printf("%d\n", index);
					//ModelManager::getInstance()->getModel(index)->sendColor(glm::vec3(1.0,0.0,0.0));

				}
				else {
					glm::vec3 screenX = glm::vec3(mousePosX, newy, depth);
					glm::vec4 viewPort = glm::vec4(0, 0, cam->width, cam->height);
					glm::vec3 pos = glm::unProject(screenX, cam->view, cam->projection, viewPort);
					printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
					ModelManager::getInstance()->createObj("Textures/tree.obj", ShaderManager::getInstance()->getTexture(cam), 5);
					ModelManager::getInstance()->getModel(ModelManager::getInstance()->returnLastId())->letsTranform()->translate(pos.x, pos.y, pos.z);
					ModelManager::getInstance()->getModel(ModelManager::getInstance()->returnLastId())->letsTranform()->scale(0.2, 0.2, 0.2);
				}

				/*if (index == 2) {
					glm::vec3 screenX = glm::vec3(mousePosX, newy, depth);
					glm::vec4 viewPort = glm::vec4(0, 0, width, height);
					glm::vec3 pos = glm::unProject(screenX, this->view, this->projection, viewPort);
					printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
					ModelManager::getInstance()->createObj("Textures/tree.obj", ShaderManager::getInstance()->getTexture(this), 5);
					ModelManager::getInstance()->getModel(ModelManager::getInstance()->returnLastId())->letsTranform()->translate(pos.x, pos.y, pos.z);
					ModelManager::getInstance()->getModel(ModelManager::getInstance()->returnLastId())->letsTranform()->scale(0.2,0.2,0.2);

				}*/
			}
		}
		else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
			this->firstClickLeftClick = true;
			this->firstClick = true;
		}
	}
}

void Controller::windowCall()
{
	printf("resize %d, %d \n", cam->width, cam->height);
	glViewport(0, 0, cam->width, cam->height);
}
