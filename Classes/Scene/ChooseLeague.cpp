#include "ChooseLeague.h"
#include "ChooseMapScene.h"
#include "LeagueDetailSprite.h"
USING_NS_CC;

Scene* ChooseLeague::createScene(){
	auto scene = Scene::create();
	auto layer = ChooseLeague::create();
	scene->addChild(layer);
	return scene;
}

bool ChooseLeague::init(){
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto titleLabel = x_label_zh(xml_string("chooce_league_title"), 20);
	titleLabel->setPosition(visibleSize.width / 2.0, visibleSize.height - titleLabel->getContentSize().height);
	this->addChild(titleLabel, 2);
	auto backSprite = MenuItemImage::create("back.png", "back.png", CC_CALLBACK_1(ChooseLeague::backActionCallback, this));
	backSprite->setPosition(backSprite->getContentSize().width / 2.0, (visibleSize.height + origin.y) - backSprite->getContentSize().height / 2.0);
	auto menu = Menu::create(backSprite, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	auto mapSprite1 = MenuItemImage::create("Wolfman_InfiniteDuress.png", "Wolfman_InfiniteDuress.png", CC_CALLBACK_1(ChooseLeague::mapActionCallback, this));
	auto mapSprite2 = MenuItemImage::create("XenZhao_Charge.png", "XenZhao_Charge.png", CC_CALLBACK_1(ChooseLeague::mapActionCallback, this));
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

    auto listener1 = EventListenerTouchOneByOne::create();
    // 设置是否吞没事件，在 onTouchBegan 方法返回 true 时吞没
    listener1->setSwallowTouches(false);
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        auto target=static_cast<Sprite*>(event->getCurrentTarget());
        if(target->getBoundingBox().containsPoint(touch->getLocation()))
        {
            log("touch");
            
            auto memory=target->getChildByTag(100);
            if(memory){
                memory->removeFromParent();
                memory=NULL;
                free(memory);
                return true;
            }
            auto layer=new LeagueDetailSprite();
            layer->setTag(100);
            layer->init("", "", "");
            layer->setAnchorPoint(Vec2(target->getContentSize().width,0));
            layer->setPosition(0,0);
            
            
            
            log("%f  w:%f",layer->getContentSize().height,layer->getContentSize().width);
            layer->setPosition(0,target->getContentSize().height);
            target->addChild(layer);

        }
        return true; // if you are consuming it
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, zhaoxinSprite);
    auto bgSprite = Sprite::create("ChooseMapBg.png");

	bgSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(bgSprite, 0);
    
	return true;
}

void ChooseLeague::backActionCallback(cocos2d::Ref *pSender)
{
	auto scene = ChooseMapScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
}
void ChooseLeague::mapActionCallback(cocos2d::Ref *pSender){
	Node *sender = (Node*)pSender;
	int tag = sender->getTag();
	switch (tag) {
	case 0:
	{

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
