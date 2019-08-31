#include "pch.h"
#include "Bar2.h"


void Bar2::OnUpdate()
{
	if (player->Attack)
	{
		SwapAnimation(UI1);
	}
	if (!player->Attack)
	{
		SwapAnimation(UI2);
	}
}

Bar2::Bar2()
{
	UI1 = new Animation(this, 0.0f);
	UI1->PushBackSprite(L"AttackUI.png");
	currentAnimation = UI1;
	UI2 = new Animation(this, 0.0f);
	UI2->PushBackSprite(L"AttackUI2.png");
	currentAnimation = UI2;

}



Bar2::~Bar2()
{
	SAFE_DELETE(UI1);
	SAFE_DELETE(UI2);

}
