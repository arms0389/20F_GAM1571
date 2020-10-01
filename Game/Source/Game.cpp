#include "GamePCH.h"

#include "Game.h"
#include "Objects/Player.h"
#include "Objects/Shapes.h"

Game::Game(fw::FWCore* pFramework) : fw::GameCore( pFramework )
{
}

Game::~Game()
{
    delete m_pShader;
    delete m_pMeshHuman;
    delete m_pMeshAnimal;

    for( fw::GameObject* pObject : m_Objects )
    {
        delete pObject;
    }

    delete m_pImGuiManager;
}

void Game::Init()
{
    m_pImGuiManager = new fw::ImGuiManager( m_pFramework );
    m_pImGuiManager->Init();

    // Load some shaders.
    m_pShader = new fw::ShaderProgram( "Data/Basic.vert", "Data/Basic.frag" );

    // Create some meshes.
    m_pMeshHuman = new fw::Mesh( meshPrimType_Human, meshNumVerts_Human, meshAttribs_Human );
    m_pMeshAnimal = new fw::Mesh( meshPrimType_Enemy, meshNumVerts_Enemy, meshAttribs_Enemy );

    // Create some GameObjects.
    m_Objects.push_back( new Player( this, vec2( 6, 5 ), m_pMeshHuman, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, vec2( 0, 0 ), m_pMeshAnimal, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, vec2( 10, 10 ), m_pMeshAnimal, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, vec2( 5, 5 ), m_pMeshAnimal, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, vec2( 1, 1 ), m_pMeshAnimal, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, vec2( 1, 9 ), m_pMeshAnimal, m_pShader ) );
}

void Game::Update(float deltaTime)
{
    m_pImGuiManager->StartFrame( deltaTime );
    ImGui::ShowDemoWindow();

    for( fw::GameObject* pObject : m_Objects )
    {
        pObject->Update( deltaTime );
    }
}

void Game::Draw()
{
    glClearColor( 0, 1, 0, 0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
    
    for( fw::GameObject* pObject : m_Objects )
    {
        pObject->Draw();
    }

    m_pImGuiManager->EndFrame();
}
