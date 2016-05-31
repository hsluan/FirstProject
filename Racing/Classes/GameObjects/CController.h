#ifndef _CCONTROLLER_H_
#define _CCONTROLLER_H_

#include "cocos2d.h"
#include "../Libs/Singleton/Singleton.h"

class CController : public Singleton<CController>
{
    CC_SYNTHESIZE(cocos2d::Vec2, m_touchLocation, TouchLocation);
    
public:
    void onTouchBegan(cocos2d::Vec2 pos);
    void onTouchMoved(cocos2d::Vec2 pos);
    void onTouchEnded(cocos2d::Vec2 pos);
    
    float getSteering();
};

#endif //_CCONTROLLER_H_
