#ifndef _ROAD_H_
#define _ROAD_H_

#include "cocos2d.h"

class Vehicle;
class RoadSegment;

class Road: public cocos2d::Node
{
    CC_SYNTHESIZE(cocos2d::Size, m_sizeRoadSegment, SizeRoadSegment);
    CC_SYNTHESIZE(Vehicle*, m_hero, Player);
    
    float m_fYHightest;
	std::vector<RoadSegment* > m_roads;
    
	Road();
	~Road();
public:		
	static Road* create();
	virtual bool init();
	virtual void update(float dt);
    
    void setFocus(cocos2d::Vec2 offset);
};

#endif //_ROAD_H_
