#pragma once

class Game : public fw::GameCore
{
public:
    Game();
    virtual ~Game();

    void Init();
    virtual void Update() override;
    virtual void Draw() override;

protected:
    fw::ShaderProgram* m_pShader = nullptr;
    fw::Mesh* m_pMeshHuman = nullptr;
    fw::Mesh* m_pMeshAnimal = nullptr;

    std::vector<fw::GameObject*> m_Objects;
};
