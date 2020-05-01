#include <iostream>
#include "mygraphics.h"
#include <conio.h>
#include <time.h>
#define ROWS 25
#define COL 80
using namespace std;

bool GameContinue = true;

int EmptyPosition[COL] = {};

char World[ROWS][COL] = {
  "                                                                               ",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | |*| | | | | | | | | | | | | | |*| | | | | | | | | | | | | | | | |*| | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | |*| | | | | | | | | | | | | | |*| | | | | | | | | | | | | | | | |*| | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
};

char FrontWorld[ROWS][COL] = {
  "                                                                               ",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
  "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |",
};

void RouteUpdatedInfo(int CEndPoint, int CStartPoint)
{
	EmptyPosition[COL - 1] = {};

	for (int i = 1; i < ROWS; i++)       // Nested Loop to Access Array Elements
	{
		for (int j = 1; j < COL; j++)
		{
			if (CEndPoint < CStartPoint)     // Checks if End Point is Placed to the Left of Starting Point.
			{
				if (World[i][j] == ' ' && (World[i + 1][j] == '|' || World[i - 1][j] == '|') && World[i][j - 1] == ' ' && World[i][j + 1] == ' ')    // Check Position of Possible Route
				{
					EmptyPosition[j + 1] = i;     // Stores the Row Index for Later Comparison with Starting Node Index. 
				}
			}
			else if (CEndPoint > CStartPoint)   // Checks if End Point is Placed to the right of Starting Point.
			{
				if (World[i][j] == ' ' && (World[i + 1][j] == '|' || World[i - 1][j] == '|') && World[i][j - 1] == ' ' && World[i][j + 1] == ' ')    // Check Position of Possible Route
				{
					EmptyPosition[j - 1] = i;     // Stores the Row Index for Later Comparison with Starting Node Index. 
				}
			}
		}
	}
}

struct Messages
{
	//Output Message At the End of Game.
	void OutputMessage(int Score, int Lives, int FoodLeft)
	{
		if (Lives > 0 && FoodLeft == 0)      // If Player Wins
		{
			cout << "\n\n\n\t\t\tWell Played!\n\n";      // Message to Player At End.

			cout << "\n\n\n\t\t\t\t\t\tYour Score is : " << Score << "\n\n\n\n";   // Display Score At End.

		}
		else           // If Player Loses or Quits.
		{
			cout << "\n\n\n\n\t\t\tBetter Luck Next Time!\n\n";    // Message to Player At End.

			cout << "\n\n\n\n\t\t\t\t\t\tYour Score is : " << Score << "\n\n\n";      // Display Score At End.

		}
	}

