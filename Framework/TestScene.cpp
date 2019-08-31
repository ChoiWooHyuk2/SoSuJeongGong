#include "pch.h"
#include "TestScene.h"
#include "TestObject.h"
#include "BackScene.h"
#include "Bar.h"
#include "Bar2.h"
#include "Attack.h"
#include "Monster.h"
#include "NewObject.h"
TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}

void TestScene::GroundSet()
{
	BackScene* Ground = new BackScene(L"bottom.png");
	BackScene* Ground2 = new BackScene(L"bottom.png");
	BackScene* Ground3 = new BackScene(L"bottom.png");
	BackScene* Ground4 = new BackScene(L"bottom.png");
	BackScene* Ground5 = new BackScene(L"bottom.png");
	BackScene* Ground6 = new BackScene(L"bottom.png");

	Ground->SetPosition(64.0f, 715.0f);
	Ground->scale.x = 1.7f;
	Ground->scale.y = 1.7f;

	Ground2->SetPosition(281.0f, 715.0f);
	Ground2->scale.x = 1.7f;
	Ground2->scale.y = 1.7f;

	Ground3->SetPosition(497.0f, 715.0f);
	Ground3->scale.x = 1.7f;
	Ground3->scale.y = 1.7f;

	Ground4->SetPosition(714.0f, 715.0f);
	Ground4->scale.x = 1.7f;
	Ground4->scale.y = 1.7f;

	Ground5->SetPosition(930.0f, 715.0f);
	Ground5->scale.x = 1.7f;
	Ground5->scale.y = 1.7f;

	Ground6->SetPosition(930.0f, 600.0f);
	Ground6->scale.x = 1.7f;
	Ground6->scale.y = 1.7f;

	PushBackGameObject(Ground);
	PushBackGameObject(Ground2);
	PushBackGameObject(Ground3);
	PushBackGameObject(Ground4);
	PushBackGameObject(Ground5);
	PushBackGameObject(Ground6);
	
}

void TestScene::Initialize()
{
	TestObject* Player = new TestObject();
	BackScene* bk = new BackScene(L"BackGround.png");
	Bar* bar = new Bar();
	Bar2* bar2 = new Bar2();
	Attack* at = new Attack();
	Monster* mt = new Monster(L"Monster.png");
	NewObject* no = new NewObject();
	


	at->SetPosition(512.0f, 900.0f);
	at->scale.x = 3.0f;
	at->scale.y = 3.0f;
	at->Player = Player;
	

	bk->SetPosition(512.0f, 384.0f);


	bar->SetPosition(150.0f, 50.0f);
	bar->player = Player;
	bar->scale.x = 1.6f;
	bar->scale.y = 1.6f;

	bar2->SetPosition(75.0f, 50.0f);
	bar2->player = Player;
	bar2->scale.x = 1.6f;
	bar2->scale.y = 1.6f;

	Player->SetPosition(512.0f, 384.0f);
	Player->scale.x = 2.0f;
	Player->scale.y = 2.0f;
	Player->Att = at;
	Player->ms = mt;
	Player->no = no;


	mt->SetPosition(850.0f, 600.0f);
	mt->scale.x = 2.0f;
	mt->scale.y = 2.0f;
	mt->at2 = at;


	mt->no = no;
	no->at2 =at;



	PushBackGameObject(bk);
	GroundSet();
	PushBackGameObject(at);
	PushBackGameObject(mt);
	PushBackGameObject(Player);
	PushBackGameObject(no);
	PushBackGameObject(bar);
	PushBackGameObject(bar2);

	
}
