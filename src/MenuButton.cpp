#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton()
	// call super constructor
	:Button(
		"../Assets/textures/MenuButton.png",
		"startButton",
		START_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{
	
}

MenuButton::~MenuButton()
{
}

bool MenuButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			Game::Instance()->changeSceneState(START_SCENE);
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
