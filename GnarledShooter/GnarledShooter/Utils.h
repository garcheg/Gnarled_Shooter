#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <thread>


using namespace std;


namespace Utilities {
	CONST FLOAT LIB_VERSION = 0.1f;

	// Консоль

	void Initialization(); // Инициализация текст консоли

	void PrintLog(string text); // Вывести текст в консоль (лог)
	void PrintError(string text); // Вывести текст в консоль (ошибка)
	void PrintWarning(string text); // Вывести текст в консоль (варнинг)
	void PrintInfo(string text); // Вывести текст в консоль (информация)
	void ClearConsole(); // Очистить консоль

	string getString(string text = " ");
	int	   getInt(string text = " ");

	void FastThread(void* func);

	string getCurrentTimeStr(); // Получить время в формате string

}