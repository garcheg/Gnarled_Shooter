// ~~~~~~~~~ [ Includes ] ~~~~~~~~~ //
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

#include "globalVars.h"
#include "Utils.h"
#include "generalLoad.h"

using namespace std;
// ~~~~~~~~~ [ Vars ] ~~~~~~~~~ //

// ~~~~~~~~~ [ Func's ] ~~~~~~~~~ //
void InitThread(); // Startup function
// ~~~~~~~~~ [ Code ] ~~~~~~~~~ //
int main() {
	setlocale(LC_ALL, "ru");
	InitThread();
	system("pause");
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


}