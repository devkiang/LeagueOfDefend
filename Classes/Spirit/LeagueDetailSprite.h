//
//  LeagueDetailSprite.hpp
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/23.
//
//

#ifndef LeagueDetailSprite_h
#define LeagueDetailSprite_h

#include "LODConfig.h"

class LeagueDetailSprite :public cocos2d::LayerColor{
protected:
    cocos2d::Label* nameLabel;
    cocos2d::Label* descriptionLabel;
    cocos2d::Label* specificLabel;
public:
    ~LeagueDetailSprite();
    /**
     创建召唤师简介层
     
     @parameter std: name 召唤师名字<br>
     @parameter std: specific 召唤师特性<br>
     @parameter std: description 召唤师简介\故事<br>
     */
    void init(const std::string& name,const std::string& specific,const std::string& description);
    void setNameText(const std::string &name);
    void setSpecificText(const std::string &specificText);
//    virtual void show(cocos2d::Vec2 &pos);//展示的位置
//    virtual void hide();//隐藏
    

};
#endif /* LeagueDetailSprite_hpp */

/*
 
 
 
 
 */