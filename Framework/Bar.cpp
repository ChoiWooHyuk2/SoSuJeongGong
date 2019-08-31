#include "pch.h"
#include "Bar.h"


void Bar::OnUpdate()
{
	

	
	if (player->JumpPoint  > 0.0f)
	{
		SwapAnimation(UI2);
	}
	if (player->JumpPoint == 0.0f)
	{
		SwapAnimation(UI1);
	}
}

Bar::Bar()
{
	UI1 = new Animation(this, 0.0f);
	UI1->PushBackSprite(L"JumpUI2.png");
	currentAnimation = UI1;
	UI2 = new Animation(this, 0.0f);
	UI2->PushBackSprite(L"JumpUI.png");
	currentAnimation = UI2;

}



Bar::~Bar()
{
	SAFE_DELETE(UI1);
	SAFE_DELETE(UI2);
	
}
