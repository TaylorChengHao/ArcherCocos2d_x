#include "arrow.h"
bool Arrow::init()
{
	
	
	if (!Sprite::initWithSpriteFrameName("arrow1.png"))
	{
		//log("TTTTTTTTTEEEEEEEEEEEEEEXXXXXXXXXXXXXXTTTTTTTTTTTT");
		return false;
	}
	

	auto visibleSize = Director::getInstance()->getVisibleSize();

	//������������
	body = PhysicsBody::createBox(Size(this->getContentSize().width*2/3,this->getContentSize().height));
	body->setGravityEnable(0);
	setPhysicsBody(body);
	//setTextureRect(Rect(0, 0, groundSize.width, groundSize.height));
	getPhysicsBody()->setRotationEnable(true);
	setContentSize(visibleSize);
	
	//������ײ����
	contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Arrow::onContactBegin, this);
	contactListener->onContactPostSolve = CC_CALLBACK_2(Arrow::onContactPostSolve, this);
	contactListener->onContactPreSolve = CC_CALLBACK_2(Arrow::onContactPreSolve, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(Arrow::onContactSeparate, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	return true;
}


void Arrow::shotend(Layer* map) {
	auto p = this->getPosition();	//����hero�ڵ�λ��
	auto hero = this->getParent(); //
	auto phero = hero->getPosition();		//Ӣ�۵�λ��
	auto pmap = map->getPosition();			//��ͼ��λ��
	this->removeFromParentAndCleanup(true);
	map->addChild(this);
	this->setPosition(p.x + phero.x - pmap.x, p.y + phero.y - pmap.y);
	this->body->setGravityEnable(1);
	//removeFromParentAndCleanup(true);
}

void Arrow::onExit() {
	Sprite::onExit();
	
}

bool Arrow::onContactBegin(PhysicsContact& contact) {
	return true;
}

bool Arrow::onContactPreSolve(PhysicsContact&  contact, PhysicsContactPreSolve&  solve) {
	return true;
}

void Arrow::onContactPostSolve(PhysicsContact& contact, const PhysicsContactPostSolve& solve) {

}

void Arrow::onContactSeparate(PhysicsContact& contact) {
	switch (contact.getShapeA()->getBody()->getContactTestBitmask() |
		contact.getShapeB()->getBody()->getContactTestBitmask())
	{
	
	case ARROW_BIT_MASK | GROUND_BIT_MASK://�����е���
	{
		//auto delayTime = DelayTime::create(2.0f);
		//this->runAction(Sequence::create(delayTime));
		this->removeFromParentAndCleanup(true);
		log("arrow hit ground");
	}
	break;
	default:
		break;
	}
}