// ~~~~~~~~~ [ Includes ] ~~~~~~~~~ //
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

#include "globalVars.h"
#include "Utils.h"
#include "generalLoad.h"
#include "render.h"

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
		Utilities::PrintLog("������� ����� ������������ ����!");
		Utilities::PrintLog("��� ��� ���������� �������� ����� ������ �� Release");
		cout << endl;
		Utilities::PrintLog("���-����: ");
		Utilities::PrintLog("-");
		cout << endl;
	}
	if (gVars.GLOBAL_SETTINGS.DEVELOPER_MODE) { Utilities::PrintLog("������� ��������� ������ ������"); }
	loadGame::StartupLoadFast();
	if (gVars.GLOBAL_SETTINGS.DEVELOPER_MODE) { Utilities::PrintLog("������ ������ �������"); }
	Utilities::FastThread(renderGame::generalThread);
}