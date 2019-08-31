#pragma once
#include "GameObject.h"
#include "Monster.h"
#include "Attack.h"
#include "TestObject.h"
class Monster;
class Attack;
class NewObject :
	public GameObject
{
public:
	NewObject();
	void OnUpdate();
	Monster* me;
	Attack* at2;


	float deltime = 0.0f;
	bool del2 = false;
	~NewObject();
};

