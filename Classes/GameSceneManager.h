#ifndef __GameSceneManager_H__
#define __GameSceneManager_H__
#include "cocos2d.h"

USING_NS_CC;

class GameSceneManger{
public:
	Scene* mainScene;
    Scene* rankScene;
public:
	//���������泡������ķ���
	void createMainScene();
	//ת��ײ������Ϸ����
	void goToFlappyScene(int);
	//ת��ˮ��������Ϸ����
	void goToSquishyScene(int);
	//ת����Ϸѡ�����
	void goToGameScene();
	//ת��������
	void goToMainScene();
	//ת�����ý���
	void goToSetScene();
	//ת�����а����
	void goToRankBirdScene();
	void goToRankFruitScene();
	//ת�����ڽ���
	void goToAboutScene();
	//ת����������
	void goToHelpScene();
};

#endif
