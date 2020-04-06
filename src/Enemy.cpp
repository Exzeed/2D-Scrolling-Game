#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(Position placement)
{
	TheTextureManager::Instance()->load("../Assets/textures/punkrobot1.png",
		"robot", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	const auto size = TheTextureManager::Instance()->getTextureSize("robot");
	setWidth(size.x);
	setHeight(size.y);

	m_reset();
	setIsColliding(false);
	setType(GameObjectType::ENEMY);
	setVelocity(glm::vec2(-5.0f, 0.0f));

	switch(placement)
	{
	case TOP:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 4 + getWidth(), Config::SCREEN_HEIGHT * 0.2));
		//m_spawnPoint = getPosition().y;
		break;
	case CENTER:
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 2.5 + getWidth(), Config::SCREEN_HEIGHT * 0.5));
		break;
	case BOTTOM:
		setPosition(glm::vec2(Config::SCREEN_WIDTH + getWidth(), Config::SCREEN_HEIGHT * 0.9));
		break;
	}
	m_spawnPoint = getPosition().y;

	TheSoundManager::Instance()->load("../Assets/audio/hit.mp3", "hit", SOUND_SFX);
}

Enemy::~Enemy()
= default;

void Enemy::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("robot", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 128, true);
}

void Enemy::update()
{
	m_move();
	m_checkBounds();
}

void Enemy::clean()
{
}

void Enemy::m_reset()
{
	// speed changes
	/*const auto randomVelocityX = Util::RandomRange(-10, -15);
	const auto randomVelocityY = Util::RandomRange(-3, 3);
	setVelocity(glm::vec2(randomVelocityX, randomVelocityY));*/

	// positional changes
	//const auto randomX = Util::RandomRange(getWidth() * 0.5, Config::SCREEN_WIDTH - getWidth());
	//const auto randomY = Util::RandomRange(getHeight() * 0.5, Config::SCREEN_HEIGHT - getHeight());

	//setPosition(glm::vec2(randomX, -getHeight()));
	//setPosition(glm::vec2(Config::SCREEN_WIDTH + getWidth(), randomY));
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 4 + getWidth(), m_spawnPoint));
}

void Enemy::m_move()
{
	const int xPos = getPosition().x + getVelocity().x;
	const int yPos = getPosition().y + getVelocity().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Enemy::m_checkBounds()
{
	if(getPosition().x <= -Config::SCREEN_WIDTH * 0.3f + getWidth())
	{
		m_reset();
	}
}