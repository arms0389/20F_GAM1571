#pragma once

class PlayerController;

class Player : public fw::GameObject
{
public:
    Player(fw::GameCore* pGameCore, PlayerController* pPlayerController, std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec4 color, fw::SpriteSheet* pSpriteSheet);
    virtual ~Player();

    virtual void Update(float deltaTime) override;

protected:
    PlayerController* m_pPlayerController = nullptr;

    fw::SpriteSheet* m_PlayerSprite = nullptr;
    fw::SpriteInfo* m_SpriteInfo;

    float AnimationTimer = 0;
    bool VerticalFacing = true;
    std::string SpriteName;
    int FrameCount = 4;
    int FrameBase = 5;
    int Frame = FrameBase;
};
