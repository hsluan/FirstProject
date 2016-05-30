#ifndef _ROADSEGMENT_H_
#define _ROADSEGMENT_H_

#include "cocos2d.h"

enum class TypeLane
{
	Straight=0,
	Cross,
	Bend
};

enum class TypeRoad
{
	Asphalt = 0,
	Dirt,
	Sand
};

class RoadSegment: public cocos2d::Node
{
	std::string m_stFilePath;
	cocos2d::Sprite* m_firstLane;
	cocos2d::Sprite* m_secondLane;
	cocos2d::Sprite* m_thirdLane;
	cocos2d::Sprite* m_fourthLane;

	CC_SYNTHESIZE(cocos2d::Vec2, m_posBegin, PosBegin);
	CC_SYNTHESIZE(bool, m_isBegin, IsBegin);
	CC_SYNTHESIZE(TypeRoad, m_type, Type);
	CC_SYNTHESIZE(TypeLane, m_lane, Lane);

public:
	RoadSegment(TypeRoad type, bool isBegin, const cocos2d::Vec2& pos);
	~RoadSegment();
	static RoadSegment* create(TypeRoad type, bool isBegin, const cocos2d::Vec2& pos);
	bool init();	
	void changeSpriteFrame(int firstIndex, int midIndex, int fourthIndex);
	virtual void update(float dt);
};

#endif //_ROADSEGMENT_H_
