#ifndef PLAYSCENENINE
#define PLAYSCENENINE
#include "cocos2d.h"
#include "Hero.h"
#include "PlayMapNine.h"
#include "GameOverScene.h"
#include "GameDirectory.h"
#include "arrow.h"
using namespace cocos2d;
USING_NS_CC;
#include "contact_data.h"

class PlaySceneNine : public Layer {
public:
	//�ڼ�����
	int playSceneNum;
	Animation* createAnimation(std::string prefixName, int framesNum, float delay);
	Hero* hero;
	Size visibleSize;
	Point proposL, proposM,proposR;
	virtual bool init();
	bool isover;//ccQuadBezierConfig

	//��ײ���
	EventListenerPhysicsContact* contactListener;
	virtual bool onContactBegin(PhysicsContact& contact);
	virtual bool onContactPreSolve(PhysicsContact&  contact,PhysicsContactPreSolve&  solve);
	virtual void onContactPostSolve(PhysicsContact& contact, const PhysicsContactPostSolve& solve);
	virtual void onContactSeparate(PhysicsContact& contact);

	Rect ControlrectMove;
	Rect ControlrectShot;
	Rect ControlrectJump;
	EventListenerTouchOneByOne* Singlelistener;
	virtual bool onTouchBegan(Touch* touches, Event* event);
	virtual void onTouchMoved(Touch* touches, Event* event);
	virtual void onTouchEnded(Touch* touches, Event* event);
	//Singlelistener->onTouchMoved = CC_CALLBACK_2(NewScene::onTouchMoved, this);
	//Singlelistener->onTouchEnded = CC_CALLBACK_2(NewScene::onTouchEnded, this);
	bool ontouch;
	static cocos2d::Scene* createScene();
	virtual void onEnter();
	virtual void onExit();
	virtual void onEnterTransitionDidFinish();
	//virtual void onEnterTransitionDidFinish();
	PlayMapNine * map;
	Sprite * gameover;
	double distance;    //����������֮��ľ���  Ϊ��㴥��׼��
	double deltax;    //Ŀ��x��ĸı�ֵ  
	double deltay;    //Ŀ��y��ĸı�ֵ  
	double mscale;   //��ʼ��ͼ���ű���
	CREATE_FUNC(PlaySceneNine);

	Scene* gameOverScene;
	Menu* menu;
	void menuPauseCallback(Ref* pSender);
	void menuBackCallback(Ref* pSender);
	void menuResumeCallback(Ref* pSender);
	// ��ʱ�����º�����ÿ֡һ��
	void Update(float time);
	void isGameOver();
};
#endif
