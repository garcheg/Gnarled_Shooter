#include "utils.h"

#pragma warning(disable : 4996)

HANDLE hConsole;

void Utilities::Initialization() { // 8 , 3 , 14
	if (hConsole == NULL)
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Utilities::PrintLog(string text) {
	if (hConsole == NULL)
		Utilities::Initialization();
	SetConsoleTextAttribute(hConsole, 14);
	cout << "[" << Utilities::getCurrentTimeStr() << "] [LOG]: ";
	SetConsoleTextAttribute(hConsole, 3);
	cout << text << endl;

	SetConsoleTextAttribute(hConsole, 8);
}

void Utilities::PrintError(string text) {
	if (hConsole == NULL)
		Utilities::Initialization();
	SetConsoleTextAttribute(hConsole, 4);
	cout << "[" << Utilities::getCurrentTimeStr() << "]" << " [ERROR]: " << text << endl;

	SetConsoleTextAttribute(hConsole, 8);
}

void Utilities::PrintWarning(string text) {
	if (hConsole == NULL)
		Utilities::Initialization();
	SetConsoleTextAttribute(hConsole, 6);
	cout << "[" << Utilities::getCurrentTimeStr() << "]" << " [WARNING]: " << text << endl;

	SetConsoleTextAttribute(hConsole, 8);
}

void Utilities::PrintInfo(string text) {
	if (hConsole == NULL)
		Utilities::Initialization();
	SetConsoleTextAttribute(hConsole, 15);
	cout << "[" << Utilities::getCurrentTimeStr() << "] [INFO]: " << text << endl;

	SetConsoleTextAttribute(hConsole, 8);
}

void Utilities::ClearConsole() {
	if (hConsole == NULL)
		Utilities::Initialization();
	system("cls");
}

string Utilities::getString(string text) {
	if (hConsole == NULL)
		Utilities::Initialization();
	cout << text;
	string result;
	cin >> result;
	return result;
}

int Utilities::getInt(string text) {
	if (hConsole == NULL)
		Utilities::Initialization();
	cout << text;
	int result;
	cin >> result;
	return result;
}

void Utilities::FastThread(void* func) {
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)func, NULL, NULL, NULL);
}

string Utilities::getCurrentTimeStr() {
	time_t current_time;
	struct tm *time_info;
	static char timeString[10];

	time(&current_time);
	time_info = localtime(&current_time);

	strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
	return timeString;
}