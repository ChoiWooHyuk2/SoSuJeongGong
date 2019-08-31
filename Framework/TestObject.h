#pragma once
#include "GameObject.h"
#include "Bar.h"
#include "Attack.h"
#include "Monster.h"
#include "NewObject.h"
class Attack;
class Monster;
class NewObject;
class TestObject : public GameObject 
{
public:
	TestObject();
	~TestObject();

	Animation* RightWalkAnimation;
	Animation* LeftWalkAnimation;

	Animation* RightjumpAnimation;
	Animation* LeftjumpAnimation;

	Animation* RightStopAnimation;
	Animation* LeftStopAnimation;

	Animation* LeftAttackAnimation;
	Animation* RightAttackAnimation;

	float JumpPoint = 1000.0f;

	Attack* Att;
	Monster* ms;
	NewObject* no;


	bool AttackMotion = false;
	bool Right = false;
	bool Left = true;
	bool stay = true;
	float delay = 0.0f;
	bool Attack = true;
	void OnUpdate();
};

