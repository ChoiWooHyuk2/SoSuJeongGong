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
//À½¾Ç
	SoundEvent* se = new SoundEvent();
	printf("À½¾ÇÀÐ´ÂÁß");
	FWSOUND->loadFile(L"Images_of_Tomorrow.mp3",se);
	FWSOUND->PlaySoundEvent(se);
	printf("À½¾ÇÀÐ´Â³¡³²");
	bk->SetPosition(512.0f, 384.0f);
	StartButton* start = new StartButton(L"startbutton.png");
	start->SetPosition(500.0f, 500.0f);
	PushBackGameObject(bk);
	PushBackGameObject(start);
}

FirstScene::~FirstScene()
{
}
