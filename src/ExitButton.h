/*
 * Source File Name: ExitButton.h
 * Author Name: Geethan Kanthasamy
 * Student Number: 301033918
 * Last Modified by: Geethan Kanthasamy
 * Date Last Modified: April 4th 2020
 * Description: Header file to be used by the ExitButton.cpp file
 */

#pragma once
#ifndef __EXIT_BUTTON__
#define __EXIT_BUTTON__

#include "Button.h"

class ExitButton : public Button
{
public:
	ExitButton();
	~ExitButton();

	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__EXIT_BUTTON__) */