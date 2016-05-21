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

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//	auto listenerKey = EventListenerKeyboard::create();
//	listenerKey->onKeyPressed = CC_CALLBACK_2(Racing::onKeyPressed, this);
//	listenerKey->onKeyReleased = CC_CALLBACK_2(Racing::onKeyReleased, this);
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKey, this);
//#endif

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
	Vec2 posRoad = Vec2(_sizeScreen.width*0.5f, (int)_sizeTilesRoad.height*0.5f);
	

	auto road = Road::create(TypeRoad::Alpha, true, posRoad);
	road->setAnchorPoint(Vec2(0.5f, 0.5f));
	addChild(road, 2);
	_roads.push_back(road);

	for (int i = 0; i < NUM_ROAD_FULL_SCREEN-1; i++)
	{		
		posRoad.y += (int)_sizeTilesRoad.height;
		auto road = Road::create(TypeRoad::Alpha, false, posRoad);
		road->setAnchorPoint(Vec2(0.5f, 0.5f));
		addChild(road, 2);
		_roads.push_back(road);
	}
	_fYHightest = (int)posRoad.y;
}

void Racing::createUI()
{

}

bool Racing::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void Racing::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void Racing::onTouchEnded(Touch *touch, Event *unused_event)
{

}

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//void Racing::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
//{
//	static Acceleration* acc = nullptr;
//	
//	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
//	{
//		acc->x -= 0.1f;
//	}
//	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
//	{
//		acc->x += 0.1f;
//	}
//	else 
//	{
//		acc->x = 0;
//	}
//	SET_MIN_MAX(-1, acc->x, 1);
//	onAcceleration(acc, nullptr);
//}
//
//void Racing::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
//{
//	log("Key with keycode %d released", keyCode);
//}
//#endif

void Racing::onAcceleration(Acceleration* acc, Event* event)
{
	SET_MIN_MAX(-1, acc->x, 1);
	log("%d", acc->x);
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
		p->setPositionY(p->getPositionY() - VELOCITY_CAR * dt);
		if ( 0 >= p->getPositionY() + _sizeTilesRoad.height*0.5f )
		{
			p->setPositionY(_fYHightest);
		}
	}	
}