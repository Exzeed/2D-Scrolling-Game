#include "Game.h"
#include "Wall.h"

Wall::Wall(Position placement)
{
	TheTextureManager::Instance()->load("../Assets/textures/wall.png",
		"wall", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	const auto size = TheTextureManager::Instance()->getTextureSize("wall");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::WALL);
	setVelocity(glm::vec2(-5.0f, 0.0f));

	switch(placement)
	{
	case TOP:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 1.03 + getWidth(), Config::SCREEN_HEIGHT * 0.51));
		break;
	case MIDDLE:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 4.03 + getWidth(), Config::SCREEN_HEIGHT * 0.1));
		break;
	case CENTER:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 4.03 + getWidth(), Config::SCREEN_HEIGHT * 0.91));
		break;
	case BOTTOM:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 2.53 + getWidth(), Config::SCREEN_HEIGHT * 0.57));
		break;
	}
	//setPosition(glm::vec2(Config::SCREEN_WIDTH * 1.04 + getWidth(), Config::SCREEN_HEIGHT * 0.5));
	m_spawnPoint = getPosition().y;

	TheSoundManager::Instance()->load("../Assets/audio/hit.mp3", "hit", SOUND_SFX);
}

Wall::~Wall()
= default;

void Wall::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("wall", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Wall::update()
{
	m_move();
	m_checkBounds();
}

void Wall::clean()
{
}

void Wall::m_reset()
{
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 4 + getWidth(), m_spawnPoint));
}

void Wall::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Wall::m_checkBounds()
{
	if(getPosition().x <= -Config::SCREEN_WIDTH * 0.3f + getWidth())
	{
		m_reset();
	}
}
