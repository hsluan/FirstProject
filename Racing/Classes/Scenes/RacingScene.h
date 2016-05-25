#ifndef __RACING_SCENE_H__
#define __RACING_SCENE_H__

#include "cocos2d.h"

class Vehicle;
class Road;
class Racing : public cocos2d::Layer
{
	cocos2d::Size _sizeTilesRoad;
	cocos2d::Size _sizeScreen;
	Vehicle* _hero;
	std::vector<Road*> _roads;
	float _fYHightest;
	float _fYLowest;		
public:
	static cocos2d::Scene* createScene();

	void createRoads();
	void createUI();
	void updateRoads(float dt);

	virtual bool init();
	virtual void update(float dt);
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* event);
	
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
//	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
//#endif

	CREATE_FUNC(Racing);
};

#endif // __RACING_SCENE_H__
