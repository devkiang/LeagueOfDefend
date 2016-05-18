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
#define x_label_normal(msg) (new ToolKit())->createLabel(msg)
class ToolKit
{
public:
    cocos2d::TTFConfig getGlobalTTF();
    cocos2d::Label* createLabel(const std::string& text);
};

#endif /* ToolKit_hpp */
