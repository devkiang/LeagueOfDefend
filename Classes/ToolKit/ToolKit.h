//
//  ToolKit.hpp
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/18.
//
//

#ifndef ToolKit_hpp
#define ToolKit_hpp

#include <stdio.h>
#include <cocos2d.h>

class ToolKit
{
public:
    cocos2d::TTFConfig getGlobalTTF(int fontSize);
    cocos2d::TTFConfig getGlobalTTF();
    cocos2d::Label* createLabel(const std::string& text);
    cocos2d::Label* createLabel(const std::string& text,int fontSize);
	std::string getSring(const std::string& text);
};

#endif /* ToolKit_hpp */
