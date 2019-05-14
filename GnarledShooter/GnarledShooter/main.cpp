// ~~~~~~~~~ [ Includes ] ~~~~~~~~~ //
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

#include "globalVars.h"
#include "Utils.h"
#include "generalLoad.h"
#include "render.h"
#include "logic.h"

using namespace std;
// ~~~~~~~~~ [ Vars ] ~~~~~~~~~ //

// ~~~~~~~~~ [ Func's ] ~~~~~~~~~ //
void InitThread(); // Startup function
// ~~~~~~~~~ [ Code ] ~~~~~~~~~ //
int main() {
	setlocale(LC_ALL, "ru");
	InitThread();
	while (gVars.GLOBAL_VARS.GAME_ON) {
		Sleep(333);
	}
	return 0;
}

void InitThread() {
	if (gVars.GLOBAL_SETTINGS.DEVELOPER_MODE) {
		Utilities::PrintLog("Запущен режим разработчика игры!");
		Utilities::PrintLog("Для его отключения измените режим сборки на Release");
		cout << endl;
		Utilities::PrintLog("Чит-коды: ");
		Utilities::PrintLog("-");
		cout << endl;
	}
	if (gVars.GLOBAL_SETTINGS.DEVELOPER_MODE) { Utilities::PrintLog("Быстрая подгрузка нужных файлов"); }
	loadGame::StartupLoadFast();
	if (gVars.GLOBAL_SETTINGS.DEVELOPER_MODE) { Utilities::PrintLog("Запуск потока графики"); }
	Utilities::FastThread(renderGame::generalThread);
	if (gVars.GLOBAL_SETTINGS.DEVELOPER_MODE) { Utilities::PrintLog("Запуск потока логики"); }
	Utilities::FastThread(logicGame::initLogic);


	// TEMP DEVOPLING
	loadGame::GameLoadNormal();
	gVars.GLOBAL_VARS.gameActiveMode = GAME;
	GameCamera g_camera;
}