#ifndef ChooseLeagueScene_h
#define ChooseLeagueScene_h
#include "BaseLayer.h"
#include "LODConfig.h"
#include "EventProtocol.h"

class ChooseLeagueScene : public BaseLayer {


public:
	bool init();
	static cocos2d::Scene* createScene();
	ChooseLeagueScene* getInstance();
	void backActionCallback(cocos2d::Ref* pSender);
	void mapActionCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ChooseLeagueScene);
    cocos2d::Sprite* zhaoxinSprite;
	cocos2d::Sprite* worftSprite;

	//bool onClickDown(Sprite * target);
	void onClickUp(Sprite * target);
private:
  /* void registerListener();
    bool touchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
    bool touchMove(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
    bool touchEnd(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);*/

};
#endif /* ChooseMapScene_hpp */