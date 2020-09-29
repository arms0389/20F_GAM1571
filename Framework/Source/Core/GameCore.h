#pragma once

namespace fw {

class FWCore;

class GameCore
{
public:
    GameCore(FWCore* pFramework);
    virtual ~GameCore();

    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;

    FWCore* GetFramework() { return m_pFramework; }

protected:
    FWCore* m_pFramework;
};

} // namespace fw
