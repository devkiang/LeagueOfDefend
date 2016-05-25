#ifndef ChooseLeague_h
#define ChooseLeague_h
#include "EventTouchLayer.h"
#include "LODConfig.h"

class ChooseLeague : public EventTouchLayer {

public:
	bool init();
	static cocos2d::Scene* createScene();
	ChooseLeague* getInstance();
	void backActionCallback(cocos2d::Ref* pSender);
	void mapActionCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ChooseLeague);
    cocos2d::Sprite* zhaoxinSprite;
	bool onClickDown(Sprite * target);
	void onClickUp(Sprite * target);
};
#endif /* ChooseMapScene_hpp */