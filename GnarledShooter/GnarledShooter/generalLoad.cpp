#include "generalLoad.h"

void loadGame::StartupLoadFast() {
	gVars.GLOBAL_VARS.gameActiveMode = MENU;
	// Load fonts

	if (!gVars.FontList.f_EuropeCondensed.loadFromFile("Fonts/EuropeCondensed.otf")) {
		Utilities::PrintError("Error load font 'EuropeCondensed.ttf' !");
		gVars.GLOBAL_VARS.GAME_ON = false;
	}

	if (!gVars.FontList.f_arial.loadFromFile("Fonts/arial.TTF")) {
		Utilities::PrintError("Error load font 'arial.ttf' !");
		gVars.GLOBAL_VARS.GAME_ON = false;
	}

	

	gVars.RENDER_VARS.Menu.logo_text_menu.setFont(gVars.FontList.f_arial);
	gVars.RENDER_VARS.Menu.logo_text_menu.setString(gVars.GLOBAL_SETTINGS.WINDOW_NAME);
	gVars.RENDER_VARS.Menu.logo_text_menu.setCharacterSize(42);
	gVars.RENDER_VARS.Menu.logo_text_menu.setPosition(Vector2f((gVars.GLOBAL_SETTINGS.WINDOW_WIDTH / 2) - (gVars.RENDER_VARS.Menu.logo_text_menu.getLocalBounds().width / 2), 120.f));

	gVars.RENDER_VARS.Menu.button_text.setFont(gVars.FontList.f_EuropeCondensed);
	gVars.RENDER_VARS.Menu.button_text.setCharacterSize(53);

	gVars.RENDER_VARS.Background.background_box.setPosition(Vector2f(0, 0));
	gVars.RENDER_VARS.Background.background_box.setSize(Vector2f(gVars.GLOBAL_SETTINGS.WINDOW_WIDTH, gVars.GLOBAL_SETTINGS.WINDOW_HEIGHT));

	gVars.RENDER_VARS.Settings.WINDOW_NAME.setFont(gVars.FontList.f_EuropeCondensed);
	gVars.RENDER_VARS.Settings.WINDOW_NAME.setCharacterSize(53);
	gVars.RENDER_VARS.Settings.WINDOW_NAME.setString("Settings");

	gVars.RENDER_VARS.Settings.Slider.slider_name.setFont(gVars.FontList.f_EuropeCondensed);

	gVars.RENDER_VARS.Settings.buttonBack.button_text.setFont(gVars.FontList.f_EuropeCondensed);
	gVars.RENDER_VARS.Settings.buttonBack.button_text.setString(gVars.RENDER_VARS.Settings.buttonBack.button_text_s);
	gVars.RENDER_VARS.Settings.buttonBack.button_text.setCharacterSize(gVars.RENDER_VARS.Settings.buttonBack.sizeY-10);

	gVars.FrameCounter.fps_text.setFont(gVars.FontList.f_EuropeCondensed);
	gVars.FrameCounter.fps_text.setFillColor(Color(255, 255, 255, 160));
	gVars.FrameCounter.fps_text.setPosition(10, 10);
	gVars.FrameCounter.fps_text.setCharacterSize(22);


}

void loadGame::GameLoadNormal() {
	// Load sprite map
	g_map.grass.img.loadFromFile("images/map_sprite.png");
	g_map.grass.textr.loadFromImage(g_map.grass.img);
	g_map.grass.sprite.setTexture(g_map.grass.textr);
	

}