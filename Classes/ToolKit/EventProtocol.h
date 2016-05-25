//
//  EventManager.h
//  LeagueOfDefend
//
//  Created by shikee_app03 on 16/5/25.
//
//

#ifndef EventProtocol_h
#define EventProtocol_h



class EventProtocol{
  
public:
   virtual bool touchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
   virtual bool touchMove(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
   virtual bool touchEnd(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
};
#endif /* EventProtocol_h */
