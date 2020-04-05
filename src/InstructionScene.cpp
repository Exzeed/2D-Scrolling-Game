/*
 * Source File Name: InstructionScene.cpp
 * Author Name: Geethan Kanthasamy
 * Student Number: 301033918
 * Last Modified by: Geethan Kanthasamy
 * Date Last Modified: April 4th 2020
 * Description: A Scene Object that displays the instructions and controls of the game
 */

#include "InstructionScene.h"
#include "Game.h"
#include <ctime>
#include "glm/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

InstructionScene::InstructionScene()
{
	InstructionScene::start();
}

InstructionScene::~InstructionScene()
{
}

void InstructionScene::draw()
{
	m_pBackground->draw();
	m_pInstructionLabel->draw();
	m_pStartButton->draw();
}

void InstructionScene::update()
{
	m_pBackground->update();
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
}

void InstructionScene::clean()
{
	delete m_pInstructionLabel;
	
	removeAllChildren();
}

void InstructionScene::handleEvents()
{
	int wheel = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event))
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
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
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
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void InstructionScene::start()
{
	m_pBackground = new Background();
	addChild(m_pBackground);

	
	SDL_Color yellow = { 255, 255, 0, 255 };
	m_pInstructionLabel = new Label("Instructions", "Consolas", 80, yellow, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 100.0f));
	m_pInstructionLabel->setParent(this);
	addChild(m_pInstructionLabel);

	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.8f));
	addChild(m_pStartButton);
}

glm::vec2 InstructionScene::getMousePosition()
{
	return m_mousePosition;
}
