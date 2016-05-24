#ifndef __ROAD_H_
#define __ROAD_H_

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

class Road : public cocos2d::Node
{
	std::string _stFilePath;
	cocos2d::Sprite* _firstLane;
	cocos2d::Sprite* _secondLane;
	cocos2d::Sprite* _thirdLane;
	cocos2d::Sprite* _fourthLane;

	CC_SYNTHESIZE(cocos2d::Vec2, _posBegin, PosBegin);
	CC_SYNTHESIZE(bool, _isBegin, IsBegin);
	CC_SYNTHESIZE(TypeRoad, _type, Type);
	CC_SYNTHESIZE(TypeLane, _lane, Lane);
public:
	Road(TypeRoad type, bool isBegin, const cocos2d::Vec2& pos);
	~Road();
	static Road* create(TypeRoad type, bool isBegin, const cocos2d::Vec2& pos);
	bool init();	
	void changeSpriteFrame(int indexImage);
	virtual void update(float dt);
};

#endif //__ROAD_H_
