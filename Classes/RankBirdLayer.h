#ifndef _RankBirdLayer_H_
#define _RankBirdLayer_H_
#include "cocos2d.h"
#include "GameSceneManager.h"

USING_NS_CC;
class RankBirdLayer :public Layer{
public:
	std::string scoreBird[5];
	Label* labels;
    GameSceneManger* sceneManager;
public:
	virtual bool init();
	void load();
	void save(int);
	void RankBirdLayer::menuCallBack0(Ref* pSender);
	void RankBirdLayer::menuCallBack1(Ref* pSender);
	CREATE_FUNC(RankBirdLayer);
};

#endif