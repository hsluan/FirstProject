#ifndef __RACING_SCENE_H__
#define __RACING_SCENE_H__

#include "cocos2d.h"

class Vehicle;

class Racing : public cocos2d::Layer
{
	Vehicle* _hero;
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void update(float dt);

	CREATE_FUNC(Racing);
};

#endif // __RACING_SCENE_H__
