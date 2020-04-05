/*
 * Source File Name: InstructionScene.h
 * Author Name: Geethan Kanthasamy
 * Student Number: 301033918
 * Last Modified by: Geethan Kanthasamy
 * Date Last Modified: April 4th 2020
 * Description: Header file to be used by the InstructionScene.cpp file
 */

#pragma once
#ifndef __INSTRUCTION_SCENE__
#define __INSTRUCTION_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "Background.h"

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
	Background* m_pBackground;

	// private data member
	glm::vec2 m_mousePosition;
};
#endif /* defined (__INSTRUCTION_SCENE__) */
