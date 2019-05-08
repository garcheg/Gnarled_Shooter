#include "render.h"

void renderGame::generalThread() {
	renderGame::Initialization();

	while (gVars.GLOBAL_VARS.GAME_ON) {
		sf::Event event;
		while (gVars.RENDER_VARS.window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				gVars.RENDER_VARS.window->close();
				gVars.GLOBAL_VARS.GAME_ON = false;
			}
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
				if (gVars.GLOBAL_VARS.gameActiveMode == MENU) {
					for (int obj = 0; obj < gVars.objList.Menu.objNum; obj++) {
						if (gVars.objList.Menu.objList[obj].hover == true) {
							logicGame::pressGeneralMenuButton(gVars.objList.Menu.objList[obj].func_id);
						}
					}
				}
			}
			if (GetAsyncKeyState(VK_LBUTTON)) {
				if (gVars.GLOBAL_VARS.gameActiveMode == MENU_SETTINGS) {
					for (int obj = 0; obj < gVars.objList.Settings.sliderNum; obj++) {
						if (gVars.objList.Settings.sliderList[obj].hovered) {
							logicGame::pressGeneralSettingSlider(obj);
						}
					}
				}
			}

		}

		gVars.RENDER_VARS.mouse_pos = Mouse::getPosition(*gVars.RENDER_VARS.window);

		gVars.RENDER_VARS.window->clear();
		gVars.RENDER_VARS.Background.background_box.setFillColor(gVars.ColorScheme.Background.background_color);
		gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Background.background_box);

		if (gVars.GLOBAL_VARS.gameActiveMode == MENU) { renderGame::DrawGeneralMenu(); }
		if (gVars.GLOBAL_VARS.gameActiveMode == MENU_SETTINGS) { renderGame::DrawSettingsMenu(); }
		gVars.RENDER_VARS.window->display();
	}
}

void renderGame::Initialization() {
	gVars.RENDER_VARS.window = new RenderWindow(VideoMode(gVars.GLOBAL_SETTINGS.WINDOW_WIDTH, gVars.GLOBAL_SETTINGS.WINDOW_HEIGHT), gVars.GLOBAL_SETTINGS.WINDOW_NAME);

}

void renderGame::DrawGeneralMenu() {
	gVars.RENDER_VARS.Menu.logo_text_menu.setFillColor(gVars.ColorScheme.Menu.logo_text_color);
	gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Menu.logo_text_menu);

	for (int obj = 0; obj < gVars.objList.Menu.objNum; obj++) {
		gVars.RENDER_VARS.Menu.box_menu.setSize(Vector2f(gVars.objList.Menu.objList[obj].width, gVars.objList.Menu.objList[obj].height));
		gVars.RENDER_VARS.Menu.box_menu.setPosition(Vector2f(gVars.objList.Menu.objList[obj].posX, gVars.objList.Menu.objList[obj].posY));
		if (gVars.objList.Menu.objList[obj].hover) {
			gVars.RENDER_VARS.Menu.box_menu.setFillColor(gVars.ColorScheme.Menu.box_menu_color_hovered);
		}
		else {
			gVars.RENDER_VARS.Menu.box_menu.setFillColor(gVars.ColorScheme.Menu.box_menu_color);
		}
		gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Menu.box_menu);

		gVars.RENDER_VARS.Menu.button_text.setFillColor(gVars.ColorScheme.Menu.button_text_color);
		gVars.RENDER_VARS.Menu.button_text.setCharacterSize(32);
		gVars.RENDER_VARS.Menu.button_text.setString(gVars.objList.Menu.objList[obj].button_name);
		gVars.RENDER_VARS.Menu.button_text.setPosition((gVars.objList.Menu.objList[obj].posX + gVars.objList.Menu.objList[obj].width / 2) - gVars.RENDER_VARS.Menu.button_text.getLocalBounds().width / 2, gVars.objList.Menu.objList[obj].posY + 5);
		gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Menu.button_text);
	}
}

void renderGame::DrawSettingsMenu() {
	gVars.RENDER_VARS.Settings.box_background.setSize(Vector2f(gVars.RENDER_VARS.Settings.BOX_WIDTH, gVars.RENDER_VARS.Settings.BOX_HEIGHT));
	gVars.RENDER_VARS.Settings.box_background.setPosition(Vector2f((gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (gVars.RENDER_VARS.Settings.BOX_WIDTH / 2), (gVars.GLOBAL_SETTINGS.WINDOW_HEIGHT / 2) - (gVars.RENDER_VARS.Settings.BOX_HEIGHT / 2)));
	gVars.RENDER_VARS.Settings.box_background.setFillColor(gVars.ColorScheme.Settings.box_color);
	gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Settings.box_background);

	gVars.RENDER_VARS.Settings.WINDOW_NAME.setFillColor(gVars.ColorScheme.Settings.window_nameText);
	gVars.RENDER_VARS.Settings.WINDOW_NAME.setPosition(Vector2f((gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (gVars.RENDER_VARS.Settings.WINDOW_NAME.getLocalBounds().width / 2), (gVars.GLOBAL_SETTINGS.WINDOW_HEIGHT / 2) - (gVars.RENDER_VARS.Settings.BOX_HEIGHT / 2) + 10));
	gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Settings.WINDOW_NAME);

	renderGame::DrawSliderSettings();
}

