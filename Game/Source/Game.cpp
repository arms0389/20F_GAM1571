#include "../../Framework/Source/Framework.h"

#include "Game.h"
#include "Objects/Player.h"

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

    m_pShader = new fw::ShaderProgram( "Data/Basic.vert", "Data/Basic.frag" );

    // Define our triangle as 3 positions.
    float attribsHuman[] =
    {
        -0.25f,  -0.25f, // Center
         0.25f,   0.25f, // Top right
         0.25f,  -0.25f, // Right center
    };

    m_pMeshHuman = new fw::Mesh();
    m_pMeshHuman->CreateShape( GL_TRIANGLES, 3, &attribsHuman[0] );

    float attribsAnimal[] =
    {
        0.0f, 0.0f, // Center
    };

    m_pMeshAnimal = new fw::Mesh( GL_POINTS, 1, &attribsAnimal[0] );

    m_Objects.push_back( new Player( this, fw::vec2( 6, 5 ), m_pMeshHuman, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, fw::vec2( 0, 0 ), m_pMeshAnimal, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, fw::vec2( 10, 10 ), m_pMeshAnimal, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, fw::vec2( 5, 5 ), m_pMeshAnimal, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, fw::vec2( 1, 1 ), m_pMeshAnimal, m_pShader ) );
    m_Objects.push_back( new fw::GameObject( this, fw::vec2( 1, 9 ), m_pMeshAnimal, m_pShader ) );
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
