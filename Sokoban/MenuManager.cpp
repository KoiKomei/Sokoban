#include "MenuManager.h"

void MenuManager::setMenuItems() {
	for (int i = 0; i < menuItems.size(); i++) {
		if (menuImages.size() == i) {
			menuImages.push_back(NULL);
		}

	}
	for (int i = 0; i < menuImages.size(); i++) {
		if (menuItems.size() == i) {
			menuItems.push_back("");
		}
	}
}

void MenuManager::setAnimations() {
	
	
	for (int i = 0; i < menuItems.size(); i++) {
		
		animations.push_back(new Animation);
			(*animations[i]).LoadContent(menuImages[i], menuItems[i], position);
		
		if (axis == 2) {
			position.second += 30;
		}
		else if (axis == 1) {
			position.first+= al_get_text_width(font, menuItems[i].c_str());
		}

	}
}

void MenuManager::LoadContent(string ID) {
	file.LoadContent("utilities/Menu.txt", attributes, contents);
	float position[2];
	for (int i = 0; i < attributes.size(); i++) {
		for (int j = 0; j < attributes[i].size(); j++) {
			if (attributes[i][j] == "Item") {
				menuItems.push_back(contents[i][j]);
			}
			else if (attributes[i][j] == "ItemLink") {
				links.push_back(contents[i][j]);
			}
			else if (attributes[i][j] == "Image") {
				menuImages.push_back(al_load_bitmap(contents[i][j].c_str()));
			}
			else if (attributes[i][j] == "Font") {
				font = al_load_font(contents[i][j].c_str(), 30, NULL);
			}
			else if (attributes[i][j] == "Align") {
				align = contents[i][j];
			}
			else if (attributes[i][j] == "Animation") {
				animationTypes.push_back(contents[i][j]);
			}
			else if (attributes[i][j] == "Axis") {
				axis = atoi(contents[i][j].c_str());
			}
			else if (attributes[i][j] == "Position") {
				stringstream str;
				str << contents[i][j];
				string value;
				int counter = 0;
				while (getline(str, value, ' ')) {
					position[counter] = atof(value.c_str());
					counter++;
				}
			}
		}
	}
	(*this).position.first = position[0];
	(*this).position.second = position[1];
	setMenuItems();
	setAnimations();
}

void MenuManager::Unload() {
	al_destroy_font(font);
	for (int i = 0; i < menuImages.size(); i++) {
		al_destroy_bitmap(menuImages[i]);
	}
	for (int i = 0; i < animations.size(); i++) {
		delete animations[i];
	}
	animations.clear();
	menuItems.clear();
	animationTypes.clear();
	attributes.clear();
	contents.clear();
	tempAnimation.clear();
}

void MenuManager::Update(ALLEGRO_EVENT ev, Input &input){
	if (input.isKeyPressed(ev, ALLEGRO_KEY_DOWN)) {
		itemNumber++;
	}
	else if (input.isKeyPressed(ev, ALLEGRO_KEY_UP)){
		itemNumber--;
	} 

	if (input.isKeyPressed(ev, ALLEGRO_KEY_ENTER)) {
		SceneManager::GetInstance().addScene(links[itemNumber]);
	}
	if (itemNumber < 0) {
		itemNumber = 0;
	}
	else if (itemNumber > menuItems.size() - 1) {
		itemNumber = menuItems.size() - 1;
	}

	for (int i = 0; i < animations.size(); i++) {
		for (int j = 0; j < animationTypes.size(); j++) {
			if (itemNumber == i) {
				(*animations[i]).getIsActive()=true;

			}
			else {
				(*animations[i]).getIsActive() = false;
			}

			if (animationTypes[j] == "Fade") {
				fade.Update(*animations[i]);
				}			
		}
	}
}

void MenuManager::Draw(ALLEGRO_DISPLAY *display) {
	for (int i = 0; i < animations.size(); i++) {
			(*animations[i]).Draw(display);
	}
}