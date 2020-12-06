#include "GamePCH.h"
#include "TileMap.h"

TileMap::TileMap(vec2 position, float scale, const TileType* pLayout, unsigned int width, unsigned int height, fw::ShaderProgram* pshader, fw::Texture* ptexture, fw::SpriteSheet* spritesheet, fw::Mesh* tileMesh ) :
    m_Scale(scale), m_Position(position), m_width(width), m_height(height), m_TileProperties(), m_pShader(pshader), m_pTexture(ptexture), m_pSpriteSheet(spritesheet), m_pTileMesh(tileMesh)
{
    m_pLayout = new TileType[(long)width * (long)height];

    for (unsigned int i = 0; i < width * height; i++)
    {
        m_pLayout[i] = pLayout[i];
    }

    m_TileProperties[(int)TileType::Floor] = TileProperties("Ground/ground_01", true, false);
    m_TileProperties[(int)TileType::Wall]  = TileProperties("Blocks/block_01", false, false);
    m_TileProperties[(int)TileType::Crate] = TileProperties("Crates/crate_01", false, false);
}


void TileMap::Draw()
{
    for(int i = 0; i < m_width * m_height; i++)
    {
        unsigned int row = (m_height - 1) - i / m_width;
        unsigned int col = i % m_width;

        vec2 position = vec2((float)col, (float)row) * m_Scale + m_Position;

        std::string SpriteName = m_TileProperties[(int)m_pLayout[i]].m_TileName;
        fw::SpriteInfo* Sprite = m_pSpriteSheet->GetSpriteInfo(SpriteName);

        vec2 UVScale  = vec2((float)Sprite->SpriteW/1024.0f, (float)Sprite->SpriteH/512.0f );
        vec2 UVOffset = vec2((float)Sprite->SpriteX/1024.0f, (float)Sprite->SpriteY/512.0f );

        m_pTileMesh->Draw(position, m_Scale, m_pShader, m_pTexture, fw::vec4::White(),  UVScale, UVOffset);
    }
}

TileMap::~TileMap()
{
   delete[] m_pLayout;
}
