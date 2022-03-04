#include "windowInicialization.h"

windowInicialization* windowInicialization::instance = 0;

windowInicialization::windowInicialization() {
	this->window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}
	this->window = glfwCreateWindow(1024,768, "ZPG sed0238", NULL, NULL);
	if (!this->window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glewExperimental = GL_TRUE;
	glewInit();

	this->getVersionInfo();

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);
}

void windowInicialization::error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

void windowInicialization::getVersionInfo()
{
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}

windowInicialization* windowInicialization::getInstance()
{
	if (instance == NULL) {
		instance = new windowInicialization();
	}
	return instance;
}

GLFWwindow* windowInicialization::getWindow()
{
	return this->window;
}
