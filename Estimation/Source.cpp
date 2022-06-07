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

void intialization();
void setPlayers();
bool sameshape(int cardnumber, int firstplayedcard, int dwr, int rb);
bool calltest(short x, short playernom);
int test(int x, int arr[], int i);
void card();
void raiseCard(int pos);
void playCard(int pos);
int getPos(Vector2i pos);

RenderWindow window(VideoMode(1365, 770), "main menu", Style::None);

int cardshufle[52];

struct Players
{
	int texture = 0;
	string lmat = "15";
	string username = "";
	short no_of_calls = 0;
	int cards[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int playedcard = 0;
	stack<char>calltype;
	bool bcard[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}players[4];

Texture charecters[25];
Font fnt, font3, fnz;

RectangleShape mainPlayer(Vector2f(600, 595)), otherPlayers[3], cardsr[13], pcard[4];
RectangleShape charecter(Vector2f(600, 600)), charecter_1(Vector2f(300, 300)), charecter__1(Vector2f(300, 300));

Text player[4];

Texture cards[53];

Text numbers[14], pss, cll, confirm;

int mkan_2l_call = 0, nom = 0, dwr = 0, wshape[4], ik = 0, rb = 0, turn = 5, z = 5, cou = 0, lastcall = 3,
roundd = 0, wth[4] = { 0,0,0,0 }, lshape = 1, shape = 1, arr[14] = { 0 }, passw = dwr - 1;

Texture backtext1, backtext2, shapeTexture[5];

RectangleShape background[7];

Text dd[3], p[3], sideshape[4];

bool q = 1, wm = 1, cl = 0, newround = 1, with = 0, done = 0, allowwith = 0;

string yy, mm;

int don = 0, g = 1, raisecard[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

Texture cardsback;

short call[4] = { 18,18,18,18 };

int main()
{
	MainMenuClass mainMenu;
	Event event;
	for (int i = 1; i <= 25; i++)
		charecters[i - 1].loadFromFile(to_string(i) + "n.png");
	int phase = 0;
	Texture backgroundt, selectedt;
	backgroundt.loadFromFile("papyrus.png");
	selectedt.loadFromFile("selected.png");
	Sprite backgrounds, selecteds;
	selecteds.setTexture(selectedt);
	selecteds.setPosition(575, 330);
	selecteds.setScale(3.3, 5);
	backgrounds.setTexture(backgroundt);
	backgrounds.setPosition(0, -10);
	backgrounds.setScale(1.08,0.74);
	intialization();
	charecter_1.setPosition(350, 450);
	charecter.setPosition(400, 220);
	charecter__1.setPosition(750, 450);
	int playerIndex = 0;
	Text enterName;
	enterName.setFont(fnt);
	enterName.setFillColor(Color::Black);
	enterName.setCharacterSize(60);
	enterName.setPosition(120, 60);
	Mouse mouse;

	while (window.isOpen())
	{
		//Main Menu
		if (phase == 0) {
			window.clear();
			mainMenu.draw(window);
			window.display();
		}
		//Choose Players
		else if (phase == 1) {
			while (window.pollEvent(event))
			{
				if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Right))
					players[playerIndex].texture++;
				else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::Left))
					players[playerIndex].texture += 24;
				else if (event.type == Event::TextEntered && event.text.unicode < 128 && event.text.unicode != 8 && players[playerIndex].username.size() < 15)
					players[playerIndex].username += event.text.unicode;
				else if (event.text.unicode == 8 && !players[playerIndex].username.empty() && !Keyboard::isKeyPressed(Keyboard::I) && event.type != Event::KeyReleased)
					players[playerIndex].username.pop_back();
				else if (Keyboard::isKeyPressed(Keyboard::Enter) && !players[playerIndex].username.empty())
					playerIndex++;
				if (playerIndex > 3) {
					playerIndex = 0;
					phase = 2;
					continue;
				}
				players[playerIndex].texture %= 25;
			}
			enterName.setString("Enter Your Name : \n\t" + players[playerIndex].username + "\n\t\t\t\tChoose You Avatar");
			charecter_1.setTexture(&charecters[(players[playerIndex].texture + 24) % 25]);
			charecter.setTexture(&charecters[players[playerIndex].texture]);
			charecter__1.setTexture(&charecters[(players[playerIndex].texture + 1) % 25]);

			window.clear();
			window.draw(backgrounds);
			window.draw(selecteds);
			window.draw(charecter);
			window.draw(charecter_1);
			window.draw(charecter__1);
			window.draw(enterName);
			window.display();
		}
		//Estimation
		else if (phase == 2)
		{
			Vector2i pos = mouse.getPosition(window);
			if (newround)
			{
				card();
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 13; j++)
						players[i].cards[j] = cardshufle[(i * 13 + j)];
				}
				newround = 0;
				background[2].setTexture(&shapeTexture[0]);
			}

			// setting cards 
			if (dwr == passw)
				for (int i = 0; i < 13; i++)
				{
					cardsr[i].setTexture(&cards[players[dwr].cards[i] - 1]);
					cardsr[i].setTextureRect(IntRect(0, 0, cards[players[dwr].cards[i] - 1].getSize().x, cards[players[dwr].cards[i] - 1].getSize().y));
				}
			else for (int i = 0; i < 13; i++)
			{
					cardsr[i].setTexture(&cardsback);
					cardsr[i].setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
			}

			//four played cards
			pcard[0].setTexture(&cards[players[dwr].playedcard - 1]);
			pcard[3].setTexture(&cards[players[(dwr + 1) % 4].playedcard - 1]);
			pcard[2].setTexture(&cards[players[(dwr + 2) % 4].playedcard - 1]);
			pcard[1].setTexture(&cards[players[(dwr + 3) % 4].playedcard - 1]);
			pcard[0].setTextureRect(IntRect(0, 0, cards[players[dwr].playedcard - 1].getSize().x, cards[players[dwr].playedcard - 1].getSize().y));
			pcard[3].setTextureRect(IntRect(0, 0, cards[players[(dwr + 1) % 4].playedcard - 1].getSize().x, cards[players[(dwr + 1) % 4].playedcard - 1].getSize().y));
			pcard[2].setTextureRect(IntRect(0, 0, cards[players[(dwr + 2) % 4].playedcard - 1].getSize().x, cards[players[(dwr + 2) % 4].playedcard - 1].getSize().y));
			pcard[1].setTextureRect(IntRect(0, 0, cards[players[(dwr + 3) % 4].playedcard - 1].getSize().x, cards[players[(dwr + 3) % 4].playedcard - 1].getSize().y));

			if (don == 0)
				setPlayers();

			//skip pass and dash and with calls
			if ((((players[dwr].calltype.top() == 'w' || players[dwr].calltype.top() == 'p') && (mkan_2l_call != 4)) || (players[dwr].calltype.top() == 'd') || (players[dwr].calltype.top() == 'm')) && (mkan_2l_call != 5))
			{
				dwr++;
				passw++;
				don = 0;
			}

			dd[1].setFillColor(Color::White);
			dd[2].setFillColor(Color::White);

			//dash
			if ((mkan_2l_call == 0) && (passw == dwr))
			{
				//Yes
				if ((pos.x >= 550) && (pos.y >= 425) && (pos.x <= 698) && (pos.y <= 555))
				{
					dd[1].setFillColor(Color::Red);
					while (window.pollEvent(event))
					{
						if (Event::MouseButtonPressed == event.type)
						{
							q = 0;
						}
						if (Event::MouseButtonReleased == event.type)
						{
							wm = 0;
						}
						if (q == 0 && wm == 0)
						{
							players[dwr].calltype.push('d');
							call[ik]=0;
							wm = 1;
							q = 1;
							ik++;
							don = 0;
							dwr++;
						}
					}
				}
				// No
				else if ((pos.x >= 700) && (pos.y >= 425) && (pos.x <= 845) && (pos.y <= 555))
				{
					dd[2].setFillColor(Color::Red);
					while (window.pollEvent(event))
					{
						if (Event::MouseButtonPressed == event.type)
						{
							q = 0;
						}
						if (Event::MouseButtonReleased == event.type)
						{
							wm = 0;
						}
						if (q == 0 && wm == 0)
						{
							ik++;
							dwr++;
							don = 0;
							q = 1;
							wm = 1;
						}
					}
				}
				if (ik == 4)
				{
					ik = 0;
					mkan_2l_call = 1;
				}
			}

			// shape choosing
			if ((mkan_2l_call > 0) && (mkan_2l_call != 4))
			{
				if ((pos.x >= 805) && (pos.x <= 840) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
					shape = 0;
				if ((pos.x >= 745) && (pos.x <= 785) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
					shape = 1;
				if ((pos.x >= 675) && (pos.x <= 715) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
					shape = 2;
				if ((pos.x >= 615) && (pos.x <= 655) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
					shape = 3;
				if ((pos.x >= 557) && (pos.x <= 597) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
					shape = 4;
				background[2].setTexture(&shapeTexture[shape]);
				background[2].setTextureRect(IntRect(0, 0, shapeTexture[shape].getSize().x, shapeTexture[shape].getSize().y));
			}
			else if (mkan_2l_call == 4)
			{
				shape = lshape;
				background[2].setTexture(&shapeTexture[shape - 1]);
				background[2].setTextureRect(IntRect(0, 0, shapeTexture[shape -1].getSize().x, shapeTexture[shape - 1].getSize().y));
			}

			// normal call
			if ((mkan_2l_call == 1) && (passw == dwr))
			{
				//normal call
				if ((call[dwr] != 0) && (call[dwr] != 14))
				{
					//make color white
					for (int j = 0; j <= 13; j++)
					{
						if ((((j >= lastcall) && (shape >= lshape)) || (j > lastcall)) && (arr[j] == 0) && (j > 3))
							numbers[j].setFillColor(Color::White);
						else if ((arr[j] == 0) || ((shape < lshape) && (j <= lastcall)))
						{
							numbers[j].setFillColor(Color::Black);
							if (arr[j] == 1)
							{
								arr[j] = 0;
								arr[j + 1]++;
								numbers[j + 1].setFillColor(Color::Red);
							}
						}
					}
					int at = -1;
					//if white number selected
					if ((pos.x >= 715) && (pos.x <= 740) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (((4 >= lastcall) && (shape >= lshape)) || (4 > lastcall)))
						at = 4;
					if ((pos.x >= 755) && (pos.x <= 780) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (((5 >= lastcall) && (shape >= lshape)) || (5 > lastcall)))
						at = 5;
					if ((pos.x >= 795) && (pos.x <= 820) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (((6 >= lastcall) && (shape >= lshape)) || (6 > lastcall)))
						at = 6;
					if ((pos.x >= 555) && (pos.x <= 580) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((7 >= lastcall) && (shape >= lshape)) || (7 > lastcall)))
						at = 7;
					if ((pos.x >= 593) && (pos.x <= 620) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((8 >= lastcall) && (shape >= lshape)) || (8 > lastcall)))
						at = 8;
					if ((pos.x >= 635) && (pos.x <= 660) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((9 >= lastcall) && (shape >= lshape)) || (9 > lastcall)))
						at = 9;
					if ((pos.x >= 665) && (pos.x <= 703) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((10 >= lastcall) && (shape >= lshape)) || (10 > lastcall)))
						at = 10;
					if ((pos.x >= 715) && (pos.x <= 750) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((11 >= lastcall) && (shape >= lshape)) || (11 > lastcall)))
						at = 11;
					if ((pos.x >= 753) && (pos.x <= 787) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((12 >= lastcall) && (shape >= lshape)) || (12 > lastcall)))
						at = 12;
					if ((pos.x >= 798) && (pos.x <= 832) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((13 >= lastcall) && (shape >= lshape)) || (13 > lastcall)))
						at = 13;
					if(at != -1)
					{
						numbers[at].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[at]++;
					}

					//identify with caller
					for (int j = 0; j <= 13; j++)
					{
						if ((arr[j] == 1) && (j == lastcall) && (shape == lshape) && ((players[0].calltype.top() == 'c') || (players[1].calltype.top() == 'c') || (players[2].calltype.top() == 'c') || (players[3].calltype.top() == 'c')))
						{
							nom = j;
							with = 1;
						}
						else if (arr[j] == 1)
						{
							nom = j;
							with = 0;
						}
					}

					//call button clicked
					for (int j = 0; j <= 13; j++)
					{
						if (arr[j] == 1)
						{
							// not with
							if ((pos.x >= 720) && (pos.x <= 820) && (pos.y >= 490) && (pos.y <= 540) && (Mouse::isButtonPressed(Mouse::Left)) && (!with))
							{
								lshape = shape;
								z = dwr;
								lastcall = nom;
								call[dwr] = nom;
								don = 0;
								players[dwr].calltype.push('c');
								dwr++;
							}
							// with
							if ((pos.x >= 720) && (pos.x <= 820) && (pos.y >= 490) && (pos.y <= 540) && (Mouse::isButtonPressed(Mouse::Left)) && (with))
							{
								wth[dwr]++;
								call[dwr] = nom;
								wshape[dwr] = shape;
								don = 0;
								players[dwr].calltype.push('w');
								dwr++;
							}
						}
					}

					//click pass
					if ((pos.x >= 580) && (pos.x <= 680) && (pos.y >= 490) && (pos.y <= 540) && (Mouse::isButtonPressed(Mouse::Left)))
					{
						call[dwr] = 14;
						don = 0;
						players[dwr].calltype.push('p');
						dwr++;
					}
				}
				for (int l = 0; l < 4; l++)
				{
					if ((players[l].calltype.top() == 'p') || (players[l].calltype.top() == 'd') || (players[l].calltype.top() == 'w'))
						cou++;
					else if (players[l].calltype.top() == 'b')
						cou--;
				}
				if (cou == 3)
				{
					mkan_2l_call = 2;
				}
				else
				{
					cou = 0;
				}
			}

			// caller confirm
			if ((mkan_2l_call == 2) && (dwr == passw))
			{
				//make numbers color white
				for (int j = 0; j <= 13; j++)
				{
					if ((((j >= lastcall) && (shape >= lshape)) || (j > lastcall)) && (arr[j] == 0) && (j > 3))
					{
						numbers[j].setFillColor(Color::White);
					}
					else if ((arr[j] == 0) || ((shape < lshape) && (j <= lastcall)))
					{
						numbers[j].setFillColor(Color::Black);
						if (arr[j] == 1)
						{
							arr[j] = 0;
							arr[j + 1]++;
							numbers[j + 1].setFillColor(Color::Red);
						}
					}
				}
				int at = -1;
				//white number choosen
				if ((pos.x >= 715) && (pos.x <= 740) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (4 >= lastcall) && (shape >= lshape))
					at = 4;
				if ((pos.x >= 755) && (pos.x <= 780) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (5 >= lastcall) && (shape >= lshape))
					at = 5;
				if ((pos.x >= 795) && (pos.x <= 820) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (6 >= lastcall) && (shape >= lshape))
					at = 6;
				if ((pos.x >= 555) && (pos.x <= 580) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (7 >= lastcall) && (shape >= lshape))
					at = 7;
				if ((pos.x >= 593) && (pos.x <= 620) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (8 >= lastcall) && (shape >= lshape))
					at = 8;
				if ((pos.x >= 635) && (pos.x <= 660) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (9 >= lastcall) && (shape >= lshape))
					at = 9;
				if ((pos.x >= 665) && (pos.x <= 703) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (10 >= lastcall) && (shape >= lshape))
					at = 10;
				if ((pos.x >= 715) && (pos.x <= 750) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (11 >= lastcall) && (shape >= lshape))
					at = 11;
				if ((pos.x >= 753) && (pos.x <= 787) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (12 >= lastcall) && (shape >= lshape))
					at = 12;
				if ((pos.x >= 798) && (pos.x <= 832) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (13 >= lastcall) && (shape >= lshape))
					at = 13;
				if(at != -1)
				{
					numbers[at].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[at]++;
				}

				//click confirm
				if ((pos.x >= 580) && (pos.x <= 920) && (pos.y >= 490) && (pos.y <= 540) && (Mouse::isButtonPressed(Mouse::Left)))
				{
					for (int j = 0; j <= 13; j++)
					{
						if (arr[j] == 1)
						{
							call[dwr] = j;
							z = dwr;
						}
					}
					lastcall = call[dwr];
					mkan_2l_call = 4;
					don = 0;
					players[dwr].calltype.push('m');
					dwr++;
					if (players[0].calltype.top() == 'd')
						players[0].calltype.push('m');
					if (players[1].calltype.top() == 'd')
						players[1].calltype.push('m');
					if (players[2].calltype.top() == 'd')
						players[2].calltype.push('m');
					if (players[3].calltype.top() == 'd')
						players[3].calltype.push('m');
				}
			}

			// pass confirm
			if ((mkan_2l_call == 4) && (dwr == passw) && (players[dwr].calltype.top() == 'p'))
			{
				//make numbers color white
				for (int j = 0; j <= 13; j++)
				{
					if ((j <= lastcall) && (calltest(j, dwr)) && (arr[j] == 0))
					{
						numbers[j].setFillColor(Color::White);
					}
					else if ((arr[j] == 0) || (j > lastcall))
					{
						numbers[j].setFillColor(Color::Black);
						if (arr[j] == 1)
						{
							arr[j] = 0;
						}
					}
				}
				int at = -1;
				//white number choosen
				if ((pos.x >= 555) && (pos.x <= 580) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (0 <= lastcall) && (calltest(0, dwr)))
					at = 0;
				if ((pos.x >= 593) && (pos.x <= 620) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (1 <= lastcall) && (calltest(1, dwr)))
					at = 1;
				if ((pos.x >= 635) && (pos.x <= 660) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (2 <= lastcall) && (calltest(2, dwr)))
					at = 2;
				if ((pos.x >= 675) && (pos.x <= 700) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (3 <= lastcall) && (calltest(3, dwr)))
					at = 3;
				if ((pos.x >= 715) && (pos.x <= 740) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (4 <= lastcall) && (calltest(4, dwr)))
					at = 4;
				if ((pos.x >= 755) && (pos.x <= 780) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (5 <= lastcall) && (calltest(5, dwr)))
					at = 5;
				if ((pos.x >= 795) && (pos.x <= 820) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (6 <= lastcall) && (calltest(6, dwr)))
					at = 6;
				if ((pos.x >= 555) && (pos.x <= 580) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (7 <= lastcall))
					at = 7;
				if ((pos.x >= 593) && (pos.x <= 620) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (8 <= lastcall))
					at = 8;
				if ((pos.x >= 635) && (pos.x <= 660) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (9 <= lastcall))
					at = 9;
				if ((pos.x >= 665) && (pos.x <= 703) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (10 <= lastcall))
					at = 10;
				if ((pos.x >= 715) && (pos.x <= 750) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (11 <= lastcall))
					at = 11;
				if ((pos.x >= 753) && (pos.x <= 787) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (12 <= lastcall))
					at = 12;
				if ((pos.x >= 798) && (pos.x <= 832) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (13 <= lastcall))
					at = 13;
				if(at != -1)
				{
					numbers[at].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[at]++;
				}

				//click confirm
				if ((pos.x >= 580) && (pos.x <= 920) && (pos.y >= 490) && (pos.y <= 540) && (Mouse::isButtonPressed(Mouse::Left)))
				{
					for (int j = 0; j <= 13; j++)
					{
						if (arr[j] == 1)
						{
							call[dwr] = j;
						}
					}
					don = 0;
					players[dwr].calltype.push('m');
					dwr++;
				}

			}

			// with confirm
			if ((mkan_2l_call == 4) && (dwr == passw) && (players[dwr].calltype.top() == 'w'))
			{
				if (wshape[dwr] != lshape)
				{
					players[dwr].calltype.push('p');
					wth[dwr] = 0;
				}
				else
				{
					players[dwr].calltype.push('m');
				}
			}

			//call done
			if (players[0].calltype.top() == 'm' && players[1].calltype.top() == 'm' && players[2].calltype.top() == 'm' && players[3].calltype.top() == 'm' && g)
			{
				g = 0;
				mkan_2l_call = 5;
				dwr = z;
				passw = dwr - 1;
			}

			if (with)
			{
				background[5].setFillColor(Color::Blue);
				cll.setString("With");
				cll.setPosition(725, 490);
			}
			else
			{
				background[5].setFillColor(Color::Red);
				cll.setString("Call");
				cll.setPosition(735, 490);
			}

			//side shapes and numbers
			for (int i = 0; i < 4; i++)
			{
				if ((players[i].lmat != "16") && (call[i] != 18))
				{
					if (players[i].calltype.top() == 'd')
						players[i].lmat = 16;
					else if ((players[i].calltype.top() == 'p') && (call[i] == 14))
						players[i].lmat = 14;
					else
						players[i].lmat = call[i];
				}
				if (players[i].lmat == "16")
					sideshape[i].setString("DASH");
				else if (players[i].lmat == "14")
					sideshape[i].setString("PASS");
				else if (players[i].lmat != "15")
					sideshape[i].setString(players[i].lmat);
			}
			
			// play a card
			if (mkan_2l_call == 5 && passw == dwr)
			{
				int position = getPos(pos);
				if (raisecard[position] == 0)
					raiseCard(position);
				playCard(position);
			    rb %= 4;
				if ((turn == 6) || (turn == 4))
					turn = 0;
			}
			
			// press Enter
			if (passw != dwr)
				while (window.pollEvent(event))
					if (event.type == Event::TextEntered)
						if (event.key.code == 13) passw = dwr;

			dwr %= 4;

			window.clear();

			window.draw(background[0]);
			window.draw(mainPlayer);
			window.draw(otherPlayers[0]);
			window.draw(otherPlayers[1]);
			window.draw(otherPlayers[2]);
			window.draw(player[0]);
			window.draw(player[1]);
			window.draw(player[2]);
			window.draw(player[3]);

			if (passw == dwr)
			{
				//dash
				if (mkan_2l_call == 0)
				{
					window.draw(background[1]);
					for (int j = 0; j < 3; j++) window.draw(dd[j]);
				}
				//normal call or pass
				else if (mkan_2l_call == 1)
				{
					window.draw(background[2]);
					window.draw(background[4]);
					window.draw(background[5]);
					for (int i = 0; i < 14; i++) window.draw(numbers[i]);
					window.draw(cll);
					window.draw(pss);
				}
				//submiting
				else if (((mkan_2l_call == 2) || (mkan_2l_call == 4)) && (players[dwr].calltype.top() != 'b') && (players[dwr].calltype.top() != 'd') && (players[dwr].calltype.top() != 'm'))
				{
					window.draw(background[2]);
					for (int i = 0; i < 14; i++) window.draw(numbers[i]);
					window.draw(background[6]);
					window.draw(confirm);
				}
			}

			if (passw != dwr)
			{
				window.draw(background[3]);
				for (int i = 0; i < 3; i++)	window.draw(p[i]);
			}
			
			if (mkan_2l_call == 5)
			{
				if (turn == 2 || turn == 3) window.draw(pcard[3]);
				if (turn == 1 || turn == 2 || turn == 3) window.draw(pcard[2]);
				if (turn == 0 || turn == 1 || turn == 2 || turn == 3) window.draw(pcard[1]);
				if (turn == 3) window.draw(pcard[0]);
			}

			for (int i = 0; i < 13; i++)
				if (players[dwr].bcard[i]) window.draw(cardsr[i]);

			window.display();
		}
    }
	return 0;
}

