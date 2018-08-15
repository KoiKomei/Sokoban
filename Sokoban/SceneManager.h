#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <string>
#include "Game.h"
#include "Screen.h"
#include "Fade.h"
#include "Gameplay.h"
#include <map>

using namespace std;


/*Allegro include*/
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"


#define WIDTH 800
#define HEIGHT 600

class SceneManager {

private:
	string text;
	Game *current, *newscene;
	Animation transition;
	Fade fade;
	ALLEGRO_BITMAP *trans;
	bool startTransition;
	map<string, Game*> directory;
public:
	SceneManager(void);
	~SceneManager(void);
	SceneManager(SceneManager const& s); 
	void operator=(SceneManager const&);

	void addScene(string sceneName);

	static SceneManager &GetInstance();
	void setText(string txt);
	void getText();
	void Initialize();
	void LoadContent();
	void Unload();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
	void Transition();
};
#endif // !SCENEMANAGER
