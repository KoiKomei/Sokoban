#include "Player.h"



Player::Player()
{

}


Player::~Player()
{
}

void Player::LoadContent(vector<string> attributes, vector<string> contents) {
	Entity::LoadContent(attributes, contents);
	
	speed = 1;
	
}

void Player::Unload() {
	Entity::Unload();
	animation.Unload();
}

void Player::Update(ALLEGRO_EVENT ev, Input input) {
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
	rect = new FloatRect(position.first, position.second, 20, 32);

	prevRect = new FloatRect(prevPosition.first, prevPosition.second, 20, 32);
}

void Player::OnCollision(Entity e) {
	//cout << "PLAYER COLLIDED" << endl;
	
}

void Player::Draw(ALLEGRO_DISPLAY *display) {
	Entity::Draw(display);
}