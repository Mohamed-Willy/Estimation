#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
bool sameshape(int cardnumber, int firstplayedcard, int dwr, int rb);
bool calltest(short x, short playernom);

Clock clck;

RenderWindow window(VideoMode(1365, 770), "main menu", Style::None);

const int sun = { 5 }, spead = { 4 }, hearts = { 3 }, karo = { 2 }, treafel = { 1 };

Texture jtext;

Mouse mouse;

Event event;

short m;

int cardshufle[52];

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

struct players
{
	string lmat = "15";
	string username;
	Texture charecter;
	short no_of_calls;
	int cards[13];
	int playedcard;
	stack<char>calltype;
	int score = 0;
	bool bcard[13];
}playersg[4];

Font fnt;
Font za8rafa;
Font font3;
Font fnz;

RectangleShape player1(Vector2f(600, 595)), player2(Vector2f(500, 450)), player3(Vector2f(500, 450)), player4(Vector2f(500, 450)),
card1(Vector2f(180, 250)), card2(Vector2f(180, 250)), card3(Vector2f(180, 250)), card4(Vector2f(180, 250)),
card5(Vector2f(180, 250)), card6(Vector2f(180, 250)), card7(Vector2f(180, 250)), card8(Vector2f(180, 250)),
card9(Vector2f(180, 250)), card10(Vector2f(180, 250)), card11(Vector2f(180, 250)), card12(Vector2f(180, 250)),
card13(Vector2f(180, 250)),
pcard1(Vector2f(100, 150)), pcard2(Vector2f(100, 150)), pcard3(Vector2f(100, 150)), pcard4(Vector2f(100, 150));

Text player[4];

Texture cards[53];

string st;

string num[14] = { "0","1","2","3","4","5","6","7","8","9","10","11","12","13" };

Text   numbers[14], pss, cll, confirm;

int mkan_2l_call = 0, nom = 0, dwr = 0, wshape[4], ik = 0, rb = 0, turn = 5, z = 5, cou = 0, lastcall = 3,
roundd = 0, wth[4] = { 0,0,0,0 }, lshape = 1, shape = 1, arr[14] = { 0 }, passw = dwr - 1;

RectangleShape background1(Vector2f(1400, 850));

RectangleShape background2(Vector2f(300, 270));

RectangleShape background3(Vector2f(580, 540));

RectangleShape background4(Vector2f(300, 170));

RectangleShape background5(Vector2f(100, 50));

RectangleShape background6(Vector2f(100, 50));

RectangleShape background7(Vector2f(240, 50));

Texture backtext1, backtext2, tree, caro, heart, speed, suns;

Text dd[3], p[3], sideshape[4];

bool q = 1, wm = 1, cl = 0, newround = 1, with = 0, done = 0, allowwith = 0;

short four;

string yy, mm;

