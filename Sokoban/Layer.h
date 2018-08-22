#pragma once
#include "Tile.h"
#include "FileManager.h"
#include <string>
#include <algorithm>
using namespace std;
class Layer
{
public:
	Layer();
	~Layer();
	void LoadContent(string ID, string mapID);
	void Unload();
	void Update(Entity &e);
	void Draw(ALLEGRO_DISPLAY *display);

	pair<int,int> setTiles(string tileString);

private:
	FileManager file;
	vector<vector<string>>attributes, contents;
	vector<pair<int, int>> solidTiles, moveTiles;
	vector<Tile> tiles;
	ALLEGRO_BITMAP *tileSheet;


};