void setPlayers() {
	don = 1;
	p[0].setString(players[dwr].username);
	mainPlayer.setTexture(&charecters[players[dwr].texture]);
	otherPlayers[0].setTexture(&charecters[players[(dwr + 1) % 4].texture]);
	otherPlayers[1].setTexture(&charecters[players[(dwr + 2) % 4].texture]);
	otherPlayers[2].setTexture(&charecters[players[(dwr + 3) % 4].texture]);
	player[0].setString(players[dwr].username);
	player[1].setString(players[(dwr + 1) % 4].username);
	player[2].setString(players[(dwr + 2) % 4].username);
	player[3].setString(players[(dwr + 3) % 4].username);
}

void intialization()
{
	players[0].calltype.push('b');
	players[1].calltype.push('b');
	players[2].calltype.push('b');
	players[3].calltype.push('b');

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			players[i].bcard[j] = 1;

	fnt.loadFromFile("a.ttf");
	font3.loadFromFile("font.ttf");
	fnz.loadFromFile("ee.ttf");

	int c = 0, x = 10;
	for (int i = 0; i < 13; i++)
	{
		cardsr[i].setSize(Vector2f(180, 250));
		cardsr[i].setPosition(i*100,630-c);
		c += x;
		if (c >= 60)x = -10;
	}

	for (int i = 0; i < 4; i++)
	{
		pcard[i].setSize(Vector2f(100, 150));
		pcard[i].setOutlineColor(Color::Black);
		pcard[i].setOutlineThickness(2);
	}
	pcard[0].setPosition(620, 400);
	pcard[1].setPosition(510, 290);
	pcard[2].setPosition(620, 220);
	pcard[3].setPosition(730, 290);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			cards[i * 13 + j].loadFromFile(to_string(i * 13 + j + 1) + ".png");

	mainPlayer.setPosition(-200, -210);
	for (int i = 0; i < 3; i++)
		otherPlayers[i].setSize(Vector2f(500, 450));
	otherPlayers[0].setPosition(850, 145);
	otherPlayers[1].setPosition(410, -165);
	otherPlayers[2].setPosition(-30, 145);

	player[0].setPosition(0, 210);
	player[1].setPosition(1050, 460);
	player[2].setPosition(610, 150);
	player[3].setPosition(170, 460);

	for (int i = 0; i < 14; i++)
	{
		numbers[i].setFont(font3);
		numbers[i].setCharacterSize(30);
		numbers[i].setString(to_string(i + 1));
		numbers[i].setFillColor(Color::White);
	}

	numbers[0].setPosition(560, 310);
	numbers[1].setPosition(600, 310);
	numbers[2].setPosition(640, 310);
	numbers[3].setPosition(680, 310);
	numbers[4].setPosition(720, 310);
	numbers[5].setPosition(760, 310);
	numbers[6].setPosition(800, 310);
	numbers[7].setPosition(560, 350);
	numbers[8].setPosition(600, 350);
	numbers[9].setPosition(640, 350);
	numbers[10].setPosition(670, 350);
	numbers[11].setPosition(715, 350);
	numbers[12].setPosition(755, 350);
	numbers[13].setPosition(800, 350);

	pss.setFont(font3);
	pss.setCharacterSize(40);
	pss.setString("Pass");
	pss.setFillColor(Color::Black);
	pss.setPosition(585, 490);

	cll.setFont(font3);
	cll.setCharacterSize(40);
	cll.setString("Call");
	cll.setFillColor(Color::White);
	cll.setPosition(735, 490);

	confirm.setFont(font3);
	confirm.setCharacterSize(40);
	confirm.setString("Confirm");
	confirm.setFillColor(Color::White);
	confirm.setPosition(600, 490);

	for (int j = 0; j < 4; j++)
	{
		player[j].setFont(font3);
		player[j].setFillColor(Color::White);
		player[j].setCharacterSize(35);
	}

	background[3].setFillColor(Color::Black);
	background[4].setFillColor(Color::Yellow);
	background[5].setFillColor(Color::Red);
	background[6].setFillColor(Color::Red);

	background[0].setPosition(-10, -10);
	background[1].setPosition(550, 290);
	background[2].setPosition(410, 170);
	background[3].setPosition(1080, 0);
	background[4].setPosition(580, 490);
	background[5].setPosition(720, 490);
	background[6].setPosition(580, 490);

	background[0].setSize(Vector2f(1400, 850));
	background[1].setSize(Vector2f(300, 270));
	background[2].setSize(Vector2f(580, 540));
	background[3].setSize(Vector2f(300, 170));
	background[4].setSize(Vector2f(100, 50));
	background[5].setSize(Vector2f(100, 50));
	background[6].setSize(Vector2f(240, 50));

	shapeTexture[0].loadFromFile("tree.jpg");
	shapeTexture[1].loadFromFile("karo.jpg");
	shapeTexture[2].loadFromFile("heart.jpg");
	shapeTexture[3].loadFromFile("speed.jpg");
	shapeTexture[4].loadFromFile("suns.jpg");

	//player n
	p[0].setFont(font3);
	p[0].setCharacterSize(40);
	p[0].setFillColor(Color::White);
	p[0].setPosition(1100, 20);

	//Press Enter
	p[1].setFont(font3);
	p[1].setCharacterSize(30);
	p[1].setFillColor(Color::White);
	p[1].setString("Press Enter");
	p[1].setPosition(1100, 100);

	dd[0].setFont(fnz);
	dd[0].setCharacterSize(80);
	dd[0].setFillColor(Color::White);
	dd[0].setString("Dash Call");
	dd[0].setPosition(580, 300);
	dd[1].setFont(fnz);
	dd[1].setCharacterSize(70);
	dd[1].setString("Yes");
	dd[1].setPosition(579, 440);
	dd[2].setFont(fnz);
	dd[2].setCharacterSize(70);
	dd[2].setString("No");
	dd[2].setPosition(735, 440);

	backtext1.loadFromFile("back.jpg");
	backtext2.loadFromFile("dash.jpg");
	background[0].setTexture(&backtext1);
	background[1].setTexture(&backtext2);

	call[0] = 1;
	call[1] = 1;
	call[2] = 1;
	call[3] = 1;

	cardsback.loadFromFile("HumanAvatar.png");
}

