#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

#include "globalVars.h"
#include "generalLoad.h"

using namespace std;
using namespace sf;

namespace logicGame {
	void initLogic();
	void Initialization();
	void addMenuButton(string button_name, int func_id = 0);
	void addMenuSlider(string sl_name, int posX, int posY, int width, int height, int func_id, int start_slider_x, float current_value = 0);
	bool checkPosRect(int st_x, int st_y, int end_x, int end_y, int obj_x, int obj_y);
	void logicGeneralMenu();
	void pressGeneralMenuButton(int func_id);
	void logicGeneralSettings();
	void pressGeneralSettingSlider(int slider_id);
	void logicKeys();
	void mlsc50Thread();
}