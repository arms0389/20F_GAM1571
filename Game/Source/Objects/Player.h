#pragma once

class Player : public fw::GameObject
{
public:
    Player(fw::GameCore* pGameCore, std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, vec4 color);
    virtual ~Player();

    virtual void Update(float deltaTime) override;

protected:
};
