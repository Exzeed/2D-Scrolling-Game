#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "ScoreBoardManager.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pBackground->draw();
	m_pWall1->draw();
	m_pWall2->draw();
	m_pWall3->draw();
	m_pWall4->draw();

	m_pEnemy1->draw();
	m_pEnemy2->draw();
	m_pEnemy3->draw();

	m_pDoor1->draw();
	m_pDoor2->draw();

	for (auto item : m_pItems)
	{
		item->draw();
	}

	m_pPlayer->draw();

	ScoreBoardManager::Instance()->Draw();
}

void Level1Scene::update()
{
	m_pBackground->update();

	m_pEnemy1->update();
	m_pEnemy2->update();
	m_pEnemy3->update();

	m_pDoor1->update();
	m_pDoor2->update();

	m_pWall1->update();
	m_pWall2->update();
	m_pWall3->update();
	m_pWall4->update();

	m_pPlayer->setPosition(glm::vec2(m_pPlayer->getPosition().x, m_mousePosition.y));
	m_pPlayer->update();

	//CollisionManager::squaredRadiusCheck(m_pPlayer, m_pWall);
	//CollisionManager::AABBCheck(m_pPlayer, m_pWall);
	CollisionManager::circleAABBCheck(m_pPlayer,m_pWall1);
	CollisionManager::circleAABBCheck(m_pPlayer,m_pWall2);
	CollisionManager::circleAABBCheck(m_pPlayer,m_pWall3);
	CollisionManager::circleAABBCheck(m_pPlayer,m_pWall4);
	
	CollisionManager::squaredRadiusCheck(m_pPlayer, m_pEnemy1);
	CollisionManager::squaredRadiusCheck(m_pPlayer, m_pEnemy2);
	CollisionManager::squaredRadiusCheck(m_pPlayer, m_pEnemy3);

	if(CollisionManager::squaredRadiusCheck(m_pPlayer, m_pDoor1))
	{
		m_pDoor1->isActive = false;
	}
	if(CollisionManager::squaredRadiusCheck(m_pPlayer, m_pDoor2))
	{
		m_pDoor2->isActive = false;
	}

	for (auto item : m_pItems)
	{
		item->update();
		CollisionManager::squaredRadiusCheck(m_pPlayer, item);
	}
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	auto wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				m_pPlayer->move(UP);
				break;
			case SDLK_s:
				m_pPlayer->move(DOWN);
				break;
			case SDLK_a:
				//m_pPlayer->move(UP);
				break;
			case SDLK_d:
				//m_pPlayer->move(RIGHT);
				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				m_pPlayer->setIsMoving(false);
				break;

			case SDLK_s:
				m_pPlayer->setIsMoving(false);
				break;

			case SDLK_a:
				//m_pPlayer->setIsMoving(false);
				break;
			case SDLK_d:
				//m_pPlayer->setIsMoving(false);
				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pBackground = new Background();
	addChild(m_pBackground);

	m_pWall1 = new Wall(TOP);
	addChild(m_pWall1);
	m_pWall2 = new Wall(BOTTOM);
	addChild(m_pWall2);
	m_pWall3 = new Wall(CENTER);
	addChild(m_pWall3);
	m_pWall4 = new Wall(MIDDLE);
	addChild(m_pWall4);
	
	m_pPlayer = new Player();
	addChild(m_pPlayer);

	m_pEnemy2 = new Enemy(TOP);
	addChild(m_pEnemy2);
	m_pEnemy3 = new Enemy(CENTER);
	addChild(m_pEnemy3);
	m_pEnemy1 = new Enemy(BOTTOM);
	addChild(m_pEnemy1);

	m_pDoor1 = new Door(TOP);
	addChild(m_pDoor1);
	/*m_pDoor3 = new Door(CENTER);
	addChild(m_pDoor3);*/
	m_pDoor2 = new Door(BOTTOM);
	addChild(m_pDoor2);

	// instantiate Item Pool
	m_buildItems();

	ScoreBoardManager::Instance()->Start();
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::m_buildItems()
{
	for (auto i = 1; i < m_itemNum; ++i)
	{
		auto item = new Item();
		m_pItems.push_back(item);
		addChild(item);
	}
}
