/*
 * Source File Name: InstructionsButton.cpp
 * Author Name: Geethan Kanthasamy
 * Student Number: 301033918
 * Last Modified by: Geethan Kanthasamy
 * Date Last Modified: April 4th 2020
 * Description: Displays a button that transitions to the Instructions Scene
 */

#include "InstructionsButton.h"
#include "Game.h"

InstructionsButton::InstructionsButton()
	// call super constructor
	:Button(
		"../Assets/textures/InstructionButton.png",
		"instructionButton",
		INSTRUCTION_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	
}

InstructionsButton::~InstructionsButton()
{
}

bool InstructionsButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			Game::Instance()->changeSceneState(INSTRUCTION_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
