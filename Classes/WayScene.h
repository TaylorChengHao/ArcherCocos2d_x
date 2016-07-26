#ifndef __WAYLAYER_SCENE_H__
#define __WAYLAYER_SCENE_H__

#include "cocos2d.h"
#include "SystemHeader.h"
#include "MyUtility.h"
#include "HomeScene.h"

class WayLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	virtual void onEnterTransitionDidFinish();

	void menuBackCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(WayLayer);
};

#endif // __HELPLAYER_SCENE_H__
