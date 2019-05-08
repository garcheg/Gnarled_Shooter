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

		}

		gVars.RENDER_VARS.mouse_pos = Mouse::getPosition(*gVars.RENDER_VARS.window);

		gVars.RENDER_VARS.window->clear();
		gVars.RENDER_VARS.Background.background_box.setFillColor(gVars.ColorScheme.Background.background_color);
		gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Background.background_box);

		if (gVars.GLOBAL_VARS.gameActiveMode == MENU) { renderGame::DrawGeneralMenu(); }
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
		gVars.RENDER_VARS.Menu.button_text.setPosition((gVars.objList.Menu.objList[obj].posX + gVars.objList.Menu.objList[obj].width / 2) - gVars.RENDER_VARS.Menu.button_text.getLocalBounds().width / 2, gVars.objList.Menu.objList[obj].posY);
		gVars.RENDER_VARS.window->draw(gVars.RENDER_VARS.Menu.button_text);
	}
}//gVars.objList.Menu.objList[obj].width