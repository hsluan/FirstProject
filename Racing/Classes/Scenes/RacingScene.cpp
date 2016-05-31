#include "RacingScene.h"
#include "Vehicle.h"
#include "const.h"
#include "RoadSegment.h"
#include "CCamera.h"
#include "GameDefine.h"
#include "CController.h"

USING_NS_CC;


#define VELOCITY_CAR						100
#define TURN_RATE							3 //degree/frame


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
	m_fYLowest	= 0.f;

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

	m_pCCamera = CCamera::create();
	addChild(m_pCCamera, 3);

	m_sizeScreen = Director::getInstance()->getVisibleSize();

	this->scheduleUpdate();
    return true;
}
	

void Racing::createUI()
{

}

bool Racing::onTouchBegan(Touch *touch, Event *unused_event)
{
    CController::GetInstance()->onTouchBegan(touch->getLocation());
	return true;
}

void Racing::onTouchMoved(Touch *touch, Event *unused_event)
{
    CController::GetInstance()->onTouchMoved(touch->getLocation());
}

void Racing::onTouchEnded(Touch *touch, Event *unused_event)
{
    CController::GetInstance()->onTouchEnded(touch->getLocation());
}

void Racing::onTouchCancelled(Touch *touch, Event *unused_event)
{
	onTouchEnded(touch, unused_event);
}

void Racing::onAcceleration(Acceleration* acc, Event* event)
{
	SET_MIN_MAX(-1, acc->x, 1);
}


void Racing::update(float dt)
{
    m_pCCamera->update(dt);
}

void Racing::updateRoads(float dt)
{		

}