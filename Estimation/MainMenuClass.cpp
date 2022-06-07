#include "MainMenuClass.h"
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

MainMenuClass::MainMenuClass() {
	f.loadFromFile("font.ttf");
	title.setFillColor(Color::White);
	title.setCharacterSize(130);
	title.setPosition(20, 50);
	title.setString("Estimation");
	choices[0].setString("Start");
	choices[1].setString("How to play");
	choices[2].setString("Exit");
	backg.loadFromFile("Menu.jpg");
	for (int i = 0; i < 3; i++)
	{
		choices[i].setFillColor(Color::White);
		choices[i].setCharacterSize(50);
		choices[i].setPosition(120, 150 * i + 300);
		choices[i].setFont(f);
	}
	background.setSize(Vector2f(1365, 770));
	background.setTexture(&backg);
	title.setFont(f);
}
void MainMenuClass::draw(RenderWindow& window) {
	window.draw(background);
	for (int i = 0; i < 3; i++)
	{
		window.draw(choices[i]);
	}
	window.draw(title);
}
