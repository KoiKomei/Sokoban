#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}


void Entity::LoadContent(vector<string> attributes, vector<string> contents) {
	for (int i = 0; i < attributes.size(); i++) {
		if (attributes[i] == "Image") {
			image = al_load_bitmap(contents[i].c_str());
		}
		else if (attributes[i] == "Position") {
			string tileString = contents[i];
			pair<int, int> tile;
			tile.first = atoi(tileString.substr(0, tileString.find(',')).c_str());
			tile.second = atoi(tileString.substr(tileString.find(',') + 1).c_str());
			position = tile;
		}
		else if (attributes[i] == "Direction") {
			if (contents[i] == "Right")
				direction = Direction::Right;
			else if (contents[i] == "Left")
				direction = Direction::Left;
		}
		else if (attributes[i] == "Speed") {
			speed = atof(contents[i].c_str());
		}
		else if (attributes[i] == "Range") {
			range = atoi(contents[i].c_str());
		}

		
	}
	animation.LoadContent(image, "", position);
	rect = new FloatRect(position.first, position.second, 32, 32);

	prevRect = new FloatRect(prevPosition.first, prevPosition.second, 32, 32);
}

void Entity::Unload() {
	al_destroy_bitmap(image);
}

void Entity::Update(ALLEGRO_EVENT ev, Input input) {
	prevPosition = position;
}
void Entity::OnCollision(Entity e) {

}
void Entity::Draw(ALLEGRO_DISPLAY *display) {
	animation.Draw(display);
}