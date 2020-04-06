#include "Player.h"
#include "Game.h"

Player::Player() :m_maxSpeed(5.0f), m_isMoving(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/ufo.png",
		"ufo", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("ufo");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.1f, Config::SCREEN_HEIGHT * 0.5f));
	setIsColliding(false);
	setType(GameObjectType::PLAYER);
	setVelocity(glm::vec2(0.0f, 0.0f));

	TheSoundManager::Instance()->load("../Assets/audio/techno.ogg",
		"bgm", sound_type::SOUND_MUSIC);
	TheSoundManager::Instance()->playMusic("bgm", -1);
}

Player::~Player()
{
}

void Player::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("ufo", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Player::update()
{
	
	/*auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	const auto deltaTime = TheGame::Instance()->getDeltaTime();
	setVelocity(glm::vec2(currentVelocity.x * (1.0f - deltaTime * 5.0f), currentVelocity.y));

	
	auto deltax = currentPosition.x + currentVelocity.x;
	setPosition(glm::vec2(deltax, currentPosition.y));*/

	m_checkBounds();
}

void Player::clean()
{
}

void Player::move(Move newMove)
{
	auto currentVelocity = getVelocity();
	
	
	switch(newMove)
	{
	case DOWN:
		setVelocity(glm::vec2(0.0f, 1.0f * m_maxSpeed));
		break;
	case UP:
		setVelocity(glm::vec2(0.0f, -1.0f * m_maxSpeed));
		break;
	}
}

bool Player::getIsMoving()
{
	return m_isMoving;
}

void Player::setIsMoving(bool newState)
{
	m_isMoving = newState;
}

void Player::m_checkBounds()
{
	// check bottom bounds
	if(getPosition().y >= Config::SCREEN_HEIGHT - getHeight() * 0.5f)
	{
		//setPosition(glm::vec2(Config::SCREEN_WIDTH - getWidth() * 0.5f, getPosition().y));
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT - getHeight() * 0.5f));
	}

	// check top bounds
	if (getPosition().y <=  getHeight() * 1.1f)
	{
		//setPosition(glm::vec2(getWidth() * 0.5f, getPosition().y));
		setPosition(glm::vec2(getPosition().x, getHeight() * 1.1f));
	}
}
