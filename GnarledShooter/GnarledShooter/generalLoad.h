#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <thread>

#include "globalVars.h"
#include "Utils.h"

namespace loadGame {
	void StartupLoadFast();
	void GameLoadNormal();
	void MusicLoadNormal();
}