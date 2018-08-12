#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <string>
#include "Game.h"
#include "Screen.h"

using namespace std;


/*Allegro include*/
#include "allegro5/allegro.h"


#define WIDTH 800
#define HEIGHT 600

class SceneManager {

private:
	string text;
	Game *current, *newscreen;
	
public:
	SceneManager(void);
	~SceneManager(void);
	SceneManager(SceneManager const& s); 
	void operator=(SceneManager const&);

	void addScene(Game *scene);

	static SceneManager &GetInstance();
	void setText(string txt);
	void getText();
	void Initialize();
	void LoadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};
#endif // !SCENEMANAGER
