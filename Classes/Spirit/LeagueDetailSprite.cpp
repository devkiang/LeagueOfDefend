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
    const Size& size=this->getContentSize();
    x_log_size(size);
    nameLabel=x_label_sys(name, 12);
    nameLabel->setPosition(size.width/2.0,size.height);
    nameLabel->setAnchorPoint(Vec2(.5,1));
    this->addChild(nameLabel);
    
    descriptionLabel=x_label_sys(description, 10);
    descriptionLabel->setPosition(0,x_getPointY(nameLabel)-x_getHeight(nameLabel));
    descriptionLabel->setAnchorPoint(Vec2(0,1));
    descriptionLabel->setDimensions(x_getWidth(this), 0);
    this->addChild(descriptionLabel);
    
    specificLabel=x_label_sys(specific, 10);
    specificLabel->setPosition(0,x_getPointY(descriptionLabel)-x_getHeight(descriptionLabel));
    specificLabel->setAnchorPoint(Vec2(0,1));
    specificLabel->setDimensions(x_getWidth(this), 0);
    this->addChild(specificLabel);
    
}