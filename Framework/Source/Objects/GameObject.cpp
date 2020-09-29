#include "FrameworkPCH.h"

#include "GameObject.h"
#include "Mesh.h"

namespace fw {

GameObject::GameObject(GameCore* pGameCore, vec2 pos, Mesh* pMesh, ShaderProgram* pShader)
{
    m_pGameCore = pGameCore;

    m_Position = pos;

    m_pMesh = pMesh;
    m_pShader = pShader;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw()
{
    m_pMesh->Draw( m_Position, m_pShader );
}

} // namespace fw
