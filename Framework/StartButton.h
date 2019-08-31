#pragma once
#include "GameObject.h"
class StartButton :
	public GameObject
{
public:
	StartButton();
	StartButton(const wchar_t* url);

	~StartButton();

	void OnUpdate();
};

