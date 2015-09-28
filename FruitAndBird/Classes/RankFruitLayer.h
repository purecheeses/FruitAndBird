#ifndef _RankFruitLayer_H_
#define _RankFruitLayer_H_
#include "cocos2d.h"
#include "GameSceneManager.h"

USING_NS_CC;
class RankFruitLayer :public Layer{
public:
	//std::string scoreBird[5];
	//Label* labels;
	GameSceneManger* sceneManager;
public:
	virtual bool init();
	//void RankFruitLayer::menuCallBack0(Ref* pSender);
	//void RankFruitLayer::menuCallBack1(Ref* pSender);
	CREATE_FUNC(RankFruitLayer);
};

#endif