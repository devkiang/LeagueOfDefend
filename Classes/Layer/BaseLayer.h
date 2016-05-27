
#ifndef BASELAYER_H
#define BASELAYER_H
#include "cocos2d.h"

class BaseLayer:public cocos2d::Layer
{
public:
    cocos2d::Vector<cocos2d::Sprite*> sprites = cocos2d::Vector<cocos2d::Sprite*>();
	virtual void initEvent();
	CREATE_FUNC(BaseLayer);
	// 重载触摸回调函数
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchDown(cocos2d::Sprite * sender);//手指按下屏幕时在这里判断是否有精灵被点击
	virtual void onTouchUp(cocos2d::Sprite * sender);//手指拿起时交给子类去实现
    virtual void onLongPressed(cocos2d::Sprite * sender);
    virtual void onDoubleTouch(cocos2d::Sprite * sender);
    virtual void onMove(cocos2d::Sprite * sender);
	//cocos2d::Vector<Sprite*> pushSprite(const Sprite& sprite);
	
private:
protected:
	void pushSprite(cocos2d::Sprite* sprite);//push sprite to vector 
	void turnToScene(cocos2d::Scene* scene);//change to next scene
};

#endif