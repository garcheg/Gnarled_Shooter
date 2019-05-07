#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <thread>


using namespace std;


namespace Utilities {
	CONST FLOAT LIB_VERSION = 0.1f;

	// �������

	void Initialization(); // ������������� ����� �������

	void PrintLog(string text); // ������� ����� � ������� (���)
	void PrintError(string text); // ������� ����� � ������� (������)
	void PrintWarning(string text); // ������� ����� � ������� (�������)
	void PrintInfo(string text); // ������� ����� � ������� (����������)
	void ClearConsole(); // �������� �������

	string getString(string text = " ");
	int	   getInt(string text = " ");

	void FastThread(void* func);

	string getCurrentTimeStr(); // �������� ����� � ������� string

}