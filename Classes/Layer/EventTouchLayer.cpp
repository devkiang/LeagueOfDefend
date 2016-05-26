
#include "EventTouchLayer.h"
USING_NS_CC;
void EventTouchLayer::initEvent(){
	
	auto touchLisener = EventListenerTouchOneByOne::create();
	// �����Ƿ����´��ݴ�����true��ʾ�����´�����
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
	// 1Ŀ�꾫��
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//ȫ������ķ�Χ
	Point locationInNode = target->convertTouchToNodeSpace(touch);
	// 3Ŀ�꾫���λ�ô�С
	Size size = target->getContentSize();
	Rect rect = Rect(0, 0, size.width, size.height);
	// 4ȫ������ķ�Χ�Ƿ���Ŀ�꾫����
	if (rect.containsPoint(locationInNode))
	{
		target->setOpacity(180);//����͸����
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