
#include "EventTouchLayer.h"
USING_NS_CC;
void EventTouchLayer::initEvent(){
	
	auto touchLisener = EventListenerTouchOneByOne::create();
	// 设置是否向下传递触摸，true表示不向下触摸。
	touchLisener->setSwallowTouches(true);
	touchLisener->onTouchBegan = CC_CALLBACK_2(EventTouchLayer::onTouchBegan, this);
	touchLisener->onTouchEnded = CC_CALLBACK_2(EventTouchLayer::onTouchEnded, this);
	
	if (!sprites.empty())
	{
		int i = 0;
		for (auto sprite : sprites)
		{
			if (i>0)
			{
				_eventDispatcher->addEventListenerWithSceneGraphPriority(touchLisener->clone(), sprite);
			}
			else
			{
				_eventDispatcher->addEventListenerWithSceneGraphPriority(touchLisener, sprite);
				i++;
			}
			
			
		}
		
	}
}
bool EventTouchLayer::onTouchBegan(Touch *touch, Event *event){
	// 1
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	return onClickDown(target);
}
void EventTouchLayer::onTouchEnded(Touch* touch, Event* event){
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	onClickUp(target);
}

bool EventTouchLayer::onClickDown(Sprite * target){
	return true;
}
void EventTouchLayer::onClickUp(Sprite * target){
}
void EventTouchLayer::pushSprite(Sprite*& sprite){

	this->sprites.pushBack(sprite);
	
}