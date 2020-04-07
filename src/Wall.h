#pragma once
#ifndef __WALL__
#define __WALL__
#include "DisplayObject.h"
#include "Position.h"

class Wall : public DisplayObject
{
public:
	Wall(Position placement);
	~Wall();
	
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	
private:
	int m_spawnPoint;
	void m_reset();
	void m_move();
	void m_checkBounds();
};
#endif /* defined (__ENEMY__) */
