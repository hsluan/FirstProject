#include "Road.h"
#include "GameDefine.h"
#include "const.h"
#include "Vehicle.h"
#include "RoadSegment.h"

USING_NS_CC;

#define NUM_ROAD_FULL_SCREEN				12
#define PIXEL_FIX							2


Road::Road()
{
	m_hero				= nullptr;
	m_fYHightest		= 0.0f;
	auto spriteTemp		= Sprite::create("Tiles/DirtRoad/road_dirt01.png");
	m_sizeRoadSegment	= spriteTemp->getContentSize();
}

Road::~Road()
{

}

Road* Road::create()
{
	auto pRet = new (std::nothrow) Road();
	if (pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool Road::init()
{

	auto sizeScreen = Director::getInstance()->getVisibleSize();
	Vec2 posRoad = Vec2(sizeScreen.width*0.5f, sizeScreen.height*0.5f);

	m_hero = Vehicle::create(TypeVehicle::BlackCar, Vec2(sizeScreen.width*0.5f, 0));
	m_hero->setPositionY(m_hero->getContentSize().height*0.5f);
	addChild(m_hero,3);


	posRoad.y = m_sizeRoadSegment.height*0.5f;
	auto road = RoadSegment::create(TypeRoad::Asphalt, true, posRoad);
	road->setAnchorPoint(Vec2(0.5f, 0.5f));
	addChild(road, 2);
	m_roads.push_back(road);

	for (int i = 0; i < NUM_ROAD_FULL_SCREEN - 1; i++)
	{
		posRoad.y += (m_sizeRoadSegment.height - PIXEL_FIX);
		auto road = RoadSegment::create(TypeRoad::Asphalt, false, posRoad);
		road->setAnchorPoint(Vec2(0.5f, 0.5f));
		addChild(road, 1);
		m_roads.push_back(road);
	}
	m_fYHightest = (int)posRoad.y;

	return true;
}

void Road::update(float dt)
{
	m_hero->update(dt);
}

void Road::setFocus(Vec2 offset)
{
    m_hero->setPosition(m_hero->getPosition() + offset);
    for (int i = 0; i < m_roads.size(); i++)
    {
        m_roads[i]->setPosition(m_roads[i]->getPosition() + offset);
		if (0 > m_roads[i]->getPositionY() + m_sizeRoadSegment.height*0.5f)
		{
			m_roads[i]->setPositionY(m_fYHightest - PIXEL_FIX);
		}
    }
    
    float rotate = -m_hero->getRotation();
    log("%f", rotate);
    if(rotate != this->getRotation())
    {
        Vec2 pivot = m_hero->getPosition();
        Vec2 pos = this->getPosition();
        pos.rotate(pivot, rotate);
        this->setPosition(pos);
        this->setRotation(rotate);
    }
}

