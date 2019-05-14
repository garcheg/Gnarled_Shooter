#include "logic.h"

void logicGame::initLogic() {
	logicGame::Initialization();

	while (gVars.GLOBAL_VARS.GAME_ON) {
		if (gVars.GLOBAL_VARS.gameActiveMode == MENU) { logicGame::logicGeneralMenu(); }
		if (gVars.GLOBAL_VARS.gameActiveMode == MENU_SETTINGS) { logicGame::logicGeneralSettings(); }
		logicGame::logicKeys();
		Sleep(10);
	}
}

void logicGame::Initialization() {
	logicGame::addMenuButton("START GAME", 0);
	logicGame::addMenuButton("SETTINGS", 2);
	logicGame::addMenuButton("EXIT", 3);

	int slider_pos_X = (gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (gVars.RENDER_VARS.Settings.BOX_WIDTH / 2) + 50;

	logicGame::addMenuSlider("All sound", slider_pos_X, 300, 400, 15, 0, 90, 0.3);
	logicGame::addMenuSlider("Effects", slider_pos_X, 350, 400, 15, 0, 90, 0.7);
	logicGame::addMenuSlider("Music", slider_pos_X, 400, 400, 15, 0, 90, 0.1);

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
		case 0: {
			loadGame::GameLoadNormal();
			gVars.GLOBAL_VARS.gameActiveMode = GAME;
			gVars.MusicaGame.music.play(); // ÒÓÒ ÌÓÇÛÊÀ!
			
			break;
		}
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

void logicGame::logicGeneralSettings() {
	for (int obj = 0; obj < gVars.objList.Settings.sliderNum; obj++) {
		if (logicGame::checkPosRect(gVars.objList.Settings.sliderList[obj].stPosX, gVars.objList.Settings.sliderList[obj].stPosY-5, gVars.objList.Settings.sliderList[obj].endPosX, gVars.objList.Settings.sliderList[obj].endPosY+5, gVars.RENDER_VARS.mouse_pos.x, gVars.RENDER_VARS.mouse_pos.y)) {
			gVars.objList.Settings.sliderList[obj].hovered = true;
		}
		else {
			gVars.objList.Settings.sliderList[obj].hovered = false;
		}
	}


	if (logicGame::checkPosRect((gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (gVars.RENDER_VARS.Settings.buttonBack.sizeX / 2), gVars.RENDER_VARS.Settings.buttonBack.posY, (gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (gVars.RENDER_VARS.Settings.buttonBack.sizeX / 2) + gVars.RENDER_VARS.Settings.buttonBack.sizeX, gVars.RENDER_VARS.Settings.buttonBack.posY + +gVars.RENDER_VARS.Settings.buttonBack.sizeY, gVars.RENDER_VARS.mouse_pos.x, gVars.RENDER_VARS.mouse_pos.y)) {
		gVars.RENDER_VARS.Settings.buttonBack.hovered = true;
	} else { gVars.RENDER_VARS.Settings.buttonBack.hovered = false; }
}

void logicGame::pressGeneralSettingSlider(int slider_id) {
	int start_point_slider = gVars.objList.Settings.sliderList[slider_id].posX + gVars.objList.Settings.sliderList[slider_id].slider_start_x;
	int end_point_slider = (gVars.objList.Settings.sliderList[slider_id].width - gVars.objList.Settings.sliderList[slider_id].slider_start_x) + (gVars.objList.Settings.sliderList[slider_id].posX + gVars.objList.Settings.sliderList[slider_id].slider_start_x);
	int size_point_slider = (end_point_slider - start_point_slider);
	float tmp = -(start_point_slider - gVars.RENDER_VARS.mouse_pos.x);
	if (tmp < 0.f) {
		tmp = 0.f;
	}
	if (tmp > 310.f) {
		tmp = 310.f;
	}
	gVars.objList.Settings.sliderList[slider_id].currentValue = tmp / 310.f;
}

void logicGame::logicKeys() {
	if (GetAsyncKeyState(VK_LEFT)) { g_player.moveLeft(); }
	if (GetAsyncKeyState(VK_RIGHT)) { g_player.moveRight(); }
	if (GetAsyncKeyState(VK_UP)) { g_player.moveUp(); }
	if (GetAsyncKeyState(VK_DOWN)) { g_player.moveDown(); }
}