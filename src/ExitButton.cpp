/*
 * Source File Name: ExitButton.cpp
 * Author Name: Geethan Kanthasamy
 * Student Number: 301033918
 * Last Modified by: Geethan Kanthasamy
 * Date Last Modified: April 4th 2020
 * Description: Displays a button that exits the application
 */

#include "ExitButton.h"
#include "Game.h"

ExitButton::ExitButton()
	// call super constructor
	:Button(
		"../Assets/textures/ExitButton.png",
		"exitButton",
		EXIT_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	
}

ExitButton::~ExitButton()
{
}

bool ExitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			TheGame::Instance()->quit();
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