	//Welcome Message Before Starting Game.
	void WelcomeMessage()
	{
		//Welcome Screen.
		string s = "\"WELCOME TO FOOD EATER\"";

		int x = 0;

		cout << "\t\t\t\t";

		while (s[x] != '\0')
		{
			cout << s[x];

			if (s[x] != ' ' && s[x] != '\n')
			{
				PlaySound(TEXT("Click.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}

			Sleep(500);
			x++;
		};

		cout << endl;

		delay(2000);

		cls();

		cout << "\t\t  NOTE: BEWARE OF THE RED CIRCLE, IT WILL HUNT YOU DOWN!" << endl << endl;

		cout << "\t\t\t\tUSE 'W' TO MOVE UP" << endl;

		cout << "\t\t\t\tUSE 'S' TO MOVE DOWN" << endl;

		cout << "\t\t\t\tUSE 'A' TO MOVE LEFT" << endl;

		cout << "\t\t\t\tUSE 'D' TO MOVE RIGHT" << endl;

		int Input;

		cout << "\n\n\t\t\t\t\"PRESS SPACE TO START\"" << endl;

		do     // Loop for Validation.
		{
			Input = _getch();      // Gets key from User.

		} while (int(Input) != 32);

		delay(1000);    // Delay for 2000 milliseconds.

		cls();    // Clear Screen.

		SetConsoleStyle(9, 20);

		SetConsoleWindowDimensions(1280, 720);
	}
};

struct Position
{
	int x, y;
};

class Player
{
public:
	char SymbolPlayer;
	char Food;
	char Key;
	int FoodLeft;
	int Score;
	int Lives;
	Position Reset;
	Position Shape;
	Position player;
	Position food[6];
	bool FoodEaten[6];

	Player(int row, int col, char symbol)
	{
		SymbolPlayer = symbol; Food = '*'; Key = NULL; FoodLeft = 6;
		Score = 0; Lives = 3; Shape.x = 0; Shape.y = 0; player.x = col;
		player.y = row; World[row][col] = SymbolPlayer; Reset.x = col; Reset.y = row;
		food[0].x = 7; food[0].y = 2; food[1].x = 37; food[1].y = 2; food[2].x = 71; food[2].y = 2;
		food[3].x = 7; food[3].y = 20; food[4].x = 37; food[4].y = 20; food[5].x = 71; food[5].y = 20;

		for (int i = 0; i < 6; i++)
		{
			FoodEaten[i] = false;
		}
	}

	void CheckFood(int row, int col)
	{
		if (row == food[0].y && col == food[0].x)
		{
			FoodEaten[0] = true;
		}

		else if (row == food[1].y && col == food[1].x)
		{
			FoodEaten[1] = true;
		}

		else if (row == food[2].y && col == food[2].x)
		{
			FoodEaten[2] = true;
		}

		else if (row == food[3].y && col == food[3].x)
		{
			FoodEaten[3] = true;
		}

		else if (row == food[4].y && col == food[4].x)
		{
			FoodEaten[4] = true;
		}

		else if (row == food[5].y && col == food[5].x)
		{
			FoodEaten[5] = true;
		}
	}

	void PlayerMovement()
	{
		bool ActionDone = false;

		Key = NULL;

		if (_kbhit() != 0)
		{
			Key = _getch();

		}

		if (Key == 'a' || Key == 'A')        // In Case of Player Moving Leftwards. 
		{
			for (int x = 1; x < ROWS; x++)         // Loop through Positive X-Axis.
			{
				for (int y = 1; y < COL - 1; y++)
				{
					// Checks Current Position of Player.
					if (World[x][y] == SymbolPlayer && !ActionDone && World[x][y - 1] != '|' && World[x][y - 1] != '_')
					{
						if (World[x][y - 1] == Food)
						{
							FoodLeft--;
							Score += 20;
							CheckFood(x, y - 1);
							World[x][y - 1] = ' ';
							FrontWorld[x][y - 1] = ' ';
						}

						World[x][y - 1] = SymbolPlayer;               // Store Player in Previous Positions.

						World[x][y] = ' ';       // Makes Current Position Blank.
						FrontWorld[x][y] = ' ';

						Shape.x = Shape.x - 9;        // Variable i controls Player Shape Movement.

						player.x = y - 1;

						ActionDone = true;

						break;
					}

					if (ActionDone)
					{
						break;
					}
				}
			}
		}

		if (Key == 'd' || Key == 'D')           //In Case of Player Moving Rightwards.
		{
			for (int x = 1; x < ROWS; x++)         // Loop through Positive X-Axis.
			{
				for (int y = 1; y < COL - 1; y++)
				{
					// Checks Current Position of Player.
					if (World[x][y] == SymbolPlayer && !ActionDone && World[x][y + 1] != '|' && World[x][y + 1] != '_')
					{
						if (World[x][y + 1] == Food)
						{
							FoodLeft--;
							Score += 20;
							CheckFood(x, y + 1);
							World[x][y + 1] = ' ';
							FrontWorld[x][y + 1] = ' ';
						}

						World[x][y] = ' ';      // Store Player in Forward Positions.
						FrontWorld[x][y] = ' ';
						World[x][y + 1] = SymbolPlayer;

						Shape.x = Shape.x + 9;        // Variable i controls Player Shape Movement.

						player.x = y + 1;

						ActionDone = true;

						break;
					}

					if (ActionDone)
					{
						break;
					}
				}
			}
		}

		if (Key == 'w' || Key == 'W')
		{
			for (int x = 2; x < ROWS; x++)         // Loop through Positive X-Axis.
			{
				for (int y = 1; y < COL - 1; y++)
				{
					// Checks Current Position of Player.
					if (World[x][y] == SymbolPlayer && !ActionDone && World[x - 1][y] != '_' && World[x - 1][y] != '|')
					{
						if (World[x - 1][y] == Food)
						{
							FoodLeft--;
							Score += 20;
							CheckFood(x - 1, y);
							World[x - 1][y] = ' ';
							FrontWorld[x - 1][y] = ' ';
						}

						World[x - 1][y] = SymbolPlayer;

						World[x][y] = ' ';
						FrontWorld[x][y] = ' ';
						Shape.y = Shape.y - 20;        // Variable i controls Player Shape Movement.

						player.y = x - 1;

						ActionDone = true;

						break;
					}

					if (ActionDone)
					{
						break;
					}
				}
			}
		}

		if (Key == 's' || Key == 'S')
		{
			for (int x = 1; x < ROWS - 2; x++)         // Loop through Positive X-Axis.
			{
				for (int y = 1; y < COL - 1; y++)
				{
					// Checks Current Position of Player.
					if (World[x][y] == SymbolPlayer && !ActionDone && World[x + 1][y] != '_' && World[x + 1][y] != '|')
					{
						if (World[x + 1][y] == Food)
						{
							FoodLeft--;
							Score += 20;
							CheckFood(x + 1, y);
							World[x + 1][y] = ' ';
							FrontWorld[x + 1][y] = ' ';
						}

						World[x + 1][y] = SymbolPlayer;

						World[x][y] = ' ';
						FrontWorld[x][y] = ' ';
						Shape.y = Shape.y + 20;        // Variable i controls Player Shape Movement.

						player.y = x + 1;

						ActionDone = true;

						break;
					}

					if (ActionDone)
					{
						break;
					}
				}
			}
		}
	}

	void GotHit(int x, int y)
	{

		World[x][y] = ' ';   // Enemy Laser Disappear.
		FrontWorld[x][y] = ' ';

		Lives--;                 // Lives Count Decrease.

		Beep(800, 10);     // Kill Sound.

		if (Lives == 0)          // Checks if No lives Left, if True then Game Finished.
		{
			GameContinue = 0;        // Game Finished.
		}
		else
		{
			World[Reset.y][Reset.x] = SymbolPlayer;
			player.x = Reset.x; player.y = Reset.y;
			Shape.x = 0; Shape.y = 0;
		}
	}

};

class Enemy
{
public:
	char SymbolEnemy;
	Position Shape;
	Position enemy;

	Enemy(int row, int col, char symbol)
	{
		SymbolEnemy = symbol;
		Shape.x = 0;
		Shape.y = 0;
		enemy.x = col;
		enemy.y = row;
		World[row][col] = SymbolEnemy;
	}

	void EnemyMovement(Player& P)
	{
		RouteUpdatedInfo(P.player.x, enemy.x);

		if (P.player.x >= enemy.x)    // Checks if End Point is Placed to the right of Starting Point.
		{
			for (int i = 1; i < ROWS; i++)             // Nested Loop to Access Array Elements.
			{
				for (int j = enemy.x; j <= P.player.x; j++)
				{
					if (World[i][j] == SymbolEnemy && j == P.player.x)    // If End Column Reached.
					{
						if (i < P.player.y)   // Checks if Starting Node is Above Ending Node.
						{
							if (World[i + 1][j] == P.SymbolPlayer)     // Checks if Starting Node is Just above Ending Node.
							{
								P.GotHit(i + 1, j);

							}

							else if (rand() % 4 == 2 && World[i + 1][j] != '|')
							{
								if (World[i + 1][j] == P.Food)
								{
									P.CheckFood(i + 1, j);
									P.FoodLeft--;
								}

								World[i + 1][j] = World[i][j];     // Move Starting Node Downwards.

								World[i][j] = ' '; // Clears Previous Location.
								FrontWorld[i][j] = ' ';

								enemy.y = enemy.y + 1;

								Shape.y = Shape.y + 20;

							}
						}

						else if (i > P.player.y)   // Checks if Starting Node is Below Ending Node.
						{
							if (World[i - 1][j] == P.SymbolPlayer)      // Checks if Starting Node is Just below Ending Node.
							{
								P.GotHit(i - 1, j);

							}

							else if (rand() % 4 == 2 && World[i - 1][j] != '|')
							{
								if (World[i - 1][j] == P.Food)
								{
									P.CheckFood(i - 1, j);
									P.FoodLeft--;
								}

								World[i - 1][j] = World[i][j];   // Move Starting Node Upwards.
								World[i][j] = ' ';   // Clears Previous Location.
								FrontWorld[i][j] = ' ';
								enemy.y = enemy.y - 1;
								Shape.y = Shape.y - 20;
							}
						}
					}

					else if (World[i][j] == SymbolEnemy && World[i][j + 1] == ' ' && rand() % 4 == 2)        // Checks if there is a possible route adjacent to Starting Node Position 
					{
						World[i][j + 1] = World[i][j];       // Stores Start at Adjacent Location.
						World[i][j] = ' ';   // Clears Previous Location.
						FrontWorld[i][j] = ' ';
						enemy.x = enemy.x + 1;
						Shape.x = Shape.x + 9;
					}

					else if (World[i][j] == SymbolEnemy && World[i][j + 1] != ' ' && rand() % 4 == 2 && EmptyPosition[j] > i&& j != P.player.x)   // Checks if No Adjacent Route so Move the Starting Node based on Shortest distance from Route.
					{
						if (World[i + 1][j] == P.Food)
						{
							P.CheckFood(i + 1, j);
							P.FoodLeft--;
						}

						World[i + 1][j] = World[i][j];   // In this Case it is below Starting Node Position so it moves downwards.
						World[i][j] = ' ';     // Clears Previous Location.
						FrontWorld[i][j] = ' ';
						enemy.y = enemy.y + 1;
						Shape.y = Shape.y + 20;
					}

					else if (World[i][j] == SymbolEnemy && World[i][j + 1] != ' ' && rand() % 4 == 2 && EmptyPosition[j] < i && j != P.player.x)
					{
						if (World[i - 1][j] == P.Food)
						{
							P.CheckFood(i - 1, j);
							P.FoodLeft--;
						}

						World[i - 1][j] = World[i][j];      // In this Case it is Above Starting Node Position so it moves Upwards.
						World[i][j] = ' ';      // Clears Previous Location.
						FrontWorld[i][j] = ' ';
						enemy.y = enemy.y - 1;
						Shape.y = Shape.y - 20;
					}

				}
			}
		}

		else if (P.player.x <= enemy.x)  // Checks if End Point is Placed to the Left of Starting Point.
		{

			for (int i = 1; i < ROWS; i++)             // Nested Loop to Access Array Elements.
			{
				for (int j = enemy.x; j >= P.player.x; j--)
				{
					if (World[i][j] == SymbolEnemy && j == P.player.x)    // If End Column Reached.
					{
						if (i < P.player.y)   // Checks if Starting Node is Above Ending Node.
						{
							if (World[i + 1][j] == P.SymbolPlayer)     // Checks if Starting Node is Just above Ending Node.
							{
								P.GotHit(i + 1, j);

							}

							else if (rand() % 4 == 2 && World[i + 1][j] != '|')
							{
								if (World[i + 1][j] == P.Food)
								{
									P.CheckFood(i + 1, j);
									P.FoodLeft--;
								}

								World[i + 1][j] = World[i][j];     // Move Starting Node Downwards.
								World[i][j] = ' '; // Clears Previous Location.
								FrontWorld[i][j] = ' ';
								enemy.y = enemy.y + 1;
								Shape.y = Shape.y + 20;
							}
						}

						else if (i > P.player.y)   // Checks if Starting Node is Below Ending Node.
						{
							if (World[i - 1][j] == P.SymbolPlayer)      // Checks if Starting Node is Just below Ending Node.
							{
								P.GotHit(i - 1, j);
							}

							else if (rand() % 4 == 2 && World[i - 1][j] != '|')
							{
								if (World[i - 1][j] == P.Food)
								{
									P.CheckFood(i - 1, j);
									P.FoodLeft--;
								}

								World[i - 1][j] = World[i][j];   // Move Starting Node Upwards.
								World[i][j] = ' ';   // Clears Previous Location.
								FrontWorld[i][j] = ' ';
								enemy.y = enemy.y - 1;
								Shape.y = Shape.y - 20;
							}
						}
					}

					else if (World[i][j] == SymbolEnemy && World[i][j - 1] == ' ' && rand() % 4 == 2)        // Checks if there is a possible route adjacent to Starting Node Position 
					{
						World[i][j - 1] = World[i][j];       // Stores Start at Adjacent Location.
						World[i][j] = ' ';   // Clears Previous Location.
						FrontWorld[i][j] = ' ';
						enemy.x = enemy.x - 1;
						Shape.x = Shape.x - 9;
					}

					else if (World[i][j] == SymbolEnemy && World[i][j - 1] != ' ' && rand() % 4 == 2 && EmptyPosition[j] > i&& j != P.player.x)   // Checks if No Adjacent Route so Move the Starting Node based on Shortest distance from Route.
					{
						if (World[i + 1][j] == P.Food)
						{
							P.CheckFood(i + 1, j);
							P.FoodLeft--;
						}

						World[i + 1][j] = World[i][j];   // In this Case it is below Starting Node Position so it moves downwards.
						World[i][j] = ' ';     // Clears Previous Location.
						FrontWorld[i][j] = ' ';
						enemy.y = enemy.y + 1;
						Shape.y = Shape.y + 20;
					}

					else if (World[i][j] == SymbolEnemy && World[i][j - 1] != ' ' && rand() % 4 == 2 && EmptyPosition[j] < i && j != P.player.x)
					{
						if (World[i - 1][j] == P.Food)
						{
							P.CheckFood(i - 1, j);
							P.FoodLeft--;
						}

						World[i - 1][j] = World[i][j];      // In this Case it is Above Starting Node Position so it moves Upwards.
						World[i][j] = ' ';      // Clears Previous Location.
						FrontWorld[i][j] = ' ';
						enemy.y = enemy.y - 1;
						Shape.y = Shape.y - 20;
					}
				}
			}
		}
	}

};

struct Shapes
{
	void InitializeShapes(Player& P, int EnemyX, int EnemyY)
	{
		SetConsoleWindowDimensions(1280, 720);

		// Player
		drawEllipse(186 + P.Shape.x, 103 + P.Shape.y, 200 + P.Shape.x, 117 + P.Shape.y, 0, 0, 0, 0, 255, 0);

		// Enemy
		drawEllipse(718 + EnemyX, 103 + EnemyY, 732 + EnemyX, 117 + EnemyY, 0, 0, 0, 255, 0, 0);

		// Borders
		{
			// Top
			drawLine(185, 20, 885, 20, 255);

			// Bottom
			drawLine(185, 480, 885, 480, 255);

			// Left
			drawLine(185, 19, 185, 480, 255);

			// Right
			drawLine(886, 19, 886, 480, 255);
		}

		// Lives
		{
			if (P.Lives == 3)
			{
				drawEllipse(817, 522, 832, 537, 0, 255, 0, 0, 255, 0);

				drawEllipse(837, 522, 852, 537, 0, 255, 0, 0, 255, 0);

				drawEllipse(857, 522, 872, 537, 0, 255, 0, 0, 255, 0);
			}

			else if (P.Lives == 2)
			{
				drawEllipse(817, 522, 832, 537, 0, 255, 0, 0, 255, 0);

				drawEllipse(837, 522, 852, 537, 0, 255, 0, 0, 255, 0);

				drawEllipse(857, 522, 872, 537, 0, 0, 0, 0, 0, 0);
			}

			else if (P.Lives == 1)
			{
				drawEllipse(817, 522, 832, 537, 0, 255, 0, 0, 255, 0);

				drawEllipse(837, 522, 852, 537, 0, 0, 0, 0, 0, 0);
			}

			else if (P.Lives == 0)
			{
				drawEllipse(817, 522, 832, 537, 0, 0, 0, 0, 0, 0);
			}
		}

		// Food
		{
			if (!P.FoodEaten[0])
			{
				// Food Top Left
				drawEllipse(240, 43, 254, 57, 0, 0, 0, 255, 255, 0);
			}

			if (!P.FoodEaten[1])
			{
				// Food Top Middle
				drawEllipse(510, 43, 524, 57, 0, 0, 0, 255, 255, 0);
			}

			if (!P.FoodEaten[2])
			{
				// Food Top Right
				drawEllipse(816, 43, 830, 57, 0, 0, 0, 255, 255, 0);
			}

			if (!P.FoodEaten[3])
			{
				// Food Bottom Left
				drawEllipse(240, 403, 254, 417, 0, 0, 0, 255, 255, 0);
			}

			if (!P.FoodEaten[4])
			{
				// Food Bottom Middle
				drawEllipse(510, 403, 524, 417, 0, 0, 0, 255, 255, 0);
			}

			if (!P.FoodEaten[5])
			{
				// Food Bottom Right
				drawEllipse(816, 403, 830, 417, 0, 0, 0, 255, 255, 0);
			}
		}
	}

	void CleanShapes()
	{
		// Lives
		{
			drawEllipse(817, 522, 832, 537, 0, 0, 0, 0, 0, 0);

			drawEllipse(837, 522, 852, 537, 0, 0, 0, 0, 0, 0);

			drawEllipse(857, 522, 872, 537, 0, 0, 0, 0, 0, 0);
		}

		// Borders
		{
			// Top
			drawLine(185, 20, 885, 20, 0);

			// Bottom
			drawLine(185, 480, 885, 480, 0);

			// Left
			drawLine(185, 19, 185, 480, 0);

			// Right
			drawLine(886, 19, 886, 480, 0);
		}
	}
};

void MakeRoute(Player& P, char Enemy)
{
	srand(unsigned int(time(NULL)));

	for (int i = 1; i < ROWS; i++)             // Nested Loop to Access Array Elements
	{
		for (int j = 2; j < COL - 2; j++)
		{
			if (rand() % 3 == 2 && World[i][j] != P.SymbolPlayer && World[i][j] != P.Food && World[i][j] != Enemy)         // If a random time is true.
			{
				World[i][j] = ' ';    // Make a Space for Route.
				FrontWorld[i][j] = ' ';
			}

		}
	}
}

void DisplayWorld(int Score, int FoodLeft, int Lives)
{

	for (int y = 0; y < ROWS; y++)          // Loop to Display World|Array.
	{
		gotoxy(20, y);
		cout << FrontWorld[y] << endl;
	}

	cout << "\n\t\t\tSCORE : " << Score << "\t\t      FOOD LEFT: " << FoodLeft << "\t\t     LIVES ";  // Score & Lives Display.
}

int main()
{
	SetINTRO();

	Player P(5, 1, 'O'); Enemy E(5, 60, '0'); Messages M; Shapes S;

	M.WelcomeMessage();

	MakeRoute(P, E.SymbolEnemy);

	while (P.Lives != 0 && P.FoodLeft != 0)
	{
		system("cls");
		cls();
		DisplayWorld(P.Score, P.FoodLeft, P.Lives);
		S.InitializeShapes(P, E.Shape.x, E.Shape.y);
		P.PlayerMovement();
		E.EnemyMovement(P);
		delay(50);
	}

	system("cls");

	S.CleanShapes();

	M.OutputMessage(P.Score, P.Lives, P.FoodLeft);

	delay(3000);

	return 0;
}
