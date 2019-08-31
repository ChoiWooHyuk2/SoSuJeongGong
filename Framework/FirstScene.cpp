#include "pch.h"
#include "FirstScene.h"
#include "TestScene.h"
#include "TestObject.h"
#include "BackScene.h"
#include "StartButton.h"
#include "SoundEvent.h"
#include "Sound.h"

FirstScene::FirstScene()
{
}

void FirstScene::Initialize()
{

	BackScene* bk = new BackScene(L"BackGround2.png");
//����
	SoundEvent* se = new SoundEvent();
	printf("�����д���");
	FWSOUND->loadFile(L"Images_of_Tomorrow.mp3",se);
	FWSOUND->PlaySoundEvent(se);
	printf("�����д³���");
	bk->SetPosition(512.0f, 384.0f);
	StartButton* start = new StartButton(L"startbutton.png");
	start->SetPosition(500.0f, 500.0f);
	PushBackGameObject(bk);
	PushBackGameObject(start);
}

FirstScene::~FirstScene()
{
}
