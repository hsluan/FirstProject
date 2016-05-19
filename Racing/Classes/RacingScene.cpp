#include "RacingScene.h"
#include "Vehicle.h"
#include "const.h"

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

// on "init" you need to initialize your instance
bool Racing::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
		return false;
    }


	_hero = nullptr;

	auto sizeScreen = Director::getInstance()->getVisibleSize();
	

	_hero = Vehicle::create( TypeVehicle::BlackCar, Vec2(sizeScreen.width*0.5f,64) );	
	addChild(_hero);

	this->scheduleUpdate();
    return true;
}

void Racing::update(float dt)
{
	_hero->update(dt);
}