bool sameshape(int cardnumber, int firstplayedcard, int dwr, int rb)
{
	if (rb == 0)
		return 1;
	for (int i = 0; i < 14; i++)
		if(((players[dwr].cards[i] - 1) / 13 == (firstplayedcard - 1) / 13) && players[dwr].bcard[i])
			return ((cardnumber - 1) / 13 == (firstplayedcard - 1) / 13);
	return 1;
}

bool calltest(short x, short playernom)
{
	if (call[0] + call[1] + call[2] + call[3] - call[playernom] + x != 13)
		return 1;
	else
		return 0;
}

int test(int x, int arr[], int i)
{
	for (int j = 0; j < i; j++)
	{
		if (arr[j] == x)
		{
			return 53;
		}
	}
	return x;
}

void card()
{
	srand(time(0));
	int i = 0;
	while (i < 52)
	{
		cardshufle[i] = test(((rand() % 52) + 1), cardshufle, i);
		if (cardshufle[i] != 53)
		{
			i++;
		}
	}
	sort(cardshufle, cardshufle + 13);
	sort(cardshufle + 13, cardshufle + 26);
	sort(cardshufle + 26, cardshufle + 39);
	sort(cardshufle + 39, cardshufle + 52);
}

void raiseCard(int pos) {
	if (pos == -1)
		return;
	cardsr[pos].move(0, -100);
	for (int i = 0; i < 13; i++)
		if (raisecard[i] == 1)
		{
			cardsr[i].move(0, 100);
			raisecard[i] = 0;
		}
	raisecard[pos] = 1;
}

