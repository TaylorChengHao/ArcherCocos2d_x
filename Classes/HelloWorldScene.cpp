#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	
	/*  �ٷ�ԭ���ļ�  ==��  ��ʼ��  
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;

	�ٷ�ԭ���ļ�  == �� ����     */


	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/loading_texture.plist");

	// add "HelloWorld" splash screen"
	//auto bg = TMXTiledMap::create("map/red_bg.tmx");

	// add the sprite as a child to this layer
	//this->addChild(bg);

	// add a label shows "Hello World"
	// create and initialize a label

	//	������Ϸ��ʼ���س�������Ϸ���ƣ�
	auto label = Label::createWithTTF("Archer", "fonts/Marker Felt.ttf", 99);
	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	//�������ñ���ͼƬ��
	auto shezhiSprite = Sprite::create("background/load.jpg");
	shezhiSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(shezhiSprite, 0);

	//������Ϸlogo��
	auto logo = Sprite::create("HelloWorldScene/logo.png");
	logo->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 2));
	this->addChild(logo,0);
	
	//������Ϸ��ʼ���ض�����
	auto sprite = Sprite::create("HelloWorldScene/loding4.png");
	sprite->setPosition(logo->getPosition() - Vec2(origin.x + 0, origin.y + logo->getContentSize().height / 2 + 100));
	this->addChild(sprite,0);

	///////////////������ʼ//////////////////////
	Animation* animation = Animation::create();
	for (int i = 1; i <= 4; i++)
	{
		__String *frameName = __String::createWithFormat("loding%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.5f);           //��������֡����ʱ��
	animation->setRestoreOriginalFrame(true);    //����ִ�к�ԭ��ʼ״̬

	Animate* action = Animate::create(animation);
	sprite->runAction(RepeatForever::create(action));
	//////////////////��������///////////////////

	m_nNumberOfLoaded = 0;

	Director::getInstance()->getTextureCache()->addImageAsync("texture/home_texture.png",
		CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("texture/setting_texture.png",
		CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));

	Director::getInstance()->getTextureCache()->addImageAsync("texture/gameplay_texture.png",
		CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));


	_loadingAudioThread = new std::thread(&HelloWorld::loadingAudio, this);

	//////////////////////////////////////

	return true;

}

/**********  ����ע��  ************
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
**********  ����ע��  ************/


void HelloWorld::loadingTextureCallBack(Texture2D *texture)
{

	switch (m_nNumberOfLoaded++)
	{
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/home_texture.plist", texture);
		log("home textrue ok.");
		break;
	case 1:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/setting_texture.plist", texture);
		log("setting textrue ok.");
		break;
	case 2:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/gameplay_texture.plist", texture);
		log("gamepla textrue ok.");
		this->schedule(schedule_selector(HelloWorld::delayCall), 1, 1, 3);
		//float interval, unsigned int repeat, float delay
		break;
	}

}

void HelloWorld::delayCall(float dt)
{
	auto sc = HomeMenuLayer::createScene();
	Director::getInstance()->replaceScene(sc);
}

void HelloWorld::loadingAudio()
{
	log("loadAudio");
	//��ʼ�� ����
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_1);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_2);
	//��ʼ����Ч  TODO  Ԥ�����û����������ֲ��ʱ����Ҫ���ԡ�
	//SimpleAudioEngine::getInstance()->preloadEffect(sound_1);

}


void HelloWorld::onExit()
{
	Layer::onExit();
	_loadingAudioThread->join();
	CC_SAFE_DELETE(_loadingAudioThread);
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("texture/loading_texture.plist");
	Director::getInstance()->getTextureCache()->removeTextureForKey("texture/loading_texture.png");
	this->unschedule(schedule_selector(HelloWorld::delayCall));
}