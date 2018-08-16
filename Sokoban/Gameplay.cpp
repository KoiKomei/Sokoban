#include "Gameplay.h"



Gameplay::Gameplay()
{
}


Gameplay::~Gameplay()
{
}

void Gameplay::LoadContent() {
	map.LoadContent("Map1");
	player.LoadContent("utilities/Player.txt", "", "Player");
	boxes.LoadContent("utilities/Boxes.txt", "", "Box");
}

void Gameplay::Unload() {
	Game::Unload();
	map.Unload();
	player.Unload();
	boxes.Unload();
}

void Gameplay::Update(ALLEGRO_EVENT ev) {
	player.Update(ev, input);
	boxes.Update(ev, input);
	for (int i = 0; i < player.entities.size(); i++) {
		map.Update(*player.entities[i]);
	}
	for (int i = 0; i < boxes.entities.size(); i++) {
		map.Update(*boxes.entities[i]);
	}

	player.EntityCollision(boxes);
		
}

void Gameplay::Draw(ALLEGRO_DISPLAY *display) {
	map.Draw(display);
	
	player.Draw(display);
	boxes.Draw(display);

}