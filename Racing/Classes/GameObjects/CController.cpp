#include "CController.h"
#include "GameDefine.h"
#include "const.h"

USING_NS_CC;

#define STEERING_MAX        1.5f

void CController::onTouchBegan(cocos2d::Vec2 pos)
{
    m_touchLocation = pos;
}

void CController::onTouchMoved(cocos2d::Vec2 pos)
{
    m_touchLocation = pos;
}

void CController::onTouchEnded(cocos2d::Vec2 pos)
{
    m_touchLocation = Vec2::ZERO;
}

float CController::getSteering()
{
    if(m_touchLocation != Vec2::ZERO)
    {
        Size size = Director::getInstance()->getVisibleSize();
        float dragPercent = (m_touchLocation.x - size.width/2) / (size.width / 2);
        return STEERING_MAX * (-dragPercent);
    }
    return 0.0f;
}