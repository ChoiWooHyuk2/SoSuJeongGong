#pragma once
#include "GameObject.h"
#include "Attack.h"
#include "NewObject.h"
#include "TestObject.h"

class NewObject;
class Attack;
class TestObject;

class Monster :
	public GameObject
{
public:
	Monster();
	Monster(const wchar_t* url);
	~Monster();

	void OnUpdate();

	Attack* at2;
	NewObject* no;


	bool del = false;
	bool Right = false;
	bool Left = true;
};

