#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

#include "globalVars.h"

using namespace std;
using namespace sf;

namespace logicGame {
	void initLogic();
	void Initialization();
	void addMenuButton(string button_name, int func_id = 0);
	bool checkPosRect(int st_x, int st_y, int end_x, int end_y, int obj_x, int obj_y);
	void logicGeneralMenu();
	void pressGeneralMenuButton(int func_id);
}