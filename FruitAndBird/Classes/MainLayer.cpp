#include "MainLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
//初始化音乐播放
bool MainLayer::musicFlag = true;
//初始化音效播放
bool MainLayer::soundFlag = true;

// on "init" you need to initialize your instance
bool MainLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Director::getInstance()->setDepthTest(true);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	if (musicFlag)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sounds/playscene.mp3", true);
	}

    int i = cocos2d::random();
	if (i % 2 == 0)
		backGround = Sprite::create("pic/morning.png");
	else
		backGround = Sprite::create("pic/night.png");
	backGround->setAnchorPoint(Point(0,0));
	backGround->setPosition(Point(origin.x,origin.y+visibleSize.height-backGround->getContentSize().height));
	this->addChild(backGround,0);

	Sprite* floor = Sprite::create("pic/floor.png");
	floor->setAnchorPoint(Point(0, 0));
	floor->setPosition(Point(origin.x, origin.y));
	this->addChild(floor);
	floor->runAction(RepeatForever::create(
		Sequence::create(
		MoveTo::create(0.5, Point(-120, 0)),
		MoveTo::create(0, Point(0, 0)),
		NULL)
		));

	effectNode = NodeGrid::create();
	this->addChild(effectNode, 10);
	Sprite* title = Sprite::create("pic/title.png");
	title->setPosition(Point(270, 800));
	effectNode->addChild(title, 12);
	Director::getInstance()->setDepthTest(false);
	effectNode->runAction(RepeatForever::create(
		Ripple3D::create(2.0f,Size(32,24),Point(270,800),360,2,5)
		));

	//游戏开始
	MenuItemImage* gameItem = MenuItemImage::create(
		"button/start.png",
		"button/start_off.png",
		CC_CALLBACK_1(MainLayer::menuCallBack0, this) //点击时执行的回调方法
		);
	gameItem->setPosition(Point(150, 600));
	//排行榜
	MenuItemImage* rankItem = MenuItemImage::create(
		"button/rank.png",
		"button/rank_off.png",
		CC_CALLBACK_1(MainLayer::menuCallBack1, this) //点击时执行的回调方法
		);
	rankItem->setPosition(Point(390, 600));
	//设置
	MenuItemImage* setItem = MenuItemImage::create(
		"button/set.png",
		"button/set_off.png",
		CC_CALLBACK_1(MainLayer::menuCallBack2, this) //点击时执行的回调方法
		);
	setItem->setPosition(Point(150, 450));
	//帮助
	MenuItemImage* helpItem = MenuItemImage::create(
		"button/help.png",
		"button/help_off.png",
		CC_CALLBACK_1(MainLayer::menuCallBack3, this) //点击时执行的回调方法
		);
	helpItem->setPosition(Point(390, 450));
	//
	MenuItemImage* aboutItem = MenuItemImage::create(
		"button/about.png",
		"button/about_off.png",
		CC_CALLBACK_1(MainLayer::menuCallBack4, this) //点击时执行的回调方法
		);
	aboutItem->setPosition(Point(150, 300));
	//
	MenuItemImage* exitItem = MenuItemImage::create(
		"button/exit.png",
		"button/exit_off.png",
		CC_CALLBACK_1(MainLayer::menuCallBack5, this) //点击时执行的回调方法
		);
	exitItem->setPosition(Point(390, 300));

	Menu* menu = Menu::create(gameItem, rankItem, setItem, helpItem, aboutItem,exitItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 10);
	return true;
}

void MainLayer::menuCallBack0(Ref* pSender)
{
	//initTitle();
	sceneManager->goToGameScene();
}
void MainLayer::menuCallBack1(Ref* pSender)
{
	initTitle();
    sceneManager->goToRankBirdScene();
}
void MainLayer::menuCallBack2(Ref* pSender)
{
	//initTitle();
	sceneManager->goToSetScene();
}
void MainLayer::menuCallBack3(Ref* pSender)
{
	//initTitle();
	sceneManager->goToHelpScene();
}
void MainLayer::menuCallBack4(Ref* pSender)
{
	//initTitle();
	sceneManager->goToAboutScene();
}
void MainLayer::menuCallBack5(Ref* pSender)
{
	//结束游戏
	Director::getInstance()->end();
}

void MainLayer::initTitle()
{
    Sprite* title = Sprite::create("pic/title.png");
    //设置精灵位置
    title->setPosition(Point(270, 800));
    //将精灵添加到布景中
    this->addChild(title, 10);
    this->removeChild(effectNode);
    
}