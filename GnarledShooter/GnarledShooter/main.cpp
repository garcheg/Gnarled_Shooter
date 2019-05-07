// ~~~~~~~~~ [ Includes ] ~~~~~~~~~ //
#include <Windows.h>
#include <iostream>
#include <string>

#include "globalVars.h"
#include "Utils.h"

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
	}
}