void renderGame::DrawSliderSettings() {
	CONST INT POINTER_SIZE_X = 10;
	CONST INT POINTER_SIZE_Y = 10;

	for (int obj = 0; obj < gVars.objList.Settings.sliderNum; obj++) {
		gVars.RENDER_VARS.Settings.Slider.slider_name.setString(gVars.objList.Settings.sliderList[obj].slider_name);
		gVars.RENDER_VARS.Settings.Slider.slider_name.setPosition(Vector2f(gVars.objList.Settings.sliderList[obj].posX, gVars.objList.Settings.sliderList[obj].posY));
		gVars.RENDER_VARS.Settings.Slider.slider_name.setCharacterSize(gVars.objList.Settings.sliderList[obj].height);
		gVars.RENDER_VARS.Settings.Slider.slider_name.setFillColor(gVars.ColorScheme.Settings.Slider.text_color);

		gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Settings.Slider.slider_name);
		//slider
		gVars.RENDER_VARS.Settings.Slider.slider_line.setSize(Vector2f(gVars.objList.Settings.sliderList[obj].width - gVars.objList.Settings.sliderList[obj].slider_start_x, gVars.objList.Settings.sliderList[obj].height/4));
		gVars.RENDER_VARS.Settings.Slider.slider_line.setPosition(Vector2f(gVars.objList.Settings.sliderList[obj].posX + gVars.objList.Settings.sliderList[obj].slider_start_x, gVars.objList.Settings.sliderList[obj].posY + (gVars.RENDER_VARS.Settings.Slider.slider_name.getLocalBounds().height)));
		gVars.RENDER_VARS.Settings.Slider.slider_line.setFillColor(gVars.ColorScheme.Settings.Slider.line_slider);

		gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Settings.Slider.slider_line);


		gVars.RENDER_VARS.Settings.Slider.slider_currentPoint.setFillColor(gVars.ColorScheme.Settings.Slider.line_pointer);
		gVars.RENDER_VARS.Settings.Slider.slider_currentPoint.setSize(Vector2f(POINTER_SIZE_X, POINTER_SIZE_Y));
		int start_point_slider = gVars.objList.Settings.sliderList[obj].posX + gVars.objList.Settings.sliderList[obj].slider_start_x;
		int end_point_slider = (gVars.objList.Settings.sliderList[obj].width - gVars.objList.Settings.sliderList[obj].slider_start_x) + (gVars.objList.Settings.sliderList[obj].posX + gVars.objList.Settings.sliderList[obj].slider_start_x);
		int size_point_slider = (end_point_slider - start_point_slider) * gVars.objList.Settings.sliderList[obj].currentValue;
		start_point_slider += size_point_slider;
		gVars.RENDER_VARS.Settings.Slider.slider_currentPoint.setPosition(Vector2f(start_point_slider - (POINTER_SIZE_X / 2), gVars.objList.Settings.sliderList[obj].posY + (gVars.RENDER_VARS.Settings.Slider.slider_name.getLocalBounds().height) - (POINTER_SIZE_Y / 2) + 1));
		
		
		gVars.objList.Settings.sliderList[obj].stPosX = gVars.objList.Settings.sliderList[obj].posX + gVars.objList.Settings.sliderList[obj].slider_start_x;
		gVars.objList.Settings.sliderList[obj].stPosY = gVars.objList.Settings.sliderList[obj].posY + (gVars.RENDER_VARS.Settings.Slider.slider_name.getLocalBounds().height);
		gVars.objList.Settings.sliderList[obj].endPosX = gVars.objList.Settings.sliderList[obj].stPosX + (gVars.objList.Settings.sliderList[obj].width - gVars.objList.Settings.sliderList[obj].slider_start_x);
		gVars.objList.Settings.sliderList[obj].endPosY = gVars.objList.Settings.sliderList[obj].stPosY + (gVars.objList.Settings.sliderList[obj].height / 4);
		
		gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Settings.Slider.slider_currentPoint);
	}
}
//gVars.objList.Settings.sliderList[obj].posX + gVars.objList.Settings.sliderList[obj].slider_start_x        // start
// (gVars.objList.Settings.sliderList[obj].width - (gVars.objList.Settings.sliderList[obj].posX + gVars.objList.Settings.sliderList[obj].slider_start_x)) + 