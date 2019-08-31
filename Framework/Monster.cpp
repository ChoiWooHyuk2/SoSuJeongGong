#include "pch.h"
#include "Monster.h"


Monster::Monster()
{
}

Monster::Monster(const wchar_t * url) :GameObject(url)
{

}


Monster::~Monster()
{
}

void Monster::OnUpdate()
{

	if (this->pos.y < 710)//중력 
		pos.y += FWAPP->DeltaTime() * 200;

	if (this->pos.x == 1020) {
		Left = true;
		Right = false;
	}
	if (this->pos.x == 0) {
		Right = true;
		Left = false;
	}

	if (Right)
		this->pos.x += 5;
	if (Left)
		this->pos.x -= 5;


	if ((at2->pos.x <= this->pos.x + 4 && at2->pos.x >= this->pos.x - 10) && (at2->pos.y >= this->pos.y - 4 && at2->pos.y <= this->pos.y + 4))
	{
	
		printf("삭제");
		scene->Destroy(this);
	
	}

	no->del2 = true;

}
