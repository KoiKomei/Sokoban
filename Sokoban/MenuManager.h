#pragma once
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "allegro5/allegro.h"
#include <vector>
#include <iostream>
#include "Fade.h"
#include "FileManager.h"
#include "SceneManager.h"
#include <sstream>
using namespace std;

class MenuManager {

public:
	void LoadContent(string ID);
	void Unload();
	void Update(ALLEGRO_EVENT ev, Input &input);
	void Draw(ALLEGRO_DISPLAY *display);
	void setMenuItems();
	void setAnimations();


private:
	vector<string> menuItems;
	vector<ALLEGRO_BITMAP*> menuImages;
	vector<Animation*> animations;
	Fade fade;
	vector<string> links;
	FileManager file;

	vector<vector<string>> attributes, contents;

	unsigned itemNumber;
	pair<float, float> position;
	int axis;
	string align;
	vector<string> animationTypes;
	ALLEGRO_FONT *font;
	vector<Animation*> tempAnimation;
};


#endif // !MENUMANAGER_H
