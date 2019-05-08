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

		}

		gVars.RENDER_VARS.window->clear();
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
}