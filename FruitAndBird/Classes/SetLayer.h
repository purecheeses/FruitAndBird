#ifndef _SetLayer_H_
#define _SetLayer_H_

#include "cocos2d.h"
#include "GameSceneManager.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class SetLayer :public Layer{
public:
	GameSceneManger* sceneManager;
public:
	void menuCallBack(Ref* pSender);
	virtual bool init();
	void selectedEvent0(Ref* pSender, CheckBox::EventType type);
	void selectedEvent1(Ref* pSender, CheckBox::EventType type);
	CREATE_FUNC(SetLayer);
};


#endif