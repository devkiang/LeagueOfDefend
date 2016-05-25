#ifndef ChooseLeague_h
#define ChooseLeague_h

#include "LODConfig.h"
#include "EventProtocol.h"

class ChooseLeague : public cocos2d::Layer{


public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	void backActionCallback(cocos2d::Ref* pSender);
	void mapActionCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ChooseLeague);
    cocos2d::Sprite* zhaoxinSprite;
private:
   void registerListener();
    bool touchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
    bool touchMove(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
    bool touchEnd(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
};
#endif /* ChooseMapScene_hpp */