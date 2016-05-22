
//  ChooseMapScene.hpp
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/18.
//
//

#ifndef ChooseMapScene_h
#define ChooseMapScene_h

#include "LODConfig.h"

class ChooseMapScene: public cocos2d::Layer {
   

public:
    virtual bool init();
    static cocos2d::Scene* createScene();
    void backActionCallback(cocos2d::Ref* pSender);
	void mapActionCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(ChooseMapScene);
};
#endif /* ChooseMapScene_hpp */
/*
中文试试
 
 */