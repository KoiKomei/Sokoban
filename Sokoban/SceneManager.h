#pragma once
#ifndef SCENEMANAGER
#define SCENEMANAGER
#include <iostream>
#include <string>
#include "Game.h"
#include "Screen.h"
#include "Includer.h"
using namespace std;

/*Include di allegro*/




#define WIDTH 800
#define HEIGHT 600

class SceneManager {

private:
	string text;
	
public:
	SceneManager(void);
	~SceneManager(void);
	SceneManager(SceneManager const& s); 
	void operator=(SceneManager const&);

	static SceneManager &GetInstance();
	void setText(string txt);
	void getText();
	void Initialize();
	void LoadContent();
	void Update();
	void Draw(ALLEGRO_DISPLAY *display);
};
#endif // !SCENEMANAGER
