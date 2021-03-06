#pragma once

class PlayerController;
class Player;
class TileMap;
class Game : public fw::GameCore
{
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game();

    void Init();
    virtual void StartFrame(float deltaTime) override;
    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

    Player* GetPlayer() { return m_pPlayer; }

protected:
    fw::ImGuiManager* m_pImGuiManager = nullptr;

    PlayerController* m_pPlayerController = nullptr;

    std::map<std::string, fw::ShaderProgram*> m_pShaders;
    std::map<std::string, fw::Mesh*> m_pMeshes;
    std::map<std::string, fw::Texture*> m_pTextures;
    std::map<std::string, fw::SpriteSheet*> m_pSpriteSheet;

    Player* m_pPlayer = nullptr;
    std::vector<fw::GameObject*> m_Objects;

    TileMap* m_pTileMap;
    // Settings.
    bool m_VSyncEnabled = true;
};
