#include "pch.h"
#include "StartButton.h"
#include "TestScene.h"
#include "Sound.h"

StartButton::StartButton()
{
}

StartButton::StartButton(const wchar_t * url) : GameObject(url)
{
}

void StartButton::OnUpdate()
{
	if (FWINPUT->GetKeyDown(VK_RETURN))
	{
		FWAPP->ChangeScene(new TestScene);

	}

}


StartButton::~StartButton()
{
}
