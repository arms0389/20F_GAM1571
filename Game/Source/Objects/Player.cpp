#include "GamePCH.h"

#include "Objects/Player.h"

Player::Player(fw::GameCore* pGameCore, fw::vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader)
    : fw::GameObject( pGameCore, pos, pMesh, pShader )
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    float speed = 2.0f;

    fw::vec2 dir;

    if( m_pGameCore->GetFramework()->IsKeyDown( 'A' ) )
    {
        dir.x = -1;
    }
    if( m_pGameCore->GetFramework()->IsKeyDown( 'D' ) )
    {
        dir.x = 1;
    }
    if( m_pGameCore->GetFramework()->IsKeyDown( 'W' ) )
    {
        dir.y = 1;
    }
    if( m_pGameCore->GetFramework()->IsKeyDown( 'S' ) )
    {
        dir.y = -1;
    }

    m_Position.x += dir.x * speed * deltaTime;
    m_Position.y += dir.y * speed * deltaTime;
}
