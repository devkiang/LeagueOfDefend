
#include "PlayScene.h"
#include "BaseSprite.h"
PlayScene::PlayScene():
map(NULL),
positionPointsVector(NULL)
{

}
PlayScene::~PlayScene(){
	positionPointsVector.clear();
}


Scene* PlayScene::createScene(){
	auto scene = Scene::create();
	auto layer = PlayScene::create();
	scene->addChild(layer);
	return scene;
}


bool PlayScene::init(){
	if (!Layer::init())
	{
		return false;
	}
	auto winSize = Director::getInstance()->getWinSize();
	auto gameBg = Sprite::create("ChooseMapBg.png");
	gameBg->setPosition(Point(winSize.width / 2, winSize.height / 2));
	addChild(gameBg, -20);
	map = TMXTiledMap::create("playmap2.tmx");
	bgLayer = map->getLayer("bg");
	bgLayer->setAnchorPoint(Point(0.5f, 0.5f));
	bgLayer->setPosition(Point(winSize.width / 2, winSize.height / 2));
	objects = map->getObjectGroup("obj");
	this->addChild(map, -10);
	offX = (map->getContentSize().width - winSize.width) / 2;
	initPositionPoints(offX);
	addMonster();
	//schedule(schedule_selector(PlayScene::logic, 2.0f));
	//scheduleUpdate();
	return true;

}

void PlayScene::initPositionPoints(float offX){
	Node *runOfPoint = NULL;
	int count = 0;
	ValueMap point;
	point = objects->getObject(std::to_string(count));
	while (point.begin() != point.end())
	{
		float x = point.at("x").asFloat();
		float y = point.at("y").asFloat();
		runOfPoint = Node::create();
		runOfPoint->setPosition(Point(x - offX, y));
		this->positionPointsVector.pushBack(runOfPoint);
		count++;
		point = objects->getObject(std::to_string(count));
	}
	runOfPoint = NULL;
}
void PlayScene::addMonster(){
	BaseSprite* monster = BaseSprite::createSprite(positionPointsVector);
	this->addChild(monster, 10);

}

void PlayScene::logic(float t){
	this->addMonster();
}