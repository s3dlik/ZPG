#include "Shader.h"
int counter = 0;
string Shader::loadFile(const char* fname)
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


Shader::Shader(Camera* camera,const char* vertexFile, const char* fragmentFile, std::string texture) : m_camera(camera)
{
	
	printf("Shader::loadShader %s %s \n", vertexFile, fragmentFile);
	string vertexShaderStr = loadFile(vertexFile);
	string fragmentShaderStr = loadFile(fragmentFile);
	int vertex_len = vertexShaderStr.length();
	int fragment_len = fragmentShaderStr.length();

	if (vertexShaderStr.empty()) printf("Vertex shader (file) is empty!\n");
	if (fragmentShaderStr.empty()) printf("Fragment shader (file) is empty!\n");

	vertex_shader = vertexShaderStr.c_str();
	fragment_shader = fragmentShaderStr.c_str();
	/*
	ShaderLoader* loader = new ShaderLoader(vertexFile, fragmentFile);
	this->vertex_shader = loader->returnVert();
	this->fragment_shader = loader->returnFrag();
	*/
	
	init_texture(texture, counter);
	counter++;
	//init_skydome();
	//camera->shader = this;
	
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);

	char log[1024];
	glGetShaderInfoLog(fragmentShader, 1024, nullptr, log);
	char log1[1024];
	glGetShaderInfoLog(vertexShader, 1024, nullptr, log1);

	fprintf(stderr, "fragment error: \n", log);
	fprintf(stderr, "vertex error: \n", log1);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);


	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
Shader::Shader(Camera* camera, const char* vertexFile, const char* fragmentFile) : m_camera(camera)
{
	printf("Shader::loadShader %s %s \n", vertexFile, fragmentFile);
	string vertexShaderStr = loadFile(vertexFile);
	string fragmentShaderStr = loadFile(fragmentFile);
	int vertex_len = vertexShaderStr.length();
	int fragment_len = fragmentShaderStr.length();

	if (vertexShaderStr.empty()) printf("Vertex shader (file) is empty!\n");
	if (fragmentShaderStr.empty()) printf("Fragment shader (file) is empty!\n");

	vertex_shader = vertexShaderStr.c_str();
	fragment_shader = fragmentShaderStr.c_str();
	/*
	ShaderLoader* loader = new ShaderLoader(vertexFile, fragmentFile);
	this->vertex_shader = loader->returnVert();
	this->fragment_shader = loader->returnFrag();
	*/
	//camera->shader = this;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);

	char log[1024];
	glGetShaderInfoLog(fragmentShader, 1024, nullptr, log);
	char log1[1024];
	glGetShaderInfoLog(vertexShader, 1024, nullptr, log1);

	if (strlen(log) > 0 || strlen(log1)>0) {
		fprintf(stderr, "fragment error: %s\n", log);
		fprintf(stderr, "vertex error: %s\n", log1);
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);


	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
//not using anymore, I just left it here. It was used before, when I didnt need to send modelMatrix and cameraMatrix to shaders
void Shader::activate()
{
	glUseProgram(shaderProgram);
	//glm::mat4 M = glm::mat4(1.0f);
	//GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	//glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}
//not using anymore, I just left it here. It was used before, when I didnt need to send modelMatrix and cameraMatrix to shaders
void Shader::activate(glm::mat4 M)
{
	glUseProgram(shaderProgram);
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
}

void Shader::activateSh(glm::mat4 M)
{
	
	glm::vec3 lightPos[4];
	lightPos[0] = LightsManager::getInstance()->getLights(0)->position;
	lightPos[1] = LightsManager::getInstance()->getLights(1)->position;
	lightPos[2] = LightsManager::getInstance()->getLights(2)->position;
	lightPos[3] = glm::vec3(m_camera->Position.x, m_camera->Position.y, m_camera->Position.z);

	glm::vec4 lightColor[4];
	lightColor[0] = LightsManager::getInstance()->getLights(0)->color;
	lightColor[1] = LightsManager::getInstance()->getLights(1)->color;
	lightColor[2] = LightsManager::getInstance()->getLights(2)->color;
	lightColor[3] = glm::vec4(1.0, 1.0, 1.0, 1.0);
	
	glUseProgram(shaderProgram);
	m_camera->Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "cameraMatrix");
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	
	glUniform3f(glGetUniformLocation(shaderProgram, "cameraPos"), m_camera->Position.x, m_camera->Position.y, m_camera->Position.z);
	glUniform3fv(glGetUniformLocation(shaderProgram, "lightPosition"), 4, glm::value_ptr(lightPos[0]));
	glUniform4fv(glGetUniformLocation(shaderProgram, "lightColor"), 1, glm::value_ptr(lightColor[0]));
	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
	//glUniform4fv(glGetUniformLocation(shaderProgram, "lightColor"), 4, glm::value_ptr(lightColor[0]));
}

void Shader::deleteShader()
{
	glDeleteProgram(shaderProgram);
}

void Shader::compileErrors()
{
	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}
void Shader::init_texture(std::string texture, int id)
{
	glActiveTexture(GL_TEXTURE0+id);	

	string tex = "Textures/";
	string complet = tex +texture;
	const char* out = complet.c_str();
	GLuint textureID = SOIL_load_OGL_texture(out, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Shader::init_skydome()
{
	glActiveTexture(GL_TEXTURE0);
	GLuint textureID = SOIL_load_OGL_cubemap("Textures/posx.jpg","Textures/negx.jpg","Textures/posy.jpg","Textures/negy.jpg","Textures/posz.jpg","Textures/negz.jpg", SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
}

void Shader::set_texture(int id)
{
	GLuint uniformID = glGetUniformLocation(shaderProgram, "textureUnitID");
	glUniform1i(uniformID, id);
}

void Shader::objColorChange(glm::vec3 color)
{
	glUniform3f(glGetUniformLocation(shaderProgram, "colour"), color.x, color.y, color.z);
}

void Shader::shader_for_light(const char* name, glm::vec3 val)
{
	glUniform3f(glGetUniformLocation(shaderProgram, "lightColor"), 0.0,1.0,0.0);

}
