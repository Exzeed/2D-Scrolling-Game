#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Player.h"
#include "Item.h"
#include "Background.h"
#include "Enemy.h"
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
	Item* m_pItem;
	Background* m_pBackground;
	Enemy* m_pEnemy1;
	Enemy* m_pEnemy2;
	Enemy* m_pEnemy3;

	/*int m_cloudNum = Config::CLOUD_NUM;
	std::vector<Cloud*> m_pClouds;
	void m_buildClouds();*/

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__LEVEL_1_SCENE__) */
