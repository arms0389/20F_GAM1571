#pragma once

namespace fw
{
	struct SpriteInfo
	{
		std::string SpriteName;
		int SpriteX = 0;
		int SpriteY = 0;
		int SpriteW = 0;
		int SpriteH = 0;

		SpriteInfo() 
		{
			
		};
	};

	class SpriteSheet
	{

	public:
		SpriteSheet(const char* filename);
		virtual ~SpriteSheet();

		int m_width;
		int m_height;

		SpriteInfo* GetSpriteInfo(std::string name);

	protected:
		const char* m_filename;
		
		std::vector<SpriteInfo> m_Sprites;
	};
}

