#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;


struct globalVars {
	struct {
		CONST BOOL DEVELOPER_MODE = true; // Developer mode

		CONST INT WINDOW_WIDTH = 1280; // Width window
		CONST INT WINDOW_HEIGHT = 720; // Height window
	} GLOBAL_SETTINGS;




}; extern globalVars gVars;