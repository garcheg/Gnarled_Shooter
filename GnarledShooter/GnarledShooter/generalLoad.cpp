#include "generalLoad.h"

void loadGame::StartupLoadFast() {
	gVars.GLOBAL_VARS.gameActiveMode = MENU;
	// Load fonts

	if (!gVars.FontList.f_arial.loadFromFile("Fonts/arial.TTF")) {
		Utilities::PrintError("Error load font 'arial.ttf' !");
		gVars.GLOBAL_VARS.GAME_ON = false;
	}

	gVars.RENDER_VARS.Menu.logo_text_menu.setFont(gVars.FontList.f_arial);
	gVars.RENDER_VARS.Menu.logo_text_menu.setString(gVars.GLOBAL_SETTINGS.WINDOW_NAME);
	gVars.RENDER_VARS.Menu.logo_text_menu.setPosition(Vector2f((gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (gVars.RENDER_VARS.Menu.logo_text_menu.getLocalBounds().width / 2), 300.f));

}

void loadGame::GameLoadNormal() {

}