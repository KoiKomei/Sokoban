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
			if ((*entities[i]).rect->Intersects(*e.entities[j]->rect)) {
				(*entities[i]).OnCollision(*e.entities[j]);
				(*e.entities[j]).OnCollision(*entities[i]);
			}
		}
	}
}

void EntityManager::Draw(ALLEGRO_DISPLAY *display) {
	for (int i = 0; i < entities.size(); i++) {
		(*entities[i]).Draw(display);
	}
}


