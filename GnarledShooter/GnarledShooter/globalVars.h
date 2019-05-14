#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class GameCamera {
public:
	GameCamera() {
		c_pos.x = 0;
		c_pos.y = 0;

		c_dist = 1.0f;
	}

	Vector2f getPos() {
		return c_pos;
	}

	float getDist() {
		return c_dist;
	}

	void addDist(float num) {
		c_dist += num;
	}

	void delDist(float num) {
		c_dist -= num;
	}

	void setPos(Vector2f tmp_pos) {
		c_pos.x = tmp_pos.x;
		c_pos.y = tmp_pos.y;
	}
private:
	Vector2f c_pos;
	float c_dist;
};

extern GameCamera g_camera;

enum gameActiveStyle {
	MENU, MENU_SETTINGS, GAME 
};

struct sliderObj {
	string slider_name = "";
	int posX, posY;
	int width, height;
	int slider_start_x;

	float currentValue;

	int func_id;

	int stPosX, stPosY; // slider
	int endPosX, endPosY; // slider

	bool hovered = false;
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

		struct {
			CONST INT BOX_WIDTH = 480;
			CONST INT BOX_HEIGHT = 300;

			RectangleShape box_background;

			Text WINDOW_NAME;

			struct {
				Text slider_name;
				RectangleShape slider_line;
				RectangleShape slider_currentPoint;
				
			} Slider;
			
			struct {
				Text button_text;
				RectangleShape box;

				string button_text_s = "Back";

				int posY = 450;

				int sizeX = 470;
				int sizeY = 50;

				bool hovered = false;
			} buttonBack;
		} Settings;

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

		struct {
			Color box_color = Color(255, 255, 255, 20);

			Color window_nameText = Color(255, 255, 255, 60);

			struct {
				Color text_color = Color(255, 255, 255, 128);
				Color line_slider = Color(255, 255, 255, 90);
				Color line_pointer = Color(255, 255, 255, 150);
			} Slider;
			struct {
				Color box = Color(255, 255, 255, 30);
				Color box_hovered = Color(255, 255, 255, 50);
				Color text = Color(255, 255, 255, 128);
			} buttonBack;
		} Settings;


	} ColorScheme;

	
	struct {
		struct {
			buttonObj objList[5];
			int objNum = 0;

		} Menu;

		struct {
			sliderObj sliderList[10];
			int sliderNum = 0;
		} Settings;
	} objList;



	struct {
		int currentframe = 0;
	} Animation;

	struct {
		int lastTime = 0;
		int renderedFrame = 0;
		int current_fps = 0;

		Text fps_text;
	} FrameCounter;


}; extern globalVars gVars;