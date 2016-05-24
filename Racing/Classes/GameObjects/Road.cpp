#include "Road.h"
#include "GameDefine.h"
#include "const.h"

USING_NS_CC;

Road::~Road()
{

}

Road::Road(TypeRoad type, bool isBegin, const cocos2d::Vec2& pos)
{
	_firstLane	= NULL;
	_secondLane = NULL;
	_thirdLane	= NULL;
	_fourthLane = NULL;
	_isBegin	= isBegin;
	_type		= type;
	_lane		= TypeLane::Straight;
	_posBegin	= pos;
}

Road* Road::create(TypeRoad type, bool isBegin, const Vec2& pos )
{
	Road* pRet = new Road(type, isBegin, pos);
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool Road::init()
{
	std::string stFilePathTemp;
	Vec2 posLane;
	Size sizeLane;
	Size screenSize = Director::getInstance()->getVisibleSize();
	int indexFirstLane	= NUM_FIRST_ROAD;
	int indexSecondLane	= NUM_MID_ROADS;
	int indexFourthLane = NUM_FOURTH_ROADS;
	if (_isBegin)
	{
		indexFirstLane	= NUM_BEGIN_FIRST_ROAD;
		indexSecondLane = NUM_BEGIN_MID_ROADS;
		indexFourthLane = NUM_BEGIN_FOURTH_ROAD;
	}

	switch (_type)
	{
	case TypeRoad::Alpha: _stFilePath = IMG_SERIAL_ROAD_ALPHA; break;
	case TypeRoad::Dirt: _stFilePath = IMG_SERIAL_ROAD_DIRT; break;
	default: _stFilePath = IMG_SERIAL_ROAD_SAND; break; //Sand road	
	}
	
	this->setPosition(_posBegin);

	stFilePathTemp = _stFilePath;
	stFilePathTemp = __String::createWithFormat(stFilePathTemp.c_str(), indexSecondLane)->getCString();
	_secondLane = Sprite::create(stFilePathTemp);	
	_secondLane->setAnchorPoint(Vec2(0.5f, 0.5f));
	sizeLane = _secondLane->getContentSize();	
	_secondLane->setPosition(-sizeLane.width*0.5f, 0);
	addChild(_secondLane, 2);

	stFilePathTemp = _stFilePath;
	stFilePathTemp = __String::createWithFormat(stFilePathTemp.c_str(), indexSecondLane)->getCString();
	_thirdLane = Sprite::create(stFilePathTemp);
	_thirdLane->setAnchorPoint(Vec2(0.5f, 0.5f));
	_thirdLane->setPosition(sizeLane.width*0.5f, 0);
	addChild(_thirdLane, 2);

	stFilePathTemp = _stFilePath;
	stFilePathTemp = __String::createWithFormat(stFilePathTemp.c_str(), indexFirstLane)->getCString();
	_firstLane = Sprite::create(stFilePathTemp);
	_firstLane->setAnchorPoint(Vec2(0.5f, 0.5f));
	_firstLane->setPosition( -(sizeLane.width*0.5f + sizeLane.width), 0);
	addChild(_firstLane, 2);

	stFilePathTemp = _stFilePath;
	stFilePathTemp = __String::createWithFormat(stFilePathTemp.c_str(), indexFourthLane)->getCString();
	_fourthLane = Sprite::create(stFilePathTemp);
	_fourthLane->setAnchorPoint(Vec2(0.5f, 0.5f));
	_fourthLane->setPosition((sizeLane.width*0.5f + sizeLane.width), 0);
	addChild(_fourthLane, 2);

	return true;
}

void Road::changeSpriteFrame(int indexImage)
{	
	std::string temp = __String::createWithFormat(_stFilePath.c_str(), indexImage)->getCString();
	
}

void Road::update(float dt)
{

}

