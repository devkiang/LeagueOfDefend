
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
    CREATE_FUNC(ChooseMapScene);
};
#endif /* ChooseMapScene_hpp */
/*
 启动游戏->选择地图(4块地，有坑道,怪物绕一圈，怪物只能陆地行走，只有一种怪物)->选择召唤师->开始游戏->建塔攻击->、
 召唤师没血了，就KO了,过了就赢了
 
 5波怪，一波怪有10只怪，下一波怪的伤害属性是当前波的一倍
 
 */