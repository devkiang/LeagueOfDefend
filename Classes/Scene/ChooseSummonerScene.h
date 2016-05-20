//
//  ChooseSummonerScene.hpp
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/20.
//
//

#ifndef ChooseSummonerScene_h
#define ChooseSummonerScene_h
#include "LODConfig.h"
class ChooseSummonerScene :public cocos2d::Layer{
  

public:
    virtual bool init();
    CREATE_FUNC(ChooseSummonerScene);
    static cocos2d::Scene* createScene();
    
    void backActionCallback(cocos2d::Ref *pSender);
};

#endif /* ChooseSummonerScene_hpp */
