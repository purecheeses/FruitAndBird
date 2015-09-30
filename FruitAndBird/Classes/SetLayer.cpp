#include "SetLayer.h"
#include "MainLayer.h"
#include "SimpleAudioEngine.h"
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

	Sprite* sound = Sprite::create("pic/sound.png");
	sound->setPosition(Point(100, 140));
	pauseBack->addChild(sound, 1);

	CheckBox* checkMusic = CheckBox::create(
		"button/sound_on.png",
		"button/sound_off.png",
		"button/sound_off.png",
		"button/sound_stop.png",
		"button/sound_stop.png"
		);
	pauseBack->addChild(checkMusic, 1);
	checkMusic->setPosition(Point(320, 220));
	checkMusic->setSelectedState(!MainLayer::musicFlag);
	checkMusic->addEventListener(CC_CALLBACK_2(SetLayer::selectedEvent0, this));

	CheckBox* checkSound = CheckBox::create(
		"button/sound_on.png",
		"button/sound_off.png",
		"button/sound_off.png",
		"button/sound_stop.png",
		"button/sound_stop.png"
		);
	pauseBack->addChild(checkSound, 1);
	checkSound->setPosition(Point(320, 140));
	checkSound->setSelectedState(!MainLayer::soundFlag);
	checkSound->addEventListener(CC_CALLBACK_2(SetLayer::selectedEvent1, this));

	return true;
}

void SetLayer::selectedEvent0(Ref* pSender, CheckBox::EventType type)
{
	switch (type)
	{
	case CheckBox::EventType::SELECTED:
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		MainLayer::musicFlag = false;
		break;
	case CheckBox::EventType::UNSELECTED:
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		MainLayer::musicFlag = true;
		break;
	default:
		break;
	}
}
void SetLayer::selectedEvent1(Ref* pSender, CheckBox::EventType type)
{
	switch (type)
	{
	case CheckBox::EventType::SELECTED:
		MainLayer::soundFlag = false;
		break;
	case CheckBox::EventType::UNSELECTED:
		MainLayer::soundFlag = true;
		break;
	default:
		break;
	}
}
void SetLayer::menuCallBack(Ref* pSender){
	sceneManager->goToMainScene();
}