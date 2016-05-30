#include "CCamera.h"
#include "GameDefine.h"
#include "const.h"
#include "Road.h"

USING_NS_CC;

CCamera::~CCamera()
{

}

CCamera::CCamera()
{

}

CCamera* CCamera::create()
{
	auto pRet = new CCamera();
	if (pRet->init())
	{
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
    Vec2 offset = m_focusPoint - m_road->getPlayer()->getPosition();
    m_road->setFocus(offset);
    m_road->update(dt);
}