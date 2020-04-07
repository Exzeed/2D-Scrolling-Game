#pragma once
#ifndef __DOOR__
#define __DOOR__
#include "DisplayObject.h"
#include "Position.h"

class Door : public DisplayObject
{
public:
	Door(Position placement);
	~Door();
	
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	bool isActive;
	
private:
	int m_spawnPoint;
	void m_reset();
	void m_move();
	void m_checkBounds();
};
#endif /* defined (__ENEMY__) */
