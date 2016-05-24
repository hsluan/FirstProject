#include "RacingScene.h"
#include "Vehicle.h"
#include "const.h"
#include "Road.h"
#include "GameDefine.h"

USING_NS_CC;

Scene* Racing::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Racing::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool Racing::init()
{
	_hero		= nullptr;
	_fYHightest = 0.f;
	_fYLowest	= 0.f;

	//Register event
	Device::setAccelerometerEnabled(true);
	setTouchEnabled(true);

	auto listener		= EventListenerAcceleration::create(CC_CALLBACK_2(Racing::onAcceleration, this));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto listenerTouch	= EventListenerTouchOneByOne::create();	
	listenerTouch->onTouchBegan = CC_CALLBACK_2(Racing::onTouchBegan, this);
	listenerTouch->onTouchMoved = CC_CALLBACK_2(Racing::onTouchMoved, this);
	listenerTouch->onTouchEnded = CC_CALLBACK_2(Racing::onTouchEnded, this);
	listenerTouch->setSwallowTouches(true);	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerTouch, this);

	_sizeScreen = Director::getInstance()->getVisibleSize();
	
	_hero = Vehicle::create(TypeVehicle::BlackCar, Vec2(_sizeScreen.width*0.5f, 0));
	_hero->setPositionY(_hero->getContentSize().height*0.5f);
	addChild(_hero, 3);

	createRoads();

	this->scheduleUpdate();
    return true;
}
	

void Racing::createRoads()
{		
	auto spriteTemp = Sprite::create("Tiles/DirtRoad/road_dirt01.png");
	_sizeTilesRoad = spriteTemp->getContentSize();
	Vec2 posRoad = Vec2(_sizeScreen.width*0.5f, _sizeTilesRoad.height*0.5f);
	
	auto road = Road::create(TypeRoad::Asphalt, true, posRoad);
	road->setAnchorPoint(Vec2(0.5f, 0.5f));
	addChild(road, 2);
	_roads.push_back(road);

	for (int i = 0; i < NUM_ROAD_FULL_SCREEN-1; i++)
	{		
		posRoad.y += (_sizeTilesRoad.height- PIXEL_FIX);
		auto road = Road::create(TypeRoad::Asphalt, false, posRoad);
		road->setAnchorPoint(Vec2(0.5f, 0.5f));
		addChild(road, 1);
		_roads.push_back(road);
	}
	_fYHightest = (int)posRoad.y;
}

void Racing::createUI()
{

}

bool Racing::onTouchBegan(Touch *touch, Event *unused_event)
{
	auto location	= touch->getLocation();
	Vec2 vectorFromHeroToTouch = location - _hero->getPosition();
	float fAngle = CC_RADIANS_TO_DEGREES(-vectorFromHeroToTouch.getAngle());
	_hero->setRotation(fAngle);//setTargetAngle(fAngle);
	return true;
}

void Racing::onTouchMoved(Touch *touch, Event *unused_event)
{
	auto location = touch->getLocation();
	Vec2 vectorFromHeroToTouch = location - _hero->getPosition();
	float fAngle = CC_RADIANS_TO_DEGREES(-vectorFromHeroToTouch.getAngle());
	_hero->setRotation(fAngle);
}

void Racing::onTouchEnded(Touch *touch, Event *unused_event)
{

}

void Racing::onAcceleration(Acceleration* acc, Event* event)
{
	SET_MIN_MAX(-1, acc->x, 1);
}


void Racing::update(float dt)
{
	_hero->update(dt);

	updateRoads(dt);
}

void Racing::updateRoads(float dt)
{
	for (auto p : _roads)
	{
		p->setPositionY(p->getPositionY() - VELOCITY_CAR*dt);
		if (0 >= p->getPositionY() + _sizeTilesRoad.height*0.5f )
		{
			p->setPositionY(_fYHightest- PIXEL_FIX);
		}		
	}	
}