
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
	// 1目标精灵
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//全屏点击的范围
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	// 3目标精灵的位置大小
	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);
	// 4全屏点击的范围是否在目标精灵上
	if (rect.containsPoint(locationInNode))
	{
		target->setOpacity(180);//设置透明度
		return true;
	}
	return false;
	//return onClickDown(target);
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