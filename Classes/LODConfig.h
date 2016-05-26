//
//  LODConfig.h
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/18.
//
//

#ifndef LODConfig_h
#define LODConfig_h
#include "cocos2d.h"
#include "ToolKit/ToolKit.h"


#define x_label_zh(msg,fontSize) (new ToolKit())->createLabel(msg,fontSize) //快捷生成支持中文的label
#define x_label_sys(msg,fontSize) Label::createWithSystemFont(msg, "Arial",fontSize)
#define xml_string(msg)         ToolKit::getSring(msg)                      //获取xml字段宏
#define x_release(obj)          if(obj){obj->release();obj=NULL;}                    //释放内存宏
#define x_getHeight(obj)        obj->getContentSize().height
#define x_getWidth(obj)         obj->getContentSize().width
#define x_getPointX(obj)        obj->getPosition().x
#define x_getPointY(obj)        obj->getPosition().y
#define x_log_size(size)        log("size,w:%f,h:%f",size.width,size.height)
#define x_log_point(position)   log("position,x:%f,y:%f",position.x,position.y)
#define x_log_rect(rect)        log("rect,x:%f,y:%f,w:%f,h:%f",rect.origin.x,rect.origin.y,rect.size.height,rect.size.width)

//xml_const
#define str_league_detail_name_001          "league_detail_name_001"
#define str_league_detail_specific_001      "league_detail_specific_001"
#define str_league_detail_description_001   "league_detail_description_001"
#define str_league_detail_name_002          "league_detail_name_002"
#define str_league_detail_specific_002      "league_detail_specific_002"
#define str_league_detail_description_002   "league_detail_description_002"
#define str_league_detail_name_003          "league_detail_name_003"
#define str_league_detail_specific_003      "league_detail_specific_003"
#define str_league_detail_description_003   "league_detail_description_003"


#endif /* LODConfig_h */
