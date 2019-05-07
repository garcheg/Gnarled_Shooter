#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

struct globalVars {
	struct {
		CONST BOOL DEVELOPER_MODE = true; // Developer mode

		CONST string WINDOW_NAME = "Gnarled Shooter"; // Window name
		CONST INT WINDOW_WIDTH = 1280; // Width window
		CONST INT WINDOW_HEIGHT = 720; // Height window
	} GLOBAL_SETTINGS;

	struct {
		BOOL GAME_ON = true;
	} GLOBAL_VARS;

	struct {
		RenderWindow *window;
	} RENDER_VARS;



}; extern globalVars gVars;