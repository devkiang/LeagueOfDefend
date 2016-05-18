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
TTFConfig ToolKit::getGlobalTTF()
{
    TTFConfig ttfConfig;
    ttfConfig.fontFilePath = "fonts/cn.ttf"; //必须配置
    ttfConfig.fontSize = 12;
    ttfConfig.distanceFieldEnabled = false;
    ttfConfig.outlineSize = 0;
    ttfConfig.glyphs = GlyphCollection::DYNAMIC;
    ttfConfig.customGlyphs = nullptr;
    return ttfConfig;
}

Label* ToolKit::createLabel(const std::string& text)
{
    Label *label=Label::createWithTTF(getGlobalTTF(), text);
    return label;
}