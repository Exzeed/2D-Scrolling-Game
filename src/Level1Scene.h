#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Item.h"
#include "Background.h"
#include "Enemy.h"
#include "Door.h"
#include "Wall.h"
#include "Config.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	Player* m_pPlayer;
	Background* m_pBackground;
	
	Enemy* m_pEnemy1;
	Enemy* m_pEnemy2;
	Enemy* m_pEnemy3;

	Door* m_pDoor1;
	Door* m_pDoor2;
	//Door* m_pDoor3;

	Wall* m_pWall1;
	Wall * m_pWall2;
	Wall* m_pWall3;
	Wall* m_pWall4;

	int m_itemNum = Config::ITEM_NUM;
	std::vector<Item*> m_pItems;
	void m_buildItems();

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__LEVEL_1_SCENE__) */
