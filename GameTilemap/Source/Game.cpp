#include "GamePCH.h"

#include "Game.h"
#include "Objects/Player.h"
#include "Objects/PlayerController.h"
#include "Objects/Shapes.h"
#include "Events/GameEvents.h"

Game::Game(fw::FWCore* pFramework) : fw::GameCore( pFramework )
{
    wglSwapInterval( m_VSyncEnabled ? 1 : 0 );
}

Game::~Game()
{
    for( fw::GameObject* pObject : m_Objects )
    {
        delete pObject;
    }

    delete m_pPlayerController;

    delete m_pEventManager;
    delete m_pImGuiManager;
}

void Game::Init()
{
    // OpenGL Settings.
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    m_pImGuiManager = new fw::ImGuiManager( m_pFramework );
    m_pImGuiManager->Init();

    m_pEventManager = new fw::EventManager();

    m_pPlayerController = new PlayerController();
    
    // Load some shaders.

    // Create some meshes.

    // Create some GameObjects.
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame( deltaTime );

    m_pPlayerController->StartFrame();

    // Process our events.
    m_pEventManager->DispatchAllEvents( this );
}

void Game::OnEvent(fw::Event* pEvent)
{
    m_pPlayerController->OnEvent( pEvent );

    if( pEvent->GetType() == RemoveFromGameEvent::GetStaticEventType() )
    {
        RemoveFromGameEvent* pRemoveFromGameEvent = static_cast<RemoveFromGameEvent*>( pEvent );
        fw::GameObject* pObject = pRemoveFromGameEvent->GetGameObject();

        auto it = std::find( m_Objects.begin(), m_Objects.end(), pObject );
        m_Objects.erase( it );

        delete pObject;
    }
}

void Game::Update(float deltaTime)
{
    // Display framerate.
    ImGui::Text( "%0.2f", 1/deltaTime );

    for( auto it = m_Objects.begin(); it != m_Objects.end(); it++ )
    {
        fw::GameObject* pObject = *it;
        pObject->Update( deltaTime );
    }

    // Debug imgui stuff.
    {
        if( ImGui::Checkbox( "VSync", &m_VSyncEnabled ) )
        {
            wglSwapInterval( m_VSyncEnabled ? 1 : 0 );
        }
    }
}

void Game::Draw()
{
    glClearColor( 0, 0, 0.2f, 0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
    
    for( auto it = m_Objects.begin(); it != m_Objects.end(); it++ )
    {
        fw::GameObject* pObject = *it;
        pObject->Draw();
    }

    m_pImGuiManager->EndFrame();
}
