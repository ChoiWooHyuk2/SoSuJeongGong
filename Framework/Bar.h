#pragma once
#include "GameObject.h"
#include "TestObject.h"

class TestObject;

class Bar : public GameObject
{
public:
	Animation* UI1;
	Animation* UI2;

	TestObject* player;

	void OnUpdate();

	Bar();
	~Bar();
};

