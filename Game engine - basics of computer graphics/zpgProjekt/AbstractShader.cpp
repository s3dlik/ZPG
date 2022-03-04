#include "AbstractShader.h"
//Metoda na naètení souboru .vertex a .fragment
string AbstractShader::loadFile(const char* fname)
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
//Konstruktor, který zpracovává naètený vertex a fragment file a taky má pointer na tøídu kamery
AbstractShader::AbstractShader(Camera* camera, const char* vertexFile, const char* fragmentFile) : m_camera(camera)
{
	m_camera->shader = this;

	printf("Shader::loadShader %s %s \n", vertexFile, fragmentFile);
	string vertexShaderStr = loadFile(vertexFile);
	string fragmentShaderStr = loadFile(fragmentFile);
	int vertex_len = vertexShaderStr.length();
	int fragment_len = fragmentShaderStr.length();

	if (vertexShaderStr.empty()) printf("Vertex shader (file) is empty!\n");
	if (fragmentShaderStr.empty()) printf("Fragment shader (file) is empty!\n");

	vertex_shader = vertexShaderStr.c_str();
	fragment_shader = fragmentShaderStr.c_str();

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

	if (strlen(log) > 0 || strlen(log1) > 0) {
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

void AbstractShader::compileErrors()
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
//Nastavení ID textury pro objekt
void AbstractShader::set_texture(int id)
{
	GLuint uniformID = glGetUniformLocation(shaderProgram, "textureUnitID");
	glUniform1i(uniformID, id);
}
//Metoda na poslání barvy do fragmentu
void AbstractShader::objColorChange(glm::vec3 color)
{
	glUniform3f(glGetUniformLocation(shaderProgram, "colour"), color.x, color.y, color.z);
}
//Metoda za poslání true nebo false (1/0) do fragmentu, po stisknutí tlaèítka F, zda má svítit baterka nebo ne
void AbstractShader::activateFlashLight(int mod)
{
	glUniform1i(glGetUniformLocation(this->shaderProgram, "flashValue"), mod);
}
