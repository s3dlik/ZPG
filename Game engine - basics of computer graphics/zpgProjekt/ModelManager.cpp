#include "ModelManager.h"
ModelManager* ModelManager::instance = 0;

ModelManager::ModelManager()
{

}


ModelManager* ModelManager::getInstance()
{
    if (instance == 0) {
        instance = new ModelManager();
    }
    return instance;
}

int ModelManager::returnCount()
{
    return this->modelVector.size();
}

void ModelManager::addModel(AbstractModel* mod)
{
    this->modelVector.push_back(mod);
}

AbstractModel* ModelManager::getModel(int mod)
{
    try
    {
        AbstractModel* tmp;
        tmp = this->modelVector.at(mod);
        return tmp;
    }
    catch (const std::exception&)
    {

    }
    return nullptr;
}

void ModelManager::removeModel(int id)
{
    try
    {
        this->modelVector.erase(this->modelVector.begin() + id);
    }
    catch (const std::exception&)
    {

    }
    
}
//creating only triangle, because you gave us only models with 3 coordinates
void ModelManager::createTriangle(const float points[], int size, AbstractShader* shader, int mode)
{
    AbstractModel* tmp = nullptr;
    tmp = ModelFactory::getInstance()->triangleCreate(new Model(mode, points,size), shader);

    this->addModel(tmp);
}

void ModelManager::createQuad(const float points[], int size, AbstractShader* shader, int mode)
{
    AbstractModel* tmp= nullptr;
    tmp = ModelFactory::getInstance()->quadCreate(new Model(mode, points, size), shader);

    this->addModel(tmp);
}

void ModelManager::createObj(string fileName, AbstractShader* shader, int id)
{
    AbstractModel* tmp= nullptr;
    tmp = ModelFactory::getInstance()->objCreate(new Model(fileName), shader, id);

    this->addModel(tmp);
}

void ModelManager::createLight(const float points[], int size, AbstractShader* shader, glm::vec3 position, glm::vec4 color)
{
    AbstractModel* tmp= nullptr;
    //tmp = new LightObject(model, shader, position, color);
    tmp = ModelFactory::getInstance()->lightCreate(new Model(1, points, size), shader, position, color);

    this->addModel(tmp);
}

void ModelManager::drawAllModels()
{
    
}

int ModelManager::returnLastId()
{
    return this->modelVector.size() - 1;
}
