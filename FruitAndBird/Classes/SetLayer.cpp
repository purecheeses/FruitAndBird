#include "SetLayer.h"
using namespace cocos2d;
using namespace ui;
using namespace std;

bool SetLayer::init(){
	if (!Layer::init()){
		return false;
	}
	//获取可见区域尺寸
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//获取可见区域原点坐标
	Point origin = Director::getInstance()->getVisibleOrigin();
	//创建背景
	Sprite* backGround = Sprite::create("pic/morning.png");
	//设置锚点
	backGround->setAnchorPoint(Point(0, 0));
	//设置精灵对象的位置
	backGround->setPosition(Point(origin.x, origin.y + visibleSize.height - backGround->getContentSize().height));
	//将精灵添加到布景中
	this->addChild(backGround, 0);

	//创建地面精灵
	Sprite* floor1 = Sprite::create("pic/floor.png");
	//设置锚点
	floor1->setAnchorPoint(Point(0, 0));
	//设置精灵对象位置
	floor1->setPosition(Point(origin.x, origin.y));
	this->addChild(floor1);
	floor1->runAction(RepeatForever::create(
		Sequence::create(
		MoveTo::create(0.5, Point(-120, 0)),
		MoveTo::create(0, Point(0, 0)),
		NULL
		)));

	Sprite* pauseBack = Sprite::create("pic/setBack.png");
	pauseBack->setPosition(Point(270, 500));
	this->addChild(pauseBack, 10);

	//音乐按钮
	Sprite* music = Sprite::create("pic/music.png");
	pauseBack->addChild(music, 1);
	music->setPosition(Point(100, 220));


	return true;
}

void SetLayer::menuCallBack(Ref* pSender){
	sceneManager->goToMainScene();
}