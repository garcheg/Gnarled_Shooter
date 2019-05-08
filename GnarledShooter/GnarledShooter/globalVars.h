#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

enum gameActiveStyle {
	MENU, GAME 
};

struct globalVars {
	struct {
		CONST BOOL DEVELOPER_MODE = true; // Developer mode

		CONST string WINDOW_NAME = "Gnarled Shooter"; // Window name
		CONST INT WINDOW_WIDTH = 1280; // Width window
		CONST INT WINDOW_HEIGHT = 720; // Height window
	} GLOBAL_SETTINGS;

	struct {
		BOOL GAME_ON = true;

		gameActiveStyle gameActiveMode;
	} GLOBAL_VARS;

	struct {
		RenderWindow *window;

		struct {
			Text logo_text_menu;
		} Menu;
	} RENDER_VARS;

	struct {
		Font f_arial;
	} FontList;

	struct {
		struct {
			Color logo_text_color = Color(250, 250, 250, 128);
		} Menu;
	} ColorScheme;

	


}; extern globalVars gVars;