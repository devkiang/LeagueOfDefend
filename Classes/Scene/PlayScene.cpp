
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
	time = Label::createWithSystemFont("5", "Arial", 24);
	time->setPosition(Point(winSize.width / 2, winSize.height-20));
	addChild(time,-10);
	scheduleOnce(schedule_selector(PlayScene::firstLogic), 5.0f);
	scheduleUpdate();
	//schedule(schedule_selector(PlayScene::logic), 3.0f);//每三秒加一个精灵
	
	return true;

}
void PlayScene::update(float t){
	currTime -= t;
	if (currTime >= 0){
		char* mtime = new char[10];
		//此处只是显示分钟数和秒数  自己可以定义输出时间格式  
		sprintf(mtime, "%d : %d", (int)currTime / 60, (int)currTime % 60);
		time->setString(mtime);
	}
	
	
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
void PlayScene::firstLogic(float t){
	
		const std::string text = std::to_string(0);
		time->setString(text);
		this->addMonster();
		schedule(schedule_selector(PlayScene::logic), 3.0f);//add a enemy sprite after three second 
	
}