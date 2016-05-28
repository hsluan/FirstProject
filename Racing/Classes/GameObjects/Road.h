#ifndef _ROAD_H_
#define _ROAD_H_

#include "cocos2d.h"

class Vehicle;
class RoadSegment;

class Road: public cocos2d::Node
{
	float m_fYHightest;

	Vehicle* m_hero;
	std::vector<RoadSegment* > m_roads;
	CC_SYNTHESIZE(cocos2d::Size, m_sizeRoadSegment, SizeRoadSegment);
	Road();
	~Road();
public:		
	static Road* create();
	virtual bool init();
	virtual void update(float dt);
};

#endif //_ROAD_H_
