#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenuClass.h"
#include <iostream>
#include <string>
#include <set>
#include <utility> 
#include <vector>
#include <algorithm> 
#include <random>
#include <ctime>
#include <stack>

using namespace sf;
using namespace std;

class MainMenuClass
{
private:
	RectangleShape background;
	Texture backg;
	Text title;
	Text choices[4];
	Font f;
public:
	MainMenuClass();
	void draw(RenderWindow& window);
};