bool how = 0;
int H = 0;
bool dev = 0;
bool txt = 1;
bool txt1 = 0;
bool txt2 = 0;
bool txt3 = 0;
bool op = 0;
bool snd = 0;
bool don = 0;
bool confrm;
bool g = 1;
bool raisecard[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

int players;
int estimation = 0, tarneeb = 0, heartss = 0, sergent = 0;

Texture cardsback;

Text d[3];

short call[4] = { 18,18,18,18 };
/*
* Regala
1-Omar
2-Tarek
3-Shahawy
4-Sob7y
5-Dodo
6-Mido
7-3bdel Megid
8-Willy
9-Ziad
10-Shabanawy
11-7elmy
12-Hima
13-Mostafa
14-Ashour
15-3bas 2l daw
*/
/*
* Banat
16- sa3dya
17- radwa
18- mariem
19- nesreen
20- laura
21- sara
22- revin
23- amber
24- basmalla
25- dalya
*/
void main()
{
	estimation = 2;
	playersg[0].username = "Willy";
	playersg[0].charecter.loadFromFile("8n.png");
	playersg[1].username = "3bdel Magid";
	playersg[1].charecter.loadFromFile("11n.png");
	playersg[2].username = "7elmy";
	playersg[2].charecter.loadFromFile("5n.png");
	playersg[3].username = "Omar";
	playersg[3].charecter.loadFromFile("14n.png");
	playersg[0].calltype.push('b');
	playersg[1].calltype.push('b');
	playersg[2].calltype.push('b');
	playersg[3].calltype.push('b');

	intialization();

	while (window.isOpen())
	{
		Vector2i position = mouse.getPosition(window);
		if (estimation == 2)
		{

			background5.setFillColor(Color::Yellow);

			if (newround)
			{
				card();
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 13; j++)
						playersg[i].cards[j] = cardshufle[(i * 13 + j)];
				}
				newround = 0;
				background3.setTexture(&tree);
			}

			// setting cards 
			if (dwr == passw)
			{
				card1.setTexture(&cards[playersg[dwr].cards[0] - 1]);
				card2.setTexture(&cards[playersg[dwr].cards[1] - 1]);
				card3.setTexture(&cards[playersg[dwr].cards[2] - 1]);
				card4.setTexture(&cards[playersg[dwr].cards[3] - 1]);
				card5.setTexture(&cards[playersg[dwr].cards[4] - 1]);
				card6.setTexture(&cards[playersg[dwr].cards[5] - 1]);
				card7.setTexture(&cards[playersg[dwr].cards[6] - 1]);
				card8.setTexture(&cards[playersg[dwr].cards[7] - 1]);
				card9.setTexture(&cards[playersg[dwr].cards[8] - 1]);
				card10.setTexture(&cards[playersg[dwr].cards[9] - 1]);
				card11.setTexture(&cards[playersg[dwr].cards[10] - 1]);
				card12.setTexture(&cards[playersg[dwr].cards[11] - 1]);
				card13.setTexture(&cards[playersg[dwr].cards[12] - 1]);
				card1.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[0] - 1].getSize().x, cards[playersg[dwr].cards[0] - 1].getSize().y));
				card2.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[1] - 1].getSize().x, cards[playersg[dwr].cards[1] - 1].getSize().y));
				card3.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[2] - 1].getSize().x, cards[playersg[dwr].cards[2] - 1].getSize().y));
				card4.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[3] - 1].getSize().x, cards[playersg[dwr].cards[3] - 1].getSize().y));
				card5.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[4] - 1].getSize().x, cards[playersg[dwr].cards[4] - 1].getSize().y));
				card6.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[5] - 1].getSize().x, cards[playersg[dwr].cards[5] - 1].getSize().y));
				card7.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[6] - 1].getSize().x, cards[playersg[dwr].cards[6] - 1].getSize().y));
				card8.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[7] - 1].getSize().x, cards[playersg[dwr].cards[7] - 1].getSize().y));
				card9.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[8] - 1].getSize().x, cards[playersg[dwr].cards[8] - 1].getSize().y));
				card10.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[9] - 1].getSize().x, cards[playersg[dwr].cards[9] - 1].getSize().y));
				card11.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[10] - 1].getSize().x, cards[playersg[dwr].cards[10] - 1].getSize().y));
				card12.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[11] - 1].getSize().x, cards[playersg[dwr].cards[11] - 1].getSize().y));
				card13.setTextureRect(IntRect(0, 0, cards[playersg[dwr].cards[12] - 1].getSize().x, cards[playersg[dwr].cards[12] - 1].getSize().y));
			}
			else
			{
				card1.setTexture(&cardsback);
				card2.setTexture(&cardsback);
				card3.setTexture(&cardsback);
				card4.setTexture(&cardsback);
				card5.setTexture(&cardsback);
				card6.setTexture(&cardsback);
				card7.setTexture(&cardsback);
				card8.setTexture(&cardsback);
				card9.setTexture(&cardsback);
				card10.setTexture(&cardsback);
				card11.setTexture(&cardsback);
				card12.setTexture(&cardsback);
				card13.setTexture(&cardsback);
				card1.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card2.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card3.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card4.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card5.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card6.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card7.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card8.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card9.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card10.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card11.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card12.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
				card13.setTextureRect(IntRect(0, 0, cardsback.getSize().x, cardsback.getSize().y));
			}

			//four played cards
			pcard1.setTexture(&cards[playersg[dwr].playedcard - 1]);
			pcard4.setTexture(&cards[playersg[(dwr + 1) % 4].playedcard - 1]);
			pcard3.setTexture(&cards[playersg[(dwr + 2) % 4].playedcard - 1]);
			pcard2.setTexture(&cards[playersg[(dwr + 3) % 4].playedcard - 1]);
			pcard1.setTextureRect(IntRect(0, 0, cards[playersg[dwr].playedcard - 1].getSize().x, cards[playersg[dwr].playedcard - 1].getSize().y));
			pcard4.setTextureRect(IntRect(0, 0, cards[playersg[(dwr + 1) % 4].playedcard - 1].getSize().x, cards[playersg[(dwr + 1) % 4].playedcard - 1].getSize().y));
			pcard3.setTextureRect(IntRect(0, 0, cards[playersg[(dwr + 2) % 4].playedcard - 1].getSize().x, cards[playersg[(dwr + 2) % 4].playedcard - 1].getSize().y));
			pcard2.setTextureRect(IntRect(0, 0, cards[playersg[(dwr + 3) % 4].playedcard - 1].getSize().x, cards[playersg[(dwr + 3) % 4].playedcard - 1].getSize().y));

			if (dwr == 0 && don == 0)
			{
				don = 1;
				p[0].setString(playersg[dwr].username);
				player1.setTexture(&playersg[0].charecter);
				player1.setTextureRect(IntRect(0, 0, playersg[0].charecter.getSize().x, playersg[0].charecter.getSize().y));
				player2.setTexture(&playersg[1].charecter);
				player2.setTextureRect(IntRect(0, 0, playersg[1].charecter.getSize().x, playersg[1].charecter.getSize().y));
				player3.setTexture(&playersg[2].charecter);
				player3.setTextureRect(IntRect(0, 0, playersg[2].charecter.getSize().x, playersg[2].charecter.getSize().y));
				player4.setTexture(&playersg[3].charecter);
				player4.setTextureRect(IntRect(0, 0, playersg[3].charecter.getSize().x, playersg[3].charecter.getSize().y));
				player[0].setString(playersg[0].username);
				player[1].setString(playersg[1].username);
				player[2].setString(playersg[2].username);
				player[3].setString(playersg[3].username);
			}
			if (dwr == 1 && don == 0)
			{
				don = 1;
				p[0].setString(playersg[dwr].username);
				player1.setTexture(&playersg[1].charecter);
				player1.setTextureRect(IntRect(0, 0, playersg[1].charecter.getSize().x, playersg[1].charecter.getSize().y));
				player2.setTexture(&playersg[2].charecter);
				player2.setTextureRect(IntRect(0, 0, playersg[2].charecter.getSize().x, playersg[2].charecter.getSize().y));
				player3.setTexture(&playersg[3].charecter);
				player3.setTextureRect(IntRect(0, 0, playersg[3].charecter.getSize().x, playersg[3].charecter.getSize().y));
				player4.setTexture(&playersg[0].charecter);
				player4.setTextureRect(IntRect(0, 0, playersg[0].charecter.getSize().x, playersg[0].charecter.getSize().y));
				player[0].setString(playersg[1].username);
				player[1].setString(playersg[2].username);
				player[2].setString(playersg[3].username);
				player[3].setString(playersg[0].username);
			}
			if (dwr == 2 && don == 0)
			{
				don = 1;
				p[0].setString(playersg[dwr].username);
				player1.setTexture(&playersg[2].charecter);
				player1.setTextureRect(IntRect(0, 0, playersg[2].charecter.getSize().x, playersg[2].charecter.getSize().y));
				player2.setTexture(&playersg[3].charecter);
				player2.setTextureRect(IntRect(0, 0, playersg[3].charecter.getSize().x, playersg[3].charecter.getSize().y));
				player3.setTexture(&playersg[0].charecter);
				player3.setTextureRect(IntRect(0, 0, playersg[0].charecter.getSize().x, playersg[0].charecter.getSize().y));
				player4.setTexture(&playersg[1].charecter);
				player4.setTextureRect(IntRect(0, 0, playersg[1].charecter.getSize().x, playersg[1].charecter.getSize().y));
				player[0].setString(playersg[2].username);
				player[1].setString(playersg[3].username);
				player[2].setString(playersg[0].username);
				player[3].setString(playersg[1].username);
			}
			if (dwr == 3 && don == 0)
			{
				don = 1;
				p[0].setString(playersg[dwr].username);
				player1.setTexture(&playersg[3].charecter);
				player1.setTextureRect(IntRect(0, 0, playersg[3].charecter.getSize().x, playersg[3].charecter.getSize().y));
				player2.setTexture(&playersg[0].charecter);
				player2.setTextureRect(IntRect(0, 0, playersg[0].charecter.getSize().x, playersg[0].charecter.getSize().y));
				player3.setTexture(&playersg[1].charecter);
				player3.setTextureRect(IntRect(0, 0, playersg[1].charecter.getSize().x, playersg[1].charecter.getSize().y));
				player4.setTexture(&playersg[2].charecter);
				player4.setTextureRect(IntRect(0, 0, playersg[2].charecter.getSize().x, playersg[2].charecter.getSize().y));
				player[0].setString(playersg[3].username);
				player[1].setString(playersg[0].username);
				player[2].setString(playersg[1].username);
				player[3].setString(playersg[2].username);
			}

			//skip pass and dash and with calls
			if ((((playersg[dwr].calltype.top() == 'w' || playersg[dwr].calltype.top() == 'p') && (mkan_2l_call != 4)) || (playersg[dwr].calltype.top() == 'd') || (playersg[dwr].calltype.top() == 'm')) && (mkan_2l_call != 5))
			{
				dwr++;
				passw++;
				don = 0;
			}

			dd[1].setFillColor(Color::White);
			dd[2].setFillColor(Color::White);

			Vector2i pos = mouse.getPosition(window);

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
							playersg[dwr].calltype.push('d');
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
				{
					background3.setTexture(&tree);
					background3.setTextureRect(IntRect(0, 0, tree.getSize().x, tree.getSize().y));
					shape = treafel;
				}
				if ((pos.x >= 745) && (pos.x <= 785) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
				{
					background3.setTexture(&caro);
					background3.setTextureRect(IntRect(0, 0, caro.getSize().x, caro.getSize().y));
					shape = karo;
				}
				if ((pos.x >= 675) && (pos.x <= 715) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
				{
					background3.setTexture(&heart);
					background3.setTextureRect(IntRect(0, 0, heart.getSize().x, heart.getSize().y));
					shape = hearts;
				}
				if ((pos.x >= 615) && (pos.x <= 655) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
				{
					background3.setTexture(&speed);
					background3.setTextureRect(IntRect(0, 0, speed.getSize().x, speed.getSize().y));
					shape = spead;
				}
				if ((pos.x >= 557) && (pos.x <= 597) && (pos.y >= 420) && (pos.y <= 480) && (Mouse::isButtonPressed(Mouse::Left)))
				{
					background3.setTexture(&suns);
					background3.setTextureRect(IntRect(0, 0, suns.getSize().x, suns.getSize().y));
					shape = sun;
				}
			}
			else if (mkan_2l_call == 4)
			{
				shape = lshape;
				if (shape == treafel)
				{
					background3.setTexture(&tree);
					background3.setTextureRect(IntRect(0, 0, tree.getSize().x, tree.getSize().y));
				}
				if (shape == karo)
				{
					background3.setTexture(&caro);
					background3.setTextureRect(IntRect(0, 0, caro.getSize().x, caro.getSize().y));
				}
				if (shape == hearts)
				{
					background3.setTexture(&heart);
					background3.setTextureRect(IntRect(0, 0, heart.getSize().x, heart.getSize().y));
				}
				if (shape == spead)
				{
					background3.setTexture(&speed);
					background3.setTextureRect(IntRect(0, 0, speed.getSize().x, speed.getSize().y));
				}
				if (shape == sun)
				{
					background3.setTexture(&suns);
					background3.setTextureRect(IntRect(0, 0, suns.getSize().x, suns.getSize().y));
				}

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

					//if white number selected
					if ((pos.x >= 715) && (pos.x <= 740) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (((4 >= lastcall) && (shape >= lshape)) || (4 > lastcall)))
					{
						numbers[4].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[4]++;
					}
					if ((pos.x >= 755) && (pos.x <= 780) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (((5 >= lastcall) && (shape >= lshape)) || (5 > lastcall)))
					{
						numbers[5].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[5]++;
					}
					if ((pos.x >= 795) && (pos.x <= 820) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (((6 >= lastcall) && (shape >= lshape)) || (6 > lastcall)))
					{
						numbers[6].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[6]++;
					}
					if ((pos.x >= 555) && (pos.x <= 580) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((7 >= lastcall) && (shape >= lshape)) || (7 > lastcall)))
					{
						numbers[7].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[7]++;
					}
					if ((pos.x >= 593) && (pos.x <= 620) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((8 >= lastcall) && (shape >= lshape)) || (8 > lastcall)))
					{
						numbers[8].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[8]++;
					}
					if ((pos.x >= 635) && (pos.x <= 660) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((9 >= lastcall) && (shape >= lshape)) || (9 > lastcall)))
					{
						numbers[9].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[9]++;
					}
					if ((pos.x >= 665) && (pos.x <= 703) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((10 >= lastcall) && (shape >= lshape)) || (10 > lastcall)))
					{
						numbers[10].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[10]++;
					}
					if ((pos.x >= 715) && (pos.x <= 750) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((11 >= lastcall) && (shape >= lshape)) || (11 > lastcall)))
					{
						numbers[11].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[11]++;
					}
					if ((pos.x >= 753) && (pos.x <= 787) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((12 >= lastcall) && (shape >= lshape)) || (12 > lastcall)))
					{
						numbers[12].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[12]++;
					}
					if ((pos.x >= 798) && (pos.x <= 832) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (((13 >= lastcall) && (shape >= lshape)) || (13 > lastcall)))
					{
						numbers[13].setFillColor(Color::Red);
						for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
						arr[13]++;
					}

					//identify with caller
					for (int j = 0; j <= 13; j++)
					{
						if ((arr[j] == 1) && (j == lastcall) && (shape == lshape) && ((playersg[0].calltype.top() == 'c') || (playersg[1].calltype.top() == 'c') || (playersg[2].calltype.top() == 'c') || (playersg[3].calltype.top() == 'c')))
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
								playersg[dwr].calltype.push('c');
								dwr++;
							}
							// with
							if ((pos.x >= 720) && (pos.x <= 820) && (pos.y >= 490) && (pos.y <= 540) && (Mouse::isButtonPressed(Mouse::Left)) && (with))
							{
								wth[dwr]++;
								call[dwr] = nom;
								wshape[dwr] = shape;
								don = 0;
								playersg[dwr].calltype.push('w');
								dwr++;
							}
						}
					}

					//click pass
					if ((pos.x >= 580) && (pos.x <= 680) && (pos.y >= 490) && (pos.y <= 540) && (Mouse::isButtonPressed(Mouse::Left)))
					{
						call[dwr] = 14;
						don = 0;
						playersg[dwr].calltype.push('p');
						dwr++;
					}
				}
				for (int l = 0; l < 4; l++)
				{
					if ((playersg[l].calltype.top() == 'p') || (playersg[l].calltype.top() == 'd') || (playersg[l].calltype.top() == 'w'))
						cou++;
					else if (playersg[l].calltype.top() == 'b')
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

				//white number choosen
				if ((pos.x >= 715) && (pos.x <= 740) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (4 >= lastcall) && (shape >= lshape))
				{
					numbers[4].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[4]++;
				}
				if ((pos.x >= 755) && (pos.x <= 780) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (5 >= lastcall) && (shape >= lshape))
				{
					numbers[5].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[5]++;
				}
				if ((pos.x >= 795) && (pos.x <= 820) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (6 >= lastcall) && (shape >= lshape))
				{
					numbers[6].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[6]++;
				}
				if ((pos.x >= 555) && (pos.x <= 580) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (7 >= lastcall) && (shape >= lshape))
				{
					numbers[7].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[7]++;
				}
				if ((pos.x >= 593) && (pos.x <= 620) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (8 >= lastcall) && (shape >= lshape))
				{
					numbers[8].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[8]++;
				}
				if ((pos.x >= 635) && (pos.x <= 660) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (9 >= lastcall) && (shape >= lshape))
				{
					numbers[9].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[9]++;
				}
				if ((pos.x >= 665) && (pos.x <= 703) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (10 >= lastcall) && (shape >= lshape))
				{
					numbers[10].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[10]++;
				}
				if ((pos.x >= 715) && (pos.x <= 750) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (11 >= lastcall) && (shape >= lshape))
				{
					numbers[11].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[11]++;
				}
				if ((pos.x >= 753) && (pos.x <= 787) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (12 >= lastcall) && (shape >= lshape))
				{
					numbers[12].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[12]++;
				}
				if ((pos.x >= 798) && (pos.x <= 832) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (13 >= lastcall) && (shape >= lshape))
				{
					numbers[13].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[13]++;
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
					playersg[dwr].calltype.push('m');
					dwr++;
					if (playersg[0].calltype.top() == 'd')
						playersg[0].calltype.push('m');
					if (playersg[1].calltype.top() == 'd')
						playersg[1].calltype.push('m');
					if (playersg[2].calltype.top() == 'd')
						playersg[2].calltype.push('m');
					if (playersg[3].calltype.top() == 'd')
						playersg[3].calltype.push('m');
				}
			}

			// pass confirm
			if ((mkan_2l_call == 4) && (dwr == passw) && (playersg[dwr].calltype.top() == 'p'))
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

				//white number choosen
				if ((pos.x >= 555) && (pos.x <= 580) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (0 <= lastcall) && (calltest(0, dwr)))
				{
					numbers[0].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[0]++;
				}
				if ((pos.x >= 593) && (pos.x <= 620) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (1 <= lastcall) && (calltest(1, dwr)))
				{
					numbers[1].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[1]++;
				}
				if ((pos.x >= 635) && (pos.x <= 660) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (2 <= lastcall) && (calltest(2, dwr)))
				{
					numbers[2].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[2]++;
				}
				if ((pos.x >= 675) && (pos.x <= 700) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (3 <= lastcall) && (calltest(3, dwr)))
				{
					numbers[3].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[3]++;
				}
				if ((pos.x >= 715) && (pos.x <= 740) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (4 <= lastcall) && (calltest(4, dwr)))
				{
					numbers[4].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[4]++;
				}
				if ((pos.x >= 755) && (pos.x <= 780) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (5 <= lastcall) && (calltest(5, dwr)))
				{
					numbers[5].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[5]++;
				}
				if ((pos.x >= 795) && (pos.x <= 820) && (pos.y >= 310) && (pos.y <= 345) && (Mouse::isButtonPressed(Mouse::Left)) && (6 <= lastcall) && (calltest(6, dwr)))
				{
					numbers[6].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[6]++;
				}
				if ((pos.x >= 555) && (pos.x <= 580) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (7 <= lastcall))
				{
					numbers[7].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[7]++;
				}
				if ((pos.x >= 593) && (pos.x <= 620) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (8 <= lastcall))
				{
					numbers[8].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[8]++;
				}
				if ((pos.x >= 635) && (pos.x <= 660) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (9 <= lastcall))
				{
					numbers[9].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[9]++;
				}
				if ((pos.x >= 665) && (pos.x <= 703) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (10 <= lastcall))
				{
					numbers[10].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[10]++;
				}
				if ((pos.x >= 715) && (pos.x <= 750) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (11 <= lastcall))
				{
					numbers[11].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[11]++;
				}
				if ((pos.x >= 753) && (pos.x <= 787) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (12 <= lastcall))
				{
					numbers[12].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[12]++;
				}
				if ((pos.x >= 798) && (pos.x <= 832) && (pos.y >= 350) && (pos.y <= 385) && (Mouse::isButtonPressed(Mouse::Left)) && (13 <= lastcall))
				{
					numbers[13].setFillColor(Color::Red);
					for (int bvc = 0; bvc < 14; bvc++)arr[bvc] = 0;
					arr[13]++;
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
					playersg[dwr].calltype.push('m');
					dwr++;
				}

			}

			// with confirm
			if ((mkan_2l_call == 4) && (dwr == passw) && (playersg[dwr].calltype.top() == 'w'))
			{
				if (wshape[dwr] != lshape)
				{
					playersg[dwr].calltype.push('p');
					wth[dwr] = 0;
				}
				else
				{
					playersg[dwr].calltype.push('m');
				}
			}

			//call done
			if (playersg[0].calltype.top() == 'm' && playersg[1].calltype.top() == 'm' && playersg[2].calltype.top() == 'm' && playersg[3].calltype.top() == 'm' && g)
			{
				g = 0;
				mkan_2l_call = 5;
				dwr = z;
				passw = dwr - 1;
			}

			if (with)
			{
				background6.setFillColor(Color::Blue);
				cll.setString("With");
				cll.setPosition(725, 490);
			}
			else
			{
				background6.setFillColor(Color::Red);
				cll.setString("Call");
				cll.setPosition(735, 490);
			}

			//side shapes and numbers
			for (size_t i = 0; i < 4; i++)
			{
				if ((playersg[i].lmat != "16") && (call[i] != 18))
				{
					if (playersg[i].calltype.top() == 'd')
					{
						playersg[i].lmat = 16;
					}
					else if ((playersg[i].calltype.top() == 'p') && (call[i] == 14))
					{
						playersg[i].lmat = 14;
					}
					else
					{
						playersg[i].lmat = call[i];
					}
				}
			}
			for (size_t i = 0; i < 4; i++)
			{
				if (playersg[i].lmat == "16")
				{
					sideshape[i].setString("DASH");
				}
				else if (playersg[i].lmat == "14")
				{
					sideshape[i].setString("PASS");
				}
				else if (playersg[i].lmat != "15")
				{
					sideshape[i].setString(playersg[i].lmat);
				}
			}
			
			// play a card
			if (mkan_2l_call == 5 && passw == dwr)
			{
				if ((pos.x >= 0) && (pos.y >= 630) && (pos.x <= 100) && (pos.y <= 770) && (playersg[dwr].cards[0]) && sameshape(playersg[dwr].cards[0], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					// raising card up
					if (raisecard[0] == 0)
					{
						card1.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[0] = 1;
					}
					// play card
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[0] = 0;
						card1.move(0, 100);
						raisecard[0] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[0];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 100) && (pos.y >= 620) && (pos.x <= 200) && (pos.y <= 770) && (playersg[dwr].cards[1]) && sameshape(playersg[dwr].cards[1], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[1] == 0)
					{
						card2.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[1] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[1] = 0;
						card2.move(0, 100);
						raisecard[1] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[1];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 200) && (pos.y >= 610) && (pos.x <= 300) && (pos.y <= 770) && (playersg[dwr].cards[2]) && sameshape(playersg[dwr].cards[2], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[2] == 0)
					{
						card3.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[2] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[2] = 0;
						card3.move(0, 100);
						raisecard[2] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[2];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 300) && (pos.y >= 600) && (pos.x <= 400) && (pos.y <= 770) && (playersg[dwr].cards[3]) && sameshape(playersg[dwr].cards[3], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[3] == 0)
					{
						card4.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[3] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[3] = 0;
						card4.move(0, 100);
						raisecard[3] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[3];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 400) && (pos.y >= 590) && (pos.x <= 500) && (pos.y <= 770) && (playersg[dwr].cards[4]) && sameshape(playersg[dwr].cards[4], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[4] == 0)
					{
						card5.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[4] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[4] = 0;
						card5.move(0, 100);
						raisecard[4] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[4];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 500) && (pos.y >= 580) && (pos.x <= 600) && (pos.y <= 770) && (playersg[dwr].cards[5]) && sameshape(playersg[dwr].cards[5], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[5] == 0)
					{
						card6.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[5] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[5] = 0;
						card6.move(0, 100);
						raisecard[5] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[5];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 600) && (pos.y >= 570) && (pos.x <= 700) && (pos.y <= 770) && (playersg[dwr].cards[6]) && sameshape(playersg[dwr].cards[6], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[6] == 0)
					{
						card7.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[6] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[6] = 0;
						card7.move(0, 100);
						raisecard[6] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[6];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 700) && (pos.y >= 580) && (pos.x <= 800) && (pos.y <= 770) && (playersg[dwr].cards[7]) && sameshape(playersg[dwr].cards[7], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[7] == 0)
					{
						card8.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[7] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[7] = 0;
						card8.move(0, 100);
						raisecard[7] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[7];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 800) && (pos.y >= 590) && (pos.x <= 900) && (pos.y <= 770) && (playersg[dwr].cards[8]) && sameshape(playersg[dwr].cards[8], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[8] == 0)
					{
						card9.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[8] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[8] = 0;
						card9.move(0, 100);
						raisecard[8] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[8];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 900) && (pos.y >= 600) && (pos.x <= 1000) && (pos.y <= 770) && (playersg[dwr].cards[9]) && sameshape(playersg[dwr].cards[9], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[9] == 0)
					{
						card10.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[9] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[9] = 0;
						card10.move(0, 100);
						raisecard[9] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[9];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 1000) && (pos.y >= 610) && (pos.x <= 1100) && (pos.y <= 770) && (playersg[dwr].cards[10]) && sameshape(playersg[dwr].cards[10], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[10] == 0)
					{
						card11.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[10] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[10] = 0;
						card11.move(0, 100);
						raisecard[10] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[10];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 1100) && (pos.y >= 620) && (pos.x <= 1200) && (pos.y <= 770) && (playersg[dwr].cards[11]) && sameshape(playersg[dwr].cards[11], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[11] == 0)
					{
						card12.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[11] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[11] = 0;
						card12.move(0, 100);
						raisecard[11] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[11];
						dwr++;
						don = 0;
					}
				}
				if ((pos.x >= 1200) && (pos.y >= 630) && (pos.x <= 1300) && (pos.y <= 770) && (playersg[dwr].cards[12]) && sameshape(playersg[dwr].cards[12], playersg[(dwr + 4 - rb) % 4].playedcard, dwr, rb))
				{
					if (raisecard[12] == 0)
					{
						card13.move(0, -100);
						if (raisecard[0] == 1)
						{
							card1.move(0, 100);
							raisecard[0] = 0;
						}
						else if (raisecard[1] == 1)
						{
							card2.move(0, 100);
							raisecard[1] = 0;
						}
						else if (raisecard[2] == 1)
						{
							card3.move(0, 100);
							raisecard[2] = 0;
						}
						else if (raisecard[3] == 1)
						{
							card4.move(0, 100);
							raisecard[3] = 0;
						}
						else if (raisecard[4] == 1)
						{
							card5.move(0, 100);
							raisecard[4] = 0;
						}
						else if (raisecard[5] == 1)
						{
							card6.move(0, 100);
							raisecard[5] = 0;
						}
						else if (raisecard[6] == 1)
						{
							card7.move(0, 100);
							raisecard[6] = 0;
						}
						else if (raisecard[7] == 1)
						{
							card8.move(0, 100);
							raisecard[7] = 0;
						}
						else if (raisecard[8] == 1)
						{
							card9.move(0, 100);
							raisecard[8] = 0;
						}
						else if (raisecard[9] == 1)
						{
							card10.move(0, 100);
							raisecard[9] = 0;
						}
						else if (raisecard[10] == 1)
						{
							card11.move(0, 100);
							raisecard[10] = 0;
						}
						else if (raisecard[11] == 1)
						{
							card12.move(0, 100);
							raisecard[11] = 0;
						}
						else if (raisecard[12] == 1)
						{
							card13.move(0, 100);
							raisecard[12] = 0;
						}
						raisecard[12] = 1;
					}
					if (Mouse::isButtonPressed(Mouse::Button::Left))
					{
						playersg[dwr].bcard[12] = 0;
						card13.move(0, 100);
						raisecard[12] = 0;
						rb++; turn++;
						playersg[dwr].playedcard = playersg[dwr].cards[12];
						dwr++;
						don = 0;
					}
				}
				if (rb == 4)
				{
					rb = 0;
				}
				if ((turn == 6) || (turn == 4))
				{
					turn = 0;
				}
			}
			
			// press Enter
			if (passw != dwr)
			{
				while (window.pollEvent(event))
					if (event.type == Event::TextEntered)
						if (event.key.code == 13) passw = dwr;
			}

			if (dwr == 4)dwr = 0;

			window.clear();

			window.draw(background1);
			window.draw(player1);
			window.draw(player2);
			window.draw(player3);
			window.draw(player4);
			window.draw(player[0]);
			window.draw(player[1]);
			window.draw(player[2]);
			window.draw(player[3]);

			if (passw == dwr)
			{
				//dash
				if (mkan_2l_call == 0)
				{
					window.draw(background2);
					for (int j = 0; j < 3; j++) window.draw(dd[j]);
				}
				//normal call or pass
				else if (mkan_2l_call == 1)
				{
					window.draw(background3);
					window.draw(background5);
					window.draw(background6);
					for (int i = 0; i < 14; i++) window.draw(numbers[i]);
					window.draw(cll);
					window.draw(pss);
				}
				//submiting
				else if (((mkan_2l_call == 2) || (mkan_2l_call == 4)) && (playersg[dwr].calltype.top() != 'b') && (playersg[dwr].calltype.top() != 'd') && (playersg[dwr].calltype.top() != 'm'))
				{
					window.draw(background3);
					for (int i = 0; i < 14; i++) window.draw(numbers[i]);
					window.draw(background7);
					window.draw(confirm);
				}
			}

			if (passw != dwr)
			{
				window.draw(background4);
				for (int i = 0; i < 3; i++)	window.draw(p[i]);
			}
			
			if (mkan_2l_call == 5)
			{
				if (turn == 2 || turn == 3) window.draw(pcard4);
				if (turn == 1 || turn == 2 || turn == 3) window.draw(pcard3);
				if (turn == 0 || turn == 1 || turn == 2 || turn == 3) window.draw(pcard2);
				if (turn == 3) window.draw(pcard1);
			}
			
			if (playersg[dwr].bcard[0]) window.draw(card1);
			if (playersg[dwr].bcard[1]) window.draw(card2);
			if (playersg[dwr].bcard[2]) window.draw(card3);
			if (playersg[dwr].bcard[3]) window.draw(card4);
			if (playersg[dwr].bcard[4]) window.draw(card5);
			if (playersg[dwr].bcard[5]) window.draw(card6);
			if (playersg[dwr].bcard[6]) window.draw(card7);
			if (playersg[dwr].bcard[7]) window.draw(card8);
			if (playersg[dwr].bcard[8])	window.draw(card9);
			if (playersg[dwr].bcard[9])	window.draw(card10);
			if (playersg[dwr].bcard[10]) window.draw(card11);
			if (playersg[dwr].bcard[11]) window.draw(card12);
			if (playersg[dwr].bcard[12]) window.draw(card13);
			window.display();
		}
    }
}

