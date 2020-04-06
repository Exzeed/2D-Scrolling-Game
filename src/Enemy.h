#pragma once
#ifndef __ENEMY__
#define __ENEMY__
#include "DisplayObject.h"
#include "Position.h"

class Enemy : public DisplayObject
{
public:
	Enemy();
	Enemy(Position placement);
	~Enemy();
	
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
