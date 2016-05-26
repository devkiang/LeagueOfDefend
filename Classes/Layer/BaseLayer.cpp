
#include "BaseLayer.h"
USING_NS_CC;
void BaseLayer::initEvent(){
	
	auto touchLisener = EventListenerTouchOneByOne::create();
	// …Ë÷√ «∑ÒœÚœ¬¥´µ›¥•√˛£¨true±Ì æ≤ªœÚœ¬¥•√˛°£
	touchLisener->setSwallowTouches(true);
	touchLisener->onTouchBegan = CC_CALLBACK_2(BaseLayer::onTouchBegan, this);
	touchLisener->onTouchEnded = CC_CALLBACK_2(BaseLayer::onTouchEnded, this);
	
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

/**
 *  push sprite to array
 *
 *  @param sprite node
 */
void BaseLayer::pushSprite(Sprite*& sprite){
    this->sprites.pushBack(sprite);
}

/**
 *  判断精灵touch事件是否在有效范围内
 *
 *  @param rect  精灵的大小位置
 *  @param point 本地坐标
 */
bool isContainsPoint(Touch *touch, Node *obj)
{
    Point locationInNode = obj->convertTouchToNodeSpace(touch);
    Size size = obj->getContentSize();
    Rect rect = Rect(0, 0, size.width, size.height);
    if (rect.containsPoint(locationInNode))//constain true
    {
        return true;
    }
    return false;
}


bool BaseLayer::onTouchBegan(Touch *touch, Event *event){
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
    if(isContainsPoint(touch, target)){
        target->setOpacity(180);
        onTouchDown(target);
        return true;
    }
    return false;
}
void BaseLayer::onTouchEnded(Touch* touch, Event* event){
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
    if(isContainsPoint(touch, target)){
        target->setOpacity(255);
        onTouchUp(target);
    }
}
#pragma mark- ======= EventTouchDelegate ===========
/*
 If subclass inherit from the this class,it is needed to override these methods in a subclass.
 */
void BaseLayer::onTouchDown(Sprite *sender){

}

void BaseLayer::onTouchUp(Sprite * sender){
    
}

void BaseLayer::onLongPressed(Sprite *sender)
{
    
}

void BaseLayer::onDoubleTouch(Sprite *sender)
{
    
}
 void BaseLayer::onMove(Sprite *sender)
{
    
}

