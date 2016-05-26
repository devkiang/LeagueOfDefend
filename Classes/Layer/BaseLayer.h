
#include "cocos2d.h"
USING_NS_CC;

class BaseLayer:public cocos2d::Layer
{
public:
	cocos2d::Vector<Sprite*> sprites = Vector<Sprite*>();
	virtual void initEvent();
	CREATE_FUNC(BaseLayer);
	// 重载触摸回调函数
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);
	virtual bool onClickDown(Sprite * target);//手指按下屏幕时在这里判断是否有精灵被点击
	virtual void onClickUp(Sprite * target);//手指拿起时交给子类去实现
	//cocos2d::Vector<Sprite*> pushSprite(const Sprite& sprite);
	void pushSprite(Sprite*& sprite);
private:

};

