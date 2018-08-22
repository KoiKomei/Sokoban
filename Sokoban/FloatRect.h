#pragma once
class FloatRect
{
public:
	FloatRect();
	~FloatRect();

	FloatRect(float x,float y,float w,float h);
	bool Intersects(FloatRect f);
	float Left, Right, Top, Bottom;
};

