#include "GamePCH.h"

#include "Objects/Player.h"
#include "Game.h"

Player::Player(fw::GameCore* pGameCore, std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader)
    : fw::GameObject( pGameCore, name, pos, pMesh, pShader )
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    float speed = 2.0f;

    vec2 dir;

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

    m_Position += dir * speed * deltaTime;

    // Deal with collision with the environment.
    {
        // Query Game for environment limits.
        //static_cast<Game*>( m_pGameCore )->

        // Apply those limits.
        if( m_Position.x > 8 )
        {
            m_Position.x = 8;
        }
    }
}
