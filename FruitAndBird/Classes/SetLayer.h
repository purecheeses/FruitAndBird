#ifndef _SetLayer_H_
#define _SetLayer_H_

#include "cocos2d.h"
#include "GameSceneManager.h"

USING_NS_CC;
using namespace ui;

class SetLayer :public Layer{
public:
	GameSceneManger* sceneManager;
public:
	void menuCallBack(Ref* pSender);
	virtual bool init();
	CREATE_FUNC(SetLayer);
};


#endif