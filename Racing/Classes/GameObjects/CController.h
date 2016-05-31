#ifndef _CCONTROLLER_H_
#define _CCONTROLLER_H_

#include "cocos2d.h"
#include "../Libs/Singleton/Singleton.h"

class CController : public Singleton<CController>
{
public:
    void OnTouchBegan(cocos2d::Vec2 pos);
    void OnTouchMoved(cocos2d::Vec2 pos);
    void OnTouchEnded(cocos2d::Vec2 pos);
};

#endif //_CCONTROLLER_H_