void intialization()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			playersg[i].bcard[j] = 1;
		}
	}

	d[0].setFont(fnz);
	d[0].setCharacterSize(80);
	d[0].setFillColor(Color::White);
	d[0].setString("Dash Call");
	d[0].setPosition(580, 300);
	d[1].setFont(fnz);
	d[1].setCharacterSize(70);
	d[1].setString("Yes");
	d[1].setPosition(579, 440);
	d[2].setFont(fnz);
	d[2].setCharacterSize(70);
	d[2].setString("No");
	d[2].setPosition(735, 440);

	fnt.loadFromFile("a.ttf");
	za8rafa.loadFromFile("c.ttf");
	font3.loadFromFile("font.ttf");
	fnz.loadFromFile("ee.ttf");

	card1.setPosition(0, 630);
	card2.setPosition(100, 620);
	card3.setPosition(200, 610);
	card4.setPosition(300, 600);
	card5.setPosition(400, 590);
	card6.setPosition(500, 580);
	card7.setPosition(600, 570);
	card8.setPosition(700, 580);
	card9.setPosition(800, 590);
	card10.setPosition(900, 600);
	card11.setPosition(1000, 610);
	card12.setPosition(1100, 620);
	card13.setPosition(1200, 630);

	pcard1.setPosition(620, 400);
	pcard2.setPosition(510, 290);
	pcard3.setPosition(620, 220);
	pcard4.setPosition(730, 290);

	pcard1.setOutlineColor(Color::Black);
	pcard2.setOutlineColor(Color::Black);
	pcard3.setOutlineColor(Color::Black);
	pcard4.setOutlineColor(Color::Black);

	pcard1.setOutlineThickness(2);
	pcard2.setOutlineThickness(2);
	pcard3.setOutlineThickness(2);
	pcard4.setOutlineThickness(2);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			st += to_string(i * 13 + j + 1);
			st.insert(st.size(), ".png");
			cards[i * 13 + j].loadFromFile(st);
			st.erase();
		}
	}

	string cs;

	player1.setPosition(-200, -210);
	player2.setPosition(850, 145);
	player3.setPosition(410, -165);
	player4.setPosition(-30, 145);

	player[0].setPosition(0, 210);
	player[1].setPosition(1050, 460);
	player[2].setPosition(610, 150);
	player[3].setPosition(170, 460);

	for (int i = 0; i < 14; i++)
	{
		numbers[i].setFont(font3);
		numbers[i].setCharacterSize(30);
		numbers[i].setString(num[i]);
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

	background4.setFillColor(Color::Black);
	background5.setFillColor(Color::Yellow);
	background6.setFillColor(Color::Red);
	background7.setFillColor(Color::Red);

	background1.setPosition(-10,-10);
	background2.setPosition(550, 290);
	background3.setPosition(410, 170);
	background4.setPosition(1080, 0);
	background5.setPosition(580, 490);
	background6.setPosition(720, 490);
	background7.setPosition(580, 490);

	tree.loadFromFile("tree.jpg");
	caro.loadFromFile("karo.jpg");
	heart.loadFromFile("heart.jpg");
	speed.loadFromFile("speed.jpg");
	suns.loadFromFile("suns.jpg");

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
	background1.setTexture(&backtext1);
	background2.setTexture(&backtext2);

	call[0] = 1;
	call[1] = 1;
	call[2] = 1;
	call[3] = 1;


	cardsback.loadFromFile("HumanAvatar.png");
}

