
#ifndef __MainMenu_SCENE_H__
#define __MainMenu_SCENE_H__

#include "LODConfig.h"
#define MenuItemTag 10

class MainMenuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void menuActionCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);
};

#endif // __HELLOWORLD_SCENE_H__
