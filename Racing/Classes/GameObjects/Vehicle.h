#ifndef __VEHICLE_H_
#define __VEHICLE_H_

#include "cocos2d.h"

enum class TypeVehicle
{
	BlackMotors = 0,
	BlueMotors,
	GreenMotors,
	RedMotors,
	YellowMotors,
	BlackCar,
	BlueCar,
	GreenCar,
	RedCar,
	YellowCar
};

class Vehicle : public cocos2d::Sprite
{
	CC_SYNTHESIZE(TypeVehicle, m_type, Type);
	float m_vel;
	float m_angle;
	std::string m_tFilePath;
public:
	static Vehicle* create(TypeVehicle type, const cocos2d::Vec2& pos);
	bool init(TypeVehicle type, const cocos2d::Vec2& pos);
	virtual void update(float dt);
};


#endif //__VEHICLE_H_