bool sameshape(int cardnumber, int firstplayedcard, int dwr, int rb)
{
	if (((((playersg[dwr].cards[0] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[0]) ||
		(((playersg[dwr].cards[1] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[1]) ||
		(((playersg[dwr].cards[2] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[2]) ||
		(((playersg[dwr].cards[3] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[3]) ||
		(((playersg[dwr].cards[4] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[4]) ||
		(((playersg[dwr].cards[5] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[5]) ||
		(((playersg[dwr].cards[6] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[6]) ||
		(((playersg[dwr].cards[7] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[7]) ||
		(((playersg[dwr].cards[8] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[8]) ||
		(((playersg[dwr].cards[9] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[9]) ||
		(((playersg[dwr].cards[10] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[10]) ||
		(((playersg[dwr].cards[11] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[11]) ||
		(((playersg[dwr].cards[12] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[12]) ||
		(((playersg[dwr].cards[13] - 1) / 13 == (firstplayedcard - 1) / 13) && playersg[dwr].bcard[13]))
		&& (rb != 0)) return ((cardnumber - 1) / 13 == (firstplayedcard - 1) / 13);
	else return 1;
}

bool calltest(short x, short playernom)
{

	if (call[0] + call[1] + call[2] + call[3] - call[playernom] + x != 13)
		return 1;
	else
		return 0;
}
