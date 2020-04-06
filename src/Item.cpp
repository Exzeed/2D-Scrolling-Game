#include "Item.h"
#include "Game.h"

Item::Item()
{
	TheTextureManager::Instance()->load("../Assets/textures/Pickup.gif",
		"item", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("item");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::ITEM);
	setVelocity(glm::vec2(-5.0f, 0.0f));

	TheSoundManager::Instance()->load("../Assets/audio/item.flac", "pickup", SOUND_SFX);
}

Item::~Item()
= default;

void Item::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("item", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Item::update()
{
	m_move();
	m_checkBounds();
}

void Item::clean()
{
}

void Item::m_reset()
{
	//const auto randomX = Util::RandomRange(getWidth() * 0.5, Config::SCREEN_WIDTH - getWidth());
	const auto randomY = Util::RandomRange(getHeight() * 1.3, Config::SCREEN_HEIGHT - getHeight());

	setPosition(glm::vec2(Config::SCREEN_WIDTH + getWidth(), randomY));
}

void Item::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Item::m_checkBounds()
{
	if(getPosition().x <= -Config::SCREEN_WIDTH * 0.2f + getWidth())
	{
		m_reset();
	}
}
