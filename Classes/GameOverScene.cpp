#include "GameOverScene.h"

USING_NS_CC;


GameOverLayer::GameOverLayer(int playSceneNum)
{
	//this->score = score;
	this->playSceneNum = playSceneNum;
}

GameOverLayer* GameOverLayer::createScene(int playSceneNum)
{
	GameOverLayer *gover = new GameOverLayer(playSceneNum);

	if (gover && gover->init()) {
		gover->autorelease();
		return gover;
	}
	CC_SAFE_DELETE(gover);
	return nullptr;
}

bool GameOverLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//��ӱ�����ͼ.
//	auto bg = TMXTiledMap::create("map/blue_bg.tmx");
//	this->addChild(bg);
	auto bg = Sprite::create("background/gameover.png");
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bg);

	//���÷������ӱ���
//	ParticleSystem *ps = ParticleSystemQuad::create("particle/light.plist");
//	ps->setPosition(Vec2(visibleSize.width, visibleSize.height - 200) / 2);
//	this->addChild(ps);

//	auto top = Sprite::create("gameover.png");
	//ê�������½�
//	top->setAnchorPoint(Vec2(0, 0));
//	top->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height / 2));
//	this->addChild(top);

//����Ŀ¼��
	auto Directory = Sprite::create("menu/game2.png");
	auto Directory0 = Sprite::create("menu/game2_0.png");
	auto DirectoryMenuItem = MenuItemSprite::create(
		Directory,
		Directory0,
		CC_CALLBACK_1(GameOverLayer::menuItemCallback, this));

	DirectoryMenuItem->setTag(ActionType1::Menu1);
	auto DirectoryMenu = Menu::create(DirectoryMenuItem, NULL);
	DirectoryMenu->setPosition(origin.x + visibleSize.width / 5 * 4, origin.y + visibleSize.height / 7);
	DirectoryMenu->alignItemsVerticallyWithPadding(12);
	addChild(DirectoryMenu);

	//������ť��
	auto Goon = Sprite::create("menu/game3.png");
	auto Goon0 = Sprite::create("menu/game3_0.png");
	auto GoonMenuItem = MenuItemSprite::create(
		Goon,
		Goon0,
		CC_CALLBACK_1(GameOverLayer::menuItemCallback, this));

	GoonMenuItem->setTag(ActionType1::Menu2);
	auto GoonMenu = Menu::create(GoonMenuItem, NULL);
	GoonMenu->setPosition(origin.x + visibleSize.width / 5 * 1, origin.y + visibleSize.height / 7);
	GoonMenu->alignItemsVerticallyWithPadding(12);
	addChild(GoonMenu);
	
/*
	//ע�� �����¼�������
	auto listener = EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);

	auto i = this->playSceneNum;
	listener->onTouchBegan = [i](Touch* touch, Event* event){
		switch (i)
		{
		case 1:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneOne::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 2:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneTwo::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 3:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneThree::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 4:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneFour::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 5:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneFive::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 6:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneSix::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 7:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneSeven::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 8:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneEight::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 9:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneNine::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		default:
			break;
		}
		log("GameOVERisTouched");
		//Director::getInstance()->popScene();//����ʹ��
		//auto tsc = TransitionFade::create(1.0f, PlaySceneOne::createScene());
		//Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		
		//if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
			//SimpleAudioEngine::getInstance()->playEffect(sound_1);
		//}
		return false;
	};

	// ��� �����¼�������
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
*/

	return true;
}

void GameOverLayer::menuItemCallback(cocos2d::Ref *sender)
{

	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect(sound_1);
	}
	Scene* tsc = nullptr;
	MenuItem* menuItem1 = (MenuItem*)sender;
	if(menuItem1->getTag() == ActionType1::Menu1)
		tsc = TransitionFade::create(1.0f, DirectoryMenuLayer::createScene());
	else
	{
		auto i = this->playSceneNum;
		switch (i){
		case 1:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneOne::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 2:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneTwo::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 3:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneThree::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 4:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneFour::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 5:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneFive::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 6:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneSix::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 7:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneSeven::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 8:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneEight::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		case 9:
		{
			log("GameOVERisTouched");
			//Director::getInstance()->popScene();//����ʹ��
			auto tsc = TransitionFade::create(1.0f, PlaySceneNine::createScene());
			Director::getInstance()->replaceScene(tsc);		//�Ѿ���дԭ����pushScene
		}break;
		default:
			break;
		}
	}

	if (tsc)
		//Director::getInstance()->pushScene(tsc);
		Director::getInstance()->replaceScene(tsc);
}

void GameOverLayer::onExit()
{
	Layer::onExit();	
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
}