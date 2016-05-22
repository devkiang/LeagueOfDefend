//
//  ToolKit.cpp
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/18.
//
//

#include "ToolKit.h"
#include "cocos2d.h"
USING_NS_CC;
TTFConfig ToolKit::getGlobalTTF(int fontSize)
{
    if(fontSize<1){
        fontSize=12;
    }
    TTFConfig ttfConfig;
    ttfConfig.fontFilePath = "fonts/cn.ttf"; //必须配置
    ttfConfig.fontSize = fontSize;
    ttfConfig.distanceFieldEnabled = false;
    ttfConfig.outlineSize = 0;
    ttfConfig.glyphs = GlyphCollection::DYNAMIC;
    ttfConfig.customGlyphs = nullptr;
    return ttfConfig;
}

TTFConfig ToolKit::getGlobalTTF()
{
    return getGlobalTTF(0);
}

Label* ToolKit::createLabel(const std::string& text)
{
    return createLabel(text, 0);
}
Label* ToolKit::createLabel(const std::string& text,int fontSize)
{
    Label *label=Label::createWithTTF(getGlobalTTF(fontSize), text);
    return label;
    
}
std::string ToolKit::getSring(const std::string& text){
	auto strings = FileUtils::getInstance()->getValueMapFromFile("fonts/strings.xml");
	std::string string = strings[text].asString();
	return string;
}