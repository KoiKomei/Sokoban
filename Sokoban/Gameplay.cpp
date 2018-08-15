#include "Gameplay.h"



Gameplay::Gameplay()
{
}


Gameplay::~Gameplay()
{
}

void Gameplay::LoadContent() {
	player.LoadContent();
}

void Gameplay::Unload() {
	Game::Unload();
	player.Unload();
}

void Gameplay::Update(ALLEGRO_EVENT ev) {
	player.Update(ev, input);
}

void Gameplay::Draw(ALLEGRO_DISPLAY *display) {
	player.Draw(display);
}