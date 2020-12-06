#include "GamePCH.h"
#include "Layout.h"

using TT = TileMap::TileType;

 const int level1Width = 6;
 const int level1Height = 9;

 const TileMap::TileType Level1Layout[] =
 {
     TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Floor,
     TT::Floor, TT::Wall , TT::Floor, TT::Floor, TT::Wall , TT::Floor,
     TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Floor,
     TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Floor,
     TT::Wall,  TT::Wall , TT::Wall,  TT::Floor, TT::Wall , TT::Wall,
     TT::Wall,  TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Wall,
     TT::Wall,  TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Wall,
     TT::Wall,  TT::Floor, TT::Floor, TT::Floor, TT::Floor, TT::Wall,
     TT::Wall,  TT::Wall,  TT::Wall,  TT::Wall,  TT::Wall,  TT::Wall
 };