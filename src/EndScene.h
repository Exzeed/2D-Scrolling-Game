#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "RestartButton.h"
#include "MenuButton.h"
#include "Background.h"

class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();
	
private:
	// Game Objects
	Label* m_pGameOverLabel{};
	Label* m_pScoreLabel{};
	RestartButton* m_pRestartButton{};
	MenuButton* m_pMenuButton{};
	Background* m_pBackground{};

	// private data member
	glm::vec2 m_mousePosition;
};

#endif /* defined (__END_SCENE__) */