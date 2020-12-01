#include "GamePCH.h"

#include "Objects/Player.h"
#include "Objects/PlayerController.h"
#include "Game.h"

Player::Player(fw::GameCore* pGameCore, PlayerController* pPlayerController, std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec4 color, fw::SpriteSheet* pSpriteSheet)
    : fw::GameObject( pGameCore, name, pos, pMesh, pShader, pTexture, color )
    , m_pPlayerController( pPlayerController )
{
    m_PlayerSprite = pSpriteSheet;
    m_SpriteInfo = m_PlayerSprite->GetSpriteInfo("Player/player_01");

    // "Player/player_05 - 07 are walking down
    // "Player/player_08 - 10 are walking up
    // "Player/player_17 - 19 are walking left
    // "Player/player_20 - 22 are walking right
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    SpriteName = "Player/player_";
    float speed = 2.0f;
    vec2 dir;

    

    if( m_pPlayerController->IsHeld( PlayerController::Mask::Up ) )
    {
        dir.y += 1;
        VerticalFacing = true;
    }
    if( m_pPlayerController->IsHeld( PlayerController::Mask::Down ) )
    {
        dir.y += -1;
        VerticalFacing = true;
    }
    if( m_pPlayerController->IsHeld( PlayerController::Mask::Left ) )
    {
        dir.x += -1;
        VerticalFacing = false;
    }
    if( m_pPlayerController->IsHeld( PlayerController::Mask::Right ) )
    {
        dir.x += 1;
        VerticalFacing = false;
    }



if (dir.x != 0 || dir.y != 0)
{
    AnimationTimer += deltaTime * 5;

    if (VerticalFacing == true)
    {
        if (dir.y > 0)
        {
            FrameBase = 8;
        }
        else
        {
            FrameBase = 5;
        }
    }
    else
    {
        if (dir.x > 0)
        {
            FrameBase = 17;
        }
        else
        {
            FrameBase = 20;
        }
    }
}
else
{
    AnimationTimer = 0;
}

if (AnimationTimer > FrameCount)
{
    AnimationTimer = 0;
}

Frame = FrameBase + ((int)AnimationTimer == 2 ? 0 : (int)AnimationTimer) + ((int)AnimationTimer == 3 ? -1 : 0);

if (Frame < 10)
{
    SpriteName.append("0");
}

SpriteName.append(std::to_string(Frame));

fw::SpriteInfo* sprite = m_PlayerSprite->GetSpriteInfo(SpriteName);

    m_UVScale = vec2( (float)sprite->SpriteW/1024.0f, (float)sprite->SpriteH/512.0f );
    m_UVOffset = vec2((float)sprite->SpriteX/1024.0f, (float)sprite->SpriteY/512.0f );

    //dir.Normalize();

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
