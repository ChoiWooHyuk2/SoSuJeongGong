#pragma once
#include "GameObject.h"
#include "TestObject.h"

class TestObject;

class Bar2 : public GameObject
{
public:
	Animation* UI1;
	Animation* UI2;

	TestObject* player;

	void OnUpdate();

	Bar2();
	~Bar2();
};