#pragma once
#include "Scene.h"
#include "NewObject.h"
class NewObject;

class TestScene :
	public Scene
{
public:
	TestScene();
	~TestScene();


	void GroundSet();

	void Initialize();
};

