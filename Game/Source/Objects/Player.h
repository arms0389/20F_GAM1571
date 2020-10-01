#pragma once

class Player : public fw::GameObject
{
public:
    Player(fw::GameCore* pGameCore, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader);
    virtual ~Player();

    virtual void Update(float deltaTime) override;

protected:
};
