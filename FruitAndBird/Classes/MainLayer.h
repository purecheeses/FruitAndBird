#ifndef _MainLayer_H_
#define _MainLayer_H_

#include "cocos2d.h"
#include "GameSceneManager.h"
USING_NS_CC;

class MainLayer : public cocos2d::Layer{
public:
	Sprite* backGround;
	NodeGrid* effectNode;
	GameSceneManger* sceneManager;
	//背景音乐标志位
	static bool musicFlag;
	//音效标志位
	static bool soundFlag;
public:
	virtual bool init();
	void menuCallBack0(Ref* pSender);
	void menuCallBack1(Ref* pSender);
	void menuCallBack2(Ref* pSender);
	void menuCallBack3(Ref* pSender);
	void menuCallBack4(Ref* pSender);
	void menuCallBack5(Ref* pSender);
	void initTitle();
	CREATE_FUNC(MainLayer);
};

#endif