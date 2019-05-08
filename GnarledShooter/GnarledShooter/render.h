#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>

#include "globalVars.h"
#include "Utils.h"
#include "generalLoad.h"
#include "logic.h"

namespace renderGame {
	void generalThread();
	void Initialization();
	void DrawGeneralMenu();
}