#ifndef __CCAMERA_H_
#define __CCAMERA_H_

#include "cocos2d.h"

class Road;

class CCamera : public cocos2d::Node
{
	CCamera();
	~CCamera();
	Road* m_road;
    cocos2d::Vec2 m_focusPoint;

public:
	static CCamera* create();
	virtual bool init();
	virtual void update(float dt);	

};


#endif //__CCAMERA_H_
