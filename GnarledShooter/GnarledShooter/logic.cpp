#include "logic.h"

void logicGame::initLogic() {
	logicGame::Initialization();

	while (gVars.GLOBAL_VARS.GAME_ON) {
		if (gVars.GLOBAL_VARS.gameActiveMode == MENU) { logicGame::logicGeneralMenu(); }
		Sleep(10);
	}
}

void logicGame::Initialization() {
	logicGame::addMenuButton("NEW GAME", 0);
	logicGame::addMenuButton("LOAD GAME", 1);
	logicGame::addMenuButton("SETTINGS", 2);
	logicGame::addMenuButton("EXIT", 3);

	int slider_pos_X = (gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (gVars.RENDER_VARS.Settings.BOX_WIDTH / 2) + 50;

	logicGame::addMenuSlider("tttest1", slider_pos_X, 200, 400, 15, 0, 90, 0.3);
	logicGame::addMenuSlider("ttest1", slider_pos_X, 250, 400, 15, 0, 90, 0.7);
	logicGame::addMenuSlider("test1", slider_pos_X, 300, 400, 15, 0, 90, 0.1);

}

void logicGame::addMenuButton(string button_name, int func_id) {
	CONST INT marginSpace = 200;

	CONST INT button_sizeX = 444;
	CONST INT button_sizeY = 50;

	gVars.objList.Menu.objList[gVars.objList.Menu.objNum].posX = (gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (button_sizeX / 2);
	gVars.objList.Menu.objList[gVars.objList.Menu.objNum].posY = marginSpace + (gVars.objList.Menu.objNum * (button_sizeY + 20));
	gVars.objList.Menu.objList[gVars.objList.Menu.objNum].button_name = button_name;
	gVars.objList.Menu.objList[gVars.objList.Menu.objNum].func_id = func_id;
	gVars.objList.Menu.objList[gVars.objList.Menu.objNum].width = button_sizeX;
	gVars.objList.Menu.objList[gVars.objList.Menu.objNum].height = button_sizeY;
	gVars.objList.Menu.objNum++;
}

void logicGame::addMenuSlider(string sl_name, int posX, int posY, int width, int height, int func_id, int start_slider_x, float current_value) {
	gVars.objList.Settings.sliderList[gVars.objList.Settings.sliderNum].slider_name = sl_name;
	gVars.objList.Settings.sliderList[gVars.objList.Settings.sliderNum].posX = posX;
	gVars.objList.Settings.sliderList[gVars.objList.Settings.sliderNum].posY = posY;
	gVars.objList.Settings.sliderList[gVars.objList.Settings.sliderNum].width = width;
	gVars.objList.Settings.sliderList[gVars.objList.Settings.sliderNum].height = height;
	gVars.objList.Settings.sliderList[gVars.objList.Settings.sliderNum].func_id = func_id;
	gVars.objList.Settings.sliderList[gVars.objList.Settings.sliderNum].currentValue = current_value;
	gVars.objList.Settings.sliderList[gVars.objList.Settings.sliderNum].slider_start_x = start_slider_x;

	gVars.objList.Settings.sliderNum++;
}

bool logicGame::checkPosRect(int st_x, int st_y, int end_x, int end_y, int obj_x, int obj_y) {
	if (st_x <= obj_x && obj_x <= end_x && st_y <= obj_y && obj_y <= end_y) {
		return true;
	}
	else {
		return false;
	}
}

void logicGame::logicGeneralMenu() {
	for (int obj = 0; obj < gVars.objList.Menu.objNum; obj++) {
		if (logicGame::checkPosRect(gVars.objList.Menu.objList[obj].posX, gVars.objList.Menu.objList[obj].posY, gVars.objList.Menu.objList[obj].posX + gVars.objList.Menu.objList[obj].width, gVars.objList.Menu.objList[obj].posY + gVars.objList.Menu.objList[obj].height, gVars.RENDER_VARS.mouse_pos.x, gVars.RENDER_VARS.mouse_pos.y)) {
			gVars.objList.Menu.objList[obj].hover = true;
		}
		else {
			gVars.objList.Menu.objList[obj].hover = false;
		}
	}
}

void logicGame::pressGeneralMenuButton(int func_id) {
	switch (func_id) {
		case 2: {
			gVars.GLOBAL_VARS.gameActiveMode = MENU_SETTINGS;
			break;
		}
		case 3: {
			gVars.GLOBAL_VARS.GAME_ON = false;
			break;
		}
	}
}