#include "pch.h"
#include "TestObject.h"


TestObject::TestObject()
{
	RightjumpAnimation = new Animation(this, 0.0f);
	RightjumpAnimation->PushBackSprite(L"RightPlayerJumping.png");
	

	LeftjumpAnimation = new Animation(this, 0.0f);
	LeftjumpAnimation->PushBackSprite(L"LeftPlayerJumping.png");
	
	RightWalkAnimation = new Animation(this, 0.7f);
	RightWalkAnimation->PushBackSprite(L"RightPlayerMoving3.png");
	RightWalkAnimation->PushBackSprite(L"RightPlayerMoving2.png");
	

	LeftWalkAnimation = new Animation(this, 0.7f);
	LeftWalkAnimation->PushBackSprite(L"LeftPlayerMoving3.png");
	LeftWalkAnimation->PushBackSprite(L"LeftPlayerMoving2.png");

	RightAttackAnimation = new Animation(this, 0.7f);
	RightAttackAnimation->PushBackSprite(L"RightAttack.png");

	LeftAttackAnimation = new Animation(this, 0.7f);
	LeftAttackAnimation->PushBackSprite(L"LeftAttack.png");

	currentAnimation = LeftWalkAnimation;

	
}


TestObject::~TestObject()
{
	SAFE_DELETE(RightWalkAnimation);
	SAFE_DELETE(RightStopAnimation);
	SAFE_DELETE(RightjumpAnimation);
	SAFE_DELETE(RightAttackAnimation);
	SAFE_DELETE(LeftWalkAnimation);
	SAFE_DELETE(LeftStopAnimation);
	SAFE_DELETE(LeftjumpAnimation);
	SAFE_DELETE(LeftAttackAnimation);
}

void TestObject::OnUpdate()
{
	UpdateAnimation();
	//����
	//������
	delay += FWAPP->DeltaTime();
	//�ִϸ��̼� �ʱ�ȭ �� ���� ���
	if (delay > 3) {
		AttackMotion = false;
		Attack = true;
	}


	//����
	if ((FWINPUT->GetKeyDown('z') || FWINPUT->GetKeyDown('Z')) && Attack)
	{
		if (Right) {
			Att->SwapAnimation(Att->attackRight);
			SwapAnimation(RightAttackAnimation);
		}
		if (Left) {
			Att->SwapAnimation(Att->attackLeft);
			SwapAnimation(LeftAttackAnimation);
		}
		printf("����\n");
		AttackMotion = true;
		delay = 0;

	}
	//���� ���
	if (FWINPUT->GetKeyUp('z') || FWINPUT->GetKeyUp('Z'))
	{
		if (Right)
			SwapAnimation(RightWalkAnimation);
		if (Left)
			SwapAnimation(LeftWalkAnimation);
		
		AttackMotion = false;
		Attack = false;
	}


	//�������̵�

	 if (this->pos.x < 1020) {
		if (FWINPUT->GetKeyPressed(VK_SPACE) && FWINPUT->GetKeyPressed(VK_RIGHT) && JumpPoint > 0)
		{
			printf("�����ʺ���\n");
			SwapAnimation(RightjumpAnimation);
			this->pos.x += 2;
			this->pos.y -= 7;
			JumpPoint -= 10;
			Right = true;
			Left = false;
			stay = false;
			AttackMotion = false;
		}

		else if (FWINPUT->GetKeyDown(VK_RIGHT))
		{
			printf("�������̵�\n");
			SwapAnimation(RightWalkAnimation);
			Right = true;
			Left = false;
			stay = false;
			AttackMotion = false;
		}

		if (FWINPUT->GetKeyPressed(VK_RIGHT))
		{
			this->pos.x += 2;
	
		}

	}
	//�����̵�
	if (this->pos.x > 1) {
		if (FWINPUT->GetKeyPressed(VK_SPACE) && FWINPUT->GetKeyPressed(VK_LEFT) && JumpPoint > 0)
		{

			printf("���ʺ���\n");
			SwapAnimation(LeftjumpAnimation);
			this->pos.x -= 2;
			this->pos.y -= 7;
			JumpPoint -= 10;
			Right = false;
			Left = true;
			stay = false;
			AttackMotion = false;
		}


		else if (FWINPUT->GetKeyDown(VK_LEFT))
		{
			printf("�����̵�\n");
			SwapAnimation(LeftWalkAnimation);
			Right = false;
			Left = true;
			stay = false;
			AttackMotion = false;
		}
		if (FWINPUT->GetKeyPressed(VK_LEFT))
		{
			this->pos.x -= 2;
			
		}

	}
	//�⺻����
	if (FWINPUT->GetKeyPressed(VK_SPACE) && JumpPoint > 0 && stay)
	{
		printf("������ ����\n");
		this->pos.y -= 7;
		JumpPoint -= 10;
		if (Right)
			SwapAnimation(RightjumpAnimation);
		if (Left)
			SwapAnimation(LeftjumpAnimation);
	}

	

	//������ ���� ��� ���� ����Ʈ �ʱ�ȭ
	if (this->pos.y > 710) {
		JumpPoint = 1000.0f;
	}

	

	//Y�� ����
	if (this->pos.y < 710)//�߷� 
		pos.y += FWAPP->DeltaTime() * 200;

	//���� ���� ����
	stay = true;

	//�浹ó�� //���� ���� ���� ���� ���� ó���ϰ� ��������
	if (((ms->pos.x <= this->pos.x + 4 && ms->pos.x >= this->pos.x - 4) && (this->pos.y > 670))
	||((no->pos.x <= this->pos.x + 4 && no->pos.x >= this->pos.x - 4) && (this->pos.y > 670)))
	{
		printf("ĳ����,���ݸ�� ����\n");
		scene->Destroy(this);
		scene->Destroy(Att);
	}
}