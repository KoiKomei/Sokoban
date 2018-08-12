#pragma once
#ifndef SCENEMANAGER
#define SCENEMANAGER
#include <iostream>
#include <string>
#include "Game.h"
#include "Screen.h"
#include "Includer.h"
using namespace std;


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
