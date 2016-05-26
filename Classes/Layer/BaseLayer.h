
#include "cocos2d.h"
USING_NS_CC;

class BaseLayer:public cocos2d::Layer
{
public:
	cocos2d::Vector<Sprite*> sprites = Vector<Sprite*>();
	virtual void initEvent();
	CREATE_FUNC(BaseLayer);
	// ���ش����ص�����
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);
	virtual bool onClickDown(Sprite * target);//��ָ������Ļʱ�������ж��Ƿ��о��鱻���
	virtual void onClickUp(Sprite * target);//��ָ����ʱ��������ȥʵ��
	//cocos2d::Vector<Sprite*> pushSprite(const Sprite& sprite);
	void pushSprite(Sprite*& sprite);
private:

};

