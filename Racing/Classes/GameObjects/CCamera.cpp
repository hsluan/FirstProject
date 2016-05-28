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

	return true;
}

void CCamera::update(float dt)
{

}