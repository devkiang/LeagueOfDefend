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
ValueMap ToolKit::xmlValueMap;

Label* ToolKit::createLabel(const std::string& text)
{
    return createLabel(text, 0);
}

Label* ToolKit::createLabel(const std::string& text,int fontSize)
{
    std::string fontPath="";
    return createLabel(text, fontSize,fontPath);
    
}

Label* ToolKit::createLabel(const std::string& text,int fontSize,std::string &fontPath)
{
    if(fontSize<1){
        fontSize=12;
    }
    if(fontPath.length()<1){
        fontPath="fonts/cn.ttf";
    }
    TTFConfig ttfConfig;
    ttfConfig.fontFilePath = fontPath; //必须配置
    ttfConfig.fontSize = fontSize;
    ttfConfig.distanceFieldEnabled = false;
    ttfConfig.outlineSize = 0;
    ttfConfig.glyphs = GlyphCollection::DYNAMIC;
    ttfConfig.customGlyphs = nullptr;
    Label *label=Label::createWithTTF(ttfConfig, text);
    return label;
    
}

std::string ToolKit::getSring(const std::string &text)
{
    if(ToolKit::xmlValueMap .empty()){
        ToolKit::xmlValueMap = FileUtils::getInstance()->getValueMapFromFile("fonts/strings.xml");
    }
    return ToolKit::xmlValueMap[text].asString();
}

