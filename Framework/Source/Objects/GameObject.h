#pragma once

#include "Math/Vector.h"

namespace fw {

class Mesh;
class ShaderProgram;
class GameCore;

class GameObject
{
public:
    GameObject(GameCore* pGameCore, std::string name, vec2 pos, Mesh* pMesh, ShaderProgram* pShader);
    virtual ~GameObject();

    virtual void Update(float deltaTime);
    virtual void Draw();

    std::string GetName() { return m_Name; }

protected:
    GameCore* m_pGameCore = nullptr;

    std::string m_Name;

    vec2 m_Position;

    Mesh* m_pMesh = nullptr;
    ShaderProgram* m_pShader = nullptr;
};

} // namespace fw
