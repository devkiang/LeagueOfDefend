//
//  ChooseMapScene.cpp
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/18.
//
//

#include "ChooseMapScene.h"
#include "MainMenuScene.h"
#include "ChooseLeagueScene.h"
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
    
    auto titleLabel=x_label_zh(xml_string("chooce_map_title"), 20);
    titleLabel->setPosition(visibleSize.width/2.0, visibleSize.height-titleLabel->getContentSize().height);
    this->addChild(titleLabel,2);
    auto backSprite=MenuItemImage::create("back.png", "back.png",CC_CALLBACK_1(ChooseMapScene::backActionCallback, this));
    backSprite->setPosition(backSprite->getContentSize().width/2.0,(visibleSize.height+origin.y)-backSprite->getContentSize().height/2.0);
    auto menu=Menu::create(backSprite, NULL);
     menu->setPosition(Vec2::ZERO);
    this->addChild(menu,1);
	auto mapSprite1 = MenuItemImage::create("level01_map.png", "level01_map.png", CC_CALLBACK_1(ChooseMapScene::mapActionCallback, this));
	auto mapSprite2 = MenuItemImage::create("level02_map.png", "level01_map.png", CC_CALLBACK_1(ChooseMapScene::mapActionCallback, this));
	mapSprite1->setAnchorPoint(Point(0.5,0.5));
	mapSprite2->setAnchorPoint(Point(0.5, 0.5));
	mapSprite1->setTag(0);
	mapSprite2->setTag(1);
	float mapW = mapSprite1->getContentSize().width;
	float mapH = mapSprite1->getContentSize().height;

	mapSprite1->setPosition(visibleSize.width / 2 - mapW/2 -15, visibleSize.height / 2);
	mapSprite2->setPosition(visibleSize.width / 2 + mapW / 2 + 15, visibleSize.height / 2);

	
	auto menu1 = Menu::create(mapSprite1, NULL);
	auto menu2 = Menu::create(mapSprite2, NULL);
	menu1->setPosition(Vec2::ZERO);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu1, 2);
	this->addChild(menu2, 2);
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
}
void ChooseMapScene::mapActionCallback(cocos2d::Ref *pSender){
	Node *sender = (Node*)pSender;
	int tag = sender->getTag();
	switch (tag) {
	case 0:
	{
			  auto scene = ChooseLeagueScene::createScene();
			  Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
	}
		break;
	case 1:
	{

	}
		break;

	case 3:
	{

	}
		break;


	default:
		break;
	}
}
