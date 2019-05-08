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


struct buttonObj {
	int posX, posY;
	int width, height;
	string button_name = "";
	int func_id = 0;

	bool hover = false;
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
			RectangleShape background_box;
		} Background;

		struct {
			Text logo_text_menu;

			RectangleShape box_menu;
			Text button_text;
		} Menu;

		Vector2i mouse_pos;
	} RENDER_VARS;

	struct {
		Font f_arial;
		Font f_EuropeCondensed;
	} FontList;

	struct {
		struct {
			Color background_color = Color(25, 25, 25, 255);
		} Background;

		struct {
			Color logo_text_color = Color(250, 250, 250, 128);

			Color box_menu_color = Color(255, 255, 255, 30);
			Color box_menu_color_hovered = Color(255, 255, 255, 80);
			Color button_text_color = Color(255, 255, 255, 122);
		} Menu;


	} ColorScheme;

	
	struct {
		struct {
			buttonObj objList[5];
			int objNum = 0;

		} Menu;
	} objList;

}; extern globalVars gVars;