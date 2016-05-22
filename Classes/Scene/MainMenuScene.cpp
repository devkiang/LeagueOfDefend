#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "ChooseMapScene.h"
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
                                origin.y + closeItem->getContentSize().height / 2));
	//strings = FileUtils::getInstance()->getValueMapFromFile("fonts/strings.xml");
	std::string startGame = xml_string("start_game");
	std::string game_setting = xml_string("game_setting");
	std::string about = xml_string("about");

	auto startItem = MenuItemLabel::create(x_label_zh(startGame, 20), CC_CALLBACK_1(MainMenuScene::menuActionCallback, this));
    startItem->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f + startItem->getContentSize().height + 30);
    startItem->setTag(MenuItemTag + 1);

	auto settingItem = MenuItemLabel::create(x_label_zh(game_setting, 20), CC_CALLBACK_1(MainMenuScene::menuActionCallback, this));
    settingItem->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f);
    settingItem->setTag(MenuItemTag + 2);
    
	auto aboutItem = MenuItemLabel::create(x_label_zh(about, 20), CC_CALLBACK_1(MainMenuScene::menuActionCallback, this));
    aboutItem->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f - aboutItem->getContentSize().height - 30);
    aboutItem->setTag(MenuItemTag + 3);
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, startItem, settingItem, aboutItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World" x_label_zh("”¢–€ ÿª§", 20);
    // create and initialize a label Label::createWithTTF("League of Defend", "fonts/Marker Felt.ttf", 24);
    
    auto label = Label::createWithTTF("League of Defend", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("LaunchCeneBackgroud.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void MainMenuScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void MainMenuScene::menuActionCallback(cocos2d::Ref *pSender)
{
    Node *sender = (Node*)pSender;
    int tag = sender->getTag();
    switch (tag - MenuItemTag) {
        case 1:
        {
            auto scene = ChooseMapScene::createScene();
            Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5, scene));
            //            Director::getInstance()->replaceScene(scene);
            
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






