#include "EntityManager.h"



EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

void EntityManager::LoadContent(string filename, string id, string type) {
	vector<vector<string>> attributes, contents;
	FileManager file;
	moving = false;
	if (id == "") {
		file.LoadContent(filename.c_str(), attributes, contents);
	}
	else
		file.LoadContent(filename.c_str(), attributes, contents, id);

	for (int i = 0; i < attributes.size(); i++) {
		Entity *entity;
		if (type == "Player") {
			entity = new Player();
			
		}
		else if (type == "Box") {
			entity = new Boxes();
		}
		entities.push_back(entity);
		(*entities[i]).LoadContent(attributes[i], contents[i]);
	}
}

void EntityManager::Unload() {
	for (int i = 0; i < entities.size(); i++) {
		(*entities[i]).Unload();
		delete entities[i];
	}
}

void EntityManager::Update(ALLEGRO_EVENT ev, Input input) {
	for (int i = 0; i < entities.size(); i++) {
		(*entities[i]).Update(ev, input);
	}
}

void EntityManager::EntityCollision(EntityManager e) {
	for (int i = 0; i < entities.size(); i++) {
		for (int j = 0; j < e.entities.size(); j++) {
			if ((*entities[i]).rect->Intersects(*e.entities[j]->rect)){
				
				if (entities[i]->rect->Bottom >= e.entities[j]->rect->Top && entities[i]->prevRect->Bottom <= e.entities[j]->rect->Top) {
					(*entities[i]).position.second = e.entities[j]->rect->Top - 32;
					(*e.entities[j]).OnCollision(*entities[i]);
				}
				else if (entities[i]->rect->Top <= e.entities[j]->rect->Bottom && entities[i]->prevRect->Top >= e.entities[j]->rect->Bottom) {
					(*entities[i]).position.second = e.entities[j]->rect->Bottom;
					(*e.entities[j]).OnCollision(*entities[i]);
				}
				else if (entities[i]->rect->Right >= e.entities[j]->rect->Left && entities[i]->prevRect->Right <= e.entities[j]->rect->Left) {
					(*entities[i]).position.first = e.entities[j]->rect->Left - 32;
					(*e.entities[j]).OnCollision(*entities[i]);
				}
				else if (entities[i]->rect->Left <= e.entities[j]->rect->Right && entities[i]->prevRect->Left >= e.entities[j]->rect->Right) {
					(*entities[i]).position.first = e.entities[j]->rect->Right;
					(*e.entities[j]).OnCollision(*entities[i]);
				}
				entities[i]->animation.Position() = entities[i]->position;
				
				//(*entities[i]).OnCollision(*e.entities[j]);
				
				
			}
			
		}
	}
}

void EntityManager::Draw(ALLEGRO_DISPLAY *display) {
	for (int i = 0; i < entities.size(); i++) {
		(*entities[i]).Draw(display);
	}
}


