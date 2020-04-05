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