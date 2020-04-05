/*
 * Source File Name: InstructionsButton.h
 * Author Name: Geethan Kanthasamy
 * Student Number: 301033918
 * Last Modified by: Geethan Kanthasamy
 * Date Last Modified: April 4th 2020
 * Description: Header file to be used by the InstructionsButton.cpp file
 */

#pragma once
#ifndef __INSTRUCTIONS_BUTTON__
#define __INSTRUCTIONS_BUTTON__

#include "Button.h"

class InstructionsButton : public Button
{
public:
	InstructionsButton();
	~InstructionsButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__INSTRUCTIONS_BUTTON__) */