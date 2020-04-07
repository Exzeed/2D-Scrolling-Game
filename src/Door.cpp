#include "Game.h"
#include "Door.h"

Door::Door(Position placement)
{
	TheTextureManager::Instance()->load("../Assets/textures/break.png",
		"door", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	const auto size = TheTextureManager::Instance()->getTextureSize("door");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::DOOR);
	setVelocity(glm::vec2(-5.0f, 0.0f));
	isActive = true;

	switch(placement)
	{
	case TOP:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 1.03 + getWidth(), Config::SCREEN_HEIGHT * 0.01 + getHeight()));
		break;
	/*case CENTER:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 2.5 + getWidth(), Config::SCREEN_HEIGHT * 0.5));
		break;*/
	case BOTTOM:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 2.53 + getWidth(), Config::SCREEN_HEIGHT * 1.07 - getHeight()));
		break;
	}
	m_spawnPoint = getPosition().y;

	TheSoundManager::Instance()->load("../Assets/audio/hit.mp3", "hit", SOUND_SFX);
}

Door::~Door()
= default;

void Door::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("door", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Door::update()
{
	if(isActive)
	{
		m_move();
		m_checkBounds();
	}

	if(!isActive)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 2, Config::SCREEN_HEIGHT * 2));
		setVelocity(glm::vec2(0.0f, 0.0f));
		setType(GameObjectType::NONE);
	}
}

void Door::clean()
{
}

void Door::m_reset()
{
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 4 + getWidth(), m_spawnPoint));
}

void Door::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Door::m_checkBounds()
{
	if(getPosition().x <= -Config::SCREEN_WIDTH * 0.3f + getWidth())
	{
		m_reset();
	}
}