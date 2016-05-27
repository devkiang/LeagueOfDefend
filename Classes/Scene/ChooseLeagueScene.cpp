#include "ChooseLeagueScene.h"
#include "ChooseMapScene.h"
#include "LeagueDetailSprite.h"
#include "PlayScene.h"
USING_NS_CC;
Scene* ChooseLeagueScene::createScene(){
	auto scene = Scene::create();
	auto layer = ChooseLeagueScene::create();
	scene->addChild(layer);
	return scene;
}


bool ChooseLeagueScene::init(){
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto titleLabel = x_label_zh(xml_string("chooce_league_title"), 20);
	titleLabel->setPosition(visibleSize.width / 2.0, visibleSize.height - titleLabel->getContentSize().height);
	this->addChild(titleLabel, 2);
	auto backSprite = MenuItemImage::create("back.png", "back.png", CC_CALLBACK_1(ChooseLeagueScene::backActionCallback, this));
	backSprite->setPosition(backSprite->getContentSize().width / 2.0, (visibleSize.height + origin.y) - backSprite->getContentSize().height / 2.0);
	auto menu = Menu::create(backSprite, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	auto mapSprite1 = Sprite::create("Wolfman_InfiniteDuress.png"); 
	auto mapSprite2 = Sprite::create("XenZhao_Charge.png"); 
	mapSprite1->setAnchorPoint(Point(0.5, 0.5));
	mapSprite2->setAnchorPoint(Point(0.5, 0.5));
	mapSprite1->setTag(0);
	mapSprite2->setTag(1);
	float mapW = mapSprite1->getContentSize().width;
	float mapH = mapSprite1->getContentSize().height;

	mapSprite1->setPosition(visibleSize.width / 2 - mapW / 2 - 15, visibleSize.height / 2);
	mapSprite2->setPosition(visibleSize.width / 2 + mapW / 2 + 15, visibleSize.height / 2);

	this->addChild(mapSprite1, 2);
	this->addChild(mapSprite2, 2);
	
    zhaoxinSprite=Sprite::create("XenZhao_Charge.png");
    zhaoxinSprite->setPosition(100,100);
    this->addChild(zhaoxinSprite,3);
	pushSprite(mapSprite1);
	pushSprite(zhaoxinSprite);
	initEvent();
    auto bgSprite = Sprite::create("ChooseMapBg.png");

	bgSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(bgSprite, 0);
    
	return true;
}


void ChooseLeagueScene::onTouchUp(Sprite * sender){
	if (sender == zhaoxinSprite)
	{
		auto scene = PlayScene::createScene();
		turnToScene(scene);
		/*if (target->getBoundingBox().containsPoint(touch->getLocation()))
		{*/
		/*auto memory = sender->getChildByTag(100);
		if (memory){
			memory->removeFromParent();
			memory = NULL;
			free(memory);
			
		}
		else
		{
			auto layer = new LeagueDetailSprite();
			layer->setTag(100);
			layer->init(xml_string(str_league_detail_name_001), xml_string(str_league_detail_specific_001), xml_string(str_league_detail_description_001));
			layer->setAnchorPoint(Vec2(sender->getContentSize().width, 0));
			layer->setPosition(0, 0);
			layer->setPosition(0, sender->getContentSize().height);
			sender->addChild(layer);
		}*/
	}
}

void ChooseLeagueScene::onTouchDown(cocos2d::Sprite*)
{
    log("down");
}

void ChooseLeagueScene::backActionCallback(cocos2d::Ref *pSender)
{
	auto scene = ChooseMapScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}


