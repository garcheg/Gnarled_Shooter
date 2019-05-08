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
}

void logicGame::addMenuButton(string button_name, int func_id) {
	CONST INT marginSpace = 175;

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
		case 3: {
			gVars.GLOBAL_VARS.GAME_ON = false;
			break;
		}
	}
}