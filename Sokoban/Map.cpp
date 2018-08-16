#include "Map.h"
 
void Map::LoadContent(string mapID) {
	(*this).mapID = mapID;
	Layer layerInstance;
	layers.push_back(layerInstance);
	layers[0].LoadContent("Layer1", (*this).mapID);
}

void Map::Unload() {
	layers[0].Unload();
}

void Map::Update(Entity &e) {
	layers[0].Update(e);
}

void Map::Draw(ALLEGRO_DISPLAY *display) {
	layers[0].Draw(display);
}