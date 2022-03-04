#include "CubemapTexture.h"

CubemapTexture::CubemapTexture(Camera* camera, const char* vertexFile, const char* fragmentFile) : AbstractShader(camera, vertexFile, fragmentFile)
{
}

void CubemapTexture::activateSh(glm::mat4 M)
{
}
