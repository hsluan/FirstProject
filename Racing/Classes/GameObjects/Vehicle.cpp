#include "Vehicle.h"
#include "CController.h"
#include "GameDefine.h"
#include "const.h"

USING_NS_CC;

#define ASSET_OFFSET        90.0f

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
    m_vel			= 60.0f;
    m_angle         = 90.0f;
    m_type			= type;
    
    switch (type)
    {
        case TypeVehicle::BlackMotors: m_tFilePath = IMG_MOTORCYCLES_BLACK; break;
        case TypeVehicle::BlueMotors: m_tFilePath = IMG_MOTORCYCLES_BLUE; break;
        case TypeVehicle::GreenMotors: m_tFilePath = IMG_MOTORCYCLES_GREEN; break;
        case TypeVehicle::RedMotors: m_tFilePath = IMG_MOTORCYCLES_RED; break;
        case TypeVehicle::YellowMotors: m_tFilePath = IMG_MOTORCYCLES_YELLOW; break;
        case TypeVehicle::BlackCar: m_tFilePath = IMG_SERIAL_CAR_BLACK; break;
        case TypeVehicle::BlueCar: m_tFilePath = IMG_SERIAL_CAR_BLUE; break;
        case TypeVehicle::GreenCar: m_tFilePath = IMG_SERIAL_CAR_GREEN; break;
        case TypeVehicle::RedCar: m_tFilePath = IMG_SERIAL_CAR_RED; break;
        default: m_tFilePath = IMG_SERIAL_CAR_YELLOW; break; //Yellow cars
    }
    
    if (type >= TypeVehicle::BlackCar)
    {
        m_tFilePath = __String::createWithFormat(m_tFilePath.c_str(), 1)->getCString();
    }
    
    this->initWithFile(m_tFilePath);
    this->setPosition(pos);
    
    return true;
}

void Vehicle::update(float dt)
{
    m_angle += CController::GetInstance()->getSteering();
    this->setRotation(-m_angle + ASSET_OFFSET);
    
    auto posCurrent		= getPosition();
    float angle = m_angle * 3.14 / 180;
    posCurrent.x = posCurrent.x + m_vel * std::cos(angle) * dt;
    posCurrent.y = posCurrent.y + m_vel * std::sin(angle) * dt;
    
    this->setPosition(posCurrent);
}