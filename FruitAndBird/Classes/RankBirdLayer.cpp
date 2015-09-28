#include "RankBirdLayer.h"
USING_NS_CC;

bool RankBirdLayer::init(){
	if (!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Sprite* backGround = Sprite::create("pic/night.png");
	backGround->setAnchorPoint(Point(0, 0));
	backGround->setPosition(Point(origin.x, origin.y + visibleSize.height - backGround->getContentSize().height));
	this->addChild(backGround, 0);

	Sprite* floor = Sprite::create("pic/floor.png");
	floor->setAnchorPoint(Point(0, 0));
	floor->setPosition(Point(origin.x, origin.y));
	this->addChild(floor);
	floor->runAction(RepeatForever::create(
		Sequence::create(
		MoveTo::create(0.5, Point(-120, 0)),
		MoveTo::create(0, Point(0, 0)),
		NULL
		)));

	Sprite* rank = Sprite::create("pic/rankBackground.png");
	rank->setPosition(Point(270, 530));
	this->addChild(rank, 1);
	Sprite* title = Sprite::create("pic/rankBird.png");
	title->setPosition(Point(270, 850));
	this->addChild(title, 1);

	MenuItemImage* menuItem =  MenuItemImage::create(
		"button/menu.png",
		"button/menu_off.png",
		CC_CALLBACK_1(RankBirdLayer::menuCallBack0, this)
		);
	menuItem->setPosition(Point(80, 50));

	MenuItemImage* nextItem = MenuItemImage::create(
		"button/next.png",
		"button/next_off.png",
		CC_CALLBACK_1(RankBirdLayer::menuCallBack1, this)
		);
	nextItem->setPosition(Point(460, 50));

	Menu* menu = Menu::create(menuItem, nextItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 10);
	int* tmpBird = new int[5];


	return true;
}

void RankBirdLayer::menuCallBack0(Ref* pSender){
	sceneManager->goToMainScene();
}

void RankBirdLayer::menuCallBack1(Ref* pSender){
	sceneManager->goToRankFruitScene();
}

void RankBirdLayer::save(int newScore){

}
void RankBirdLayer::load(){
	for (int i = 0; i < 5; i++){
		
	}
}