#include "GameSceneManager.h"
#include "MainLayer.h"
#include "RankBirdLayer.h"
#include "RankFruitLayer.h"

void GameSceneManger::createMainScene(){
	mainScene = Scene::create();
	MainLayer* layer = MainLayer::create();
	layer->sceneManager = this;
	mainScene->addChild(layer);
}


void GameSceneManger::goToFlappyScene(int i){};

void GameSceneManger::goToSquishyScene(int i){};

void GameSceneManger::goToGameScene(){

};

void GameSceneManger::goToMainScene(){
    Director::getInstance()->setDepthTest(true);
    mainScene = Scene::create();
    MainLayer* layer = MainLayer::create();
    mainScene->addChild(layer);
    layer->sceneManager = this;
    auto ss = TransitionFade::create(1,mainScene);
    Director::getInstance()->replaceScene(ss);
};

void GameSceneManger::goToSetScene(){};

void GameSceneManger::goToRankBirdScene(){
    Director::getInstance()->setDepthTest(true);
    rankScene = Scene::create();
    RankBirdLayer* layer = RankBirdLayer::create();
    rankScene->addChild(layer);
    layer->sceneManager = this;
    auto ss = TransitionPageTurn::create(1, rankScene, false);
    Director::getInstance()->replaceScene(ss);
};
void GameSceneManger::goToRankFruitScene(){
	Director::getInstance()->setDepthTest(true);
	rankScene = Scene::create();
	RankFruitLayer* layer = RankFruitLayer::create();
	rankScene->addChild(layer);
	layer->sceneManager = this;
	auto ss = TransitionPageTurn::create(1, rankScene, false);
	Director::getInstance()->replaceScene(ss);
};

void GameSceneManger::goToAboutScene(){};

void GameSceneManger::goToHelpScene(){};