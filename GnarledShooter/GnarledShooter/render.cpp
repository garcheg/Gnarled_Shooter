#include "render.h"

void renderGame::generalThread() {
	renderGame::Initialization();
}

void renderGame::Initialization() {
	gVars.RENDER_VARS.window = new RenderWindow(VideoMode(gVars.GLOBAL_SETTINGS.WINDOW_WIDTH, gVars.GLOBAL_SETTINGS.WINDOW_HEIGHT), gVars.GLOBAL_SETTINGS.WINDOW_NAME);

}