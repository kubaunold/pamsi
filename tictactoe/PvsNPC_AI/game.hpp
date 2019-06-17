#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <iomanip>	//for setw
#include <algorithm>	//for max() & min()

//struct responsible for x & y coordinates
struct move
{
	unsigned int x = 0;
	unsigned int y = 0;

	move() : x(17), y(23) {}


	move(int a, int b) : x(a), y(b) {}

};

class Game
{
	/*
	klasa wyliczeniowa dla roznych 3 stanow na planszy
	none - pole, na ktorym "nie ma ruchu"
	O - cz³owiek
	X - gracz
	*/
	enum class player { none = '-', human = 'O', PC = 'X' };

	int N; //# of tiles per row/column
	player **board; // dynamic 2D array of players (representing actual board)

public:
	//parameterized constructor
	Game(int n);

	//destructor
	~Game();

	void showBoard(); //shows board

	bool isDraw();	//returns true if draw

	//Always 3 in a row is enough
	bool checkWin(player participant);

	move bestMove();	//best move for PC (AI)

	void playersMove();	//player move

	void play();	//function responsible for gameplay

	int minimax(int depth, bool czyMax, int alpha, int beta);
	//int minimax(move position, int depth, player maximizingPlayer);

	int countDepth();
};

#endif