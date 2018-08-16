#pragma once

#ifndef MAP_H
#define MAP_H
#include "Layer.h"


class Map {
public:
	void LoadContent(string mapID);
	void Unload();
	void Update(Entity &e);
	void Draw(ALLEGRO_DISPLAY *display);
	
private:
	vector<Layer> layers;
	string mapID;
	


};
#endif // !MAP_H
