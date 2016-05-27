
#ifndef BASELAYER_H
#define BASELAYER_H
#include "cocos2d.h"

class BaseLayer:public cocos2d::Layer
{
public:
    cocos2d::Vector<cocos2d::Sprite*> sprites = cocos2d::Vector<cocos2d::Sprite*>();
	virtual void initEvent();
	CREATE_FUNC(BaseLayer);
	// ���ش����ص�����
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchDown(cocos2d::Sprite * sender);//��ָ������Ļʱ�������ж��Ƿ��о��鱻���
	virtual void onTouchUp(cocos2d::Sprite * sender);//��ָ����ʱ��������ȥʵ��
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