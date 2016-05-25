
#include "cocos2d.h"
USING_NS_CC;

class EventTouchLayer:public cocos2d::Layer
{
public:
	cocos2d::Vector<Sprite*> sprites = Vector<Sprite*>();
	virtual void initEvent();
	CREATE_FUNC(EventTouchLayer);
	// ���ش����ص�����
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);
	virtual bool onClickDown(Sprite * target);
	virtual void onClickUp(Sprite * target);
	//cocos2d::Vector<Sprite*> pushSprite(const Sprite& sprite);
	void pushSprite(Sprite*& sprite);
private:

};

