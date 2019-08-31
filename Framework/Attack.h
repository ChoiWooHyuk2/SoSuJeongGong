#pragma once
#include "GameObject.h"
#include "TestObject.h"

class TestObject;

class Attack :
	public GameObject
{
public:
	Attack();

	~Attack();

	Animation* attackRight;
	Animation* attackLeft;

	void OnUpdate();

	bool Ani = false;

	TestObject* Player;
	
};

