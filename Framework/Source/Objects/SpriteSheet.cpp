#include "FrameworkPCH.h"
#include "SpriteSheet.h"
#include "Utility/Helpers.h"
#include "Math/Vector.h"

namespace fw
{
	SpriteSheet::SpriteSheet(const char* filename)
	{
		const char* JsonString = fw::LoadCompleteFile(filename, nullptr);

		rapidjson::Document document;
		document.Parse(JsonString);
		delete[] JsonString;

		m_width = document["Width"].GetInt();
		m_height = document["Height"].GetInt();

		for (auto& pass : document["Sprites"].GetArray())
		{
			SpriteInfo tempSpriteInfo;

			tempSpriteInfo.SpriteName = pass["Name"].GetString();
			tempSpriteInfo.SpriteX = pass["X"].GetInt();
			tempSpriteInfo.SpriteY = pass["Y"].GetInt();
			tempSpriteInfo.SpriteW = pass["W"].GetInt();
			tempSpriteInfo.SpriteH = pass["H"].GetInt();

			m_Sprites.push_back(tempSpriteInfo);
		}
	}
	SpriteSheet::~SpriteSheet()
	{

	}

	SpriteInfo* SpriteSheet::GetSpriteInfo(std::string name)
	{
		SpriteInfo* tempSprite;

		for (int i = 0; i < m_Sprites.size(); i++)
		{
			if (m_Sprites.at(i).SpriteName == name)
			{
				tempSprite = &m_Sprites.at(i);
			}
		}
		return tempSprite;
	}
}
