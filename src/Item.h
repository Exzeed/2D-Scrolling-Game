#pragma once
#ifndef __ITEM__
#define __ITEM__
#include "DisplayObject.h"

class Item : public DisplayObject
{
public:
	Item();
	~Item();
	
	void draw() override;
	void update() override;
	void clean() override;

private:
	void m_reset();
	void m_move();
	void m_checkBounds();
};

#endif /* defined (__ITEM__) */