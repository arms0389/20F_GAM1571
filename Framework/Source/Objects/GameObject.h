#pragma once

#include "Math/Vector.h"

namespace fw {

class Mesh;
class ShaderProgram;
class GameCore;

class GameObject
{
public:
    GameObject(GameCore* pGameCore, vec2 pos, Mesh* pMesh, ShaderProgram* pShader);
    virtual ~GameObject();

    virtual void Update(float deltaTime);
    virtual void Draw();

protected:
    GameCore* m_pGameCore = nullptr;

    vec2 m_Position;

    Mesh* m_pMesh = nullptr;
    ShaderProgram* m_pShader = nullptr;
};

} // namespace fw
