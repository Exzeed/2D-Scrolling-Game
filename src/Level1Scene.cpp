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
	
	m_pItem->draw();
	
	m_pPlayer->draw();

	for (auto cloud : m_pClouds)
	{
		cloud->draw();
	}

	ScoreBoardManager::Instance()->Draw();
}

void Level1Scene::update()
{
	m_pBackground->update();

	m_pItem->update();

	//m_pPlayer->setPosition(glm::vec2(m_mousePosition.x, m_pPlayer->getPosition().y));
	m_pPlayer->setPosition(glm::vec2(m_pPlayer->getPosition().x, m_mousePosition.y));
	m_pPlayer->update();

	CollisionManager::squaredRadiusCheck(m_pPlayer, m_pItem);

	for (auto cloud : m_pClouds)
	{
		cloud->update();
		CollisionManager::squaredRadiusCheck(m_pPlayer, cloud);
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

	m_pItem = new Item();
	addChild(m_pItem);
	
	m_pPlayer = new Player();
	addChild(m_pPlayer);

	// instantiate Cloud Pool
	m_buildClouds();

	ScoreBoardManager::Instance()->Start();
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::m_buildClouds()
{
	for (auto i = 0; i < m_cloudNum; ++i)
	{
		auto cloud = new Cloud();
		m_pClouds.push_back(cloud);
		addChild(cloud);
	}
}
