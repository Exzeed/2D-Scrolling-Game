#pragma once
#ifndef __INSTRUCTION_SCENE__
#define __INSTRUCTION_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "Ocean.h"

class InstructionScene : public Scene
{
public:
	// constructor
	InstructionScene();
	// destructor
	~InstructionScene();

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
	Label* m_pInstructionLabel;
	StartButton* m_pStartButton;
	Ocean* m_pOcean;

	// private data member
	glm::vec2 m_mousePosition;
	
};

#endif /* defined (__INSTRUCTION_SCENE__) */