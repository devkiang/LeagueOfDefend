#ifndef ChooseLeague_h
#define ChooseLeague_h

#include "LODConfig.h"

class ChooseLeague : public cocos2d::Layer {


public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	void backActionCallback(cocos2d::Ref* pSender);
	void mapActionCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ChooseLeague);
};
#endif /* ChooseMapScene_hpp */