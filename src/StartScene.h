#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "ExitButton.h"
#include "InstructionsButton.h"
#include "Background.h"

class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

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
	Label* m_pStartLabel;
	StartButton* m_pStartButton;
	ExitButton* m_pExitButton;
	InstructionsButton* m_pInstructionsButton;
	Background* m_pBackground;

	// private data member
	glm::vec2 m_mousePosition;
	
};

#endif /* defined (__START_SCENE__) */