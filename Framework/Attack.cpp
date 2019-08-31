#include "pch.h"
#include "Attack.h"


Attack::Attack()
{
	attackRight = new Animation(this , 0.3f);
	attackRight->PushBackSprite(L"AttackSkill.png");
	attackRight->PushBackSprite(L"AttackSkill11.png");
	attackRight->PushBackSprite(L"AttackSkill12.png");

	attackLeft = new Animation(this, 0.3f);
	attackLeft->PushBackSprite(L"AttackSkill2.png");
	attackLeft->PushBackSprite(L"AttackSkill21.png");
	attackLeft->PushBackSprite(L"AttackSkill22.png");

	currentAnimation = attackLeft;
}




Attack::~Attack()
{
	SAFE_DELETE(attackRight);
	SAFE_DELETE(attackLeft);
}

void Attack::OnUpdate()
{
	UpdateAnimation();
	if (Player->AttackMotion)
	{
		if (Player->Right ) 
		{		
			this->pos.x = Player->pos.x + 150;
			this->pos.y = Player->pos.y;
		}
		if (Player->Left) 
		{
			this->pos.x = Player->pos.x - 150;
			this->pos.y = Player->pos.y;
		}
		Ani = true;
	}
	else
	{
		if (Player->JumpPoint == 1000.0f && !Player->AttackMotion)
		{
			if(Player->Right && Ani)
				Player->SwapAnimation(Player->RightWalkAnimation);
			if(Player->Left && Ani)
				Player->SwapAnimation(Player->LeftWalkAnimation);

			Ani = false;
		}

		if (Player->Right &&  Player->pos.y > 700 && Player->JumpPoint < 1000) {
			Player->SwapAnimation(Player->RightWalkAnimation);
		}
		if (Player->Left  &&  Player->pos.y > 700 && Player->JumpPoint < 1000) {
			Player->SwapAnimation(Player->LeftWalkAnimation);
		}

		this->SetPosition(1000,1000);
	}


}
