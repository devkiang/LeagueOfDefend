
#ifndef AboutScene_h
#define AboutScene_h

#include "LODConfig.h"
#define MenuItemTag 10

class AboutScene: public cocos2d::Layer {


public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	void menuActionCallback(cocos2d::Ref* pSender);
	void AboutScene::backActionCallback(cocos2d::Ref *pSender);
	CREATE_FUNC(AboutScene);
};

#endif