#include "SetLayer.h"
using namespace cocos2d;
using namespace ui;
using namespace std;

bool SetLayer::init(){
	if (!Layer::init()){
		return false;
	}
	//��ȡ�ɼ�����ߴ�
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//��ȡ�ɼ�����ԭ������
	Point origin = Director::getInstance()->getVisibleOrigin();
	//��������
	Sprite* backGround = Sprite::create("pic/morning.png");
	//����ê��
	backGround->setAnchorPoint(Point(0, 0));
	//���þ�������λ��
	backGround->setPosition(Point(origin.x, origin.y + visibleSize.height - backGround->getContentSize().height));
	//��������ӵ�������
	this->addChild(backGround, 0);

	//�������澫��
	Sprite* floor1 = Sprite::create("pic/floor.png");
	//����ê��
	floor1->setAnchorPoint(Point(0, 0));
	//���þ������λ��
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

	//���ְ�ť
	Sprite* music = Sprite::create("pic/music.png");
	pauseBack->addChild(music, 1);
	music->setPosition(Point(100, 220));


	return true;
}

void SetLayer::menuCallBack(Ref* pSender){
	sceneManager->goToMainScene();
}