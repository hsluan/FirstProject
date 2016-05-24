#include "Vehicle.h"
#include "GameDefine.h"
#include "const.h"

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
	_vel			= Vec2::ZERO;
	_targetAngle	= 0.f;
	_type			= type;

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
	auto posCurrent		= getPosition();
	//float fCurrentAngle = getRotation();

	//if (_targetAngle != fCurrentAngle )
	//{

	//	float delta = _targetAngle - fCurrentAngle;

	//	//Limit range from -180 to 180  degree
	//	if (180 <= delta)
	//		delta -= 360;
	//	else if (-180 > delta)
	//		delta += 360;
	//	fCurrentAngle += delta;
	//	/*if ( 0 < delta )
	//		fCurrentAngle += TURN_RATE;
	//	else
	//		fCurrentAngle -= TURN_RATE;

	//	if ( TURN_RATE > abs(delta))
	//	{			
	//		fCurrentAngle = _targetAngle;
	//	}*/
	//}
	//this->setRotation(_targetAngle);
	this->setPosition(posCurrent);
}