void playCard(int pos) {
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		players[dwr].bcard[pos] = 0;
		cardsr[pos].move(0, 100);
		raisecard[pos] = 0;
		rb++; turn++;
		players[dwr].playedcard = players[dwr].cards[pos];
		dwr++;
		don = 0;
	}
}

int getPos(Vector2i pos) {
	if ((pos.x >= 0) && (pos.y >= 630) && (pos.x <= 100) && (pos.y <= 770) && (players[dwr].cards[0]) && sameshape(players[dwr].cards[0], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 0;
	if ((pos.x >= 100) && (pos.y >= 620) && (pos.x <= 200) && (pos.y <= 770) && (players[dwr].cards[1]) && sameshape(players[dwr].cards[1], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 1;
	if ((pos.x >= 200) && (pos.y >= 610) && (pos.x <= 300) && (pos.y <= 770) && (players[dwr].cards[2]) && sameshape(players[dwr].cards[2], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 2;
	if ((pos.x >= 300) && (pos.y >= 600) && (pos.x <= 400) && (pos.y <= 770) && (players[dwr].cards[3]) && sameshape(players[dwr].cards[3], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 3;
	if ((pos.x >= 400) && (pos.y >= 590) && (pos.x <= 500) && (pos.y <= 770) && (players[dwr].cards[4]) && sameshape(players[dwr].cards[4], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 4;
	if ((pos.x >= 500) && (pos.y >= 580) && (pos.x <= 600) && (pos.y <= 770) && (players[dwr].cards[5]) && sameshape(players[dwr].cards[5], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 5;
	if ((pos.x >= 600) && (pos.y >= 570) && (pos.x <= 700) && (pos.y <= 770) && (players[dwr].cards[6]) && sameshape(players[dwr].cards[6], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 6;
	if ((pos.x >= 700) && (pos.y >= 580) && (pos.x <= 800) && (pos.y <= 770) && (players[dwr].cards[7]) && sameshape(players[dwr].cards[7], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 7;
	if ((pos.x >= 800) && (pos.y >= 590) && (pos.x <= 900) && (pos.y <= 770) && (players[dwr].cards[8]) && sameshape(players[dwr].cards[8], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 8;
	if ((pos.x >= 900) && (pos.y >= 600) && (pos.x <= 1000) && (pos.y <= 770) && (players[dwr].cards[9]) && sameshape(players[dwr].cards[9], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 9;
	if ((pos.x >= 1000) && (pos.y >= 610) && (pos.x <= 1100) && (pos.y <= 770) && (players[dwr].cards[10]) && sameshape(players[dwr].cards[10], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 10;
	if ((pos.x >= 1100) && (pos.y >= 620) && (pos.x <= 1200) && (pos.y <= 770) && (players[dwr].cards[11]) && sameshape(players[dwr].cards[11], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 11;
	if ((pos.x >= 1200) && (pos.y >= 630) && (pos.x <= 1300) && (pos.y <= 770) && (players[dwr].cards[12]) && sameshape(players[dwr].cards[12], players[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
		return 12;
	return -1;
}