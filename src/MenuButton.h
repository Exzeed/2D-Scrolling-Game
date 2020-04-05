/*
 * Source File Name: MenuButton.h
 * Author Name: Geethan Kanthasamy
 * Student Number: 301033918
 * Last Modified by: Geethan Kanthasamy
 * Date Last Modified: April 4th 2020
 * Description: Header file to be used by MenuButton.cpp
 */

#pragma once
#ifndef __MENU_BUTTON__
#define __MENU_BUTTON__

#include "Button.h"

class MenuButton : public Button
{
public:
	MenuButton();
	~MenuButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__MENU_BUTTON__) */