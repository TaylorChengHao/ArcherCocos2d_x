#ifndef _GROUND
#define _GROUND
#include <iostream>
#include <cocos2d.h>
USING_NS_CC;

class Ground : public Sprite
{
public:
	//����ĳߴ�
	Size groundSize;
	PhysicsBody* groundPhysicsBody;
	//Ĭ�ϵĳ�ʼ��
	virtual bool init();
	//�Զ���ߴ�ĳ�ʼ��
	bool init(Size &groundSize);
	CREATE_FUNC(Ground);
};

#endif
#pragma once
