#include "CCamera.h"
#include "GameDefine.h"
#include "const.h"
#include "Road.h"
#include "Vehicle.h"

USING_NS_CC;

CCamera::~CCamera()
{
    
}

CCamera::CCamera()
{
    m_road			= nullptr;
    m_focusPoint	= Vec2::ZERO;
}

CCamera* CCamera::create()
{
    auto pRet = new CCamera();
    if (pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool CCamera::init()
{
    m_road = Road::create();
    addChild(m_road);
    
    Size sizeScreen = Director::getInstance()->getVisibleSize();
    m_focusPoint = Vec2(sizeScreen.width/2, sizeScreen.height/3);
    
    return true;
}

void CCamera::update(float dt)
{
    m_road->update(dt);
    
    float rotate = -m_road->getPlayer()->getRotation();
    m_road->setRotation(rotate);
    
    Vec2 playerWorldPos = m_road->convertToWorldSpace(m_road->getPlayer()->getPosition());
    Vec2 offset = m_focusPoint - playerWorldPos;
    m_road->setPosition(m_road->getPosition() + offset);
}