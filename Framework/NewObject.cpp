#include "pch.h"
#include "NewObject.h"


NewObject::NewObject()
{
}

void NewObject::OnUpdate()
{

	
	if (del2 == true) {
		deltime += FWAPP->DeltaTime() * 1;
	
	}

	if (deltime >= 2.0f)
	{
		printf("몬스터 생성\n");
		Monster* mt = new Monster(L"Monster.png");

		mt->SetPosition(850.0f, 600.0f);
		mt->scale.x = 2.0f;
		mt->scale.y = 2.0f;
		mt->at2 = at2;
		mt->no = this;
		scene->PushBackGameObject(mt);

		del2 = false;
		deltime = 0;
	}


}


NewObject::~NewObject()
{
}
