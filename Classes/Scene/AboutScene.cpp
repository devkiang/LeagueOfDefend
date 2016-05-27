//
//  AbouScene.cpp
//  LeagueOfDefend
//
//  Created by voisd on 16/5/25.
//

#include "AboutScene.h"
#include "MainMenuScene.h"
USING_NS_CC;


Scene* AboutScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = AboutScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool AboutScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	std::string about_introduce = xml_string("about_introduce");

	auto settingItem = MenuItemLabel::create(x_label_zh(about_introduce, 20), CC_CALLBACK_1(AboutScene::menuActionCallback, this));
	settingItem->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f);
	settingItem->setTag(MenuItemTag + 2);
	this->addChild(settingItem, 1);

	auto backSprite = MenuItemImage::create("back.png", "back.png", CC_CALLBACK_1(AboutScene::backActionCallback, this));
	backSprite->setPosition(backSprite->getContentSize().width / 2.0, (visibleSize.height + origin.y) - backSprite->getContentSize().height / 2.0);
	auto menu = Menu::create(backSprite, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto sprite = Sprite::create("LaunchCeneBackgroud.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);


}

void AboutScene::backActionCallback(cocos2d::Ref *pSender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}

void AboutScene::menuActionCallback(cocos2d::Ref *pSender)
{
	Node *sender = (Node*)pSender;
	int tag = sender->getTag();
	switch (tag - MenuItemTag) {
	case 1:
	{
		
	}
	break;
	case 2:
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


