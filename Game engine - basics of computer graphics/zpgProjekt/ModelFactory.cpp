#include "ModelManager.h"
#include "ModelFactory.h"

ModelFactory *ModelFactory::instance = 0;

ModelFactory::ModelFactory()
{

}

ModelFactory* ModelFactory::getInstance()
{
    if (instance == 0) {
        instance = new ModelFactory();
    }
    return instance;
}

AbstractModel* ModelFactory::quadCreate(Model *model, AbstractShader *shader)
{
    AbstractModel *tmp = nullptr;
    tmp = new Quad(model,shader);

    return tmp;
}

AbstractModel* ModelFactory::triangleCreate(Model *model, AbstractShader* shader)
{
    AbstractModel* tmp = nullptr;
    tmp = new Triangle(model,shader);
    
    return tmp;
}

AbstractModel* ModelFactory::objCreate(Model *model, AbstractShader* shader, int id)
{
    AbstractModel* tmp = nullptr;
    tmp = new assimpObjects(model, shader, id);

    return tmp;
}

AbstractModel* ModelFactory::lightCreate(Model* model, AbstractShader* shader, glm::vec3 position, glm::vec4 color)
{
    AbstractModel* tmp = nullptr;
    tmp = new LightObject(model, shader, position, color);
    return tmp;
}

