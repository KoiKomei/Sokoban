#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include <vector>
#include <string>
#include "Input.h"
#include "Animation.h"
#include "FloatRect.h"
#include "Spritesheet.h"
#include <iostream>
using namespace std;

class Entity
{
public:
	Entity();
	~Entity();
	enum Type {Box, Player};
	Type type;
	virtual void LoadContent(vector<string> attributes, vector<string> content);
	virtual void Unload();
	virtual void Update(ALLEGRO_EVENT ev, Input input);
	virtual void Draw(ALLEGRO_DISPLAY *display);
	virtual void OnCollision(Entity e);
	pair<float, float> position, prevPosition, moveSpeed;
	Animation animation;
	bool gravity;
	FloatRect *rect, *prevRect;
	int tileID;

	enum Direction { Up, Right, Down, Left };

	Direction direction;
protected:
	
	ALLEGRO_BITMAP *image;
	float grav;
	float speed;

	Spritesheet sprite;
	int range;

};

