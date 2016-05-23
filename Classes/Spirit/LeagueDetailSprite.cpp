//
//  LeagueDetailSprite.cpp
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/23.
//
//

#include "LeagueDetailSprite.h"
USING_NS_CC;

LeagueDetailSprite::~LeagueDetailSprite(){
    x_release(nameLabel);
    x_release(specificLabel);
    x_release(descriptionLabel);
}

void LeagueDetailSprite::init(const std::string &name,const std::string &specific,const std::string &description)
{
    LayerColor::initWithColor(Color4B(0, 0, 0, 255.0f));
    this->setContentSize(Size(100, 100));
    const Size& size=this->getContentSize();log("size,h:%f,w:%f",size.height,size.width);
    nameLabel=x_label_zh(xml_string("league_detail_name_001"), 12);
    nameLabel->setPosition(size.width/2.0,size.height);
    nameLabel->setAnchorPoint(Vec2(0.5,1));
//    nameLabel->setDimensions(30, MAXFLOAT);
    this->addChild(nameLabel);
    
    descriptionLabel=x_label_zh(xml_string("league_detail_description_001"), 10);
    descriptionLabel->setPosition(0,nameLabel->getPosition().y-nameLabel->getContentSize().height);
    descriptionLabel->setAnchorPoint(Vec2(0.0,1));
    this->addChild(descriptionLabel);
    
    specificLabel=x_label_zh(xml_string(str_league_detail_specific_001), 10);
    specificLabel->setPosition(0,descriptionLabel->getPosition().y-descriptionLabel->getContentSize().height);
    specificLabel->setAnchorPoint(Vec2(0.0,1));
    this->addChild(specificLabel);
    
}