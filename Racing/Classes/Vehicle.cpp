#include "Vehicle.h"
#include "GameDefine.h"

USING_NS_CC;

Vehicle* Vehicle::create( TypeVehicle type, const Vec2& pos )
{
	Vehicle* pRet = new(std::nothrow) Vehicle;
	if (pRet && pRet->init(type, pos))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool Vehicle::init( TypeVehicle type, const Vec2& pos)
{
	//init value
	_vel = Vec2::ZERO;
	
	switch (type)
	{	
	case TypeVehicle::BlackMotors: _stFilePath = IMG_MOTORCYCLES_BLACK; break;
	case TypeVehicle::BlueMotors: _stFilePath = IMG_MOTORCYCLES_BLUE; break;
	case TypeVehicle::GreenMotors: _stFilePath = IMG_MOTORCYCLES_GREEN; break;
	case TypeVehicle::RedMotors: _stFilePath = IMG_MOTORCYCLES_RED; break;
	case TypeVehicle::YellowMotors: _stFilePath = IMG_MOTORCYCLES_YELLOW; break;
	case TypeVehicle::BlackCar: _stFilePath = IMG_SERIAL_CAR_BLACK; break;
	case TypeVehicle::BlueCar: _stFilePath = IMG_SERIAL_CAR_BLUE; break;
	case TypeVehicle::GreenCar: _stFilePath = IMG_SERIAL_CAR_GREEN; break;
	case TypeVehicle::RedCar: _stFilePath = IMG_SERIAL_CAR_RED; break;
	default: _stFilePath = IMG_SERIAL_CAR_YELLOW; break; //Yellow cars
	}

	if (type >= TypeVehicle::BlackCar)
	{
		_stFilePath = __String::createWithFormat(_stFilePath.c_str(), 1)->getCString();
	}

	this->initWithFile(_stFilePath);
	this->setPosition(pos);

	return true;
}

void Vehicle::update(float dt) 
{
	auto posCurrent = getPosition();
	posCurrent.y += dt;
	this->setPosition(posCurrent);
}