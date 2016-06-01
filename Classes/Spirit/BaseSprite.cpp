
#include "BaseSprite.h"
BaseSprite::BaseSprite() :
points(NULL),
pointCounter(0){
}
BaseSprite::~BaseSprite(){
}


bool BaseSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	setspeed(20);
	sprite = Sprite::create("XenZhao_Charge.png");
	this->addChild(sprite);
	return true;
}
BaseSprite* BaseSprite::createSprite(Vector<Node*> points){
	BaseSprite* sprite = new BaseSprite();
	if (sprite && sprite->init())
	{
		sprite->setPositionPoints(points);
		sprite->goOnFoot();
		sprite->autorelease();
		return sprite;
	}
	else
	{
		delete sprite;
		sprite = NULL;
		return NULL;
	}
}

Node* BaseSprite::currPosition(){
	if (!points.empty())
	{
		return points.at(pointCounter);
	}
	return NULL;
}

Node * BaseSprite::nextPosition(){
	int maxPointsCount = points.size();
	pointCounter++;
	if (pointCounter < maxPointsCount)
	{
		auto node = points.at(pointCounter);
		return node;
	}
	
	return NULL;

}

void BaseSprite::goOnFoot(){
	auto currPoint = currPosition();
	sprite->setPosition(currPoint->getPosition());
	auto nextPoint = nextPosition();
	if (nextPoint != NULL)
	{
		auto duration = currPoint->getPosition().getDistance(nextPoint->getPosition()) / getspeed();
		auto callFun = CallFuncN::create(CC_CALLBACK_0(BaseSprite::goOnFoot, this));
		auto move = MoveTo::create(duration, nextPoint->getPosition());
		auto action = Sequence::create(move, callFun, NULL);
		sprite->runAction(action);
		
	}
	
}

void BaseSprite::setPositionPoints(Vector<Node*> points){
	this->points = points;
}


