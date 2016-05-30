#include "RoadSegment.h"
#include "GameDefine.h"
#include "const.h"

USING_NS_CC;

RoadSegment::~RoadSegment()
{

}

RoadSegment::RoadSegment(TypeRoad type, bool isBegin, const cocos2d::Vec2& pos)
{
	m_firstLane	= NULL;
	m_secondLane = NULL;
	m_thirdLane	= NULL;
	m_fourthLane = NULL;
	m_isBegin	= isBegin;
	m_type		= type;
	m_lane		= TypeLane::Straight;
	m_posBegin	= pos;
}

RoadSegment* RoadSegment::create(TypeRoad type, bool isBegin, const Vec2& pos )
{
	RoadSegment* pRet = new RoadSegment(type, isBegin, pos);
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool RoadSegment::init()
{
	std::string stFilePathTemp;
	Vec2 posLane;
	Size sizeLane;
	Size screenSize = Director::getInstance()->getVisibleSize();
	int indexFirstLane	= NUM_FIRST_ROAD;
	int indexSecondLane	= NUM_MIDm_roads;
	int indexFourthLane = NUM_FOURTH_ROADS;
	if (m_isBegin)
	{
		indexFirstLane	= NUM_BEGIN_FIRST_ROAD;
		indexSecondLane = NUM_BEGIN_MID_ROAD;
		indexFourthLane = NUM_BEGIN_FOURTH_ROAD;
	}

	switch (m_type)
	{
	case TypeRoad::Asphalt: m_stFilePath = IMG_SERIAL_ROAD_ALPHA; break;
	case TypeRoad::Dirt: m_stFilePath = IMG_SERIAL_ROAD_DIRT; break;
	default: m_stFilePath = IMG_SERIAL_ROAD_SAND; break; //Sand road	
	}
	
	this->setPosition(m_posBegin);

	stFilePathTemp = m_stFilePath;
	stFilePathTemp = __String::createWithFormat(stFilePathTemp.c_str(), indexSecondLane)->getCString();
	m_secondLane = Sprite::create(stFilePathTemp);
	m_secondLane->setAnchorPoint(Vec2(0.5f, 0.5f));
	sizeLane = m_secondLane->getContentSize();
	m_secondLane->setPosition(-sizeLane.width*0.5f, 0);
	addChild(m_secondLane, 2);

	stFilePathTemp = m_stFilePath;
	stFilePathTemp = __String::createWithFormat(stFilePathTemp.c_str(), indexSecondLane)->getCString();
	m_thirdLane = Sprite::create(stFilePathTemp);
	m_thirdLane->setAnchorPoint(Vec2(0.5f, 0.5f));
	m_thirdLane->setPosition(sizeLane.width*0.5f, 0);
	addChild(m_thirdLane, 2);

	stFilePathTemp = m_stFilePath;
	stFilePathTemp = __String::createWithFormat(stFilePathTemp.c_str(), indexFirstLane)->getCString();
	m_firstLane = Sprite::create(stFilePathTemp);
	m_firstLane->setAnchorPoint(Vec2(0.5f, 0.5f));
	m_firstLane->setPosition( -(sizeLane.width*0.5f + sizeLane.width), 0);
	addChild(m_firstLane, 2);

	stFilePathTemp = m_stFilePath;
	stFilePathTemp = __String::createWithFormat(stFilePathTemp.c_str(), indexFourthLane)->getCString();
	m_fourthLane = Sprite::create(stFilePathTemp);
	m_fourthLane->setAnchorPoint(Vec2(0.5f, 0.5f));
	m_fourthLane->setPosition((sizeLane.width*0.5f + sizeLane.width), 0);
	addChild(m_fourthLane, 2);

	return true;
}

void RoadSegment::changeSpriteFrame(int firstIndex, int midIndex, int fourthIndex)
{	
	std::string stTemp = __String::createWithFormat(m_stFilePath.c_str(), firstIndex)->getCString();
	SpriteFrame* spFrame = SpriteFrame::create(stTemp, m_firstLane->getBoundingBox());
	m_firstLane->setSpriteFrame(spFrame);
	
	stTemp = __String::createWithFormat(m_stFilePath.c_str(), midIndex)->getCString();
	spFrame = SpriteFrame::create(stTemp, m_secondLane->getBoundingBox());
	m_secondLane->setSpriteFrame(spFrame);
	m_thirdLane->setSpriteFrame(spFrame);

	stTemp = __String::createWithFormat(m_stFilePath.c_str(), fourthIndex)->getCString();
	spFrame = SpriteFrame::create(stTemp, m_fourthLane->getBoundingBox());
	m_fourthLane->setSpriteFrame(spFrame);
	
}

void RoadSegment::update(float dt)
{

}

