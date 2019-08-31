#pragma once
#include "GameObject.h"
class BackScene :
	public GameObject
{
public:
	BackScene();
	BackScene(const wchar_t* url);
	~BackScene();
};

