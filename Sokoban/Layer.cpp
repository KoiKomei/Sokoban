#include "Layer.h"



Layer::Layer()
{
}


Layer::~Layer()
{
}

pair<int, int> Layer::setTiles(string tileString) {
	pair<int, int> tile;
	tile.first = atoi(tileString.substr(0, tileString.find(',')).c_str());
	tile.second = atoi(tileString.substr(tileString.find(',') + 1).c_str());
	return tile;
}

void Layer::LoadContent(string ID, string mapID) {
	string filename = "utilities/Maps/" + mapID + ".txt";
	file.LoadContent(filename.c_str(), attributes, contents, ID);
	int indexY = 0;
	int id = 0;
	for (int i = 0; i < attributes.size(); i++) {
		for (int j = 0; j < attributes[i].size(); j++) {
			if (attributes[i][j] == "SolidTiles") {
				solidTiles.push_back(setTiles(contents[i][j]));
			}
			else if (attributes[i][j] == "TileSheet") {
				tileSheet = al_load_bitmap(contents[i][j].c_str());
			}
			else if (attributes[i][j] == "StartLayer"){
				for (int k = 0; k < contents[i].size(); k++) {
					if (contents[i][k] != "---") {
						ALLEGRO_BITMAP *tileImage;
						Tile::State tempState = Tile::State::Passive;
						pair<int, int> tile=setTiles(contents[i][k]);
						if (find(solidTiles.begin(), solidTiles.end(), tile) != solidTiles.end()) {
							tempState = Tile::State::Solid;
						}
						tileImage = al_create_sub_bitmap(tileSheet, tile.first * 32, tile.second * 32, 32, 32);

						pair<float, float> position(k * 32, indexY * 32);

						Tile tileInstance;
						tiles.push_back(tileInstance);
						tiles[tiles.size() - 1].setContent(id, tileImage, tempState, position);
						id++;
					}
				}
				indexY++;
			}
		}
	}
}

void Layer::Unload() {
	for (int i = 0; i < tiles.size(); i++) {
		tiles[i].Unload();
	}
	al_destroy_bitmap(tileSheet);
}

void Layer::Update(Entity &e) {
	for (int i = 0; i < tiles.size(); i++) {
		tiles[i].Update(e);
	}
}

void Layer::Draw(ALLEGRO_DISPLAY *display) {
	for (int i = 0; i < tiles.size(); i++) {
		tiles[i].Draw(display);
	}
}