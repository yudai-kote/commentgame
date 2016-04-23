#pragma once
#include "../AppEnv.h"


class ItemBase
{
public:
	//使った時の関数
	virtual void use(Vec2f _pos, Direction _direction) {};
	virtual	void update() {};
	virtual	void draw() {};
private:

};

