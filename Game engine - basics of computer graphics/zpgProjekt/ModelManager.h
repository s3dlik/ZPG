#pragma once
#include <vector>
#include "AbstractModel.h"
#include "ModelFactory.h"
#include "assimpObjects.h"
#include "AbstractShader.h"
using namespace std;
class ModelManager
{
private:
	
	//static ModelFactory* factory;
	ModelManager();
	static ModelManager* instance;
public:
	vector<AbstractModel*> modelVector;
	static ModelManager* getInstance();
	int returnCount();
	void addModel(AbstractModel*);
	AbstractModel* getModel(int mod);
	void removeModel(int id);
	void createTriangle(const float points[], int size, AbstractShader* AbstractShader, int mode);

	void createQuad(const float points[], int size, AbstractShader*shader, int mode);
	void createObj(string fileName, AbstractShader*shader, int id);
	void createLight(const float points[], int size, AbstractShader* shader, glm::vec3 position, glm::vec4 color);
	void drawAllModels();
	int returnLastId();
};

