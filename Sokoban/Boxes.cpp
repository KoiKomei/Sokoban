#include "Boxes.h"



Boxes::Boxes()
{
}


Boxes::~Boxes()
{
}


void Boxes::LoadContent(vector<string> attributes, vector<string> contents) {
	counter = 0;
	Entity::LoadContent(attributes, contents);
	animation.getIsActive() = true;
	direction = Direction::Down;
}
void Boxes::Unload() {}
void Boxes::Update(ALLEGRO_EVENT ev, Input input) {
	/*prevPosition = position;
	if (direction == Direction::Right) {
		position.first += speed;
	}
	else if (direction == Direction::Left) {
		position.first -= speed;
	}
	else
		animation.getIsActive() = false;
	position.first = position.first + moveSpeed.first;
	position.second = position.second + moveSpeed.second;
	animation.CurrentFrame().second = direction;
	animation.Position() = position;
	sprite.Update(animation);

	delete rect;
	delete prevRect;
	rect = new FloatRect(position.first, position.second, 32, 32);

	prevRect = new FloatRect(prevPosition.first, prevPosition.second, 32, 32);
	/*counter += moveSpeed.first;
	if (counter >= range) {
		counter = 0;
		if (direction == Direction::Right) {
			direction = Direction::Left;
		}
		else
			direction = Direction::Right;
	}*/
	Entity::Update(ev, input);
	input.Update();
	animation.getIsActive() = true;

	if (input.isKeyDown(ALLEGRO_KEY_DOWN)) {
		direction = Direction::Down;
		position.second += speed;
	}
	else if (input.isKeyDown(ALLEGRO_KEY_UP)) {
		direction = Direction::Up;
		position.second -= speed;
	}
	else if (input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
		direction = Direction::Right;
		position.first += speed;
	}
	else if (input.isKeyDown(ALLEGRO_KEY_LEFT)) {
		direction = Direction::Left;
		position.first -= speed;
	}
	else
		animation.getIsActive() = false;
	animation.CurrentFrame().second = direction;
	animation.Position() = position;
	sprite.Update(animation);

	delete rect;
	delete prevRect;
	rect = new FloatRect(position.first, position.second, 32, 32);

	prevRect = new FloatRect(prevPosition.first, prevPosition.second, 32, 32);
}

void Boxes::OnCollision(Entity e) {
	cout << "Enemy collision" << endl;
	e.position.first = position.first + 20;

}

void Boxes::Draw(ALLEGRO_DISPLAY *display) {
	animation.Draw(display);
}