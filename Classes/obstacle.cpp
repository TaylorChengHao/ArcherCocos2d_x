#include "obstacle.h"

bool Obstacle::init() {
	count = 0;
	Sprite::initWithFile("obstaclebig.png");
	body = PhysicsBody::createBox(this->getContentSize());
	body->setGravityEnable(1);
	//Vect impulse = Vect(200.0f, 0.0f);
	//body->setVelocity(impulse);
	body->setRotationEnable(true);
	setPhysicsBody(body);
	schedule(schedule_selector(Obstacle::MyUpdate), 0.2f);	//ÿ0.2��ִ��һ��

	return true;
}

void Obstacle::MyUpdate(float time) {
	if (count < 60) {
		Sprite::initWithFile("obstaclebig.png");
		//Vect impulse = Vect(200.0f, 0.0f);
		//body->setVelocity(impulse);
		++count;
	}
	else if (60 <= count&&count < 120) {
		Sprite::initWithFile("obstaclebig.png");
		//Vect impulse = Vect(-200.0f, 0.0f);
		//body->setVelocity(impulse);
		++count;
	}
	else if (count == 120)count = 0;
}