#pragma once

class TileMap
{
public:
	enum class TileType
	{
		Floor,
		Wall,
		Crate,
		NumTileTypes,
	};

	struct TileProperties
	{
		TileProperties() : m_IsWalkable(true), m_IsHazard(false), m_TileName("") {};
		TileProperties(std::string name, bool walkable, bool hazard) : m_TileName(name), m_IsWalkable(walkable), m_IsHazard(hazard) {};
		TileProperties& operator=(const TileProperties& tileproperties) { m_TileName = tileproperties.m_TileName; m_IsWalkable = tileproperties.m_IsWalkable; m_IsHazard = tileproperties.m_IsHazard; return *this; };
		
		std::string m_TileName;
		bool m_IsWalkable;
		bool m_IsHazard;
	};

public:
	TileMap(vec2 position, float scale, const TileType* pLayout, unsigned int width, unsigned int height, fw::ShaderProgram* pshader, fw::Texture* ptexture, fw::SpriteSheet* spritesheet, fw::Mesh* tileMesh );
	~TileMap();
	void Draw();

protected:
	//vec2 m_Position;
	int m_width;
	int m_height;
	fw::Mesh* m_pTileMesh;
	TileType* m_pLayout;
	fw::ShaderProgram* m_pShader;
	fw::Texture* m_pTexture;
	fw::SpriteSheet* m_pSpriteSheet;
	vec2 m_Position;
	float m_Scale;
	TileProperties m_TileProperties[	(int)TileType::NumTileTypes		];
};

