//
//  ChooseMapScene.cpp
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/18.
//
//

#include "ChooseMapScene.h"
#include "MainMenuScene.h"
USING_NS_CC;

Scene* ChooseMapScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ChooseMapScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool ChooseMapScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto titleLabel=x_label_zh("请选择您要玩耍的地图,啊啊哈", 20);
    titleLabel->setPosition(visibleSize.width/2.0, visibleSize.height-titleLabel->getContentSize().height);
    this->addChild(titleLabel,2);
    auto backSprite=MenuItemImage::create("back.png", "back.png",CC_CALLBACK_1(ChooseMapScene::backActionCallback, this));
    backSprite->setPosition(backSprite->getContentSize().width/2.0,(visibleSize.height+origin.y)-backSprite->getContentSize().height/2.0);
    auto menu=Menu::create(backSprite, NULL);
     menu->setPosition(Vec2::ZERO);
    this->addChild(menu,1);
    
    
    auto bgSprite=Sprite::create("ChooseMapBg.png");
    
    bgSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(bgSprite, 0);

    return true;
}

void ChooseMapScene::backActionCallback(cocos2d::Ref *pSender)
{
    auto scene =MainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
    log("fuck");
}
